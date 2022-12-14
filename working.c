#include<stdio.h>
#include <windows.h>
#include<string.h>
#include <stdbool.h>
char arrayData[100];
typedef struct User{
    char name[100];
    char accountNumber[17];
    char password[20];
    char address[100];
    char aadhar[16];
    char mobile[15];
    char balance[8];
} User;

User person, fetched,fetched2;


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
void generateAccountNUmber();
bool fetchData(char user[]);
void reStoreUser(User person){
    FILE *fuser;
    char filepath[23]="users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".txt");
    fuser = fopen(filepath,"w+");
    fprintf(fuser,"%s\n",person.accountNumber);
    fprintf(fuser,"%s\n",person.password);
    fprintf(fuser,"%s\n",person.name);
    fprintf(fuser,"%s\n",person.mobile);
    fprintf(fuser,"%s\n",person.aadhar);
    fprintf(fuser,"%s\n",person.address);
    fprintf(fuser,"%s\n",person.balance);
    fprintf(fuser,"\0");
    fclose(fuser);
    printf("User Stored Successfully");
}


void storeUser(User person)
{ 
    FILE *fuser;
    char filepath[23]="users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".txt");
    fuser = fopen(filepath,"a");
    fprintf(fuser,"%s\n",person.accountNumber);
    fprintf(fuser,"%s\n",person.password);
    fprintf(fuser,"%s\n",person.name);
    fprintf(fuser,"%s\n",person.mobile);
    fprintf(fuser,"%s\n",person.aadhar);
    fprintf(fuser,"%s\n",person.address);
    fprintf(fuser,"%s\n",person.balance);
    fprintf(fuser,"\0");
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

void displayUser(User person){
    printf("Name: %s\n",person.name);

    printf("Account Number: XXXXXXXXXXXX%c%c%c%c\n", person.accountNumber[12], person.accountNumber[13], person.accountNumber[14], person.accountNumber[15]);

    printf("Address: %s\n",person.address);

    printf("Mobile Number: %s\n",person.mobile);
    printf("Balance: %s\n",person.balance);
    printf("Password: %s\n",person.password);

}

void createUser(){
    char repassword[20];
    int k=0;
    // char c;
    getchar();
    printf("Full Name: ");
    gets(person.name);  getchar();
    printf("Account Number: ");
    scanf("%s",&person.accountNumber); getchar();
    printf("Mobile: "); 
    gets(person.mobile);
    printf("Address: ");
    gets(person.address);
    printf("Aadhar Number: ");
    gets(person.aadhar);
    while(k==0){
        printf("Password: ");
        gets(person.password);
        printf("Enter Password again: ");
        gets(repassword);
        if(strcmp(repassword,person.password)==0)
            k++;
    
        else
            printf("\nBoth the passwords were different. Enter Again\n");
    
    }
    // person.balance="";
    strcpy(person.balance,"1000");
    printf("saving now");
    storeUser(person);
    printf("User created successfully!!\n");
    displayUser(person);
    
}

void updateUser(){

}

void transactMenu()
{
    char accNo[16];
    char filepath[23] = "users\\";
    printf("-------------------------------------------------------------------\n");
    printf("\t\t\tWelcome to PDEU BANK\n");
    printf("\t\t   ::Enter your Account Number::\n");
    scanf("%s",&accNo);getchar();
    printf("-------------------------------------------------------------------\n");
    if (fetchData(accNo))
    {
        printf("1. Deposit Money  \t\t\t\t  2. Withdraw Money\n");
        printf("-------------------------------------------------------------------\n");
        int ch1;scanf("%d",&ch1);
        long amt;
        switch (ch1)
        {
        case 1:
            printf("Enter the amount to be deposited :- ");
            scanf("%ld",&amt);
            long bal = (long) fetched.balance;
            bal+=amt;
            strcpy(fetched.balance,"");
            sprintf(fetched.balance,"%ld",bal);
            printf("The amount %ld is deposited successfully!\n");
            printf("The updated balance is %s",fetched.balance);
            restoreUser(fetched);
            break;
        case 2:
            
            printf("Enter the amount to be withdrawn :-");
            scanf("%d",&amt);
            bal = (int)fetched.balance;
            if(bal>=amt){
                bal-=amt;
                strcpy(fetched.balance,"");
                sprintf(fetched.balance,"%ld",bal);
                printf("The amount %ld is successfully withdrawn!!\n");
                printf("The updated balance is %s",fetched.balance);
                restoreUser(fetched);
            }
            else   
                printf("Insufficient Balance!!");
            break;
        
        default:
            printf("Invalid Choice !!");
            break;
        }
    }
    else
        printf("The account does not exist!!");
}


void authUser(char user[], char passwd[]){
    fetchData(user);
    if(strcmp(fetched.password,passwd)==0){
        // clrscr();
        printf("Logging You In....");
    }
    else{
        printf("%s",fetched.password);
    }
}

bool fetchData(char user[]) {
    char balance[8];
    char filepath[23]="users\\";
    strcat(filepath,user);
    strcat(filepath,".txt");
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL)
        //printf("Account does not exist\n");
        return false;
    else {
        fgets(fetched.accountNumber,20,fptr);
        fgets(fetched.password,20,fptr);
        fgets(fetched.name,20,fptr);
        fgets(fetched.mobile,20,fptr);
        fgets(fetched.aadhar,20,fptr);
        fgets(fetched.address,20,fptr);
        fgets(fetched.balance,8,fptr);

        fetched.password[ strcspn (fetched.password, "\n")] = '\0';
        fetched.address[ strcspn (fetched.address, "\n")] = '\0';
        fetched.mobile[ strcspn (fetched.mobile, "\n")] = '\0';
        return true;
        
}

    displayUser(fetched);
}
int main(){
    menu();
//     printf("%s",person.accountNumber);
    // authUser("1234567891234567","1");
    // fetchData("1234567891234567");
}
