#include <stdio.h>
int main() {
    int num;
    int count=0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }    
    printf("The Number of Bits is: %d\n",count);
    return 0;
}
