#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void dance_more(vector<int>& line, int& energy, int& honor) {
  int count = 0;
  for(int i=0; i<line.size(); i++) {
    if(line[i] < energy) {
      energy -= line[i];
      honor += 1;
      count += 1;
    }
    else break;
  }
  line.erase(line.begin(), line.begin()+count);
}

void recruit_most(vector<int>& line, int& energy, int& honor) {
  energy += line[line.size() - 1];
  honor -= 1;
  line.pop_back();
}

int main() {
  int case_num = 0, energy, rivals, iter = 1;
  cin>> case_num;

  while(cin>>energy>>rivals) {

    vector<int> rival_skill;
    int honor = 0;

    for(int i=0; i<rivals; i++) {
      int n;
      cin>>n;
      rival_skill.push_back(n);
    }
    std::sort(rival_skill.begin(), rival_skill.end());

    while(1) {
      dance_more(rival_skill, energy, honor);
      //cout<<energy<<" "<<honor<<" "<<rival_skill.size()<<endl;
      if(rival_skill.size() == 1 || rival_skill.size() == 0 || honor == 0) {
        stringstream ss, hh;
        ss << iter;
        string s, h;
        ss >> s;
        hh << honor;
        hh >> h;
        cout<<"Case #"+s+": "+h<<endl;
        break;
      }
      if(honor > 0)
        recruit_most(rival_skill, energy, honor);
      //cout<<energy<<" "<<honor<<" "<<rival_skill.size()<<endl;
    }
    iter++;
  }
  return 0;
}
