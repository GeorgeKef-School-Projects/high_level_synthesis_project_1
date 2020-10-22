#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

//The function that returns the checksum
unsigned int checksum(unsigned int Num){
  //Find the length of our Number
  int digits=0;

  for(int i=0;i<11;i++){
    if((Num/pow(10,i))>=1){
      digits++;
    }
  }
  //*****************************

  //The sum of the digits
  bool is_even = !(digits % 2);
  unsigned int sum = 0;
  unsigned int cmplx_sum;
  while(digits>0){
    int digit_to_add = Num/pow(10,digits-1);
    Num -=(digit_to_add*pow(10,digits-1));
    if(is_even){
      if((digit_to_add*2) > 9){
	 digit_to_add = (digit_to_add*2)-9;
       }else{
         digit_to_add = digit_to_add * 2;
       }
    }
    sum += digit_to_add;
    is_even = !is_even; 
    digits--; 
  }
  return sum;
}


int main(){

  /* initialize random seed: */
  srand (time(NULL));

  /* generate random numbers*/
  for(int j=0;j<20;j++){
    unsigned int test_num = rand() % 32767;
    unsigned int ans = checksum(test_num);

    std::cout<< "The number:" << test_num <<std::endl;
    std::cout<< "Has checksum equal to:" << ans <<std::endl;
  }
    
  return 0;
}


