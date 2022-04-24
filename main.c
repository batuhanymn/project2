#include "string.h"
#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>

int main()
{
	FILE *vt;
	vt = fopen("votes.txt", "a"); //openin file for storing votes, it stores all votes in every single run without deleting
    int yes = 0; //defining some variables to the system
    int no = 0;
    int abstain = 0;
    int choice;
    int vote_change;
    int voted;
    long int user_ID[] = {20191706008,20191706020,20191706022}; //defining user ID's
    int password0, password1, password2; //defining variables for passwords
    FILE *ps;
    ps = fopen("passwords.txt","w+");  //opening file for passwords
    fprintf(ps, "%d %d %d",321, 654, 987); //saving the passwords to the file
    fseek(ps, 0, SEEK_END);  //these are used for rearranging the cursor in the file
    rewind(ps);
    fscanf(ps, "%d", &password0);  //reading passwords from file and write into the variables
    fscanf(ps, "%d", &password1);
    fscanf(ps, "%d", &password2);
    long int user_ID_input[] = {0,0,0};  //opening an array to store user's inputs for ID
    int user_password_input[] = {0,0,0}; //opening an array to store user's inputs for password
    int vote[] = {3,3,3}; //opening an array to store user's inputs for vote
    for(int i = 0; i <= 10; ++i){  //for loop is for asking every user
        printf("Please enter your ID: ");  
        scanf("%ld", &user_ID_input[i]);  //asks users to enter their ID's
        printf("Please enter your password: ");
        scanf("%d", &user_password_input[i]); //asks users to enter their passwords
        if(i>0){
            for(int j=0; j<i; j++){ //for loop for avoiding a user to vote multiple times
                if(user_ID_input[i] == user_ID_input[j] ){
                    printf("You have already logged in \n"); 
                }
                if(user_ID_input[i] != user_ID_input[j]){
                	voted = 0;
				}

            }
        }
        
        //if condition that compares user ID and password to decide whether they match
        if(((user_ID_input[i]==user_ID[0] && user_password_input[i]==password0) || (user_ID_input[i]==user_ID[1] && user_password_input[i]==password1) 
		|| (user_ID_input[i]==user_ID[2] && user_password_input[i]==password2))){
        	if(voted == 0){
        		printf("What would you like to do? \n If you want to change your password, press 0. \n If you want to vote, press 1: \n"); //Creates an interface 
																														//to ask logged in user to what they want. 
        		scanf("%d", &choice);
        		if(choice == 0){
        			printf("Please enter your new password: \n"); //Asks new password from user
        			fseek(ps, 0, SEEK_SET);
        			if(user_ID_input[i]==user_ID[0]){
        				scanf("%d", &password0);
        				fprintf(ps, "%d", password0);  //stores new password to a file
					}
					if(user_ID_input[i]==user_ID[1]){
        				scanf("%d", &password1);
        				fprintf(ps, "%d", password1);
					}
					if(user_ID_input[i]==user_ID[2]){
        				scanf("%d", &password2);
        				fprintf(ps, "%d", password2);
					}
					rewind(ps);
                	fclose(ps);
                	choice = 1; //since the vote is a must for the program, it moves the user to voting interface
				}
				if(choice == 1){
					voted = 1;
					printf("Enter your vote 1 or 0 as yes or no respectively.\nIf you want to stay abstain, vote 2: "); //asks users to vote
            		scanf("%d", &vote[i]); //reads users vote
            		printf("Are you sure?");  //users can change their vote if they want
            		scanf("%d", &vote_change);
            		if(vote_change == 0){
                		printf("Enter your vote 1 or 0 as yes or no respectively.\nIf you want to stay abstain, vote 2: ");
                		scanf("%d", &vote[i]);
            		}
				}
            	fprintf(vt, "%d\n", vote[i]); //writes the vote to the file without overwriting the previous
            	fflush(vt);
            	if(vote[i] == 2){ //counting the votes
               		abstain = abstain+1;
                	printf("You stayed abstain about the issue. Thank you for your contribution! \n");
            	}
            	if(vote[i] == 1){
                	yes = yes+1;
                	printf("You voted for YES. Thank you for your vote! \n");
            	}
            	if(vote[i] == 0){
                	no = no+1;
                	printf("You voted for NO. Thank you for your vote! \n");
            	}
            	if(vote[i] != 1 && vote[i] != 0 && vote[i] != 2){ //checks if there is invalid input or not
                	return printf("Invalid vote. \n");
            	}
            	getch();
            	if(yes>=2){ //if the majority has agreed, program terminates before asking remaining users
            		fprintf(vt, "%s\n", "end");
					printf("The result of voting is YES. \n");
					printf("Votes for Yes = %d\n",yes);
        			printf("Votes for No = %d\n",no);
            		return 0; 
				}
				if(no>=2){
					fprintf(vt, "%s\n", "end");
					printf("The result of voting is NO. \n");
					printf("Votes for Yes = %d\n",yes);
        			printf("Votes for No = %d\n",no);
					return 0;
				}	
            	if(yes+no+abstain==3){
					if(yes>no){
    					fprintf(vt, "%s\n", "end");
        				printf("Votes for Yes = %d\n",yes); //counts votes and prints the results
        				printf("Votes for No = %d\n",no);
        				printf("The result of voting is YES");
        				return 0;
    				}
    				if(no>yes){
    					fprintf(vt, "%s\n", "end");
        				printf("Votes for Yes = %d\n",yes);
        				printf("Votes for No = %d\n",no);
        				printf("The result of voting is NO");
        				return 0;
    				}
    				if (no==yes && no != 0 && yes !=0){
    					fprintf(vt, "%s\n", "end");
        				printf("Votes for Yes = %d\n",yes);
        				printf("Votes for No = %d\n",no);
        				printf("The result of voting is DRAW");
        				return 0; 
    				}
    				if (no == 0 && yes == 0 && abstain > yes && abstain > no){
    					fprintf(vt, "%s\n", "end");
        				printf("Votes for Yes = %d\n",yes);
        				printf("Votes for No = %d\n",no);
        				printf("The result of voting is ABSTAIN");
        				return 0; 
    				}
				
				}
        		
        	        		       				
			}

        }
        else{
            if(voted == 0){
            	printf("Your ID or password is wrong. \n"); //if password and username does not match, it avoids this user from voting

			}
        	
            
        }
    }
    
    fclose(vt); //closing the files
    fclose(ps);
    
 
}
