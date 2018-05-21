#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include<stack>
#include<sstream>
#include<fstream>
using namespace std;
class Graphs{
private:
  unordered_map<int,vector<int> > Graph;
  unordered_map<int,vector<int> > ReverseGraph;
  map<int,set<int> > StronglyComponentsComponents;
  set<int> Visited;
  stack<int> S;
  void Push_value(int scr , int des){
          //  Actual Graph
              if(Graph.find(scr) == Graph.end()){
                 vector<int> Temp1;
                 Temp1.push_back(des);
                 Graph[scr] = Temp1;
             }
             else{
                  vector<int>& X = Graph[scr];
                  X.push_back(des);
              }
              if(Graph.find(des) == Graph.end()){
                vector<int> Temp1;
                Graph[des] = Temp1;
              }
          // Reverse Graph
            if(ReverseGraph.find(des) == ReverseGraph.end()){
                 vector<int> Temp1;
                 Temp1.push_back(scr);
                 ReverseGraph[des] = Temp1;
             }
             else{
                  vector<int>& X = ReverseGraph[des];
                  X.push_back(scr);
              }
              if(ReverseGraph.find(scr) == ReverseGraph.end()){
                vector<int> Temp1;
                ReverseGraph[scr] = Temp1;
              }
          }
public:
  void ReadFile(){
    int N=0;
      ifstream input;
      input.open("GraphVertex.txt");
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
  void PrintReverseGraph(){
    unordered_map<int ,vector<int> >::iterator it;
        for(it = ReverseGraph.begin() ; it != ReverseGraph.end() ;it++){
            cout<<it->first<<":- ";
                for( int i = 0 ; i < it->second.size() ; i++){
                        cout<<it->second[i]<<" ";
                    }
                    cout<<endl;
        }
  }

void ReverseDFS(int CurrentVertex){
    vector<int>& CurrentVerticies = ReverseGraph[CurrentVertex];
    vector<int>::iterator it;
    Visited.insert(CurrentVertex);
    for(it = CurrentVerticies.begin() ; it != CurrentVerticies.end() ; it++){
      if(Visited.find(*it) == Visited.end()){
        ReverseDFS(*it);
      }
    }
    S.push(CurrentVertex);
}

void DFS(int CurrentVertex,int ComponentNo){
    vector<int>& CurrentVerticies = Graph[CurrentVertex];
    set<int>& CurrentComponent = StronglyComponentsComponents[ComponentNo];
    vector<int>::iterator it;
    Visited.insert(CurrentVertex);
    for(it = CurrentVerticies.begin() ; it != CurrentVerticies.end() ; it++){
      if(Visited.find(*it) == Visited.end()){
        DFS(*it,ComponentNo);
      }
    }
    CurrentComponent.insert(CurrentVertex);
}
void GetStronglyComponents(){
  unordered_map<int,vector<int> >::iterator it;
  //Get The Magical Odering Using Stack
  for(it = ReverseGraph.begin() ; it != ReverseGraph.end() ; it++){
    if(Visited.find(it->first) == Visited.end()){
          ReverseDFS(it->first);
    }
  }
  Visited.clear();
  // Use MagicalOdering To Calculate Strongly Connected Components
    int i = 1;
    while(S.size() > 0){
        if(Visited.find(S.top()) == Visited.end()){
            DFS(S.top(),i);
            i++;
        }
        S.pop();
    }
  PrintComponents();
}

void PrintComponents(){
  map<int,set<int> >::iterator it;
  for(it = StronglyComponentsComponents.begin() ; it != StronglyComponentsComponents.end() ; it++){
    cout<<it->first<<"->";
    set<int>::iterator itr;
    for(itr = it->second.begin() ; itr != it->second.end() ; itr++){
      cout<<*itr<<" ";
    }
    cout<<endl<<endl<<endl;
  }
}
void PrintStack(){
  stack<int> Temp(S);
  while(Temp.size()>0){
    cout<<Temp.top()<<endl;
    Temp.pop();
  }
}
};
int main(){
  Graphs graph;
  graph.ReadFile();
  graph.GetStronglyComponents();
}
