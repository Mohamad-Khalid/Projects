/*
* This is calculator version 1.0
* simple calculator program to apply testing , input validation
* given two numbers you can apply 4 mathematical operations
* // get input : 2 numbers
* // input validation
* // show the menu
* // repeat or close the program
*
* */

import 'dart:io';

void welcomeMessege(){
  print ("\t\t Welcome to the calcualtor");
}

// check if s is a number or not
bool isNumeric(String s) {
  if (s == null) {
    return false;
  }
  return double.tryParse(s) != null;
}

// check if the input is valid or not
// if it is not valid try to get a valid input
double inputValidate(String s){
  while(!isNumeric(s)){
    print('Invalid , enter a correct number');
    s = stdin.readLineSync();
    s.trim();
  }
  return double.parse(s);
}

void showMinue(){
  print ('Enter your choice ');
  print ('1-sum');
  print ('2-sub');
  print ('3-mul');
  print ('4-div');
  print ('0-exit');
}


main(){

  welcomeMessege();
  bool run = true;
  while(run){
    print ('Please enter two numbers ');
    // input from the user
    String a = stdin.readLineSync(); // read a as a string
    a.trim(); // ignore whitespaces
    double num1 = inputValidate(a); // convert string a to double num1

    String b = stdin.readLineSync(); // read b as a string
    b.trim();
    double num2= inputValidate(b); // convert string b to double num2

    bool valid = true; // valid choice (1,2,3,4,0)
    while (valid){
      valid = false;
      showMinue();
      String choice = stdin.readLineSync();
      choice.trim();
      double d = inputValidate(choice);
      int iChoice = d.round(); // convert double to int so can do switch case
      switch(iChoice){
        case 1 :
          print ('sum = ${num1 + num2}');
          break;
        case 2 :
          print ('sub = ${num1 - num2}');
          break;
        case 4 :
          if(num2!=0)
            print ('div = ${num1 / num2}'); // corner case
          else
            print('Canot divide by 0');
          break;
        case 3 :
          print ('mul = ${num1 * num2}');
          break;
        case 0 :
          print('Thanks');
          run=false;
          break;
        default:
          print ('choose a correct number');
          valid = true; // repeat the choice again
      }
    }
  }
}
