#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<set>
#include<sstream>
#include<set>
#include<string>
#include "MinHeap.h"
using namespace std;

class Graphs{
private:
    unordered_map<int,vector<Node> > Graph;
    MinHeap Heap;
    unordered_map<int,string> Vertex_Edge;
    set<int> visited;
    int Edges,Vertices;
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
             // TO MAKE GRAPH UNDIRECTED
             Node temp2 = CreateNode(scr,weight);
             vector<Node> Temp2;
             Temp2.push_back(temp2);
             Graph[des] = Temp2;
          }
         else{
              Node temp = CreateNode(des,weight);
              vector<Node>& X = Graph[scr];
              X.push_back(temp);
              // TO MAKE GRAPH UNDIRECTED
              Node temp2 = CreateNode(scr,weight);
              vector<Node>& Y = Graph[des];
              Y.push_back(temp2);
          }
    }
  void ReadFile(){
    ifstream input;
    input.open("PrimsGraph.txt");
    input >> Vertices >> Edges;
    int scr,des,weight;
    while(input >>scr >>des >>weight){
        Push_value(scr,des,weight);
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
   return ( visited.find(vertex) == visited.end() ) ? false : true;
}
int ChoseStartVertex(){
    unordered_map<int,vector<Node> >::iterator it;
    it = Graph.begin();
    return it->first;
}
void UpdateVertexEdge_at(int Vertex_des , int Vertex_scr){
    string des = to_string(Vertex_des);
    string arrow = "->";
    string scr = to_string(Vertex_scr);
    string Edge = scr + arrow + des;
    Vertex_Edge[Vertex_des] = Edge;
    cout<<Edge<<endl;
}
void  PrintVertexEdge(){
  unordered_map<int,string>::iterator it;
  for(it = Vertex_Edge.begin() ; it != Vertex_Edge.end() ; it++){
    cout<<it->second<<endl;
  }
}
void PrimsMst(){
    initialize();
    int StartVertex = ChoseStartVertex();
    int IndexOfStartVertex = Heap.Index_of(StartVertex);
    Heap.UpdateHeapAt(IndexOfStartVertex,0);
    while(!Heap.isempty()){
      pair<int,int> NextVertex = Heap.get_min();
      visited.insert(NextVertex.first);
      vector<Node>& CurrentVertices = Graph[NextVertex.first];
      vector<Node>::iterator it;
      for(it = CurrentVertices.begin() ; it != CurrentVertices.end() ; it++) {
        if(!isDone(it->des)){
          int CurrentPathWeight = it->weight;
          int index = Heap.Index_of(it->des);
          if(Heap.CurrentPathWeight_of(index) > CurrentPathWeight){
              Heap.UpdateHeapAt(index,CurrentPathWeight);
            UpdateVertexEdge_at(it->des,NextVertex.first);
          }
        }
      }
  }
  PrintVertexEdge();
}

};
int main(){
  Graphs graph;
  graph.ReadFile();
  graph.print();
  graph.PrimsMst();
}
