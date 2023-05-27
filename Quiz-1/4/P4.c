#include <stdio.h>
#include <inttypes.h>

int long_add(int a, int b, int c, int d);

void main(){
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d",long_add(a,b,c,d));    
}
