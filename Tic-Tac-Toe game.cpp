/*
//  - This is Tic-Tac-Toe game project version 1.0.0 
  - Requirements : # Grid of N*N  
                   # Player 1 and Player2 take turns
                   # The player wins if the hole row or colomn or diagonal is the same character
                   # Welcome message for the user when the game starts 
                   # Message guides the user for Input 
                   # Checking if the input is vlaid or not 
                   # Message when a player wins the game 

  -  Testing     : # natural behavior  row[1,3] col[1,3] 
                   # wrong behavior    input character , numbers > N 
                   # corner cases      right and left diagonal , there is no winner

 - Implementation: Structured Programin using C++ 
                    main() 
                      runGame()
                        init()
                        draw()
                        play()
                        winner()

 -   Issues     :  Some bug fixes and organizing the code applied  



*/

#include <iostream>
using namespace std;


const int N=3;
char grid[N][N];

// initiate the game 
// fill the grid with '.'
void init(){
  cout << "\n\t\tThis is Tic-Tac-Toe game \n\n";
  cout << "There are two players x and O \n\n";
  for(int i=0; i<N ;++i)
    for(int j=0; j<N ; ++j)
      grid[i][j]='.';
}


// draw the grid for the player
void draw(){
  for(int i=0; i<N ;++i){
    cout <<"\t";
    for(int j=0; j<N ; ++j)
      cout  << grid[i][j]<<' ';
    cout << endl;
  }
  cout <<"________________\n";
}

// Player Action: return true if the action is valid 
bool play(char role ,int r, int c){
  // check that the value of r and c is valid 
  if(r >=0 && r <N && c>=0 && c< N && grid[r][c]=='.'){
    grid[r][c]=role;
    return 1;
  }
  else 
    cout << "Invalid Input, Try again\n";
  return false;
}

// check if the a player won the game or not
bool winner(char role,int row ,int col){
  int r=0;// check the hole row 
  for(int i = 0 ; i<N;i++){
    if(grid[row][i]==role)r++;
  }


  // check the hole colomn
  int c=0;
  for(int i=0;i<N; i++){
    if(grid[i][col]==role) c++;
  }

  //check the hole left diagonal if the cell is located on it 
  int dl=0;
  if(row == col){
    for(int i=0;i<N;i++)
      if(grid[i][i]==role) dl++;
  }

  //check the hole rigtht diagonal if the cell is located on it 
  int dr=0;
  for(int i=0, j=N-1 ; i<N && j>=0 ; i++,j--){
    if(grid[i][j]==role) dr++;
  }

  // if any of 4 variables equal N --> then the player won
  return (r==N || c==N || dl==N || dr==N );
}


// Run the game 
void runGame(){

  init();

  char player1='x',player2='o';
  int row , col , maxSteps=0;
  bool turn = 1;

  while(true){
    ++maxSteps;
    char role = (turn? player1:player2);

    takeInput://lable to start again form here if the chosen cell is invlaid 

    cout << "Role of "<< char (toupper(role)) <<"  Enter Empty location (r,c)\n";

    draw();

    // Input vlaidation
    while(cin >> row >> col , cin.fail()){
      cout << "Invalid Input\n";
      cout << "Enter Empty location (r,c)\n";
      cin.clear();
      cin.ignore(100000,'\n');
    }
    --row , --col;

    while(!play(role,row,col)) goto takeInput;


    if(winner(role , row , col)){
      draw();
      cout << char (toupper(role)) << " is the winner\n";
      break;
    }

    turn=!turn;//to change the turn 

    if(maxSteps==N*N){ // if there is no winner the game finishs
      cout << "EQUAL !\n";
      break;
    } 
  }
}

int main(){

    runGame();
  
  return 0;
}
