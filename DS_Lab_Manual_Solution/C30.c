// WAP to replace lowercase characters by uppercase & vice-versa in a user 
// specified string.

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char s1[50];
    printf("Enter a String: ");
    scanf("%s",s1);

    char s2[50];

    for(int i = 0; s1[i]!='\0'; i++){
        if(s1[i] >= 'A' && s1[i] <= 'Z'){
            s2[i] = tolower(s1[i]);
        }
        else if(s1[i] >= 'a' && s1[i] <= 'z'){
            s2[i] = toupper(s1[i]);
        }
        else{
            printf("Only Alphabets are allowed!!!");
            return 1;
        }
    }

    printf("New String: %s",s2);

    return 0;
}