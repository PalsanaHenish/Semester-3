#include<stdio.h>
#include<string.h>
struct Student{
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};
void main(){
    struct Student s;
    struct Student *ptr=&s;
    printf("Enter roll number: ");
    scanf("%d", ptr->roll_no);
    printf("Enter roll number: ");
    scanf("%d",&s.roll_no);
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter name: ");
    scanf("%s",&s.name);
    printf("Enter branch: ");
    scanf("%s", ptr->branch);
    printf("Enter branch: ");
    scanf("%s",&s.branch);
    printf("Enter batch number: ");
    scanf("%d", ptr->batch_no);
    printf("Enter batch number: ");
    scanf("%d", &s.batch_no);
    printf("Student Details:\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Branch: %s\n", s.branch);
    printf("Batch Number: %d\n", s.batch_no);
}