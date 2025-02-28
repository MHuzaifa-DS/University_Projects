#include<iostream>      //for input/output on console screen
#include<iomanip>       //for setw function
#include <ctime>        //seed the random number generator with the current time
#include<stdlib.h>      //for system("cls")
using namespace std;
//use global variable
string player1;
string player2;

//function decleration of level of the game
int levels_of_the_game();
//function  decleration of  play with second player
int play_with_other_player();
//function decleration of level easy 
int level_easy();
//function decleration of level normal
int level_normal();
//function decleration of level difficult
int level_difficult();
//function decleration of play the game with second player
int player2_to_player1();
// function definition of display 
int display()

{
	// Display the WELCOME 
	cout<<"\t\t**************************************"<<endl;
	cout<<right<<setw(50)<<"WELCOME TO HANG MAN GAME"<<endl;
	cout<<"\t\t**************************************"<<endl;
	//Diagram of Hanged Man
	      cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
}
// Function Definition of Menu of the Game
int menu()
{
	//taking the choice from the user 
	char choice; 	
	cout<<"\n\tEnter \"S\" for Start this game"<<endl;    //for start the game 
	cout<<"\tEnter \"R\" for Check the Rules of this game"<<endl;   //for checking the rules of the game
	cout<<"\tEnter \"E\" for Exit"<<endl;   //for exit the game
	cout<<"\tEnter your choise :";
	cin>>choice;
	//checking the choice of the user
	if(choice=='S'|| choice=='s')  //S for start the game
	{
		system("cls");
	   char  user_choise;
	   //using while loop if user enter invalid choice 
	    while(user_choise!= '1' || user_choise!='2')
	   {
	   	system("cls");
	   	//start the game
	   cout<<"Lets start the game"<<endl;
	   		//Diagram of Hanged Man
	   		cout<<"\n\n";
	      cout<<"\t|^^^^^^^^^^"<<endl;
		  cout<<"\t|         |"<<endl;
		  cout<<"\t|         O"<<endl;
		  cout<<"\t|        / \\ "<<endl;
	      cout<<"\t|         |"<<endl;
		  cout<<"\t|        / \\ "<<endl; 
	      cout<<"\t|          "<<endl;
	   //asking from user play with computer or play with second player
	   cout<<"\n\n1.Play with Computer "<<endl;    
	   cout<<"\t OR "<<endl;
	   cout<<"2.Play with Second player "<<endl;
	   cout<<"\nEnter your choice :";
	   cin>>user_choise;
	   //checking the choice
	  
	   if(user_choise=='1')
	   {
	   	system("cls");
	   	cout<<"\n";
	   	//Calling function... level of the game 
	   	levels_of_the_game();
	   }
	    else if(user_choise=='2')
	   {
	   	system("cls");
	   	cout<<"\n";
	   	//Calling function...play with second player 
	   	play_with_other_player();
	   	player2_to_player1();
	   	
	   }
	}
}
	else if(choice=='R'|| choice=='r')  //for check the rules of the game
	{
		system("cls");
		//Check the rules of the game 
		cout<<right<<setw(50)<<"Follow THe Following Rules :   "<<endl;
	   cout<<"\n                 Guess the word by guessing letters."<<endl;
	   cout<<"           1.Each incorrect guess brings you closer to being hanged"<<endl;
	   cout<<"    2.Fill the letter in the blanks if the players guess correctly."<<endl;
	   cout<<" 3.Draw the  part of the hangman when the players guess wrong."<<endl;
	   cout<<"    4.The players win when they guess the correct word."<<endl;
	   cout<<"        5.Draw a blank line for each letter in the word."<<endl;
	   cout<<"            6.Start guessing letters."<<endl;
	   //Enter M for main Menu
	   while(choice!='M' || choice!='m')
	   {
	   cout<<"\nEnter \"M\" for going to main menu :";
	   cin>>choice;
	   if(choice=='M' || choice=='m')
	   {
	   	system("cls");
	   	//Calling  menu function here
	   	 menu();
	   }
	  
}
	}
	//for exit the game 
	else if(choice=='E'|| choice=='e')
	{
	   exit(0);
	}
	//if user enter a invalid choice
	else 
	{
		system("cls");
		cout<<"\nYou enter a invalid choice."<<endl;
		cout<<"Enter again.";
		//Calling Menu function here menu 
		menu();
	}
}
//Function definition of level of the game
levels_of_the_game()
{
	char levels;
	//Taking the choice from the user 
	cout<<"\nChoose your level"<<endl;
	cout<<"1.Easy"<<right<<setw(23)<<"|^^^^^^^^^^"<<endl;        //level easy
	cout<<right<<setw(29)<<"|         |"<<endl;
	cout<<"2.Normal"<<right<<setw(21)<<"|         O"<<endl;          //level normal
	cout<<right<<setw(31)<<"|        / \\ "<<endl;
	cout<<"3.Difficult"<<right<<setw(18)<<"|         |"<<endl;          //level Difficult
	cout<<right<<setw(31)<<"|        / \\ "<<endl; 
	cout<<right<<setw(29)<<"|          "<<endl;
	//Taking choice
	cout<<"\n\nEnter your choice :"; 
	cin>>levels;
	system("cls");
	//for level easy
	if(levels == '1')
	{
	cout<<"Guess the word"<<endl;
	//Calling level_easy function 
	level_easy();
    }
    //for level normal
    else if(levels =='2')
    {
	cout<<"Guess the word"<<endl;
	//Calling level_normal function 
	level_normal();
    }
    //for level difficult
    else if(levels =='3')
    {
	cout<<"Guess the word"<<endl;
	//Calling level_difficult function 
	level_difficult();
    }
    //for invalid choice
	else
	{
		system("cls");
		cout<<"\nInvalid choice"<<endl;
		cout<<"Enter again"<<endl;
		//Calling function again for invalid choice
		levels_of_the_game();
    }	
}
 //Function declaration of Level Easy of the game
level_easy()
{
	//store the fruits name in 2D Array
    string fruits[2][5] = {{"apple", "melon", "olive", "grape", "kiwii"},
     {"peach", "pears", "mango", "pinea", "guava"}};
     srand(time(0));          //seed the random number generator with the current time
    int row = rand() % 2;     //for random number of row
    int column = rand() % 5;  //for random number of column
    int incorrect = 0;        //count the incorrect guesses
    //suppose word= fruits[1][1];
    string word = fruits[row][column];   //store the random 2D array in varaible
    int length = 5;     //length of the word
    string guessed (5, '_');      //Length of  underscore 
    int remaining=length;         //Remaining guesses
    //guess the fruit name
    cout << "\nThe fruit has " << length << " letters." << endl;
    cout << "Here is your initial guess: " << guessed << endl;
    //using while loop for count the remaining guesses and incorrect guesses
      while (remaining > 0 && incorrect < 6) 
	  {
	  	//Taking guess from the user
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
       //count tries of the user
        int tries = 0;
        //using for loop 
        for (int i = 0; i < length; i++) 
		{
			//random fruit chosen by the program is "mango"
			//if  random word[i] == user guess && guessed[i]=='_'
			 //e.g.,  word[0]== 'm' && guessed[0]=='_' 
            if (word[i] == guess && guessed[i] == '_') 
			{
                guessed[i] = guess;   //replace guessed with [0]='m'
                remaining--;    //after decrement remaining 4
                tries++;       //after increment tries 1
            }
        }
         //if tries>0 and user guess correct  
         //   1   > 0
        if (tries > 0)
		 {
		 	//correct guess and output the word position in underscore
            cout << "Good guess! Here is your current guess: " << guessed << endl;
        }
		 else 
		 {
		 	//if user guess wrong so 
            cout << "Sorry, that letter is not in the word." << endl;
            incorrect++; //increment in incorrect guesses
            //whenever user guess the wrong word a part of diagram draw
          if (incorrect == 1)
			{
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if  (incorrect == 2)
	 {
	 	  system("cls");
		  cout<<"|       "<<endl;
		  cout<<"|       "<<endl;
		  cout<<"|        "<<endl;
	      cout<<"|        "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 	 
	 }
	 if(incorrect==3)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|         "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|        "<<endl; 
	      cout<<"|          "<<endl;
	 }
	if(incorrect ==4)
	 {
	 	  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\"<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if(incorrect ==5)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\"<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|           "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 
	 if(incorrect==6)
	 {
	 	  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
	      //if user incorrect guess == 5 he lose the game
	      cout<<"\n Your man is hang"<<endl;
	      cout<<"You lose the game "<<endl;
	      cout << "\nYou made too many incorrect guesses. The fruit was " << word << "." << endl;
	 }
      else 
		    {
		    	//count the incorrect guesses
                cout << "You have " << 6 - incorrect << " guesses left." << endl;
            }
        }
    }
    //if remaining not word user win the game
    if (remaining == 0) 
	{
    	system("cls");
    	//congratulation to user 
        cout << "\nCongratulations, you guessed the word " << word << "!" << endl;
    }
    //if user want to play again
    char again;
    cout<<"\n\nYou want to play again press y "<<endl;       //y for play again
    cout<<"Enter \"M\" key for going to main menu "<<endl;   // m for going to menu
     cout<<"Enter any other key for exit the game "<<endl;   // any other key for exit
     //taking choice from the user
    cout<<"Enter your choise :";
    cin>>again;
    if(again=='Y' || again=='y')
    {
    	system("cls");
    	//calling level_easy for play again the level 
    	level_easy();
	}
	else if(again=='M' || again=='m')
	{
		system("cls");
		//Calling menu function for going to menu 
		menu();
	}
	else
	{
		exit(0);
	}

}
//Level Normal of the game
level_normal()
{
	//store the country  name in 2D Array
	 string country[3][5] = {{"england", "germany", "ireland", "lebanon", "brazil"},
     {"iceland", "ireland", "namibia", "romania", "canada"},
	 {"ukraine","america","morocco"," turkey","pakistan"}};
     srand(time(0));          //seed the random number generator with the current time
    int row = rand() % 3;     //for random number of row
    int column = rand() % 5;  //for random number of column
    int incorrect = 0;        //count the incorrect guesses
    //suppose word= country[1][1];
    string word = country[row][column];  //store the random 2D array in varaible
    int length = 7;           //length of the word
    string guessed (7, '_');  //Length of  underscore 
    int remaining=length;     //Remaining guesses
    //guess the country  name
    cout << "\nThe country has " << length << " letters." << endl;
    cout << "Here is your initial guess: " << guessed << endl;
    //using while loop for count the remaining guesses and incorrect guesses
      while (remaining > 0 && incorrect < 8) 
	  {
      	//Taking guess from the user
	    char guess;
        cout << "Enter a letter: ";
        cin >> guess;
         //count tries of the user
        int tries = 0;
        //using for loop 
        for (int i = 0; i < length; i++) 
		{
			//the word is chosen by the program is "england"
			//if  random word[i] == user guess && guessed[i]=='_'
			 //e.g.,  word[0]== 'e' && guessed[1]=='_' 
            if (word[i] == guess && guessed[i] == '_')
			{
				//replaced guessed with guessed[0]='e'
                guessed[i] = guess;
                remaining--;     //after decrement remaining 6
                tries++;         //after increment tries 1
            }
        }
         //if tries>0 and user guess correct  
         //   1   > 0 
        if (tries > 0) 
		{
			//correct guess and output the word position in underscore
            cout << "Good guess! Here is your current guess: " << guessed << endl;
        } else 
		{
			//if user guess wrong so 
            cout << "Sorry, that letter is not in the word." << endl;
            //increment in incorrect guesses
            incorrect++;
            //whenever user guess the wrong letter a part of diagram draw
           if (incorrect == 1)
			{
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if  (incorrect == 2)
	 {
	 	 system("cls");
		  cout<<"|       "<<endl;
		  cout<<"|       "<<endl;
		  cout<<"|        "<<endl;
	      cout<<"|        "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 	 
	 }
	 if(incorrect==3)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|         "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|        "<<endl; 
	      cout<<"|          "<<endl;
	 }
	if(incorrect ==4)
	 {
	 	system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if(incorrect ==5)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|           "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 
	 if(incorrect==6)
	 {
	 	system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	  }
	  if(incorrect==7)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	  }
	   if(incorrect==8)
	 {
	 	system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
	       //if user incorrect guess == 5 he lose the game
	      cout<<"\n Your man is hang"<<endl;
	      cout<<"You lose the game "<<endl;
	      cout << "\nYou made too many incorrect guesses. The country was " << word << "." << endl;
	 }	
              
            else 
			{
				//count the incorrect guesses
                cout << "You have " << 8 - incorrect << " guesses left." << endl;
            }
        }
    }
    //if remaining letter == 0 user win the game
    if (remaining == 0)
	{
    	system("cls");
    	//congratulation to user 
        cout << "\nCongratulations, you guessed the word " << word << "!" << endl;
    }
     //if user want to play again
    char again;
    cout<<"\n\nYou want to play again press y "<<endl;     //y for play again
    cout<<"Enter \"M\" key for going to main menu "<<endl;   // m for going to menu
     cout<<"Enter any other key for exit the game "<<endl;   // any other key for exit
    cout<<"Enter your choise :";
    cin>>again;
    if(again=='Y' || again=='y')
    {
    	system("cls");
    	level_normal();    //play again the level 
	}
	else if(again=='M' || again=='m')
	{
		system("cls");
		menu();      //for going to menu
	}
	else
	{
		exit(0);
	}

	
}
//Level Difficult of the game
int level_difficult()
{
	//store the voclubary words in 2D Array
	 string voculbary[5][5] = {{"accustomed", "beneficial", "confident", "deficient", "efficient"},
     {"fragmented", "generation", "haphazard", "inclusive", "judicious"},
	 {"knowledgeable","lamentable","multitude","nostalgia ","obligatory"},
	 {"enigmatic", "reluctant", "sensible", "tolerable", "unanimous"},
	 {"validate", "wandering", "xenophile", "youthful", "zoonotic"}};
     srand(time(0));          //seed the random number generator with the current time
    int row = rand() % 5;     //for random number of row
    int column = rand() % 5;  //for random number of column
    int incorrect = 0;        //count the incorrect guesses
    //suppose word= voculbary[1][1];
    string word = voculbary[row][column];    //store the random 2D array in varaible
    int length = 9;         //length of the word
    string guessed (9, '_');        //Length of  underscore 
    int remaining=length;      //Remaining guesses
     //guess the voculbary word
    cout << "\nThe voculbary has " << length << " letters." << endl;
    cout << "Here is your initial guess: " << guessed << endl;
        //using while loop for count the remaining guesses and incorrect guesses
      while (remaining > 0 && incorrect < 10) 
	  {
	  	//Taking guess from the user
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
          //count tries of the user
        int tries = 0;
        //using for loop 
        for (int i = 0; i < length; i++) 
		{
			//e.g., word is chosen by the program is "efficient"
				//if  random word[i] == user guess && guessed[i]=='_'
			 //e.g.,  word[0]== 'e' && guessed[0]=='_' 
            if (word[i] == guess && guessed[i] == '_') 
			{
                guessed[i] = guess;     //guessed[0]='e'
                remaining--;          //after decrement remaining 8
                tries++;               //after increment tries 1
            }
        }
         // tries = 1 if user guess correct
        if (tries > 0)
        //if tries>0 and user guess correct  
		 {
		 		//correct guess and output the word position in underscore
            cout << "Good guess! Here is your current guess: " << guessed << endl;
        } else 
		{
        	//if user guess wrong so 
            cout << "Sorry, that letter is not in the word." << endl;
            incorrect++; //increment in incorrect guesses
            //whenever user guess the wrong letter a part of diagram draw
             if (incorrect == 1)
			{
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if  (incorrect == 2)
	 {
	 	   system("cls");
		  cout<<"|       "<<endl;
		  cout<<"|       "<<endl;
		  cout<<"|        "<<endl;
	      cout<<"|        "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 	 
	 }
	 if(incorrect==3)
	 {
	 	  cout<<"|^^^^^"<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|         "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|        "<<endl; 
	      cout<<"|          "<<endl;
	 }
	if(incorrect ==4)
	 {
	 	  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|        "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 if(incorrect ==5)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         "<<endl;
		  cout<<"|         "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|           "<<endl; 
	      cout<<"|          "<<endl;
	 }
	 
	 if(incorrect==6)
	 {
	 	  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|         "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	  }
	  if(incorrect==7)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         "<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
	  }
	   if(incorrect==8)
	 {
	 	  system("cls");
	   	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|         "<<endl; 
	      cout<<"|          "<<endl;
       }
        if(incorrect==9)
	 {
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        /  "<<endl; 
	      cout<<"|          "<<endl;
	  }
	   if(incorrect==10)
	 {
	 	  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
	      //if user incorrect guess == 10 he lose the game
	      cout<<"\n Your man is hang"<<endl;
	      cout<<"You lose the game "<<endl;
	      
	       cout << "\nYou made too many incorrect guesses. The voculbary word was " << word << "." << endl;
	  }
              
             else {
             	//count the incorrect guesses
                cout << "You have " << 10 - incorrect << " guesses left." << endl;
            }
        }
    }
     //if remaining not letter. user win the game
    if (remaining == 0) 
	{
    	system("cls");
    	//congratulation to user 
        cout << "\nCongratulations, you guessed the word " << word << "!" << endl;
    }
    //if user want to play again
    char again;
    cout<<"\n\nYou want to play again press y "<<endl;       //y for play again
    cout<<"Enter \"M\" key for going to main menu "<<endl;   // m for going to menu
     cout<<"Enter any other key for exit the game "<<endl;   // any other key for exit
    cout<<"Enter your choise :";
    cin>>again;
    if(again=='Y' || again=='y')
    {
    	system("cls");
    		//play again the level 
    	level_difficult();
	}
	else if(again=='M' || again=='m')
	{
		system("cls");
			//for going to menu
		menu();
	}
	else
	{
		exit(0);
	}
}
//play with second player
int play_with_other_player()
{
	//for player 1 
	player1;   //global variable
	cout << "Please type in your name, PLAYER 1" << endl;
cin >> player1;
  // player 2
     player2;   //global variable
cout << "Please type in your name, PLAYER 2" << endl;
cin >> player2;
//lets start the game 
cout << "OK " << player1 << " and " << player2 << ". Let's start with the game!" << endl;
// taking word from the player 1 to guess from player 2 
string words;
cout << "Ok Now "<<player1 << " please input the word (max 7 characters) you want to guess from " << player2 <<"!"<< endl;
cin >> words;
// set the lmit of the word ==7
//using while loop for check the condition 
while(words.size()>7)
{
//if word letter greater than >7
if(words.size()>7)
{
	cout<<"Enter the word again :";
	cin>>words;
}
}
         system("cls");
       //length of the word letters     
    int length = words.size();
    string guessed (length, '_');   //Length of  underscore  
    int remaining=length;           //Remaining guesses
    string word = words;
    //guess the  word
    cout << "\nThe word has  " << length << " letters." << endl;
    cout<<" OK "<<player2<<" guess the word  "<<endl;
    int incorrect=0;
    //using while loop for count the remaining guesses and incorrect guesses
      while (remaining > 0 && incorrect < length) 
	  {
        char guess;
        //Taking guess from the player 2
        cout << "Enter a letter: ";
        cin >> guess;
          //count tries of the player 2
         int tries = 0;
          //using for loop 
        for (int i = 0; i < length; i++) 
		{
				//if  random word[i] == user guess && guessed[i]=='_'
			 //e.g.,  word[0]== 'h' && guessed[0]=='_' 
            if (word[i] == guess && guessed[i] == '_') 
			{
                guessed[i] = guess;   //guessed[0]='h'
                remaining--;            //after decrement 6          
                tries++;            //after increment 1    
            }
        }
         //if tries>0 and player 2 guess correct  
        if (tries > 0)
		 {
		 	//correct guess and output the word position in underscore
            cout << "Good guess! Here is your current guess: " << guessed << endl;
        }
		 else 
		 {
		 		//if user guess wrong so 
            cout << "Sorry, that letter is not in the word." << endl;
            incorrect++;    //increment in incorrect guesses
             //whenever user guess the wrong letter a part of diagram draw
            if (incorrect == length)
			{   
                  system("cls");
	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
	      //if user incorrect guess == length  he lose the game
	    
	      cout<<"\nYou lose the game "<<endl;
	       cout<<"\n Your man is  hanged "<<player2;
	       cout << "\nYou made too many incorrect guesses. The  word was " << word << "." << endl;
	 }
	
              
            else 
			{
            		//count the incorrect guesses
                cout << "You have " << length - incorrect << " guesses left." << endl;
            }
        }
    }
          //if remaining not letter. user win the game
    if (remaining == 0)
	 {    
       //congratulation to user        
       cout << "\nCongratulations, you guessed the word " << word << "!" << endl;
    }
}
int player2_to_player1()
{
  
   //now taking word from player  2 to guess from player 1  
   cout<<"\n\n"<<endl;  
string words;
cout << "Ok Now "<<player2 << " please input the word (max 7 characters) you want to guess from " << player1 <<"."<< endl;
cin >> words;
// set the lmit of the word ==7
//using while loop for check the condition 
while(words.size()>7)
if(words.size()>7)
{
	//if word letter greater than >7
	cout<<"Enter the word again :";      //input again
	cin>>words;
}
      system("cls");
    //length of the word letters     
    int length = words.size();     //length == word size which is enter by user
    string guessed (length, '_');    //Length of  underscore  
    int remaining=length;        //Remaining guesses
    string word = words;            //guess the  word
    cout << "\nThe word has  " << length << " letters." << endl;
    cout<<" OK "<<player2<<" guess the word  "<<endl;
    int incorrect=0;
    //using while loop for count the remaining guesses and incorrect guesses
      while (remaining > 0 && incorrect < length)
	   {
        char guess;
        //Taking guess from the player 1
        cout << "Enter a letter: ";
        cin >> guess;
        //count tries of the player 1
         int tries = 0;
         //using for loop 
        for (int i = 0; i < length; i++) 
		{
				//if  random word[i] == user guess && guessed[i]=='_'
			 //e.g.,  word[0]== 'n' && guessed[0]=='_' 
            if (word[i] == guess && guessed[i] == '_') 
			{
                guessed[i] = guess;         //guessed[0]='h'
                   remaining--;        //remaining 6 
                  tries++;           //tries 1        
 
               
            }
        }
        //if tries>0 and player 1 guess correct  
        if (tries > 0)
		 {
		 	//correct guess and output the word position in underscore
            cout << "Good guess! Here is your current guess: " << guessed << endl;
        }
		 else 
		 {
		 		//if user guess wrong so 
            cout << "Sorry, that letter is not in the word." << endl;
            incorrect++;     //increment in incorrect guesses
             //whenever user guess the wrong letter a part of diagram draw
            if (incorrect == length)
			{
	           system("cls");

	 	  cout<<"|^^^^^^^^^^"<<endl;
		  cout<<"|         |"<<endl;
		  cout<<"|         O"<<endl;
		  cout<<"|        / \\ "<<endl;
	      cout<<"|         |"<<endl;
		  cout<<"|        / \\ "<<endl; 
	      cout<<"|          "<<endl;
	      //if user incorrect guess == length he lose the game
	    
	      cout<<"\nYou lose the game "<<player1<<endl;
	       cout<<"\n Your man is  hanged "<<player1;
	       cout << "\nYou made too many incorrect guesses. The  word was " << word << "." << endl;
	 }
	
              
            else 
			{
            		//count the incorrect guesses
                cout << "You have " << length - incorrect << " guesses left." << endl;
            }
        }
    }
 //if remaining not letter. user win the game
    if (remaining == 0) 
	{
    	system("cls");
    	   //congratulation to user 
        cout << "\nCongratulations, you guessed the word " << word << "!" << endl;
    }
    char again;
    cout<<"\n\nYou want to play again press y "<<endl;     //y for start the game
    cout<<"Enter \"M\" key for going to main menu "<<endl;    //"M" for going to main menu
     cout<<"Enter any other key for exit the game "<<endl;   //  any other key for exit 
    cout<<"Enter your choise :";
    cin>>again;
    if(again=='Y' || again=='y')
    {
    	system("cls");
    	//caling the function if user want to play again
    	play_with_other_player();
	}
	else if(again=='M' || again=='m')
	{
		system("cls");
		//calling menu function for going to menu
	   menu();
	}
	else
	{
		exit(0); //for exit the game
	}

}  
int main()
{
	display();     //calling  display  function
	menu();    //calling  menu function
    levels_of_the_game();  //calling level of the game function
    play_with_other_player();	//calling  player1 to player2  function
    player2_to_player1();     //calling  player2 to player1  function
   
}

