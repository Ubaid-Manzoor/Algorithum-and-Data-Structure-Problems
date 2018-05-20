#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<queue>
#include <sstream>
#include <iterator>
using namespace std;
class Graphs{
private:
    unordered_map<int,vector<int> > Graph;
    unordered_map<int,bool> marked;
    vector<int> Topological_ordering;
    queue<int> Q;
public:
  void Push_value(int scr , int des){
              if(Graph.find(scr) == Graph.end()){
                 vector<int> Temp1;
                 if(des != -1){
                   Temp1.push_back(des);
                 }
                 Graph[scr] = Temp1;
             }
             else{
                  vector<int>& X = Graph[scr];
                  if(des != -1){
                     X.push_back(des);
                 }
              }
          }
 void ReadFile(){
     vector<int> vertex;
     int index;
     ifstream input;
     string s;
     input.open("GraphVertexs.txt");
     while(getline(input,s)){
         int mark = 0,scr,des;
         int length = s.length();
         stringstream stoi(s);
         stoi>>scr;
         if(length == 1){
           Push_value(scr,-1);
         }
         while(s.length() > 0){
             index = s.find_first_of(' ');
             string number = s.substr(0,index);
             if(mark == 0){
                 stringstream stoi(number);
                 stoi>>scr;
                 mark = 1;
                 s = s.substr(index+1,s.length()-1);
                 continue;
             }
             stringstream stoi(number);
             if(index != -1){
               stoi>>des;
               Push_value(scr,des);
             }else{
               stoi>>des;
               Push_value(scr,des);
               break;
             }

           //push to Graph
             s = s.substr(index+1,s.length()-1);
         }
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
void markallVerticesUnvisited(){
    unordered_map<int,vector<int> >::iterator it;
    for(it = Graph.begin() ; it != Graph.end() ; it++){
        pair<int,bool> temp;
        temp.first = it->first;
        temp.second = false;
        marked.insert(temp);
    }
}
void DFS(int CurrentVertex){
    vector<int>& CurrentVerticies = Graph[CurrentVertex];
    vector<int>::iterator it;
    marked[CurrentVertex] = true;
    for(it = CurrentVerticies.begin() ; it != CurrentVerticies.end() ; it++){
      if(marked[*it] == false){
        DFS(*it);
      }
    }
    Topological_ordering.push_back(CurrentVertex);
}
void GiveTopologicalOdering(){
    markallVerticesUnvisited();
    unordered_map<int,vector<int> >::iterator it;
    for(it = Graph.begin() ; it != Graph.end() ; it++){
      if(marked[it->first] == false){
         DFS(it->first);
      }
    }
}
void PrintTopologicalOdiring(){
  int length = Topological_ordering.size();
  for(int i = length - 1 ; i >= 0  ; i--){
    cout<<Topological_ordering[i]<<" ";
  }
}
};
int main(){
  Graphs graph;
  graph.ReadFile();
  graph.print();
  graph.GiveTopologicalOdering();
  graph.PrintTopologicalOdiring();
}
