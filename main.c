#include <stdlib.h>
#include "functions.h"
#include "exercises.h"

int main() {
    system("clear");
    int ex;
    set_ex(&ex);

    if (ex == 1) {
        ex1();
        return 0;
    }
    if (ex == 2) {
        ex2();
        return 0;
    }
    return 0;
}