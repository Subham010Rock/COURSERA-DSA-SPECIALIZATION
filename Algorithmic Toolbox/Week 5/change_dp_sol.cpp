#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  //write your code here
      int coins[]={1,3,4};
      vector<int>c(m+1,INT_MAX);
      c[0]=0;
      for(int i=1;i<=m;i++){
          for(int j=0;j<3;j++){
              if(i>=coins[j]){
                    if(c[i-coins[j]]!=INT_MAX)
                       c[i]=min(c[i],c[i-coins[j]]+1);
                  }
              }
          }
    return c[m]==INT_MAX? -1:c[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
