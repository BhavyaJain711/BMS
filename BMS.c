#include<stdio.h>

struct User{
    char firstName[20];
    char lastName[20];
    char accountNumber[16];
    char address[100];
    char adhaar[16];
    char mobile[10];
    char fatherName[20];
    char motherName[20];
    
};

struct User person;


struct Money{
    char username[25];
    char password[20];
    long int amount;
    
};

void createUser();
void updateUser();
void authUser();
void checkBalance();
void withdraw();
void deposit();
void transfer();
void forexExchange();
void deleteUser();

void displayUser(){
    printf("Name: %s %s\n",person.firstName,person.lastName);

    printf("Account Number: XXXXXXXXXXXX%c%c%c%c\n",
    person.accountNumber[12],person.accountNumber[13],
    person.accountNumber[14],person.accountNumber[15]);

    printf("Father's Name: %s\n",person.fatherName);

    printf("Mother's Name: %s\n",person.motherName);

    printf("Address: %s\n",person.address);

    printf("Mobile Number: %s\n",person.mobile);

    
}
void createUser(){
    char c;
    printf("Full Name: ");
    scanf("%s %s",&person.firstName,&person.lastName);
    printf("Account NUmber: ");
    scanf(" %s",&person.accountNumber);
    printf("Father's Name: ");
    printf("%s",&person.fatherName);
    printf("Mothers Name: ");
    scanf(" %s",&person.motherName);
    printf("Address: ");
    scanf(" %[^\n]%*c",&person.address);
    printf("Mobile: ");
    scanf(" %s",&person.mobile);

    
}


int main(){
    createUser();
    displayUser();
    
}
