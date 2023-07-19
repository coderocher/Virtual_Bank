//CodeRocher Virtual Bank
#include <stdio.h>
#include <string.h>
#include<math.h>
#include <stdlib.h>
struct customer{
    char name[40], place[20], account_type[30],password[15];
    int login, accno;
    float balance;
}c1,c2;

char dummy;
int i;
int accNum(){
    FILE *ptr;
    ptr = fopen("accno.txt", "r");
    fscanf(ptr, "%d\n", &c1.accno);
    fclose(ptr);
    FILE *sptr;
    sptr = fopen("accno.txt", "w");
    ++c1.accno;
    fprintf(sptr,"%d",c1.accno);
    fclose(sptr);
    return c1.accno-1;
}

void custDetails(int accno,char name[],char place[],char acc_type[],float balance){
    char fname[11];
    for(i=0;i<6;i++){
        int fnamenum=(c1.accno%(int)(pow(10,6-i)))/(int)(pow(10,5-i));
        fname[i]=(char)(fnamenum+48);
    }
    fname[6] = '.';
    fname[7] = 't';
    fname[8] = 'x';
    fname[9] = 't';
    fname[10] = '\0';

    c1.login = 1;
    FILE *fptr;
    fptr = fopen(fname,"w");
    fprintf(fptr,"%d\n",accno);
    fprintf(fptr, "%s\n",name);
    fprintf(fptr,"%s\n",place);
    fprintf(fptr,"%s\n%.2f\n",acc_type,balance);
    fprintf(fptr,"%d\n",c1.login);
    fprintf(fptr,"%s\n",c1.password);
    fclose(fptr);
}
int createAccount()
{
    printf("Enter your name:\n");
    scanf("%[^\n]s",c1.name);
    scanf("%c",&dummy);
    printf("Enter city:\n");
    scanf("%[^\n]s",c1.place);
    scanf("%c",&dummy);
    printf("Enter the account type\n");
    scanf("%[^\n]s",c1.account_type);
    scanf("%c",&dummy);
    printf("Enter depositing amount in ur acc\n");
    scanf("%f%c",&c1.balance,&dummy);
    password:
    printf("Set your password\n");
    scanf("%[^\n]s",c1.password);
    scanf("%c",&dummy);
    char reenter[15];
    printf("Re-enter your password\n");
    scanf("%[^\n]s",reenter);
    scanf("%c",&dummy);
    int v = strcmp(c1.password,reenter);
    if(v==0){
        c1.accno = accNum();
        printf("Your account number is : %d\n",c1.accno);
        printf("Thank you, your account is created\n");
        custDetails(c1.accno,c1.name,c1.place,c1.account_type,c1.balance);
    }
    else{
        printf("Passwords are not matching\n");
        goto password;
    }
    return 0;
}
int transferMoney(){
    printf("Enter your account number\n");
    scanf("%d",&c1.accno);
    printf("Enter the reciever's account number\n");
    scanf("%d",&c2.accno);
    printf("Enter amount to be paid\n");
    float moneytr;
    scanf("%f",&moneytr);
    scanf("%c",&dummy);
    FILE *tmp;
    char fname[11];
    for(i=0;i<6;i++){
        int fnamenum=(c1.accno%(int)(pow(10,6-i)))/(int)(pow(10,5-i));
        fname[i]=(char)(fnamenum+48);
    }
    fname[6] = '.';
    fname[7] = 't';
    fname[8] = 'x';
    fname[9] = 't';
    fname[10] = '\0';
    tmp = fopen(fname,"r");
    fscanf(tmp,"%d",&c1.accno);
    // printf("%d\n",c1.accno);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%[^\n]s",c1.name);
    // printf("%s\n",c1.name);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%[^\n]s",c1.place);
    // printf("%s\n",c1.place);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%[^\n]s",c1.account_type);
    // printf("%s\n",c1.account_type);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%f",&c1.balance);
    // printf("%.2f\n",c1.balance);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%d",&c1.login);
    // printf("%d\n",c1.login);
    fscanf(tmp,"%c",&dummy);
    fscanf(tmp,"%[^\n]s",&c1.password);
    // printf("%s",c1.password);
    fclose(tmp);


    if(c1.login){
    if (c1.balance>=moneytr){
        c1.balance-=moneytr;
        // printf("%.2f\n",c1.balance);
        FILE *tmpsw;
        tmpsw = fopen(fname,"w");
        fprintf(tmpsw,"%d\n",c1.accno);
        fprintf(tmpsw,"%s\n",c1.name);
        fprintf(tmpsw,"%s\n",c1.place);
        fprintf(tmpsw,"%s\n",c1.account_type);
        fprintf(tmpsw,"%.2f\n",c1.balance);
        fprintf(tmpsw,"%d\n",c1.login);
        fprintf(tmpsw,"%s\n",c1.password);
        fclose(tmpsw);
    }
    else{
        printf("Balance in your account is lesser than money requested for transfer.\n");
        exit(0);
    }

    FILE *tmpr;
    for(i=0;i<6;i++){
        int fnamenum=(c2.accno%(int)(pow(10,6-i)))/(int)(pow(10,5-i));
        fname[i]=(char)(fnamenum+48);
    }
    fname[6] = '.';
    fname[7] = 't';
    fname[8] = 'x';
    fname[9] = 't';
    fname[10] = '\0';
    tmpr = fopen(fname,"r");
    fscanf(tmpr,"%d",&c2.accno);
    // printf("%d\n",c2.accno);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%[^\n]s",c2.name);
    // printf("%s",c2.name);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%[^\n]s",c2.place);
    // printf("%s",c2.place);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%[^\n]s",c2.account_type);
    // printf("%s",c2.account_type);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%f",&c2.balance);
    // printf("%.2f\n",c2.balance);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%d",&c2.login);
    // printf("%d\n",c2.login);
    fscanf(tmpr,"%c",&dummy);
    fscanf(tmpr,"%[^\n]s",c2.password);
    // printf("%s",c2.password);
    fclose(tmpr);

    FILE *tmprsw;
    tmprsw = fopen(fname,"w");
    fprintf(tmprsw,"%d\n",c2.accno);
    fprintf(tmprsw,"%s\n",c2.name);
    fprintf(tmprsw,"%s\n",c2.place);
    fprintf(tmprsw,"%s\n",c2.account_type);
    c2.balance+=moneytr;
    // printf("%.2f\n",c2.balance);
    fprintf(tmprsw,"%.2f\n",c2.balance);
    fprintf(tmprsw,"%d\n",c2.login);
    fprintf(tmprsw,"%s\n",c2.password);
    fclose(tmprsw);
    printf("Transaction successful\n");
    }
    else{
        printf("Your account's logging status is 'logout'\n");
        exit(0);
    }
    return 0;
}
int checkBalance(){
    printf("Enter your account no.\n");
    scanf("%d",&c2.accno);
    char fname[11];
    for(i=0;i<6;i++){
        int fnamenum=(c2.accno%(int)(pow(10,6-i)))/(int)(pow(10,5-i));
        fname[i]=(char)(fnamenum+48);
    }
    fname[6] = '.';
    fname[7] = 't';
    fname[8] = 'x';
    fname[9] = 't';
    fname[10] = '\0';
    FILE *cb;
    cb = fopen(fname,"r");
    fscanf(cb,"%d",&c2.accno);
    // printf("%d\n",c2.accno);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%[^\n]s",c2.name);
    // printf("%s",c2.name);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%[^\n]s",c2.place);
    // printf("%s",c2.place);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%[^\n]s",c2.account_type);
    // printf("%s",c2.account_type);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%f",&c2.balance);
    // printf("%.2f\n",c2.balance);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%d",&c2.login);
    // printf("%d\n",c2.login);
    fscanf(cb,"%c",&dummy);
    fscanf(cb,"%[^\n]s",c2.password);
    // printf("%s",c2.password);
    fscanf(cb,"%c",&dummy);
    if(c2.login==1){
        printf("Your account balance is %.2f\n",c2.balance);
    }
    else{
        printf("You are not logged in.\n");
        exit(0);
    }
    fclose(cb);
    return 0;
}
int login(){
    printf("Enter account num \n");
    scanf("%d",&c2.accno);
    char fname[11];
    for(i=0;i<6;i++){
        int fnamenum=(c2.accno%(int)(pow(10,6-i)))/(int)(pow(10,5-i));
        fname[i]=(char)(fnamenum+48);
    }
    fname[6] = '.';
    fname[7] = 't';
    fname[8] = 'x';
    fname[9] = 't';
    fname[10] = '\0';
    FILE *l;
    l = fopen(fname,"r");
    printf("Enter : \n'0' to logout\n'1' to login\n");
    int log_option;
    scanf("%d",&log_option);
    fscanf(l,"%d",&c2.accno);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%[^\n]s",c2.name);
    // printf("%s",c2.name);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%[^\n]s",c2.place);
    // printf("%s\n",c2.place);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%[^\n]s",c2.account_type);
    // printf("%s\n",c2.account_type);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%f",&c2.balance);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%d",&c2.login);
    fscanf(l,"%c",&dummy);
    fscanf(l,"%[^\n]s",c2.password);
    // printf("%s",c2.password);
    fscanf(l,"%c",&dummy);
    fclose(l);

    FILE *lw;
    lw = fopen(fname,"w");
    fprintf(lw,"%d\n",c2.accno);
    fprintf(lw,"%s\n",c2.name);
    // printf("%s\n",c2.place);
    fprintf(lw,"%s\n",c2.place);
    // printf("%s\n",c2.account_type);
    fprintf(lw,"%s\n",c2.account_type);
    fprintf(lw,"%.2f\n",c2.balance);
    if(log_option&&c2.login){
        printf("it's already logged in\n");
    }
    else if(!(log_option||c2.login)){
        printf("it's already logged out\n");
    }
    else if((log_option==1)&&(c2.login==0)){
        passwordCheck:
        printf("Enter your password\n");
        char enteredpassword[15];
        scanf("%s",enteredpassword);
        int u = strcmp(enteredpassword,c2.password);
        if(!u){
            printf("login successful\n");
            c2.login=1;
        }
        else{
            printf("wrong password\n");
            goto passwordCheck;
        }
    }
    else{
        c2.login = 0;
        printf("successfully logged out\n");
    }
    fprintf(lw,"%d\n",c2.login);
    fprintf(lw,"%s\n",c2.password);
    fclose(lw);
    return 0;
}

int main()
{
    int serial_no=0;
    start:
    do{
    printf("\t\tWELCOME TO CODEROCHER VIRTUAL BANK!!\n");
    printf("Enter the serial no.\n");
    printf("1. Create an account\n");
    printf("2. Transfer money to a friend\n");
    printf("3. Check Bank Balance\n");
    printf("4. Login to your account\n");
    printf("5. Exit\n");
    int result;
    scanf("%d%c",&serial_no,&dummy);
    switch (serial_no)
    {
    case 1:
        result = createAccount();
        break;
    case 2:
        result = transferMoney();
        break;
    case 3:
        result = checkBalance();
        break;
    case 4:
        result = login();
        break;
    case 5:
        return 0;
    default:
        break;
    }
    if (result){
        printf("Error\n\n");
        goto start;
    }
}while(serial_no!=5);
return 0;
}