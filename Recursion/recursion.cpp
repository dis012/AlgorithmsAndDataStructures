#include <iostream>

using namespace std;

int factorial(int n){
  if(n == 1){
    return 1;
  }
  return n*factorial((n-1));
}

int sum(int n){
  if(n == 1){
    return 1;
  }
  return n+sum(n-1);
}

int main(){
  int a = 5;
  int b = factorial(a);
  int c = sum(a);

  cout << b << endl;
  cout << c << endl;

}
