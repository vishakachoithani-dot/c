#include <stdio.h>
int main(){
    printf("Enter the first number: ");
    int num1;
    scanf("%d",&num1);
    printf("Enter the second number: ");
    int num2;
    scanf("%d",&num2);
    printf(num1/num2);
    printf(num1 % num2);
}