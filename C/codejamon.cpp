#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;

struct edge;
struct node {
  node() : dist(100000), traveled(false){}
  int  id;
  int  dist;
  node* prev;
  bool traveled;
  vector<edge> edge_list;
};

struct edge {
  node* from;
  node* to;
  int minute;
};

struct less_dist_node {
  inline bool operator() (const node* A, const node* B) {
    return A->dist < B->dist;
  }
};

void init_graph(vector<node>& graph, int node_num) {
  for(int i=1; i<=node_num; i++) {
    node A;
    A.id = i;
    graph.push_back(A);
  }
}
void reset_graph(vector<node>& graph, int node_num) {
  for(int i=0; i<node_num; i++) {
    graph[i].dist = 100000;
    graph[i].prev = 0;
    graph[i].traveled = false;
  }
}

void Dijkstra(vector<node>& graph, int start) {
  vector<node*> queue;
  queue.push_back(&graph[start-1]);
  queue[0]->dist = 0; queue[0]->traveled = true;
  for(int i=0; i<queue[0]->edge_list.size(); i++) {
    queue[0]->edge_list[i].to->dist = queue[0]->edge_list[i].minute;
    queue[0]->edge_list[i].to->prev = queue[0];
    queue[0]->edge_list[i].to->traveled = true;
    queue.push_back(queue[0]->edge_list[i].to);
  }
  queue.erase(queue.begin());
  sort(queue.begin(), queue.end(), less_dist_node());

  while(!queue.empty()) {
    int to_del = queue.size();
    for(int i=0; i<queue.size(); i++) {
      for(int j=0; j<queue[i]->edge_list.size(); j++) {
        if(queue[i]->edge_list[j].to->dist > queue[i]->dist+queue[i]->edge_list[j].minute) {
          queue[i]->edge_list[j].to->dist = queue[i]->dist+queue[i]->edge_list[j].minute;
          queue[i]->edge_list[j].to->prev = queue[i];
        }
        if(!queue[i]->edge_list[j].to->traveled) {
          queue[i]->edge_list[j].to->traveled = true;
          queue.push_back(queue[i]->edge_list[j].to);
        }
      }
    }
    queue.erase(queue.begin(), queue.begin() + to_del);
    sort(queue.begin(), queue.end(), less_dist_node());
  }
}

int get_all_dist(vector<node> graph, int node_num) {
  int total = 0;
  for(int i=0; i<node_num; i++) {
    //self is zero, doesn't matter
    total += graph[i].dist;
  }
  return total;
}

int main() {
  int case_num, node_num, edge_num, poke_num, iter=1;
  cin>>case_num;

  while(cin>>node_num>>edge_num>>poke_num) {
    vector<node> graph;
    init_graph(graph, node_num);
    for(int i=0; i<edge_num; i++) {
      int a, b, time;
      cin>>a>>b>>time;
      edge a_b, b_a;
      a_b.from = &graph[a-1]; a_b.to = &graph[b-1]; a_b.minute = time;
      b_a.from = &graph[b-1]; b_a.to = &graph[a-1]; b_a.minute = time;

      graph[a-1].edge_list.push_back(a_b); graph[b-1].edge_list.push_back(b_a);
    }
    
    vector<int> all;
    for(int i=0; i<node_num; i++) {
      Dijkstra(graph, i+1);
      all.push_back(get_all_dist(graph, node_num));
      reset_graph(graph, node_num);
    }
    //for(int i=0; i<5; i++)
    int A = 1, B = 0;
    double average = 0.0;
    for(int i=0; i<poke_num; i++) {
      double denominator = (A + (node_num-1)*B);
      average += A*all[0] / (double)((node_num-1)*denominator);
      for(int j=1; j<all.size(); j++)
        average += B*all[j] / (double)((node_num-1)*denominator);
      if(i != poke_num - 1) {
        int temp = A;
        A = (node_num - 1)*B;
        B = temp + (node_num - 2)*B;
      }
    }

    stringstream ss, aa;
    string s, a;
    ss << iter;
    ss >> s;
    aa << average;
    aa >> a;
    if(a.find(".") == -1) a += ".000";
    cout<<"Case #"+s+": "+a<<endl;

    iter++;
  }
  return 0;
}
