//DFS for Undirected Graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include<queue>
#include<sstream>
#include<fstream>
using namespace std;
class Graphs{
private:
  unordered_map<int,vector<int> > Graph;
  vector<int> magicOdering;
  set<int>visited;
  queue<int> Q;
  void Push_value(int scr , int des){
              if(Graph.find(scr) == Graph.end()){
                 vector<int> Temp1;
                 Temp1.push_back(des);
                 Graph[scr] = Temp1;
             }
             else{
                  vector<int>& X = Graph[scr];
                  X.push_back(des);
              }
          }
public:
  void ReadFile(){
    int N=0;
      ifstream input;
      input.open("GraphVertexs.txt");
      string s,splitter=" ";
      while (getline(input,s)) {
        int scr,des;
        int index = s.find_first_of(splitter);
        string Currentscr = s.substr(0,index);
        string Currentdes = s.substr(index+1,s.length()-1);
        stringstream stoi(Currentscr);
        stoi >> scr;
        stringstream stoi1(Currentdes);
        stoi1 >> des;
        Push_value(scr,des);
      }
  }
  void print(){
      unordered_map<int ,vector<int> >::iterator it;
          for(it = Graph.begin() ; it != Graph.end() ;it++){
              cout<<it->first<<":- ";
                  for( int i = 0 ; i < it->second.size() ; i++){
                          cout<<it->second[i]<<" ";
                      }
                      cout<<endl;
          }
  }
  void DFS(int CurrentVertex){
      vector<int>& CurrentVerticies = Graph[CurrentVertex];
      vector<int>::iterator it;
      visited.insert(CurrentVertex);
      for(it = CurrentVerticies.begin() ; it != CurrentVerticies.end() ; it++){
        if(visited.find(*it) == visited.end()){
          DFS(*it);
        }
      }
      cout<<CurrentVertex<<endl;
  }
};
int main(){
  Graphs graph;
  graph.ReadFile();
  graph.print();
  cout<<endl;
  graph.DFS(1);
}
