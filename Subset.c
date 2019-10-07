/* Author: Stephen Moon
 * Date: October 4, 2019
 * Description: Return all subset for the given Binomial Coefficients
 * For n sequence, return the subsets made up of k elements
 *
 * i.e. C(n,k) = 1 if k = 0 or k = n, else 
 *      C(n-1, k-1) + C(n-1, k) if 0 < k < n
 */

#include <stdio.h>
#include <stdlib.h>  //needed for strtol == string to longi
#include <ctype.h>   //needed for isalpha, isdigit
#include <string.h>  //needed for strlen 
#include <stdbool.h> //needed for bool type

#define BUF_SIZE 1024 //this is normally the max buffer size 
#define MAX_SIZE 100

//  %s requires a pointer to character (i.e. an address to the character
void message(char *argv) {
  printf("Usage: %s n k (n and k are ints satisfying 0<=k<=n<=%d)\n", argv, MAX_SIZE);
}

bool isFloat(char *argOne, char *argTwo) {
  char *endptr = NULL;
  char argOneStr[BUF_SIZE];  // enough buffer size for user input, n
  char argTwoStr[BUF_SIZE];  // enough buffer size for user input, k
  
  sprintf(argOneStr, "%ld", strtol(argOne, &endptr, 10)); //sprintf converts a long value into a string
  sprintf(argTwoStr, "%ld", strtol(argTwo, &endptr, 10)); //arg1: pointer to char, arg2: ending pointer (normally null), arg3: base 10 values

  // compare argOne and argOneStr to see whether a number is float.  i.e. 102.234 converted to long becomes 102
  // converting 102 to argOneStre will effect in a string of length 3
  // converting 102.234 to argOne will effect in a string of length 7
  // in this example, they are not equal, hence it means the number is not an integer
  if(strlen(argOne) != strlen(argOneStr) || strlen(argTwo) != strlen(argTwoStr)) {
    return true; 
  }

  return false;
}

bool isBinomialCoefficients(long n, long k) {
  if(k < 0 || n < 0) {
    return false;
  } else if(k > MAX_SIZE || n > MAX_SIZE) {
    return false;
  } else if(k > n) {
    return false;
  }

  return true;
}

/** These two functions need to be implemented
void printSet(int B[], int n)

void printSubsets(int B[], int n, int k, int i)
*/

int main(int argc, char *argv[]) {

  // always try to use a standard library wherever you can
  char *programName = argv[0];
  char *n = argv[1];
  char *k = argv[2];

  if(argc != 3) {
    message(programName); 
    return EXIT_FAILURE;

  } else {

    // in order to pass a character to isalpha, you need to dereference n and k.
    // dereferencing means getting the actual value at particular address.
    // pointer to character is an address or reference in case of java.
    if(isalpha(*n) || isalpha(*k)) {
      message(programName);
      return EXIT_FAILURE;
    } else if(isFloat(n, k)) {
      message(programName);
      return EXIT_FAILURE;
    // in the following comparison, the inputs to the function need to be "longs"
    // hence strtol is used to convert string to long
    } else if(!isBinomialCoefficients(strtol(n,NULL,10), strtol(k,NULL,10))) {
      message(programName);
      return EXIT_FAILURE;
    }

    printf("\nARG1: %s, ARG2: %s\n", n, k);
    //printSet(B, n) B array with n size

  }

  return EXIT_SUCCESS;
}
