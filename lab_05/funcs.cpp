#include <iostream>


bool isDivisibleBy(int n, int d){
  if (n%d==0)
    return true;
  return false;
}

bool isPrime(int n){
  if (n < 2)
    return false;
  for (int i = 2; i < n; i++){
    if (n%i == 0)
      return false;
  }
  return true;
}

int nextPrime(int n){
  for (int i = n+1; i < 10000000; i++){
    if (isPrime(i)==true){
      return i;
    }
  }
  return 0;
}

int countPrimes(int a, int b){
  int counter = 0;
  for (int i = a; i <= b; i++){
    if (isPrime(i))
      counter++;
  }
  return counter;
}

bool isTwinPrime(int n){
  if (isPrime(n) && (isPrime(n-2) || isPrime(n+2)))
    return true;
  return false;
}

int nextTwinPrime(int n){
  for (int i = n+1; i < 1000000; i++){
    if (isTwinPrime(i))
      return i;
  }
  return 0;
}

int largestTwinPrime(int a, int b){
  int ans = -1;
  for (int i = a; i <= b; i++){
    if (isTwinPrime(i))
      ans = i;
  }
  return ans;
}
