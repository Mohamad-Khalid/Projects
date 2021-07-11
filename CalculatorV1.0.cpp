/*
 Simple Calculator program 
 Calcualator V1.0

Applying concepts of testing , validation , estimating time of coding , naming convesiions

// given 2 number you can do 4 mathimatical operations 
// + - * / 

The big picture  : welcome messeage
                 : input messege
                 : validation 
                 : output menue for operations 
                 : validation 
                 : repetition or closing 
                 : final messege 

*/

#include<iostream>

using namespace std;


int main(){

  cout << "\t\t Welcome to my calcualtor\n";

  bool run = true;
  while(run){

    double num1=0,num2=0;

    input:
    cout << "\nPlease enter 2 numbers\n";
    // input validation
    while(cin >> num1 >> num2 , cin.fail()){
      cout << "Invalid input , Please enter two numbers \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }

    int choice; // 1-sum , 2-sub , 3-mul , 4-div , 5-closing 
    cout <<"1-sum\n2-sub\n3-mul\n4-div\n5-close\n";
    // input validaion 
    while(cin >> choice , cin.fail()){
      cout <<"Invalid input , Please enter a number from 1-5 \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }

    choose:
    switch(choice){
      case 1 : 
        cout << "\nSum = " << num1 + num2 << '\n';
        break;
      case 2 : 
        cout << "\nSub = " << num1 - num2 << '\n';
        break;
      case 3 : 
        cout << "\nMult = " << num1 * num2 << '\n';
        break;
      case 4 : 
        if(num2==0){
          cout <<"\nCan't dived by 0\n";
          goto input;
        }
        else 
          cout << "\nDiv = " << num1 / num2 << '\n';
        break;
        case 5: 
        run = false;
        cout << "Thanks\n";
        break;
        default:
        goto choose;
    }
  }
  


  return 0;
}
