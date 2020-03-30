# Compilers 101
Computer Science Undergrad Course - Compilers


### tinyexpr 

File: **sample.c**
```c
#include <stdio.h>
#include "tinyexpr.h"

int main() {
    char expr[] = "2 * (3 + 7)^2";
    double expr_value = te_interp(expr, 0);
    printf("%f", expr_value);
}
```

**Up & Running:** 
```
$ gcc -g sample.c tinyexpr.c -o sample.bin
$ ./sample.bin
```

Returns: `200`