#include<stdio.h>    
#include<string.h>   
#include<stdlib.h>

  void displayHangman(int);
	

	int main(void)
	{
	    char theWord[100], tempArray[100];       /**theWord[] array for the original word and tempArray[] array to get the alphabet from user and compare it with original word**/
	    char OutputArray[100];                    /**This array will show the remaining blanks and correct inputs**/
	    int wrongAttempt = 6 , foundMatch = 0;          /**player will get 5 chances, so we use wrongAttempt to count for chances**/
	                                                /**foundMatch to search the alphabet, if the alphabet from user does not exist
	                                                in the original word it will remain 0, upon finding the word, foundMatch will
	                                                be set as 1**/
	    int counter = 0 , position = 0, winner, length , i;
	    char alphabetFromUser;
	

	    system("cls");                              /**for clearing the screen**/
	    printf("\n\n Enter any word in small case and hit >>ENTER<<");
	    printf("\n\n\t Enter HERE ==>  ");
	    scanf("%s",theWord);                    /**get the string from opponent**/
	    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
	    printf("\n\n\tHIT >>ENTER<<");
	    getchar();                                  /**hold the computer screen**/
	    length = strlen(theWord);               /**get the length of the word**/
	

	    system("cls");
	

	    printf("\n\n WELCOME TO HANGMAN \n\n\n");   /**Brief description of the game**/
	    printf("\n\n You will get 5 chances to guess the right word");
	    printf("\n\n Get Started!“);
	

	    getchar();
	

	    printf("\n\n\tHIT >>ENTER<< ");
	

	    getchar();
	

	    system("cls");
	

	        printf("\n\t||===== ");                 /**show the HANGMAN**/
		printf("\n\t||    | ");
	        printf("\n\t||      ");
	        printf("\n\t||      ");
	        printf("\n\t||      ");
	        printf("\n\t||      ");
	

	    printf("\n\n     The word has %d alphabets \n\n",length);  /**tell the user how many alphabets the word has**/
	    for( i = 0; i < length ; i++)
	    {
	        OutputArray[i] = '_';
	        OutputArray[length] = '\0';
	    }
	

	    for(i = 0 ; i < length ; i++)
	    {
	        printf(" ");
	        printf("%c",OutputArray[i]);        /**Show the Word With n(length of the original word) number of underscores (_)**/
	

	    }
	    while(wrongAttempt != 0)                        /**while loop for exiting the program when no try left**/
	    {
	        foundMatch = 0;
	        printf("\n\n   enter any alphabet from a to z and please use small case!!");
	        printf("\n\n\t Enter HERE ==> ");
	

		    fflush(stdin);
	

		    scanf("%c",&alphabetFromUser);            /**get alphabet from user**/
	    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /**In case player gives input other than 'a' to 'z' the console will ask again**/
	    {
	        system("cls");
	        printf("\n\n\t Wrong input TRY AGAIN ");
	        foundMatch = 2;
	    }
	    fflush(stdin);
	    if (foundMatch != 2)
	    {
	        for(counter=0;counter<length;counter++)    /**for loop to check whether player input alphabet exists or not in the word**/
		    {
			    if(alphabetFromUser==theWord[counter])
			     {
			       foundMatch = 1;
	                     }//end of if()
	            }//end of for()
	

		   if(foundMatch == 0)                      /**in case of wrong guess**/
		    {
	     	      printf("\n\t :( You have %d tries left ",--wrongAttempt);
		          getchar();
	              displayHangman(wrongAttempt);
	              getchar();
		    }//end of if()
	

		   else
		   {
		     for(counter = 0; counter < length; counter++)
	             {
	     	         foundMatch = 0;
	                 if(alphabetFromUser == theWord[counter])
		          {
	     		     position = counter ;
	     		     foundMatch = 1;
		          }//end of if
	    	      if(foundMatch == 1)
		          {
	                 for(i = 0 ; i < length ; i++)
	                 {
	                      if( i == position)
	                  	  {
	                          OutputArray[i] = alphabetFromUser; /**Put the alphabet at right position**/
	                      }
	                      else if( OutputArray[i] >= 'a' && OutputArray[i] <= 'z' ) /** If the position already occupied
	                                                                                  by same alphabet then no need to
	                                                                                  fill again EASY!! and continue */
	                      {
	                          continue;
	                  	  }
	

	                      else
	                      {
	                          OutputArray[i] = '_';            /** Put a blank at not guessed alphabet position **/
	                      }
	                }
	                tempArray[position] = alphabetFromUser;      /**put the alphabet in another char array to check with the original word**/
	                tempArray[length] = '\0';                    /**put the NULL character at the end of the temp string**/
	                winner = strcmp(tempArray,theWord);      /**upon True comparison it will return 0**/
	

	                if(winner == 0)                             /**if the player guessed the whole word right then he/she is the WINNER**/
	                {
	                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
	                    printf("\n\n\t The Word was %s ",theWord);
	                    printf("\n\n\n\n\t\tEASY HUH???\n\n");
	                    getchar();
	                    return 0;
	                }//end of inner if
		       }//end of outer if
		    }//end of for loop
	      }//end of else
	     }// end of if(foundMatch != 2) condition
	

	    printf("\n\n\t");
	    for(i = 0 ; i < length ; i++)
	      {
	          printf(" ");
	          printf("%c",OutputArray[i]);                /**Show the original Word With blanks and right Input alphabet**/
	      }
	

	    getchar();
	    }//end of while loop
	

	      if(wrongAttempt <= 0)                                 /**if the player can not guess the whole word in 5 chaces**/
	      {
	          printf("\n\n\t The Word was %s ",theWord);
	          printf("\n\n\t The man is dead you IDIOT!!!!!");
		      printf("\n\n\t Better luck next!!!");
	

	      }
	getchar();
	return 0;
	}//end of main();
	

	

	

	void displayHangman(int choice)                            /**This function show the hangman after each wrong try**/
	 {
	

	     switch(choice)
	     {
	

	     case 0:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||   / %c",'\\');
		printf("\n\t||      ");
		break;
	     case 1:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||     %c",'\\');
		printf("\n\t||      ");
		break;
	     case 2:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||    | ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	     case 3:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/",'\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	     case 4:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO ",'\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	     case 5:
	         system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||    O ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	      }//end of switch-case
	      return;
	 }

