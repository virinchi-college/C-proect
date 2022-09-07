#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define CANDIDATE_COUNT

#define CANDIDATE1 "Tribibek Shrestha"
#define CANDIDATE2 "Sabut Kumar Baidhya"
#define CANDIDATE3 "Bishesh Deshar"
#define CANDIDATE4 "Prashant Shahu"

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
FILE *fp1;
fp1=fopen("stats.txt","w+");

printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
getch();
fprintf(fp1,"\n\n ##### Voting Statics ####");
fprintf(fp1,"\n %s - %d ", CANDIDATE1, votesCount1);
fprintf(fp1,"\n %s - %d ", CANDIDATE2, votesCount2);
fprintf(fp1,"\n %s - %d ", CANDIDATE3, votesCount3);
fprintf(fp1,"\n %s - %d ", CANDIDATE4, votesCount4);
fclose(fp1);
}

void getLeadingCandidate(){
    FILE *fp;
    fp=fopen("Detail.txt","w+");

    printf("\n\n  #### Leading Candiate ####\n\n");
    fprintf(fp,"\n\n  #### Leading Candiate ####\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4){
    printf("[%s]",CANDIDATE1);
    getch();
    fprintf(fp,"[%s]",CANDIDATE1);}
    
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1){
    printf("[%s]",CANDIDATE2);
    getch();
    fprintf(fp,"[%s]",CANDIDATE2);}
    
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1){
    printf("[%s]",CANDIDATE3);
    getch();
    fprintf(fp,"[%s]",CANDIDATE3);}
    
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3){
    printf("[%s]",CANDIDATE4);
    getch();
    fprintf(fp,"[%s]",CANDIDATE4);	}
    
    else{
    printf("----- Warning !!! No-win situation----");
    getch();
    fprintf(fp,"----- Warning !!! No-win situation----");	}
    fclose(fp);


}

int main()
{
int choice;
int i,a=0;
	    char username[20];
	    char password[10];
	//	char user[20]="Dibash";
     //   char pass[10]="12345";

	logingo:
	printf("\n \t\t\t   LOGIN FIRST   ");
	printf("\n\n   \t\t\t\t            ENTER USERNAME:-");
	scanf("%s",&username);
	printf("\n\n   \t\t\t\t            ENTER PASSWORD:-");
	scanf("%s",&password);


	if(strcmp(username,"Dibash")==0 && strcmp(password,"12345")==0)
	{
	do{
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
case 0: exit(0);break;
default: printf("\n Error: Invalid Choice");
}
}while(choice!=0);
//hold the screen
getchar();
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\a\a");
		goto logingo;
		getch();//holds the screen

	}



//hold the screen
getchar();

return 0;
}
