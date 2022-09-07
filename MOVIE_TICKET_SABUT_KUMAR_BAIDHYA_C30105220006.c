#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<strings.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct moviedetails{
	char name[25];
	char phone[15];
	int seat;
	int id;
};


int changeprize(int);
void reservation(int *,int,int );
int choice1(void);
void cancel(int *);        
void ticket1(int choice,char name[10],int id2,int price);
void ticket2(int choice,char name[10],int id2,int price);
void ticket3(int choice,char name[10],int id2,int price);
int cmovie(void);
int movie(void);
void details(void);

struct moviedetails person[300];
int count=0;
int id2=3000;
	


char takepassword(char pwd[20]){
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

int main()
{
	system("color 02");
	int w=0;
	char username[20]="sabut",uname[20];
	char password[20]="Enter",pas[20];
	top:
	printf("\t\t\t\t	=====================================\n");
	printf("\t\t\t\t	||------------Login Page-----------||\n");
	printf("\t\t\t\t	=====================================\n");
	printf("\nEnter username\t");
	scanf("%s",&uname);
	printf("\nEnter password\t");
	takepassword(pas);
	if(strcmp(uname,username)==0&&strcmp(pas,password)==0){
		printf("\n\nlogin success");
		getch();
		
	}
	else{
		printf("\n\nlogin is not sucessful try again\n");
		
		getch();
		while(w<2){
			w++;
			system("cls");
			goto top;
		}
		exit(0);
			
	}
	
	
	
	system("cls");
	int **seat,choice,price=300,slection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;	
			case 3:	
				slection=movie();
				reservation(seat[slection-1],price,slection);	
				count++;
				break;
			case 4:
				slection=cmovie();	
				cancel(seat[slection-1]);	
				break;
			case 5:
				x=5;
				break;
			default: 
				printf("Choice not available\n");
				break;	
		}
	}
}


	

int changeprize(int prize)
{
	char pass[10],pak[10]="Enter";
	printf("Enter the password to change price of ticket: ");
	takepassword(pass);
	if (strcmp(pass,pak)==0)
	{
		printf("\nPlease enter new price: ");
		scanf("%d",&prize);
		printf("\nprice change to Rs.%d\n",prize);
		system("PAUSE");
		system("CLS");
	}
	else 
		printf("\nThe entered password is wrong! ");
	return prize;
}
void reservation(int *array,int price,int slection)
{          
		int i,j;
		printf("\n                                SEATES AVAILABLE\n\n\n");
		for (i=1;i<=10;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else 
				printf("*\t",i);	
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>10||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this seat is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else			
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
		else if (slection==2) 	
			ticket2(j,person[count].name,id2,price);
		else 
			ticket3(j,person[count].name,id2,price);			
		id2++;	
}
int choice1(void)
{
	
	int choice;
	printf("                 Simple Movie Ticket Booking System\n");
	printf(" ==================================================================\n");
	printf("||             1- To edit price of tickets (only admin):          ||\n");
	printf("||             2- To view reserved seats (only admin):            ||\n");
	printf("||             3- To puchase ticket:                              ||\n");
	printf("||             4- To cancel the seat:                             ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  \nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<100;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					
					 printf("%s your seat no %d is cancelled\n",person[i].name,person[i].seat);
					 system("pause");
					 system("cls");
					 array[person[i].seat]=0;
					 i=100;
	  		}
	  }
	  if (stop!=5)	
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id2,int price)
{
	FILE *fp;
	fp=fopen("ticket.txt","a");
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name :	Thor Love and Thunder\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 25-07-2022\n");
        printf("\t                                              Time      : 07:00am\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        
        fprintf(fp,"\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp,"\t============================================================\n");
        fprintf(fp,"\t Booking ID : %d \t\t\tShow Name :	Thor Love and Thunder\n",id2);
        fprintf(fp,"\t Customer  : %s\n",name);
        fprintf(fp,"\t\t\t                              Date      : 25-07-2022\n");
        fprintf(fp,"\t                                              Time      : 07:00am\n");
        fprintf(fp,"\t                                              Hall      : 02\n");
        fprintf(fp,"\t                                              seats No. : %d  \n",choice);
        fprintf(fp,"\t                                              price . : %d  \n\n",price);
		 person[count].id=id2;
        fprintf(fp,"\t============================================================\n\n\n\n");
        fclose(fp);
        return;
}
void details(void)
{
	
	int i;
	char pass[10],pak[10]="Enter";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d",person[i].seat,person[i].name,person[i].id);
		}
	}
	else                                                 
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");
	}

		
             
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to watch?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for Thor Love and Thunder\n\n");
	printf("\t\t\tpress 2 for Wakanda Forever\n\n");
	printf("\t\t\tpress 3 for Doctor Strange Multiverse of Madness\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
	FILE *fp;
	fp=fopen("ticket.txt","a");
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name :	Wakanda Forever\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 25-07-2022\n");
        printf("\t                                              Time      : 09:00am\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        
        fprintf(fp,"\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp,"\t============================================================\n");
        fprintf(fp,"\t Booking ID : %d \t\t\tShow Name :	Wakanda Forever\n",id2);
        fprintf(fp,"\t Customer  : %s\n",name);
        fprintf(fp,"\t\t\t                              Date      : 25-07-2022\n");
        fprintf(fp,"\t                                              Time      : 09:00am\n");
        fprintf(fp,"\t                                              Hall      : 03\n");
        fprintf(fp,"\t                                              seats No. : %d  \n",choice);
        fprintf(fp,"\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        fprintf(fp,"\t============================================================\n");
        fclose(fp);
        return;
        
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for Thor Love and Thunder\n\n");
	printf("\t\t\tpress 2 Wakanda Forever\n\n");
	printf("\t\t\tpress 3 Doctor Strange Multiverse of Madness\n");
	scanf("%d",&i);
	return i;		
}
void ticket3(int choice,char name[10],int id2,int price)
{
	FILE *fp;
	fp=fopen("ticket.txt","a");
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name :	Doctor Strange Multiverse of Madness\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 25-07-2022\n");
        printf("\t                                              Time      :11:00am:\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        
        system("cls");
		fprintf(fp,"\n\n");
        fprintf(fp,"\t-----------------THEATER BOOKING TICKET----------------\n");
        fprintf(fp,"\t============================================================\n");
        fprintf(fp,"\t Booking ID : %d \t\t\tShow Name :	Doctor Strange Multiverse of Madness\n",id2);
        fprintf(fp,"\t Customer  : %s\n",name);
        fprintf(fp,"\t\t\t                              Date      : 25-07-2022\n");
        fprintf(fp,"\t                                              Time      :11:00am:\n");
        fprintf(fp,"\t                                              Hall      : 04\n");
        fprintf(fp,"\t                                              seats No. : %d  \n",choice);
        fprintf(fp,"\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        fprintf(fp,"\t============================================================\n");
        fclose(fp);
        return;
}
