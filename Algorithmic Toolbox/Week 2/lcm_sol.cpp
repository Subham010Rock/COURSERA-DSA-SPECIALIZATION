#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long gcd(int a, int b){
  if(b==0)
    return a;
  gcd(b,a%b);
}

long long lcm_naive(int a, int b) {
  
  return (long long)(min(a,b)/gcd(max(a,b),min(a,b)))*max(a,b);

}

int main(){
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
