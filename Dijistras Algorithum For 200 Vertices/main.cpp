#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<set>
#include<sstream>
#include<set>
#include "MinHeap.h"
using namespace std;

class Graphs{
private:
    unordered_map<int,vector<Node> > Graph;
    MinHeap Heap;
    unordered_map<int,int> Vertex_Distance;
   class Node CreateNode(int des,int weight){
   Node temp;
   temp.des = des;
   temp.weight = weight;
   return temp;
}
public:
    void Push_value(int scr , int des , int weight){
          if(Graph.find(scr) == Graph.end()){
             Node temp = CreateNode(des,weight);
             vector<Node> Temp1;
             Temp1.push_back(temp);
             Graph[scr] = Temp1;
          }
         else{
              Node temp = CreateNode(des,weight);
              vector<Node>& X = Graph[scr];
              X.push_back(temp);
          }
    }

  void ReadFile(string splitter){
    ifstream input;
    input.open("GraphForDijistra.txt");
    string s;
    while (getline(input,s)) {
      int Scr,Des,Weight;
      int index = s.find_first_of(splitter);
      string Currentscr = s.substr(0,index);
      string RestVertxes = s.substr(index+1,s.length()-1);
      while (RestVertxes.length() > 0) {
          int index1 = RestVertxes.find_first_of(splitter);
              string CurrentComponent = RestVertxes.substr(0,index1);
              RestVertxes = RestVertxes.substr(index1+1,RestVertxes.length() - 1);
              int indexOfComma = CurrentComponent.find_first_of(",");
              string desVertex = CurrentComponent.substr(0,indexOfComma);
              string weight = CurrentComponent.substr(indexOfComma+1,CurrentComponent.length() - 1);
              stringstream stoi(Currentscr);
              stoi >> Scr;
              stringstream stoi1(desVertex);
              stoi1 >> Des;
              stringstream stio2(weight);
              stio2 >> Weight;
              Push_value(Scr,Des,Weight);
      }
    }
  }

void Print_Vertex_and_distance(){
  unordered_map<int,int>::iterator it;
  cout<<endl;
      for(it = Vertex_Distance.begin() ; it != Vertex_Distance.end() ; it++){
          cout<<"("<<it->first<<" ";
          cout<<it->second<<")";
          cout<<endl;
      }
 }
  void print(){
  unordered_map<int ,vector<Node> >::iterator it;
   for(it = Graph.begin() ; it != Graph.end() ;it++){
       cout<<it->first<<":-"<<endl;
       for( int i = 0 ; i < it->second.size() ; i++){
           cout<<"   "<<"("<<it->second[i].des;
           cout<<","<<it->second[i].weight<<")";
           if(i != it->second.size()-1)
           cout<<",";
       }
       cout<<endl;
   }
}


void initialize(){
  Heap.initialize(Graph);
}

bool isDone(int vertex){
   return (Vertex_Distance.find(vertex) == Vertex_Distance.end())? false:true;
}

void UpdateVertex_Distance(pair<int,int> VertexDistance){
  Vertex_Distance[VertexDistance.first] = VertexDistance.second;
}

void FindPathByDijistra(int StartVertex){
    int IndexOfStartVertex = Heap.Index_of(StartVertex);
    cout<<IndexOfStartVertex<<endl;
    Heap.UpdateHeapAt(IndexOfStartVertex,0);
    while(!Heap.isempty()){
      pair<int,int> NextVertex = Heap.get_min();
      UpdateVertex_Distance(NextVertex);
      vector<Node>& CurrentVertices = Graph[NextVertex.first];
      vector<Node>::iterator it;
      for(it = CurrentVertices.begin() ; it != CurrentVertices.end() ; it++) {
        if(!isDone(it->des)){
          int GreedyScore = NextVertex.second + it->weight;
          int index = Heap.Index_of(it->des);
          if(Heap.CurrenetGreedyScoreOf(index) > GreedyScore){
              Heap.UpdateHeapAt(index,GreedyScore);
          }
        }
      }
  }
Print_Vertex_and_distance();
}

};
int main(){
  Graphs graph;
  graph.ReadFile("\t");
  graph.initialize();
  graph.FindPathByDijistra(1);
}
