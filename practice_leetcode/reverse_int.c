/*C program to reverse the digits of a signed 32-bit integer.
If reversing the number causes it to go outside the range
[-2^31, 2^31 - 1], then return 0.
Assume that the environment does not allow the use of 64-bit integers.*/


#include<stdio.h>
#include<limits.h>

int reverse(int x){
    int rev=0;

    while(x!=0){
        int digit= x%10;
        x=x/10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;
        
        rev= rev*10 + digit;

    }

    return rev;
}

int main(){
    int x= -123;
    int ans = reverse(x);
    printf("%d\n", ans);
    return 0;
}