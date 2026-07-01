// WAP to check whether the string is Palindrome or not using Pointer. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *s = (char *)malloc(sizeof(char)*50);
    scanf("%s",s);
    int n = strlen(s);
    int count = 0;
    for(int i=0;i<n/2;i++){
        if(*(s+i) != *(s+n-i-1)){
            count++;
            printf("Not Palindrome !!!");
            break;
        }
    }

    if(count == 0){
        printf("Palindrome(\'-\')");
    }

    return 0;
}