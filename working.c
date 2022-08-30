#include<stdio.h>
#include <windows.h>
#include<string.h>

typedef struct User{
    char name[100];
    char accountNumber[16];
    char password[20];
    char address[100];
    char aadhar[16];
    char mobile[10];
    long balance;
} User;

User person;

void fetchData(FILE *fptr) {

}

void createUser();
void updateUser();
void authUser(char user[], char passwd[]);
void checkBalance();
void withdraw();
void deposit();
void transfer(char, char, char);
void deleteUser();
void menu();
void transactMenu();

void storeUser()
{ 
    FILE *fuser;
    char filepath[22] = "users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".csv");
    fuser = fopen(filepath,"a");
    fprintf(fuser,"%s,",person.accountNumber);
    fprintf(fuser,"%s,",person.password);
    fprintf(fuser,"%s,",person.name);
    fprintf(fuser,"%s",person.mobile);
    fprintf(fuser,"%s,",person.aadhar);
    fprintf(fuser,"%s,",person.address);
    fprintf(fuser,"%s,",person.balance);
    // fprintf(fuser,"\n");
    fclose(fuser);
    printf("User Stored Successfully");
}

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
    default:
        break;
    }
    
}

// void displayUser(){
//     printf("Name: %s\n",person.name);

//     printf("Account Number: XXXXXXXXXXXX%c%c%c%c\n", person.accountNumber[12], person.accountNumber[13], person.accountNumber[14], person.accountNumber[15]);

//     printf("Address: %s\n",person.address);

//     printf("Mobile Number: %s\n",person.mobile);

// }

void createUser(){
    char repassword[20];
    int k=0;
    // char c;
    getchar();
    printf("Full Name: ");
    gets(person.name);
    printf("Account Number: ");
   
    scanf("%s",&person.accountNumber);
    printf("Mobile: ");
    scanf(" %s", &person.mobile);
    printf("Address: "); getchar();
    gets(person.address);
    printf("Aadhar Number: ");
    scanf(" %s", &person.aadhar);
   


    printf("Password: ");
    scanf(" %s", &person.password);
    printf("Enter Password again: ");
    // scanf(" %s", &repassword);
    // re enter required
    person.balance=1000;
    printf("User created successfully!!\n");
    // displayUser();
    storeUser();
    
}

void updateUser(){

}

void authUser(char user[], char passwd[]) {
    FILE *fptr = fopen(user, "r");
    if(fptr == NULL)
        printf("Account does not exist\n");
    else {
        printf("need a function here");
    }
}

int main(){
    menu();
}
