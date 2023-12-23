#include<stdio.h>

int factorial(int num){
    int sum = 1;
    for(int i = num; i > 0 ; i--){
        sum *= i;
    }

    return sum;
}

int recursiveFactorial(int num){
    if (num == 1){
        return num;
    }
    return num * recursiveFactorial(num-1);
}
  
int main(){
    printf("Enter the number to find the factorial: ");
    int num;
    scanf("%d", &num);
    int ans = recursiveFactorial(num);
    printf("Factorial of the %d is %d", num, ans);
}