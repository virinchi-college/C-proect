#include<stdio.h>
#include<conio.h>
#include<stdlib.h>  
#include<string.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
struct User{
	char fullname[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
};

char takeinput(char ch[50]){
fgets(ch,50,stdin);
ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50],char username[50]){
	int i;
	//abc123@gmail.com
	for(i=0;i<strlen(email);i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

char takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}
		else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}
		else{
			pwd[i++] = ch;
			printf("* \b");
			
		}
	}
}

void detail(){
	char qt;
	FILE *fp;
	struct User usr;
	system("cls");
		printf("\t\t\t\t\t\t<===User Detail===>\n\n");
		printf("%-20s %-30s %-20s %-30s %s\n","User Name","Full Name","Phone Number","Email","Password");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		
		fp = fopen("Users.txt","r");
		while(fread(&usr,sizeof(struct User),1,fp)){
			printf("%-20s %-30s %-20s %-30s %s\n",usr.username,usr.fullname,usr.phone,usr.email,usr.password);
		}
		fclose(fp);	
		
}

void search(){
	char qt;
	FILE *fp;
	struct User usr;
	char NM[50];
	system("cls");
		printf("\t\t\t\t\t\t<=====Search=====>\n\n");
		printf("Enter User name to edit:\t");
		fflush(stdin);
		takeinput(NM);
		system("cls");
		printf("\n\n\t\t\t\t\t\t<===User Srearch Detail===>\n\n");
		printf("%-20s %-30s %-20s %-30s %s\n","User Name","Full Name","Phone Number","Email","Password");
		printf("-------------------------------------------------------------------------------------------------------------------\n\n");
		
		
		fp = fopen("Users.txt","r");
            
		while(fread(&usr,sizeof(struct User),1,fp)){
			if(strcmp(NM,usr.username)==0){
				printf("%-20s %-30s %-20s %-30s %s\n",usr.username,usr.fullname,usr.phone,usr.email,usr.password);
			}
		}
		fclose(fp);	
		
}

void edit(){
	char password2[50];
	struct User usr;
	FILE *fp;
	FILE *ft;
	int f;
			char NM[50];
			system("cls");
			printf("\t\t\t\t\t\t<===Update Password===>\n\n");
			printf("Enter User name to edit:\t");
			fflush(stdin);
			takeinput(NM);
			
			fp = fopen("Users.txt","r");
			ft = fopen("temp.txt","w");
            
			while(fread(&usr,sizeof(struct User),1,fp)){
				
				if(strcmp(NM,usr.username)==0){
					f=1;
			        printf("\nEnter new Password         :\t");
			        fflush(stdin);
			        takepassword(usr.password);
			        printf("\nConfirm your password      :\t");
			        fflush(stdin);
			        takepassword(password2);
			        if(strcmp(usr.password,password2)==0)
			        printf("\n\nUser's password changed sussesfully'");
				    else
				    printf("\n\nSorry! Something went wrong :(");
				}
				fwrite(&usr, sizeof(struct User),1,ft);
			}
			fclose(fp);
			fclose(ft);
			if(f==1){
				ft = fopen("temp.txt","r");
				fp = fopen("Users.txt","w");
				
				while(fread(&usr,sizeof(struct User),1,ft)){
					fwrite(&usr,sizeof(struct User),1,fp);
				}
			printf("\n\n\nUser Updated.....");
			fclose(fp);
			fclose(ft);
			}
			else{
				printf("\n\n\nUser not found !!!");
			}
			
}

void deletes(){
	struct User usr;
	FILE *fp;
	FILE *ft;
	int f;
			char NM[50];
			system("cls");
			printf("\t\t\t\t\t\t<===Delete User===>\n\n");
			printf("Enter User name to delete:\t");
			fflush(stdin);
			takeinput(NM);
			
			fp = fopen("Users.txt","r");
			ft = fopen("temp.txt","w");
            
			while(fread(&usr,sizeof(struct User),1,fp)){
				
				if(strcmp(NM,usr.username)==0){
					f=1;  
				}
				else
				fwrite(&usr, sizeof(struct User),1,ft);
			}
			fclose(fp);
			fclose(ft);
			if(f==1){
				ft = fopen("temp.txt","r+");
				fp = fopen("Users.txt","w+");
				
				while(fread(&usr,sizeof(struct User),1,ft)){
					fwrite(&usr,sizeof(struct User),1,fp);
				}
			printf("\n\n\nUser Deleted.....");
			fclose(fp);
			fclose(ft);
			}
			else{
				printf("\n\n\nUser not found !!!");
			}
			
}

void signin(){
	struct User Usr;
	char password2[50];
	char qt;
	FILE *fp;
	system("cls");
	printf("\t\t\t\t\t\t<===Signin===>\n\n");
			printf("\nEnter your full name     :\t");
			takeinput(Usr.fullname);
			printf("\nEnter your email         :\t");
			takeinput(Usr.email);
			printf("\nEnter your contact number:\t");
			takeinput(Usr.phone);
			printf("\nEnter your Password      :\t");
			takepassword(Usr.password);
			printf("\nConfirm your password    :\t");
			takepassword(password2);
			
			if(!strcmp(Usr.password,password2)){
				generateUsername(Usr.email,Usr.username);
				fp = fopen("Users.txt","a+");
				fwrite(&Usr,sizeof(struct User),1,fp);
				if(fwrite != 0)
				printf("\n\nUser resgistration success, Your UserName is %s",Usr.username);
				else
				printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nYour password donot matched");
				Beep(750,300);
			}
			
}

void login(){
	int usrFound = 0;
	char usern[50];
	FILE *fp;
	system("cls");
			char username[50],pword[50];
			struct User usr;
			printf("\t\t\t\t\t\t<===Login===>\n\n");
			printf("\n\t\tUserName:\t");
			takeinput(usern);
			printf("\n\t\tPassword:\t");
			takepassword(pword);
			
			fp = fopen("Users.txt","r");
			while(fread(&usr,sizeof(struct User),1,fp)){
				if(!strcmp(usr.username,usern) && !strcmp(usr.password,pword)){
					usrFound=1;
					system("cls");
					printf("\n\t\t\t\t\t\tWelcome %s",usr.fullname);
					printf("\n\n|FULL NAME:\t%s",usr.fullname);
					printf("\n\n|Email    :\t%s",usr.email);
					printf("\n\n|USER NAME:\t%s",usr.username);
					printf("\n\n|PHONE NO.:\t%s",usr.phone);
				}
			}
			
			if(!usrFound){
				printf("\n\nInvalid User or Password!");
				Beep(700,300);
			}
			fclose(fp);
			
}

int main(){
	system("color 02");
	int opt,opt2,opt3,p;
	char qt,a;
	char password3[50];
	printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\t\t\xdb                                               \xdb\n");
	printf("\t\t\t\t\xdb          =============================        \xdb\n");
	printf("\t\t\t\t\xdb              Cyber Cafe Management            \xdb\n");
	printf("\t\t\t\t\xdb                     System                    \xdb\n");
	printf("\t\t\t\t\xdb          =============================        \xdb\n");
	printf("\t\t\t\t\xdb                Virinchi college               \xdb\n");
	printf("\t\t\t\t\xdb               Kumaripati lalitpur             \xdb\n");
	printf("\t\t\t\t\xdb                                               \xdb\n");
	printf("\t\t\t\t\xdb                                               \xdb\n");
	printf("\t\t\t\t\xdb         CONTACT US:9888888888,01-5500000      \xdb\n");
	printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
    printf("Enter y to continue:\t");
    scanf("%c",&a);
    if(a == 'y'){
    goto CCMS;
}
	CCMS:
		system("cls");
	printf("\t\t\t\t*********************************\n");
	printf("\t\t\t\t*--------------CCMS-------------*\n");
	printf("\t\t\t\t*********************************\n");
	printf("Please Chose the option");
	printf("\n1. Admin");
	printf("\n2. User");
	printf("\n3. Exit");
	
	printf("\n\nYour Choise:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	switch(opt){
	case 1:
	system("cls");	
	printf("Password:\t");
	takepassword(password3);
	if(!strcmp(password3,"password")){
	ADMIN:
	system("cls");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t*----------WELCOME ADMIN----------*\n");
	printf("\t\t\t\t***********************************\n");
	printf("Please Chose the option");
	printf("\n1. User detail");
	printf("\n2. Search");
	printf("\n3. Update password");
	printf("\n4. Delete User");
	printf("\n5. Exit");
	printf("\n\nYour Choise:\t");
	scanf("%d",&opt2);
	fgetc(stdin);
	
	switch(opt2){
		case 1:
		detail();
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
			goto ADMIN;
		}
		break;
		
		case 2:
		search();	
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
			goto ADMIN;
		}
		break;
		
		case 3:
		edit();	
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
			goto ADMIN;
		}
		break;
			
		case 4:
		deletes();
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
		goto ADMIN;
		}		
		break;
			
		case 5:
		goto CCMS;
		break;
		
		default:
		printf("\n\nInvalid Input.......");	
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
			goto ADMIN;
		}
	}
}
else{
	printf("\n\nYou entered wrong password !!!!");
	Beep(700,300);
	printf("\n\nEnter 'q' to try again:\t");
	scanf("%c",&qt);
	if(qt == 'q'){
	goto CCMS;
	}
}

break;
    
	case 2:
	USER:
	system("cls");
	printf("\t\t\t\t**********************************\n");
	printf("\t\t\t\t*----------WELCOME USER----------*\n");
	printf("\t\t\t\t**********************************\n");
	printf("Please Chose the option");
	printf("\n1. Signup");
	printf("\n2. login");
	printf("\n3. Exit");
	
	printf("\n\nYour Choise:\t");
	scanf("%d",&opt3);
	fgetc(stdin);
	
	switch(opt3){
		case 1:
		signin();
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
		goto USER;
		}	
		break;
		
		
		case 2:
		login();	
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
		goto USER;
		}
		break;
		
		case 3:
		goto CCMS;
		break;
		
		default:
		printf("\n\nInvalid Input.......");
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q'){
		goto USER;
		}	
		return 0;
	}
	break;	

case 3:
	system("cls");
	printf("\t\t\tBye Bye :)");	
	break;
	
default:
printf("\n\nInvalid Input.......");
printf("\n\nEnter 'q' to exit:\t");
scanf("%c",&qt);
if(qt == 'q'){
goto CCMS;
}	
return 0;
}
return 0;
}
