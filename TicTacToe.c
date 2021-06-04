#include<stdio.h>

typedef char TwoD[3][3];

void display_TICTACTOE ()	//displays the words Tic Tac Toe
{
	printf("\n\n\n\n\n\n\n\n");
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf(" _________  _____     ______      _________      _        ______      _________    ___   ________  \n" );     
	printf("|  _   _  ||_   _|  .' ___  |    |  _   _  |    / \\     .' ___  |    |  _   _  | .'   `.|_   __  | \n");
	printf("|_/ | | \\_|  | |   / .'   \\_|    |_/ | | \\_|   / _ \\   / .'   \\_|    |_/ | | \\_|/  .-.  \\ | |_ \\_|  \n");
	printf("    | |      | |   | |               | |      / ___ \\  | |               | |    | |   | | |  _| _   \n");
	printf("   _| |_    _| |_  \\ `.___.'\\       _| |_   _/ /   \\ \\_\\ `.___.'\\       _| |_   \\  `-'  /_| |__/ | \n");
	printf("  |_____|  |_____| `. ____ .'      |_____| |____| |____| `.____.'      |_____|   `.___.'|________| \n");
	printf("\n\t\t\t\t\t    with a twist\n");

}

void MainMenu(int *ptr)  //displays the Main Menu and scans for which choice the player wants to make
{	
	display_TICTACTOE();
	printf("\n [1] Play \n [2] How to Play \n [3] Exit\n\n Enter a valid choice: ");
	do
	{
	scanf("%d", ptr);
	switch (*ptr)
		{
				case 1: *ptr = 1;
						break;
				
				case 2: *ptr = 2;
						break;
				
				case 3: *ptr = 3;
						break;
	
			    default : 
				fflush(stdin); // If user inputs a character
				printf("Invalid Input! Type again! \n");
				printf("\n\n=========================");
				printf("\n [1] Play \n [2] How to Play \n [3] Exit\n\n Enter a valid choice: ");
	 			break;
		}
	} while (*ptr != 1 && *ptr != 2 && *ptr != 3);
}
void PrintTicTacToe(TwoD XO)	// The function basically just prints the updated board
{
	printf("_____________________________________________________________________________\n"); // design layout
	printf(" \n\n\n\n  - 1 - 2 - 3 -\n");
	printf("  -------------\n");
	printf("1 | %c | %c | %c |\n", XO[0][0] ,XO[0][1] ,XO[0][2] );
	printf("  ------------- \n");
	printf("2 | %c | %c | %c |\n", XO[1][0] ,XO[1][1] ,XO[1][2] );
	printf("  -------------\n");
	printf("3 | %c | %c | %c |\n", XO[2][0] ,XO[2][1] ,XO[2][2] );
	printf("  -------------\n\n\n\n");
	printf("_____________________________________________________________________________\n");
	
}
			
void GameInput(TwoD XO, char Mark, int ctr) 	// the one for the input and mapping of the game
{	

	int RowNum = 0;				// used for scanf to map Row Number
	int ColNum = 0;				// used for scanf to map Column Num
	int RowNum2 = 0;				// used for scanf to map Row Number
	int ColNum2 = 0;				// used for scanf to map Column Num
  	int Input = 0;              // Input used to calculate the RowNum and ColNum
  	int Input2 = 0;
  	int checker = 0;            // checker is the condition for the while-loop of the three rounds of each player before they can have the ability to 
	if (ctr == 7 || ctr == 8)   //                                                                                  change the values of the position.
  		printf("\n\n\n\nIt is your FOURTH turn, Player %c\n\n", Mark);
  	
  	
	do
	{
		if (ctr < 7)
		{
  			do
    		{
    			printf("Enter Position: ");
				scanf("%d", &Input);
	
				printf("\n\n\n\n\n\n\n");
				RowNum = Input / 10;
				ColNum = Input % 10;

				if(((RowNum > 3) || (RowNum < 1)) || ((ColNum < 1) || ( ColNum > 3)))
				{
        			printf("\n The Address you've entered is incorrect\n" );  // If user did not input 11, 12, 13, 21, 22, 23, 31, 32, or 33
        			fflush(stdin); // If user inputs a character
    			}
    			else if (XO[RowNum-1][ColNum-1] != 95)
    			{
					PrintTicTacToe(XO);
    				printf("\nCannot be placed since position is already occupied\n" ); 
    			}
    			else
    				checker = 1;
    				
    		} while(checker == 0);
    	}
    	
    	else
    	{
    		do
    		{
				printf("Enter Position to be removed: ");
				scanf("%d", &Input2);	
				printf("Enter Position to be placed: ");
				scanf("%d", &Input);
				RowNum2 = Input2 / 10;
				ColNum2 = Input2 % 10;
	
				printf("\n\n\n\n\n\n\n");
				RowNum = Input / 10;
				ColNum = Input % 10;
				
				if(((RowNum > 3) || (RowNum < 1)) || ((ColNum < 1) || ( ColNum > 3)) || ((ColNum2 < 1) || ( ColNum2 > 3)) || ((RowNum2 > 3) || (RowNum2 < 1)))
				{
					PrintTicTacToe(XO);
        			printf("\nThe Address you've entered is incorrect\n" );  // If user did not input 11, 12, 13, 21, 22, 23, 31, 32, or 33
        			fflush(stdin); // If user inputs a character
    			}
    			
    			else if (XO[RowNum2-1][ColNum2-1] == 95)
    			{
					PrintTicTacToe(XO);
    				printf("\nCannot be replaced since position is empty\n" ); 
    			}
    			else if (XO[RowNum2-1][ColNum2-1] != Mark)  // If user replaces an empty position or the value is not from the player's.
    			{
    				PrintTicTacToe(XO);
    				printf("\nPosition is owned by opposing player\n" ); 
    				
    				if (XO[RowNum-1][ColNum-1] != 95)
						printf("Position to be placed with value is ALSO not empty!\n\n" );
						
        			fflush(stdin); // If user inputs a character
				}
				
				else if (XO[RowNum-1][ColNum-1] != 95)  // Position is not empty
				{
					PrintTicTacToe(XO);
					printf("Position is not empty!\n" ); 
        			fflush(stdin); // If user inputs a character
				}
				
				else
					checker = 1; 
					
    		} while(checker == 0);
    	}
    	
    	if (ctr >= 7)
    		XO[RowNum2-1][ColNum2-1] = 95;
    	
    	XO[RowNum-1][ColNum-1] = Mark;
		
	
	} while (checker == 0);
	
	PrintTicTacToe(XO);
}

int CheckWinCond ( TwoD XO) // Win Condition Function
{
 int WinFlag = 0;

 if( ( (XO[0][1] == XO[1][1]) && (XO[1][1] == XO[2][1]) && ( (XO[1][1] == 'O') || (XO[1][1] == 'X') ) ) // Vertical
        ||
     ( (XO[1][0] == XO[1][1]) && (XO[1][1] == XO[1][2]) && ( (XO[1][1] == 'O') || (XO[1][1] == 'X') ) ) // Horizontal 
   		||
     ( (XO[0][0] == XO[1][1]) && (XO[1][1] == XO[2][2])	&& ( (XO[1][1] == 'O') || (XO[1][1] == 'X') ) ) // Diagonal TopLeft to BottomRight
   		||
     ( (XO[0][2] == XO[1][1]) && (XO[1][1] == XO[2][0]) && ( (XO[1][1] == 'O') || (XO[1][1] == 'X') ) ) ) // Diagonal BottomLeft to TopRight
   WinFlag = 1;

  return WinFlag;
}

void GameBody()				// controls input and display in the game
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	int Turnctr = 0; 		// ctr in order to modulo 2 to find out whose player's turn is it
	
	int PlayerNum ;  		// used for printing Player '1' or PLayer '2', because modulo of Turnctr returns 0 or 1
	int i,j;	
	TwoD XO;

	for(i = 0; i < 3; i++)			// 2D character array for the X's and O's
		for(j = 0; j < 3; j++)
			XO[i][j] = 95;
		
	int WinCond = 0; 		//Win Condition variable, 0 for not yet done, 1 for someone won
	char Mark; 				//for the X or O, depending on whose turn it is
	while(WinCond == 0)
	{	
		Turnctr++;
		
		if (Turnctr % 2 == 1) // First player is always X
   			{
				Mark = 'X';
				PlayerNum = 1;
    		}    
		else // if the turn is now an even number, it'll go to player O
    		{
				Mark = 'O';
				PlayerNum = 2;
			}	
			
		printf("\n\n\nPlayer %d, enter the Row and Column of where you want to place your %c\n\n", PlayerNum, Mark); // Instructions
	
		if(Turnctr == 1) // Starting Display of the Game
			{
				PrintTicTacToe(XO);
				printf("\nExample : 11 or 23 or 31\n\n");
			}
		GameInput( XO, Mark, Turnctr); // call function
		WinCond = CheckWinCond(XO); // check condition and return WinFlag
	
    	if (WinCond == 1) 
    		{
    			 PrintTicTacToe(XO);
			 	printf("\n\n\n\n\n\n\n\t-----------------------\n\t-----------------------\n\t-------ENDGAME---------\n\t-----------------------\n\t-----------------------\n\n\n\n");
			 	printf("\n\n CONGRATULATIONS PLAYER %d, YOU WON!", PlayerNum);
			}
    }	
}

void how_to_play () //this function displays the how to play the game
{	
	int choice;
	printf("\n\n\n\n\n-----------------------------------------------------------------------------------------------------\n");	
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf(" _  _  _____      __  _____ ___    ___ _      _ __   __\n");
	printf("| || |/ _ \\ \\    / / |_   _/ _ \\  | _ \\ |    /_\\\\ \\ / /\n");
	printf("| __ | (_) \\ \\/\\/ /    | || (_) | |  _/ |__ / _ \\\\ v / \n");
	printf("|_||_|\\___/ \\_/\\_/     |_| \\___/  |_| |____/_/ \\_\\|_|  ");
	printf("\n\n");
	printf("\n THE RULES");
	printf("\n 1. This game is played on a grid of 3x3 squares.");
	printf("\n 2. Player 1 is X and Player 2 is O.");
	printf("\n 3. Each player is given a maximum of 3 moves to mark 3 squares in a row. ");
	printf("\n\n THE TWIST");
	printf("\n 1. When the players consumed their 3 moves, they will be given a chance to change the position of one of their past\n    moves and move it to a free space.");
	printf("\n 2. To win the game, a player must mark 3 squares in a row in a specific place, not just anywhere. ");
	printf("\n 3. With these, this Tic Tac Toe game will never end in a tie.");
	
	printf("\n\n\n\n\n\n Press [1] to EXIT:     ");
	
	do
		{
			scanf("%d", &choice);
			if ((choice != 1)) 
				{
					printf("\n Please enter a valid choice: ");
					fflush(stdin);
				}
			
		} while ((choice != 1));
	printf("\n\n\n\n\n\n\n\n");
}

int main()
{
	int MMchoice; 									// choice to be inputted in the Main Menu
	int *MMchoiceptr; 								// pointer to MMchoice
	MMchoiceptr = &MMchoice;

	do 
	{
		printf("\n\n\n\n\n\n");
 		MainMenu(MMchoiceptr);							// calls main menu function, void
 	
		if ((MMchoice == 1) || (MMchoice == 2)) 		// player chooses to play the game or how to play the game
			{			
				if (MMchoice == 1) 							// player chooses to play the game
					GameBody();								// calls game body
				else 										// player chooses to know how to play the game
					how_to_play();		
			}
	} while (MMchoice != 1 && MMchoice != 3);

	return 0; 
}
 
