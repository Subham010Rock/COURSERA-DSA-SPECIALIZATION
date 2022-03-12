#include<bits/stdc++.h>

using std::vector;
using std::pair;
using std::make_pair;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<pair<int,int>>p;
   for (size_t i = 0; i < segments.size(); ++i) {
    p.push_back(make_pair(segments[i].start,segments[i].end));
}
  sort(p.begin(),p.end());
  
  vector<int>points;
  int checks=p[p.size()-1].second;
  int checkf=p[p.size()-1].first;
  //points.push_back(check);
  for(int i=p.size()-1;i>0;i--){
    if(checks>p[i-1].second and checkf>p[i-1].second){
      points.push_back(checkf);
      checks=p[i-1].second;
      checkf=p[i-1].first;
    }
  }
  if(checkf!=p[p.size()-1].first and checks!=p[p.size()-1].second)
    points.push_back(checkf);
  else
    points.push_back(checkf);
  
return points;
}


int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
