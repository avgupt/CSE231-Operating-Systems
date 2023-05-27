#include <stdio.h>
#include <inttypes.h>

int64_t checkGreater(int64_t, int64_t);

int main() {

    int64_t x, y;
    scanf("%ld %ld", &x, &y);
    checkGreater(x,y);

    return 0;
}
