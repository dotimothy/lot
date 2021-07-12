/* lot.c: The Lottery Simulator made in C
* Author: Timothy Do
* Modifitcations:
* v1.0: Initial Version (07/10/21)
* v1.1: Added Simulation (07/12/21)
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char *red = "\x1b[1;31m";
char *blue = "\x1b[1;34m";
char *yellow = "\x1b[1;33m";
char *white = "\x1b[1;0m";

void chooseMegaMillion(int *numbers)
{
	for(int i = 0; i < 5; i++)
	{
		int temp;
		do
		{
			temp = (rand() % 70) + 1;

		} while(temp == *(numbers) || temp == *(numbers + 1) || temp == *(numbers + 2) || temp == *(numbers + 3) || temp == *(numbers + 4));
		*(numbers + i) = temp;
	}
	*(numbers + 5) = (rand() % 25) + 1;
}

void choosePowerBall(int *numbers)
{
	for(int i = 0; i < 5; i++)
	{
		int temp;
		do
		{
			temp = (rand() % 69) + 1;

		} while(temp == *(numbers) || temp == *(numbers + 1) || temp == *(numbers + 2) || temp == *(numbers + 3) || temp == *(numbers + 4));
		*(numbers + i) = temp;
	}
	*(numbers + 5) = (rand() % 26) + 1;
}

void chooseSuperLotto(int *numbers)
{
	for(int i = 0; i < 5; i++)
	{
		int temp;
		do
		{
			temp = (rand() % 47) + 1;

		} while(temp == *(numbers) || temp == *(numbers + 1) || temp == *(numbers + 2) || temp == *(numbers + 3) || temp == *(numbers + 4));
		*(numbers + i) = temp;
	}
	*(numbers + 5) = (rand() % 27) + 1;
}

int check(int *test, int *number)
{
    int i,j;
    //checks for repeats in ticket number
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(i != j)
            {
                int one = *(test + i);
                int two = *(test + j);
                if(one == two)
                {
                    return 0;
                }
            }
        }     
    }
    //checks for matching numbers
    int matchReg = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            int one = *(test + i);
            int two = *(number + j);
            if(one == two)
            {
                matchReg++;
                break;
            }
        }
    }   
    if(matchReg != 5)
    {
        return 0;
    }
    else 
    {
        int specialOne = *(test + 5);
        int specialTwo = *(number + 5);
        if(specialOne != specialTwo)
        {
            return 0;
        }  
    }
    return 1;
}

void printMainOptions()
{
	printf("\nLottery Options:\n");
	printf("(1) %sMega Millions%s\n",blue,white);
	printf("(2) %sPowerball%s\n",red,white);
	printf("(3) %sSuper Lotto%s\n",yellow,white);
	printf("(4) All\n");
	printf("(5) Simulation\n");
	printf("(0) Exit\n");
	printf("\nChoose an Option: ");
}

void printSimOptions()
{
	printf("\nSimulation Options:\n");
	printf("(1) %sMega Millions%s\n",blue,white);
	printf("(2) %sPowerball%s\n",red,white);
	printf("(3) %sSuper Lotto%s\n",yellow,white);
	printf("(0) Main Menu\n");
	printf("\nChoose an Option: ");
}

int menu()
{
	//global seed
	printf("Welcome to Lottery Number Chooser!\n");
	srand(time(0));
	int choice = 0, drawings = 0, max = 0;
    int numbers[6] = {0,0,0,0,0,0};
	do
	{
		printMainOptions();
		scanf("%d",&choice);
		while(getchar() != '\n');
		switch(choice)
		{
			case 1:
				printf("\nHow Many Drawings: ");
				scanf("%d",&drawings);
				max = drawings;
				printf("\nDrawing %d %sMega Million(s)%s...\n",drawings,blue,white);
				while(drawings > 0)
				{
			               	chooseMegaMillion(numbers);
					printf("%d. %d %d %d %d %d %s%d%s\n",max - drawings + 1,numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],blue,numbers[5],white);
					drawings--;
				}
				break;
			case 2:
				printf("\nHow Many Drawings: ");
				scanf("%d",&drawings);
				max = drawings;
				printf("\nDrawing %d %sPowerball(s)%s...\n",drawings,red,white);
				while(drawings > 0)
				{
					choosePowerBall(numbers);
					printf("%d. %d %d %d %d %d %s%d%s\n",max - drawings + 1,numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],red,numbers[5],white);
					drawings--;
				}
				break;
			case 3:
				printf("\nHow Many Drawings: ");
				scanf("%d",&drawings);
				max = drawings;
				printf("\nDrawing %d %sSuper Lotto(s)%s...\n",drawings,yellow,white);
				while(drawings > 0)
				{
					chooseSuperLotto(numbers);
					printf("%d. %d %d %d %d %d %s%d%s\n",max - drawings + 1,numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],yellow,numbers[5],white);
					drawings--;
				}
				break;
			case 4:
				printf("\nChoosing All!\n");
				chooseMegaMillion(numbers);
				choosePowerBall(numbers);
				chooseSuperLotto(numbers);
				break;
			case 5:
				printf("Simulation:\n");
				int secondChoice, trials;
				int test[6];
				do 
				{
					printSimOptions();
					scanf("%d", &secondChoice);
					switch(secondChoice)
					{
						case 1:
							printf("Enter Your Ticket Number: ");
							scanf("%d %d %d %d %d %d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
							while(getchar() != '\n');
							printf("Desired Ticket: %d %d %d %d %d %s%d%s\n",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],blue,numbers[5],white);
							do
							{
								chooseMegaMillion(test);
								trials++;
								#ifdef more
									printf("%d. %d %d %d %d %d %s%d%s\n",trials,test[0],test[1],test[2],test[3],test[4],blue,test[5],white);
								#endif
							} while(!(check(test,numbers)));
							printf("Matched Ticket: %d %d %d %d %d %s%d%s\n",test[0],test[1],test[2],test[3],test[4],blue,test[5],white);
							printf("It took %d Drawings.\n", trials);
							secondChoice = 0;
							break;
						case 2:
							printf("Enter Your Ticket Number: ");
							scanf("%d %d %d %d %d %d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
							while(getchar() != '\n');
							printf("Desired Ticket: %d %d %d %d %d %s%d%s\n",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],red,numbers[5],white);
							do
							{
								choosePowerBall(test);
								trials++;
								#ifdef more
									printf("%d. %d %d %d %d %d %s%d%s\n",trials,test[0],test[1],test[2],test[3],test[4],red,test[5],white);
								#endif
							} while(!(check(test,numbers)));
							printf("Matched Ticket: %d %d %d %d %d %s%d%s\n",test[0],test[1],test[2],test[3],test[4],red,test[5],white);
							printf("It took %d Drawings.\n", trials);
							secondChoice = 0;
							break;
						case 3:
							printf("Enter Your Ticket Number: ");
							scanf("%d %d %d %d %d %d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
							while(getchar() != '\n');
							printf("Desired Ticket: %d %d %d %d %d %s%d%s\n",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],yellow,numbers[5],white);
							do
							{
								chooseSuperLotto(test);
								trials++;
								#ifdef more
									printf("%d. %d %d %d %d %d %s%d%s\n",trials,test[0],test[1],test[2],test[3],test[4],yellow,test[5],white);
								#endif
							} while(!(check(test,numbers)));
							printf("Matched Ticket: %d %d %d %d %d %s%d%s\n",test[0],test[1],test[2],test[3],test[4],yellow,test[5],white);
							printf("It took %d Drawings.\n", trials);
							secondChoice = 0;
							break;
						default:
							printf("\nInvalid Choice. Try Again.\n");
							break;
						case 0:
							break;
					}
				} while(secondChoice);
				break;
			case 0:
				printf("\nThank you for Choosing Lottery Numbers!\n\n");
				break;
			default:
				printf("\nInvalid Choice. Try Again.\n");
				break;
		}
	} while(choice);
	return 0;
}

int main(void)
{ 
    menu();
	return 0;
}
