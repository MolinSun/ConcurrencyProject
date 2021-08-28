/*!
   \mainpage Concurrency Project
   \copyright This code is covered by the GNU general public license v3.0
   \author Molin Sun, Student Number: C00266170
   \date 25/08/2021 
*/

#include<chrono>
#include<vector>
#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;

/*! \fn int isPrime(int number)
    \param number  the number which is checked whether it is a prime
    \brief returns whether a number is prime and this process is serial
*/
bool isPrime(int number){
    if (number <= 1) return false;
    if (number <= 3) return true;

    if(number%2 == 0 || number%3 == 0) return false;

    for(int i = 5; i*i <=number; i=i+6)
    {
      if(number%i == 0 || number%(i+2) == 0) return false;
    }
    return true;
 }


/*! \fn int numberPrimes(int first, int last)
    \param first The first number to check
    \param last The last number to check
    \brief returns the number of primes less than n
*/
void numberPrimes(int first, int last)
{
    int i;
    int count = 0;
    #pragma omp parallel for num_threads(3)
    for(i = first; i <= last; i++)
    {
      if(isPrime(i))
      {
        //#pragma omp atomic
        count++;
      }
    }
    printf("\nThe number of primes less than %d: %d\n", last, count);

}
/*! \fn int numberPrimes(int first, int last)
    \param first The first number to check
    \param last The last number to check
    \brief returns the number of twin primes pairs less than n
*/
void numberTwins(int first, int last)
{
    int count =0;
    #pragma omp parallel for num_threads(3)
    for(int i = first; i <= last; i++)
    {
      if (isPrime(i) && isPrime(i+2)){
        #pragma omp atomic
        count++;
      }
    }
    printf("\nThe number of twin primes less than %d: %d\n", last, count);
}



/*! \fn main(int argc, char *argv[])
    \param argc Record the number of command line arguments
    \param argv Is an array of pointers that hold the commands that are typed on the command line
    \brief Main method. The entrance of the program.
*/
int main(int argc, char *argv[])
  {
    int first = 1;
    char *value = argv[1];
    int last = atoi(value);
    numberPrimes(first, last);
    numberTwins(first, last);
    return 0;
  }