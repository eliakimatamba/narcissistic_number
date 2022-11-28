#include <math.h>
#include <vector>
#include <iostream>

bool narcissistic( int value ){
  //Code away
  //lets determine number of digits in the number
  int copy=value;
  int count=0;
  while(copy>0){
    count++;
    copy/=10;
  }
  
  //get individual digits from the number and store in a vector digits
  copy=value;
  std::vector<int>  digits;
  int last_digit =0;
  for(int i=0; i<count; i++){
    last_digit=copy%10;
    digits.push_back(last_digit);
    copy/=10;
  }
  
  //re-arrange the number from last to first, the correct order
  //since push stores in a stack, i.e FILO
  std::vector<int> lro;
  for(int i=digits.size()-1; i>=0; i--)
    lro.push_back(digits[i]);

  //get sum of the i-th digit indexed to number digits
  //e.g, 12 = 1^2+2^2 = 5
  int candidate=0;
  for(int i=0; i<count; i++)
    candidate+=pow(lro[i],count);
  
  //check if the evaluated number equals original number
  if(value == candidate){
    std::cout<<"true: "<<value<<" = "<< candidate<<std::endl;
    return true;
    }
  std::cout<<"false: "<<value<<" != "<< candidate<<std::endl;
  return false;
}

int main(){
    narcissistic(7);
    narcissistic(371);
    narcissistic(122);
    narcissistic(4887);
    
    return 0;
}
