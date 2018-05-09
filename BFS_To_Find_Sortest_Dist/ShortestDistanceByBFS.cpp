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
    unordered_map<int,int> DistMap;
    queue<int> Q;
public:
 void Push_value(int scr , int des){
             if(Graph.find(scr) == Graph.end()){
//                Node temp1 = CreateNode(scr,des);
                vector<int> Temp1;
                Temp1.push_back(des);
                Graph[scr] = Temp1;
            }
            else{
//                Node temp1 = CreateNode(scr,des);
                 vector<int>& X = Graph[scr];
                 X.push_back(des);
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
        while(s.length() > 0){
            index = s.find_first_of("\t");
            string number = s.substr(0,index);
            if(mark == 0){
                stringstream stoi(s);
                stoi>>scr;
                mark = 1;
                 string sub = s.substr(index+1,s.length()-1);
                 s = sub;
                continue;
            }
            stringstream stoi(s);
            stoi>>des;
            Push_value(scr,des);//push to Graph
            string sub = s.substr(index+1,s.length()-1);
            s = sub;
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
void initializeDistMap(){
    unordered_map<int,vector<int> >::iterator it;
  for(it = Graph.begin() ; it != Graph.end() ; it++){
      pair<int,int> temp;
      temp.first = it->first;
      temp.second = 0;
      DistMap.insert(temp);
  }
}
void CalShortestDist(int sourceVertex){
    markallVerticesUnvisited();
    initializeDistMap();
    Q.push(sourceVertex);
    marked[sourceVertex] = true;
    while(!Q.empty()) {
        int CurrentVertex = Q.front();
        Q.pop();
        vector<int>& RelatedVerticies = Graph[CurrentVertex];
        vector<int>::iterator it;
        for(it = RelatedVerticies.begin() ; it != RelatedVerticies.end() ; it++){
         if(marked[*it] == false){
           marked[*it] = true;
           Q.push(*it);
           DistMap[*it] = DistMap[CurrentVertex]+1;
         }
        }
    }
}
void PrintDistances(){
  unordered_map<int,int>::iterator it;
  for(it = DistMap.begin() ; it != DistMap.end() ; it++){
      cout<<it->first<<"  "<<it->second<<endl;
  }
}
};
int main(){
    int sourceVertex;
    sourceVertex = 1;
    Graphs graph;
    graph.ReadFile();
    graph.CalShortestDist(sourceVertex);
    graph.PrintDistances();
}
