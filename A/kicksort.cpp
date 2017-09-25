#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool check_worse(vector<int> seq, int min, int max) {
  int length = seq.size();
  int pivot = (length - 1) / 2;
  if(length == 2) return true;
  else if(seq[pivot] == min) {
    min = min + 1;
    seq.erase(seq.begin()+pivot);
    //return true;
    return check_worse(seq, min, max);
  }
  else if(seq[pivot] == max) {
    max = max - 1;
    seq.erase(seq.begin()+pivot);
    //return true;
    return check_worse(seq, min, max);
  }
  else return false;
}
int main() {
  //int a;
  //cin>>a;
  //cout<<"!!!!"<<a;
  int case_num = 0, len = 0, iter=1;
  cin>>case_num;

  while(cin>>len) {
    vector<int> num_list;
    int min_num = 1, max_num = len;

    for(int i=0; i<len; i++) {
      int n;
      cin>>n;
      num_list.push_back(n);
    }

    stringstream ss;
    ss << iter;
    string s;
    ss >> s;
    
    if(check_worse(num_list, min_num, max_num)) {
      cout<<"Case #"+s+": YES";
    }
    else cout<<"Case #"+s+": NO";
    cout<<endl;

    iter++;
  }
  return 0;
}
