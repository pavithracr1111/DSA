#include <stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int main()
{
    int num1, num2;
    printf("Enter the 2 numbers : ");
    scanf("%d%d", &num1, &num2);
    printf("Add -> %d\n", add(num1, num2));
    printf("MUlti -> %d\n", mul(num1, num2));
    printf("Sub -> %d\n", sub(num1, num2));
    
}