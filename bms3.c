#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
int main_exit;
char arrayData[100];
struct date
{
    int month, day, year;
};

typedef struct User
{
    char name[100];
    char accountNumber[17];
    char password[20];
    char address[100];
    char aadhaar[16];
    char mobile[15];
    char balance[8];
    int age;
    char acc_type[10];

    struct date dob;

} User;

User person, fetched;
typedef struct transaction
{
    char trsaccountNumber[16];
    float amt;
} transaction;
transaction trans;

void createUser();
void updateUser();
void storeUser();
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
void fordelay();
void exit1();

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}
void exit1(void)
{
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Thank You  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
}
void createUser()
{

    char repassword[20];
    int k = 0;
    char c;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Create An Account  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\tToday's Date(mm/dd/yyyy) and Time:  %d/%02d/%02d  %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("\n\t\tAccount NUmber: ");
    scanf(" %s", &person.accountNumber);
    while (k == 0)
    {
        printf("\n\t\tPassword: ");
        scanf("%s", &person.password);
        printf("\n\t\tEnter Password again: ");
        scanf("%s", repassword);
        if (strcmp(repassword, person.password) == 0)
        {
            printf("\n\t\tPasswords Matched\n");
            k++;
        }

        else
            printf("\n\t\tBoth the passwords were different. Enter Again\n");
    }
    printf("\n\t\tName: ");
    scanf(" %[^\n]%*c", &person.name);
    printf("\n\t\tEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &person.dob.month, &person.dob.day, &person.dob.year);
    printf("\n\t\tEnter the age:");
    scanf("%d", &person.age);
    printf("\n\t\taddress: ");
    scanf(" %[^\n]%*c", &person.address);
    printf("\n\t\tEnter the adhar no. number:");
    scanf("%s", person.aadhaar);
    printf("\n\t\tEnter the mobile number: ");
    scanf(" %s", &person.mobile);
    printf("\n\t\tType of account:\n\t\t#Saving\n\t\t#Current\n\t\t#Fixed1(for 1 year)\n\t\t#Fixed2(for 2 years)\n\t\t#Fixed3(for 3 years)\n\n\t\tEnter your choice: ");
    scanf("%s", person.acc_type);
    strcpy(person.balance, "1000");
    printf("\n\t\tAccount created successfully!!\n\t\tSaving Information");
    for (int i = 0; i <= 8; i++)
    {
        printf(".");
    }
    storeUser();

person_invalid:
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit1:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
    {
        system("cls");
        exit1();
    }
    else
    {
        printf("\nInvalid!\a");
        goto person_invalid;
    }
}

void storeUser()
{
    FILE *fuser;
    char filepath[23] = "users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".txt");
    fuser = fopen(filepath, "a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fuser, "%d/%02d/%02d  %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fuser, "%s\n", person.accountNumber);
    fprintf(fuser, "%s\n", person.password);
    fprintf(fuser, "%s\n", person.name);
    fprintf(fuser, "%d/%d/%d\n", person.dob);
    fprintf(fuser, "%s\n", person.mobile);
    fprintf(fuser, "%s\n", person.aadhaar);
    fprintf(fuser, "%s\n", person.address);
    fprintf(fuser, "%s\n", person.acc_type);
    fprintf(fuser, "%d\n", person.balance);
    fprintf(fuser, "\0");
    fclose(fuser);

    printf("\n\t\tSaved Successfuly!\n");
}

void reStoreUser(User person)
{
    FILE *fuser;
    char filepath[23] = "users\\";
    strcat(filepath, person.accountNumber);
    strcat(filepath, ".txt");
    fuser = fopen(filepath, "w+");
    fprintf(fuser, "%s\n", person.accountNumber);
    fprintf(fuser, "%s\n", person.password);
    fprintf(fuser, "%s\n", person.name);
    fprintf(fuser, "%s\n", person.mobile);
    fprintf(fuser, "%s\n", person.aadhaar);
    fprintf(fuser, "%s\n", person.address);
    fprintf(fuser, "%s\n", person.balance);
    fprintf(fuser, "\0");
    fclose(fuser);
    // printf("User Stored Successfully");
}

void displayUser()
{

    system("cls");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Account Information  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\tName: %s\n", person.name);
    printf("\n\t\tAccount Number: XXXXXXXXXXXX%c%c%c%c\n", person.accountNumber[12], person.accountNumber[13], person.accountNumber[14], person.accountNumber[15]);
    printf("\n\t\tMobile Number: %s\n", person.mobile);
    printf("\n\t\tAddress: %s\n", person.address);
    printf("\n\t\tBalance: %s\n", person.balance);
display:
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit1:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
    {
        system("cls");
        exit1();
    }
    else
    {
        printf("\nInvalid!\a\n");
        goto display;
    }
}
bool fetchData(char user[])
{
    char balance[8];
    char filepath[23] = "users\\";
    strcat(filepath, user);
    strcat(filepath, ".txt");
    FILE *fptr = fopen(filepath, "r");
    if (fptr == NULL)
    {
        // printf("Account does not exist\n");
        return false;
    }
    else
    {
        fgets(fetched.accountNumber, 20, fptr);
        fgets(fetched.password, 20, fptr);
        fgets(fetched.name, 20, fptr);
        fgets(fetched.mobile, 20, fptr);
        fgets(fetched.aadhaar, 20, fptr);
        fgets(fetched.address, 20, fptr);
        fgets(fetched.balance, 8, fptr);

        fetched.password[strcspn(fetched.password, "\n")] = '\0';
        fetched.address[strcspn(fetched.address, "\n")] = '\0';
        fetched.mobile[strcspn(fetched.mobile, "\n")] = '\0';
        return true;
    }

    displayUser(fetched);
}

void transactMenu()
{
    char accNo[16];
    char filepath[23] = "users\\";
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Welcome to PDEU BANK  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");

    printf("\n\t\tEnter your Account Number: ");
    scanf("%s", &accNo);
    getchar();
    if (fetchData(accNo))
    {
        printf("\n\n\t\tSelect One of the choices below:\n");
        printf("\n\t\t1. Deposit Money  \t\t\t\t  2. Withdraw Money\n\n");
        printf("\t\tEnter your choice: ");
        int ch1;
        scanf("%d", &ch1);
        long amt;
        switch (ch1)
        {
        case 1:
            printf("\n\t\tEnter the amount to be deposited: ");
            scanf("%ld", &amt);
            long bal = (long)fetched.balance;
            bal += amt;
            strcpy(fetched.balance, "");
            sprintf(fetched.balance, "%ld", bal);
            printf("\n\t\tThe amount %ld is deposited successfully!\n");
            printf("\n\t\tThe updated balance is %s\n", fetched.balance);
            reStoreUser(fetched);
            break;

        case 2:
            printf("\n\t\tEnter the amount to be withdrawn: ");
            scanf("%d", &amt);
            bal = (int)fetched.balance;
            if (bal >= amt)
            {
                bal -= amt;
                strcpy(fetched.balance, "");
                sprintf(fetched.balance, "%ld", bal);
                printf("\n\t\tThe amount %ld is successfully withdrawn!!\n");
                printf("\n\t\tThe updated balance is %s\n", fetched.balance);
                reStoreUser(fetched);
            }
            else
                printf("\n\t\tInsufficient Balance!!\n");
            break;

        default:
            printf("\n\t\tInvalid Choice !!\n");
            break;
        }
    }
    else
    {
        printf("\n\t\tThe account does not exist!!");
        printf("\n\t\tplease try again with another account number");
    }
transaction_invalid:
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit1:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
    {
        system("cls");
        exit1();
    }
    else
    {
        printf("\nInvalid!\a");
        goto transaction_invalid;
    }
}

void menu()
{
    int choice;
    system("color E4");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Welcome to PDEU BANK  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\t\t\tSelect One of the choices below:\n");
    printf("\n\n\t\t1.Create Account\n");
    printf("\t\t2.Update Account\n");
    printf("\t\t3.Transaction\n");
    printf("\t\t4.Check Balance\n");
    printf("\t\t5.View customer's list\n");
    printf("\t\t6.Exit\n\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        createUser();
        break;
    case 2:
        // updateUser();
        break;
    case 3:
        transactMenu();
        break;
    case 4:
        // checkBalance();
        break;
    case 5:
        displayUser();
        break;
    case 6:
        exit1();
        break;
    }
}
void authUser(char user[], char passwd[])
{
    fetchData(user);
    if (strcmp(fetched.password, passwd) == 0)
    {

        printf("Logging You In....");
    }
    else
    {
        printf("%s", fetched.password);
    }
}

int main()
{

    menu();
}
