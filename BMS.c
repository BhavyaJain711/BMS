#include<stdio.h>
#include <windows.h>

int count = 0;

typedef struct User{
    char name[100];
    int account_number;
    char password[20];
    char address[100];
    char adhaar[16];
    char mobile[10];
    long int amount;
} User;

User person;

void createUser();
void updateUser();
void authUser();
void checkBalance();
void withdraw();
void deposit();
void transfer();
void forexExchange();
void deleteUser();
void menu();
void transactMenu();

void menu(){
    int choice;
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE
                                                             |FOREGROUND_INTENSITY
                          );
    printf("\t\t\t\t\tWelcome to PDEU SOT BANK\n\n");
    printf("\t\t\t\tSelect One of the choices below:\n");
    printf("1.Create Account\n");
    printf("2.Update Account\n");
    printf("3.Transact\n");
    printf("4.Check Balance\n");
    printf("5.Forex\n");
    
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        createUser();
        break;
    case 2:
        // updateUser();
        break;
    case 3:
        // transactMenu();
        break;
    case 4:
        // checkBalance();
        break;
    case 5:
        // forexExchange();
        break;
    default:
        break;
    }
    
}

void displayUser(){
    printf("Name: %s \n",person.name);
    printf("Account number: %d\n", person.account_number);
    printf("Address: %s\n",person.address);
    printf("Mobile Number: %s\n",person.mobile);
}

void createUser(){
    char c;
    person.account_number += count; 
    printf("Account Number: %d\n", person.account_number);
    printf("Full Name: ");
    gets(person.name);
    printf("Address: ");
    scanf(" %[^\n]%*c",&person.address);
    printf("Mobile: ");
    scanf(" %s",&person.mobile);

    printf("User created successfully!!\n");
    displayUser();
}


int main(){
    menu();
    
}
