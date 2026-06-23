// WAP to sort the N names in an alphabetical order.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter Name in UpperCase: \n");
    char name[size][50];
    for(int i=0;i<size;i++){
        printf("Enter Name :");
        scanf("%s",name[i]);
    }

    for(int i=0;i<size;i++){
        name[i][0] = toupper(name[i][0]);
    }

    char temp[50];

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if (strcmp(name[i],name[j]) > 0){
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
                // name[i][0] = name[j];
                // name[j][0] = temp;
            } 
        }
    }

    printf("Sorted Names:  ");
    for(int i=0;i<size;i++){
        printf("%s  ",name[i]);
    }

    return 0;
}