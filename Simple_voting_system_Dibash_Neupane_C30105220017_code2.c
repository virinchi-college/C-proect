#include<stdio.h>

#define CANDIDATE_COUNT

#define CANDIDATE1 "Tribibek Shrestha"
#define CANDIDATE2 "Sabut Kumar Baidhya"
#define CANDIDATE3 "Bishesh Deshar"
#define CANDIDATE4 "Prashant Shahu"
#include<stdlib.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
struct User{
	char fullname[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
}Usr;

char takeinput(char ch[50]){
fgets(ch,50,stdin);
ch[strlen(ch) - 1] = 0;
}
char takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){

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


int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0;

void castVote(){
int choice;
printf("\n\n ### Please choose your Candidate ####\n\n");
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "None of These");

printf("\n\n Input your choice (1 - 4) : ");
scanf("%d",&choice);

switch(choice){
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    default: printf("\n Error: Wrong Choice !! Please retry");
             //hold the screen
             getchar();
}
printf("\n thanks for vote !!");
}

void votesCount(){
printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
}

void getLeadingCandidate(){
    printf("\n\n  #### Leading Candiate ####\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    printf("[%s]",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    printf("[%s]",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    printf("[%s]",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    printf("[%s]",CANDIDATE4);
    else
    printf("----- Warning !!! No-win situation----");



}
void signin(){
	struct User Usr;
	char password2[50];
	char qt;
	FILE *fp;
	system("cls");
	printf("\t\t\t\t\t\t<===Signin===>\n\n");
			printf("\nEnter your full name     :\t");
			scanf("%s",Usr.fullname);
			printf("\nEnter your email         :\t");
			scanf("%s",Usr.email);
			printf("\nEnter your contact number:\t");
			scanf("%s",Usr.phone);
			printf("\nEnter your Password      :\t");
			scanf("%s",Usr.password);
			printf("\nConfirm your password    :\t");
			scanf("%s",password2);
			printf("\nEnter your voter id      :\t");
			scanf("%s",Usr.username);
			if(!strcmp(Usr.password,password2)){
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

			}

}

void login(){
	int usrFound = 0,choice;
	char usern[50];
	FILE *fp;
	system("cls");
			char username[50],pword[50];
			struct User usr;
			printf("\t\t\t\t\t\t<===Login===>\n\n");
			printf("\n\t\tUserName:\t");
			scanf("%s",&usern);
			printf("\n\t\tPassword:\t");
			scanf("%s",&pword);

			fp = fopen("Users.txt","r");
			while(fread(&usr,sizeof(struct User),1,fp)){
				if(!strcmp(usr.username,usern) && !strcmp(usr.password,pword)){
					usrFound=1;
					system("cls");
					printf("\n\n ###### Welcome to Election/Voting 2022 #####");
printf("\n\n 1. Cast the Vote");
printf("\n 2. Find Vote Count");
printf("\n 3. Find leading Candidate");
printf("\n 0. Exit");

printf("\n\n Please enter your choice : ");
scanf("%d", &choice);

switch(choice)
{
case 1: castVote();break;
case 2: votesCount();break;
case 3: getLeadingCandidate();break;
default: printf("\n Error: Invalid Choice");
}
}

	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\a\a");
}

}
			fclose(fp);

}
int main()
{char qt;
int choice;
int i,a=0;
	int choice2;
	logingo:
		printf("\n\n ###### Welcome to Election/Voting 2022 #####");
printf("\n\n 1. Signup");
printf("\n 2. Login");
printf("\n 3. Exit");
printf("\n\n Please enter your choice : ");
scanf("%d", &choice2);
switch(choice2){
case 1: signin();
break;
case 2: login();
break;
case 3: printf("bye bye");
break;
default: printf("\n\nInvalid Input.......");
		printf("\n\nEnter 'q' to exit:\t");
		scanf("%c",&qt);
		if(qt == 'q')
    printf("bye bye");

}



return 0;
}
