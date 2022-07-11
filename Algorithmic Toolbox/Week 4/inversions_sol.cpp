#include <iostream>
#include <vector>

using std::vector;
long long merge(vector<int>&a,vector<int>&b,int l,int m,int r){
  int k=0;
  int c=0;
  int i=l;
  int j=m+1;
  while(i<=m && j<=r){
    if(a[i]<=a[j]){
      b[k++]=a[i++];
    }
    else{
      b[k++]=a[j++];
      c+=(m-i)+1;
    }
  }
  while(i<=m){
    b[k++]=a[i++];
  }
  while(j<=r){
    b[k++]=a[j++];
  }
  for( i=r;i>=l;i--){
    a[i]=b[--k];
  }
  return c;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right>left){
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  //write your code here
  number_of_inversions+=merge(a,b,left,ave,right);}
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
