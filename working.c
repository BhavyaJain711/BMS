#include<stdio.h>
#include <windows.h>
#include<string.h>
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

User person, fetched;


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



void storeUser()
{ 
    FILE *fuser;
    char filepath[23]="users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".csv");
    fuser = fopen(filepath,"a");
    fprintf(fuser,"%s,",person.accountNumber);
    fprintf(fuser,"%s,",person.password);
    fprintf(fuser,"%s,",person.name);
    fprintf(fuser,"%s",person.mobile);
    fprintf(fuser,"%s,",person.aadhar);
    fprintf(fuser,"%s,",person.address);
    fprintf(fuser,"%d",person.balance);
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
    // strcpy(person.balance,"1000");
    printf("saving now");
    storeUser();
    printf("User created successfully!!\n");
    displayUser(person);
    
}

void updateUser(){

}

// void authUser(char user[], char passwd[]) {
//     int i=0,accno=1,pass=1;
//     char filepath[23]="users\\";
//     strcat(filepath,user);
//     strcat(filepath,".csv");
//     FILE *fptr = fopen(filepath, "r");
//     if(fptr == NULL)
//         printf("Account does not exist\n");
//     else {
//        char arr[1][100];
//         while(fgets(arr[i++], 100, fptr) != NULL);

//         for(int j=0; j<i; j++) {
//           //  mobile = 0;
//             //count = 0;
//             for(int k=0; arr[j][k] != '\0'; k++) {
//                 if(arr[j][k] == ',')
//                     arrayData[i]='\0';
//                 else {
//                     arrayData[i]=arr[j][k];
//                 }
//                 // printf("%c", arr[j][k]);
//             }
//         }   int count=7,z=0;
//             while(count--){
//                 for(int i=0;i<100;i++){
//                     while(arr[i]!='\0'){
//                         fetched.accountNumber[z++]=arr[i];
//                         continue;
//                     }

//                 }
//             }

//     } fclose(fptr);
// } 

void fetchData(char user[]) {
    char balance[8];
char filepath[23]="users\\";
    strcat(filepath,user);
    strcat(filepath,".csv");
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL)
        printf("Account does not exist\n");
    else {
        fgets(fetched.accountNumber,20,fptr);
        fgets(fetched.password,20,fptr);
        fgets(fetched.name,20,fptr);
        fgets(fetched.mobile,20,fptr);
        fgets(fetched.aadhar,20,fptr);
        fgets(fetched.address,20,fptr);
        fgets(fetched.balance,8,fptr);
        
}

    displayUser(fetched);
}
int main(){
    // menu();
//     printf("%s",person.accountNumber);
    // authUser("1234567891234567","1");
    fetchData("1234567891234567");
}
