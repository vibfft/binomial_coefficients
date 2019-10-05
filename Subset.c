/* Author: Stephen Moon
 * Date: October 4, 2019
 * Description: Return all subset for the given Binomial Coefficients
 * For n sequence, return the subsets made up of k elements
 *
 * i.e. C(n,k) = 1 if k = 0 or k = n, else 
 *      C(n-1, k-1) + C(n-1, k) if 0 < k < n
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 1024 
#define MAX_SIZE 100


void message(char *argv) {
  printf("Usage: %s n k (n and k are ints satisfying 0<=k<=n<=%d)\n", argv, MAX_SIZE);
}

bool isFloat(char *argOne, char *argTwo) {
  char *endptr = NULL;
  char argOneStr[BUF_SIZE];
  char argTwoStr[BUF_SIZE];
  
  sprintf(argOneStr, "%ld", strtol(argOne, &endptr, 10));
  sprintf(argTwoStr, "%ld", strtol(argTwo, &endptr, 10));
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

int main(int argc, char *argv[]) {

  char *programName = argv[0];
  char *n = argv[1];
  char *k = argv[2];

  if(argc != 3) {
    message(programName); 
    return EXIT_FAILURE;

  } else {

    if(isalpha(*n) || isalpha(*k)) {
      message(programName);
      return EXIT_FAILURE;
    } else if(isFloat(n, k)) {
      message(programName);
      return EXIT_FAILURE;
    } else if(!isBinomialCoefficients(strtol(n,NULL,10), strtol(k,NULL,10))) {
      message(programName);
      return EXIT_FAILURE;
    }

    printf("\nARG1: %s, ARG2: %s\n", n, k);

  }

  return EXIT_SUCCESS;
}
