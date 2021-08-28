// Your First C++ Program

#include <iostream>

int isPrime2(int number){
    int temp = number - 1;
    for (int i=2; i< temp; i++){
       if (number%i == 0)
          return false;
    } 
    return true;
}
int isPrime(int number)
  int temp = number-1;
  for(int i = 2; i <= temp; i++){
    if(number%i == 0)
      return false;
}
int main() {
    std::cout << "Hello World!";
    int result = isPrime(3);
    std::cout << result;
    return 0;
}

