# Compilers 101
Computer Science Undergrad Course - Compilers


## Tech Stack
- C++ 2020
- CMake


## Up & Running 

### CMake

**Build:**
```
$ cd {PROJECT_ROOT} 
$ mkdir cmake-build-debug & cd cmake-build-debug
$ cmake ..
$ make
```

**Run:**
```$xslt
./expr_eval
```


### Manual Linking in C++

File: **expr_eval.cpp**
````c++
#include <stdio.h>
#include "libs/tinyexpr.h"

int main() {
    string expr;

    cout << "Evaluate Expr: ";
    getline(cin, expr);
    double expr_value = te_interp(expr.c_str(), nullptr);

    cout << "Result: " << expr_value << endl;
}
````

**Build:** 
```
$ g++ -g -c expr_eval.cpp -o expr_eval.o
$ cc -g -c tinyexpr.c -o tinyexpr.o
$ g++ expr_eval.o tinyexpr.o -lm -o expr_eval
$ ./expr_eval
```


## tinyexpr in C

File: **expr_eval.c**
```c
#include <stdio.h>
#include "libs/tinyexpr.h"

int main() {
    char *expr = NULL;
    unsigned int len;

    printf("Evaluate Expr: ");
    getline(&expr, &len, stdi);

    double expr_value = te_interp(expr, 0);
    printf("Result: %f\n", expr_value);
}
```

**Up & Running:** 
```
$ gcc -g expr_eval.c tinyexpr.c -o expr_eval
$ ./expr_eval
```
