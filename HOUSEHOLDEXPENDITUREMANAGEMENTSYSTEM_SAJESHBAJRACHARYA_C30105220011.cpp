// code for household expenditure management system
#include<stdio.h>//header file, preprocessor
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void help();//userdefine function
void exp();
void cus();
void home();
void calc();
char ch;//globally declared variable
int main()
{
	home();
}
void home()//function
{ 
	system("cls");//screen clear
	printf("\n\t\t***************************************************");
     printf("\n\t\t                    WELCOME                ");
     printf("\n\t\t                      TO                   ");
     printf("\n\t\t       Household Expenditure Calculation         ");
     printf("\n\t\t***************************************************");
     printf("\n\t\t***************************************************");
     printf("\n\t\t    Find Out How Your Expenses Are Going    ") ;
     printf("\n\t\t***************************************************");
     printf("\n\t\t***************************************************");
     printf("\n\t\t -> Press S to start the Calculation");
     printf("\n\t\t -> Press H for help            ");
     printf("\n\t\t -> Press Q to quit             ");
     printf("\n\t\t***************************************************\n\n");
	printf("\n\t\tEnter your choice:\n");
	scanf("%c",&ch);
		switch(ch)
		{
		case 'H':
		case 'h':
			help();
			break;// can only be used in switch and loop
		case 'Q':
		case 'q':
	 		exit(0);//terminate
		case 'S':
		case 's':
			calc();	
			break;
		}
	}
	 		void calc()//function
	 		{
			 
			system("cls");//to clear screen
			char name[20];// declaration for name
			printf("Enter your name\n");
			scanf("%s",&name);
			system("cls");
			printf("                          Welcome %s  to Household Expenditure Calculation ",name);
			printf("\n\n            Here are some tips you wanna know before starting the calculation");
			printf("\n              This calculation is basically divided into two major catagories.");
			printf("\n                  You will be choosing either Automatic Expenses or Custom Total");
            printf("\n\n\n                        Press any key to start the calculation!\n"); 
			getch();// to hold screen
		    system("cls");
		    char ch1;
		    printf("Choose Automatic Expenses calculation(E) or Custom Total(C)\n");
	     	printf("Enter your choice:\n");
			scanf("%s",&ch1);
			switch(ch1)
			{
			case 'E':
			case 'e': 
				exp();//to go to that function
				break;
			case 'C':
			case 'c':
	 			cus();
				break;
			}
			getch(); //hold screen
// expenses calculation	
}
void exp() //function
{
	system("cls");
	float eIncome=0.0,Food=0.0,Housing=0.0,Cloth=0.0,Entertainment=0.0,Others=0.0,eTotal=0.0;
			printf("Please enter the income:\n");
			printf("Income:........... Rs."); 
			scanf("%f",&eIncome);				
			Food=eIncome*(0.1);
			Housing=eIncome*(0.15);
			Cloth=eIncome*(0.1);
			Others=eIncome*(0.05);
			Entertainment=eIncome*(0.2);
			eTotal=Food+Housing+Cloth+Others+Entertainment;
			printf("The food expenses expected is %f\n",Food);
			printf("The housing expenses expected is %f\n",Housing);
			printf("The Cloth expenses expected is %f\n",Cloth);
			printf("The entertainment expenses expected is %f\n",Entertainment);
			printf("The Others expenses expected is %f\n",Others);
			printf("The total expenses expected is %f\n",eTotal);
			printf("\npress any key to continue...\n");
			getch();// to hold screen
			calc();
}
    
        
		
// custom calculation
	void cus()
{
	system("cls");
	int whom;
	{
	 printf("\n\t\t Do you want to calculate the expenses for a person or a family?\n ");
	 printf("\n\t\t -> Press 0 For Person \n");
	 printf("\n\t\t -> Press 1 For family \n");
	 scanf("%d",&whom);
	 if(whom == 0)
	 {
	system("cls");
		int Num = 0, i = 0;
		printf("You have chosen the category for person! \n");
		float Income=0.0,Expense=0.0,Saving=0.0,Investment=0.0,Education=0.0,Total=0.0, sTotal=0.0;

			system("cls");
			printf("For person\n");
			printf("Please enter the following info for category:\n");
			
			printf("Income:........... Rs."); 
			scanf("%f",&Income);
			printf("Expense:.......... Rs."); 
			scanf("%f",&Expense);
			printf("Savings:.......... Rs."); 
			scanf("%f",&Saving);
			printf("Investments:...... Rs."); 
			scanf("%f",&Investment);
			printf("Education:........ Rs."); 
			scanf("%f",&Education);
			system("cls");
			
			Total=Income-Expense-Investment-Education;
			printf("Total= %.2f\n",Total);
			sTotal=Total+Saving;
			printf("The outcome for the calculation of person are: \n");
			printf("Total with saving= %.2f\n",sTotal);
         	if(sTotal>5000)
         	{
         		printf("Your income status for a person is good\n");
			 }
			 else
			 {
			 	printf("\nYour income for a person is bad \n");
			 	printf("\nYou need to follow a budget rule:\n");
			 	printf("You need to keep 50 percentage of your income in your needs \n");
			 	printf("Needs include Housing, groceries and other utilitizes\n");
			 	printf("You need to keep 30 percentage of your income in your wants \n");
			 	printf("Wants include shopping, hobbies and dinning out\n");
			 	printf("You need to keep 20 percentage of your income in financial goals\n");
			 	printf("Financial goals include savings and investments\n");
			 	printf("If you follow these rule you might reach your financial goals\n");
			 }
		 	printf("\nPress any key to continue:\n");
			getch();
			calc();
	}
	
	else if (whom == 1)
		system("cls");
	{
		int Num = 0, i = 0, Fam = 0;
		printf("You have chosen the category for family! \n");
		float Income = 0.0, Expense = 0.0, Saving = 0.0, Investment = 0.0, Education =0.0,N_total=0.0, Total = 0.0;	
			system("cls");
			printf("For Family\n");
			printf("\nPlease enter the following info for the categories :\n");
			
			printf("Income:........... Rs."); 
			scanf("%f",&Income);
			printf("Expense:.......... Rs."); 
			scanf("%f",&Expense);
			printf("Savings:.......... Rs."); 
			scanf("%f",&Saving);
			printf("Investments:...... Rs."); 
			scanf("%f",&Investment);
			printf("Education:...... Rs."); 
			scanf("%f",&Education);
			N_total=Expense+Investment+Education;
			Total=Income-N_total-Saving;
			printf("\nThe outcome for the calculation of family is: \n");
			printf("Total= %2.0f\n",Total);
			if(Total>10000)
         	{
         		printf("\nYour income status for a family is good\n");
			 }
			 else
			 {
			 	printf("\nYour income for a family is bad \n");
			 	printf("\nYou need to follow a budget rule:\n");
			 	printf("You need to keep 50 percentage of your income in your needs \n");
			 	printf("Needs include Housing, groceries and other utilitizes\n");
			 	printf("You need to keep 30 percentage of your income in your wants \n");
			 	printf("Wants include shopping, hobbies and dinning out\n");
			 	printf("You need to keep 20percentage of your income in financial goals\n");
			 	printf("Financial goals include savings and investments\n");
			 	printf("If you follow these rule you might reach your financial goals\n");
			 }
			printf("\nPress any key to continue.....\n");
			getch();
		  	home();	
		}
	}		
}
void help()
{
	system("cls");
	printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... Household expenditure managment calculator...........");
    printf("\n    There will be three options given and You can choose one of them as your preference");
    printf("\n    By choosing one of two options it will ask ask for 2 other option...........");
    printf("\n    All the questions regarding income is based on monthly.................... ");
	printf("\n    After that according to the choices you made the calculation will commence ");
	printf("\n    Choosing the individual in the custom will execute both individual and family ");
	printf("\n    If your income is low and expenses is high it will also give you some tips ");
	printf("\n\n\t******************** May your expenses status be good *************");
	getch();
}


