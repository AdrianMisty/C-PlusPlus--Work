//Program made by Adriana A. Alva
#include<ctime>
#include<cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#define CONTINUE 0
#define DRAW 1
#define USER_WINS 2
#define COMPUTER_WINS 3
char table[6][7];//Global 2-dimensional array
void displayConfig()
/*displayConfig() - display the contents*/
{
cout<<"   "<<"1 2 3 4 5 6 7"<<endl;//print out numbers for the columns
for(int i=0;i<6;i++)//print out row numbers with the formatting shown ":"
{
  cout<<i+1<<": ";
    for(int j=0;j<7;j++)
     {
      cout<<table[i][j]<<" ";//fil up all the spaces inside the numbered rows and columns with empty spaces
     }
  cout<<endl;
}
}
void userTurn()
/*userTurn() - ask the user to select a column to put RED piece in.
the selected column is full, ask the user to select another column.*/
{
int PlayersChoice;//unassigned variable to this since it changes once player  picks a spot somewhere
 do{
    cout<<"Player's turn:";
    cin>>PlayersChoice;//accept user's choice for inputting a red piece
         PlayersChoice--;
    }while(table[0][PlayersChoice]!=' '||PlayersChoice>6);//as long as there is an empty with no R or B then end the loop
 for(int x=5;x>-1;x--)
    {
    if(table[x][PlayersChoice]==' ')
        {
            table[x][PlayersChoice]='R';//Player is the RED PIECE!!!!!
            /* User always plays Red, and the computer plays Blue. */
            break;//job is done so end here
        }
     }
}
void initialize()//it was provided in the elearning code.I tried.
{
for(int a=0;a<6;a++)
{
    for(int b=0;b<7;b++)
    {
    table[a][b]=' ';//yay spaces ' ' throughout the whole board
    }
}
}

void computerTurn()
/*computerTurn() - computer randomly selects a column to put BLUE piece in.
If the selected column is full, re-select another column.*/
{
int computerChoice;
do{
    cout<<"Computer's selection:";
    computerChoice=rand()%7;//Computer need not be very intelligent - you can make it to drop a ball in random column.
    //I made it 7 cause of the way I formatted everything
    cout<<computerChoice;
  }while(table[0][computerChoice]!=' ');//if it finds a space that has no R or B then exit loop
for(int i=5;i>-1;i--)//look for spot that is empty for sure for sure.
    {
    if(table[i][computerChoice]==' ')
        {
        table[i][computerChoice]='B';//Computer is always BLUE!!!! :)
        break;//end function after move has been made by computer
        }
    }
    cout<<endl;//extra formatting to give a polished look
}

int checkConfiguration()
/*checkConfiguration() - returns a code to indicate continue, declares draw, user wins, or computer wins!*/
{
for(int a=0;a<6;a++)//if there is a horizontal win
{
 for(int b=0;b<4;b++)
 {
  if( (table[a][b]==table[a][b+1]) && (table[a][b+1]==table[a][b+2]) && (table[a][b+2]==table[a][b+3]) && (table[a][b+3]=='R') )
    //if they are all "R".Then the player wins :)
     return 1;//number when player wins
  else if( (table[a][b]==table[a][b+1]) && (table[a][b+1]==table[a][b+2]) && (table[a][b+2]==table[a][b+3]) && (table[a][b+3]=='B') )
     //if they are all "B", then computer won
     return 6;//number for when player loses
 }
}
for(int c=0;c<7;c++)//This is when there is a win:Vertically
{
 for(int d=0;d<3;d++)
 {
  if( (table[c][d]==table[c+1][d]) && (table[c+1][d]==table[c+2][d]) && (table[c+2][d]==table[c+3][d]) && (table[c+3][d]=='R') )
        return 1;
  else if( (table[c][d]==table[c+1][d]) && (table[c+1][d]==table[c+2][d]) && (table[c+2][d]==table[c+3][d]) && (table[c+3][d]=='B') )
        return 6;
 }
}
for(int e=6;e>-1;e--)//check for a diagonal win from the left angle
{
  for(int f=0;f<3;f++)
    {
     if( (table[e][f]==table[e+1][f-1]) && (table[e+1][f-1]==table[e+2][f-2]) && (table[e+2][f-2]==table[e+3][f-3]) && (table[e+3][f-3]=='R') )
            //Player wins
            return 1;
     else if( (table[e][f]==table[e+1][f-1]) && (table[e+1][f-1]==table[e+2][f-2]) && (table[e+2][f-2]==table[e+3][f-3]) && (table[e+3][f-3]=='B'))
            //Computer wins
            return 6;
    }
}
for(int h=0;h<7;h++)//Check for a diagonal win from the right angel
{
    for(int i=0;i<3;i++)
    {
        if( (table[i][h]==table[i+1][h+1]) && ( table[i+1][h+1]==table[i+2][h+2]) && (table[i+2][h+2]==table[i+3][h+3]) && (table[i+3][h+3]=='R') )
            //Player wins :D
            return 1;
        else if( (table[i][h]==table[i+1][h+1]) && (table[i+1][h+1]==table[i+2][h+2]) && (table[i+2][h+2]==table[i+3][h+3]) && (table[i+3][h+3]=='B') )
            //Computer wins :(
            return 6;
    }
}
int KeepTrackIfThereIsADrawHomeSlice=0;//This is for a draw, if there is one
  for(int p=0;p<6;p++)
    for(int j=0;j<7;j++)
        if(table[p][j]!=' ')//haha pj like PJ's ahhh im trying to code...
              KeepTrackIfThereIsADrawHomeSlice++;
  if(KeepTrackIfThereIsADrawHomeSlice==42)
     return 4;// this is the number that represent a draw

 return 0;//bleh, this is here just to see if it works properly..ignore it
}

main()//main that was provided
{
srand(time(NULL));//time
    initialize();//so set up a fresh start
    displayConfig();//show the board
    do{//this is for when the game is being played :)
        userTurn();
        displayConfig();
        if(checkConfiguration()!=CONTINUE)
            break;//end it all
        computerTurn();
        displayConfig();
      }while(checkConfiguration()==CONTINUE);
//Check for wins and loses or draws
   if(checkConfiguration()==1)
    {
     cout<<"PLAYER!!!YOU WON CONNECT!CONGRATULATIONS!!!!You managed to win a game that has no inherent meaning or value!WOOT"<<endl;
    }
   else if(checkConfiguration()==6)
    {
    cout<<"Player...You lost, Homie...Sorry."<<endl;
    }
    else if(checkConfiguration()==4)
    {
    cout<<"Player...It's a draw!"<<endl;
    }
   //the end of the main code
}
