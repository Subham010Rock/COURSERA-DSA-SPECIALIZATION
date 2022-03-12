#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long fast_solution(vector<int>v){
	long long  first_max=INT_MIN;
	long long second_max=INT_MIN;
	int first_index;
	for(int i=0;i<v.size();i++){
       if(v[i]>first_max){
       	first_max=v[i];
       	first_index=i;
       }
	}
	for(int i=0;i<v.size();i++){
		if(v[i]>second_max and first_index!=i){
			second_max=v[i];
		}

	}
	return first_max*second_max;


}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n;i++){
    	cin>>v[i];
    }
    long long result=fast_solution(v);
    cout<<result;
	return 0;
}