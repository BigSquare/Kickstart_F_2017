#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

int check_1(int size) {
  int rt = sqrt(size);
  if(size - rt*rt == 0) return 1;
  else return -1;
}
int check_2(int size) {
  int rt = sqrt(size);
  for(int i=rt; i>0; i--) {
    int t_1  = i*i;
    int rt_2 = sqrt(size-t_1);
    if(size-t_1 - rt_2*rt_2 == 0) return 2;
  }
  return -1;
}
int check_3(int size) {
  int rt = sqrt(size);
  for(int i=rt; i>0; i--) {
    int t_1  = i*i;
    int rt_2 = sqrt(size-t_1);
    for(int j=rt_2; j>0; j--) {
      int t_2 = j*j;
      int rt_3 = sqrt(size-t_1-t_2);
      if(size-t_1-t_2-rt_3*rt_3 == 0) return 3;
    }
  }
  return -1;
}
int check_4(int size) {
  int rt = sqrt(size);
  for(int i=rt; i>0; i--) {
    int t_1  = i*i;
    int rt_2 = sqrt(size-t_1);
    for(int j=rt_2; j>0; j--) {
      int t_2  = j*j;
      int rt_3 = sqrt(size-t_1-t_2);
      for(int k=rt_3; k>0; k--) {
        int t_3  = k*k;
        int rt_4 = sqrt(size-t_1-t_2-t_3);
        if(size-t_1-t_2-t_3-rt_4*rt_4 == 0) return 4;
      }
    }
  }
  return -1;
}
int check_5(int size) {
  int rt = sqrt(size);
  for(int i=rt; i>0; i--) {
    int t_1  = i*i;
    int rt_2 = sqrt(size-t_1);
    for(int j=rt_2; j>0; j--) {
      int t_2  = j*j;
      int rt_3 = sqrt(size-t_1-t_2);
      for(int k=rt_3; k>0; k--) {
        int t_3  = k*k;
        int rt_4 = sqrt(size-t_1-t_2-t_3);
        for(int l=rt_4; l>0; l--) {
          int t_4  = l*l;
          int rt_5 = sqrt(size-t_1-t_2-t_3-t_4);
          if(size-t_1-t_2-t_3-t_4-rt_5*rt_5 == 0) return 5;
        }
      }
    }
  }
  return -1;
}
int main() {
  int case_num, size, iter=1;
  cin >> case_num;

  while(cin>>size) {
    int count = 0;
    //while(size > 0) {
      //int rt = sqrt(size);
      //size -= rt*rt;
      //count++;
    //}
    if(check_1(size) == 1) count = 1;
    else if(check_2(size) == 2) count = 2;
    else if(check_3(size) == 3) count = 3;
    else if(check_4(size) == 4) count = 4;
    else if(check_5(size) == 5) count = 5;
    
    if(count == 0) {
      while(size > 0) {
        int rt = sqrt(size);
        size -= rt*rt;
        count++;
      }
    }

    stringstream ss, cc;
    string s, c;
    ss << iter;
    ss >> s;
    cc << count;
    cc >> c;
    cout<<"Case #"+s+": "+c<<endl;
    iter += 1;
  }
  return 0;
}
