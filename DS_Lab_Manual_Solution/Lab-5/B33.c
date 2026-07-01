// Design anagram game using array.  
//   Allow a user to enter N words and store it in an array.  
//   Generate a random number between 0 to N-1.  
//   Based on the random number generated display the word stored at that 
//    index of an array and allow user to enter its anagram.  
//   Check whether the word entered by the user is an anagram of displayed 
//    number or not and display an appropriate message.  
//   Given a word A and word B. B is said to be an anagram of A if and only if the 
//    characters present in B is same as characters present in A, irrespective of 
//    their sequence. For ex: “LISTEN” == “SILENT”

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int size;
    printf("Enter no. of words you want to enter: ");
    scanf("%d",&size);

    char words[size][20];
    for(int i=0;i<size;i++){
        printf("Enter word: ");
        scanf("%s",words[i]);
    }

    int r = (int)(rand()*100)%size;
    printf("Word: %s",words[r]);
    printf("\nEnter Anagram of given word: ");
    char anagram[20];
    scanf("%s",anagram);

    if (strlen(anagram) != strlen(words[r])){
        printf("Not An Anagram !!!");
    }
    else{
        int count = 0;
        for(int i=0;i<strlen(anagram);i++){
            for(int j=0;j<strlen(words[r]);j++){
                if(anagram[i] == words[r][j]){
                    count++;
                    break;
                }
            }
        }

        if(count == strlen(anagram)){
            printf("Congratulation! (\'-\')");
        }
        else{
            printf("Not An Anagram !!!");
        }
    }
    
    return 0;
}