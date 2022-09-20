#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct user {
    char phone[50];
    char ac[50];
    char name[50];
    char password[50];
    float balance;
};

void red ()
    {
        printf("\033[1;31m");
    }

void yellow ()
    {
        printf("\033[1;33m");
    }

void green ()
    {
        printf("\033[0;32m");
    }

void blue ()
    {
        printf("\033[1;34m");
    }

void reset ()
    {
        printf("\033[0;0m");
    }

int main() {
    struct user usr , usr1;
    FILE *fp;
    char filename[50];
    char pword[50],newpass[50],oldpass[50];
    char phone[50] , name[50];
    int opt,choice,n=1,rnd;
    float amount ;
    char cont='y';
    
while( n==1 || n==0 )
{
    system("cls");
    yellow();
    printf("\t\n\n--->>> Welcome to MAYBORG Bank <<<---\t\n");
    reset();
    printf("\nWhat do you want to Do ?");
    printf("\n\n1. Register an Account[1]");
    printf("\n2. Login to an Account[2]");
    printf("\n3. Exit[3]");

    printf("\n\nYour Choice :\t");
    scanf("%d",&opt);

    
    if(opt==1 || n==0){
        system("cls");
        printf("\nEnter your Name:\t");
        scanf("%s",usr.name);
        printf("\nEnter your Account No.:\t");
        scanf("%s",usr.ac);
        printf("\nEnter your Phone No.:\t");
        scanf("%s",usr.phone);
        printf("\nEnter your Password :\t");
        scanf("%s",usr.password);
        usr.balance=0;
        strcpy(filename,usr.phone);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite != 0)
        {
            green();
            printf("\n\n** Account Created Successfully! **\n\n");
            reset();
        }
        else
        {   red ();
            printf("** Something Went Wrong **");
            reset();
            fclose(fp);
        }

    }
    
    if(opt==2)
    {
        system("cls");
        printf("\nEnter Your Phone no. : \t");
        scanf("%s",phone);
        printf("Enter Password : \t");
        scanf("%s",pword);
        strcpy(filename,phone);     //--> copies/stores phone in filename
        
        fp=fopen(strcat(filename,".dat"),"r");
        
        if(fp == NULL){
            red();
            printf("\n!!Account Not Registered !!");
            reset();
        }
        else{
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);

        for(int i=4;i>=0;i--)  //--> Checks for Password
            {  
  
                if(i==0)
                {
                     if(n==0) //n is converted to zero after logging in the account thus ,if we have wish to exit from program n=0 directs us to the end.
                        {
                            break;
                        }
                    else
                    {
                     red();
                     printf("\nYou have Reached Maximum Attempts to Login!!\n\tTry After Some time !!\n\n ");
                     reset();
                     break;
                    }
                } 
                if(!strcmp(pword,usr.password) && n!=0)
                    {
                     n=0;
                     printf("\n*** Login Successfull ! ***\n");
                     scanf("n");
                     while(cont == 'y')
                        {
                            system("cls");
                            yellow();
                            printf("\t\n\n--->>> Welcome to MAYBORG Bank <<<---\t\n");
                            reset();

                            printf("\nUser No.:\t");
                            blue();
                            printf("%s\n",usr.phone);
                            reset();
                            printf("User Name :\t");
                            blue();
                            printf("%s\n\t",usr.name);
                            reset();

                            printf("\npress '1' to Check Balance");
                            printf("\npress '2' to Deposit Money");
                            printf("\npress '3' to Withdraw Money");
                            printf("\npress '4' to Transfer Money");
                            printf("\npress '5' to Change Password");
                            printf("\nPress '6' to Exit");
                            printf("\n\nYour Choice:\t");
                            scanf("%d",&choice);

                            switch(choice){
                                case 1:
                                    blue();
                                    printf("\nYour Current Balance is Rs.:\t\n\n%.2f",usr.balance);
                                    reset();
                                    break;

                                case 2:
                                    printf("\nEnter The Amount:\t");
                                    scanf("%f",&amount);
                                    usr.balance+=amount;
                                    fp = fopen(filename,"w");
                                    fwrite(&usr, sizeof(struct user),1,fp);
                                    if(fwrite != NULL)
                                        {   
                                            green();
                                            printf("\nSuccessfully deposited Rs.'%.2f'\n\t",amount);
                                            blue();
                                            printf("\n--** Current Bank Balance is Rs.'%.2f' **--\n",usr.balance);
                                            reset();
                                        }
                                    fclose(fp);
                                    break;

                                case 3:
                                    printf("\nEnter The Amount:\t");
                                    scanf("%f",&amount);
                                    usr.balance-=amount;
                                    fp = fopen(filename,"w");
                                    fwrite(&usr, sizeof(struct user),1,fp);

                                    if(fwrite != NULL)
                                        {
                                            green();
                                            printf("\nSuccessfully Withdrawn Amount of Rs.'%.2f'\n\t",amount);
                                            blue();
                                            printf("\n--** Current Bank Balance is Rs.'%.2f' **--\n",usr.balance);
                                            reset();
                                        }
                                    fclose(fp);

                                    break;

                                case 4:
                                    printf("\nEnter The Phone No. to transfer the Balance:\n");
                                    scanf("%s",phone);
                                    printf("\nEnter The Amount to Transfer :\t");
                                    scanf("%f",&amount);
                                    if(amount>usr.balance)
                                        {
                                            red();
                                            printf("\nInsufficient Balance !!");
                                            reset();
                                        }
                                    else
                                        {
                                            strcpy(filename,phone);
                                            fp = fopen(strcat(filename,".dat"),"r");

                                            if(fp==NULL)
                                                {
                                                    red();
                                                    printf("\n\tAccount NOT Registered\n\t");
                                                    reset();
                                                }

                                            else
                                                {
                                                    fread(&usr1,sizeof(struct user),1,fp);
                                                    fclose(fp);

                                                    fp = fopen(filename,"w");
                                                    usr1.balance += amount;
                                                    fwrite(&usr1,sizeof(struct user),1,fp);
                                                    fclose(fp);
                                                    if(fwrite != NULL)
                                                        {
                                                            green();
                                                            printf("\nSuccessfully Transfered Rs.'%.2f'to ",amount);
                                                            reset();
                                                            yellow();
                                                            printf("%s\t\n",usr1.name);
                                                            reset();
                                                        }
                                                }

                                        }
                                    break;

                                case 5:
                                    printf("\nEnter Old Password :\t");
                                    scanf("%s",oldpass);



                                    if(!strcmp(oldpass,usr.password))
                                    {
                                        printf("\nEnter New Password :\t");
                                        scanf("%s",newpass);
                                        fp = fopen(filename,"w");
                                        strcpy(usr.password,newpass);
                                        fwrite(&usr,sizeof(struct user),1,fp);
                                        fclose(fp);

                                        if(!strcmp(newpass,usr.password))
                                            {
                                                green();
                                                printf("\n\t--** Password changed Successfully **--\t\n");
                                                reset();
                                            }

                                    }
                                    else{
                                        red();
                                        printf("\nInvalid Password !!");
                                        reset();
                                        }

                                    fclose(fp);
                                    break;

                                case 6:
                                    n=0;
                                    cont='n';
                                    break;

                                default:
                                    red();
                                    printf("\n\tInvalid Option\t");
                                    reset();

                                }

                            if(cont=='y')
                            {
                                printf("\nDo you Want to Continue [y/n]: \t");
                                scanf("%s",&cont);
                            }
                        }

                    }  

                if(strcmp(pword,usr.password)) 
                    { 
                        if(n!=0)
                            {
                             system("cls");
                             red();
                             printf("\n*** Password Invalid , Try Again ***\n\t %d Atttempts Remaining\n\n",i-1);
                             reset();
                             printf("\nEnter Password : \t");
                             scanf("%s",pword);
                            }
                        
                    }
                
                else
                {
                    n=1;
                    break;
                }

            }

        }
        
    }
    
    if(opt==3)
        {   
            cont='x';
            n=2;
        }

}

if(cont=='x')
       {   
           blue();
           printf("\n\n\t--**  Thank you, Have a Good Day ! **--\t\n\n\n");
           reset();
           
           getch(); //holds the screen when program is about to close.
       }

    return 0;
}

