# Compilers 101
Computer Science Undergrad Course - Compilers


## tinyexpr in C++

File: **sample.cpp**
````c++
#include <iostream>
#include "libs/tinyexpr.h"

using namespace std;

int main() {
    char expr[] = "2 * (3 + 7)^2";
    double expr_value = te_interp(expr, nullptr);
    cout << expr_value << endl;
}
````

**Up & Running:** 
```
$ g++ -g -c sample.cpp -o sample.o
$ cc -g -c tinyexpr.c -o tinyexpr.o
$ g++ sample.o tinyexpr.o -lm -o sample.bin
$ ./sample.bin
```

Returns: `200`


## tinyexpr in C

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