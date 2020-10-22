#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

//The function that returns the number of digits that are equal to one.
unsigned short int digit_counter(unsigned int Num){
  unsigned short int num_of_ones = 0;
  unsigned int exp;
  int i = 31; //Flaoting point restriction. Check!  
  int check_digit;

  while(i>=0){
    exp = pow(2,i);
    check_digit = Num/exp; 
    if(check_digit == 1){
      num_of_ones++;
      Num = Num - exp;
    }
    i--; 
  }
  
  return num_of_ones;
}


//Our main function.
int main(){
  
  /* initialize random seed: */
  srand (time(NULL));

  /* generate random numbers */
  for(int j=0;j<20;j++){
    unsigned int test_num = rand() % 30000;
    unsigned short int ans = digit_counter(test_num);

    std::cout << "The number:" << test_num << std::endl;
    std::cout << "Number of ones:" << ans << std::endl;
  }
  return 0;
}
