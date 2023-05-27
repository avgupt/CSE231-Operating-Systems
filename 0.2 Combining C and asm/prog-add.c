#include <stdio.h>
#include <inttypes.h>

int64_t sum(int64_t, int64_t);

int main() {

    int64_t x, y;
    scanf("%ld %ld", &x, &y);
    printf("%ld\n", sum(x, y));

    return 0;
}
