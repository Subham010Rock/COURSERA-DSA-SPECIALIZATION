#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    std::vector<int>::iterator it;
    it = stops.begin();
    it = stops.insert ( it , 0 );
    stops.push_back(dist);
    int res=0;
    int cur_refill=0;
    while(cur_refill<stops.size()-1){
       int last_refill=cur_refill;
       while(cur_refill<stops.size()-1 and (stops[cur_refill+1]-stops[last_refill])<=tank){
         cur_refill++;
       }
       if(cur_refill==last_refill)
        return -1;
       if (cur_refill<stops.size()-1)
        res+=1;
       
    }
    return res;
            
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
