//insert()
//get_min()
//Print_Heap()
//isempty()

#ifndef MinHeap_H
#define MinHeap_H
#define INF 1000000

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
  int des;
  int weight;
};

class MinHeap{


private:
    vector<pair<int,int> > Heap;
    unordered_map<int,int> Vertex_and_Index;
bool hasParent(int index){
    return (ParentIndex(index) < 0) ? false : true;
}
bool FirstChildExit(int Parentindex){
    return ( (Parentindex*2 + 1) < Heap.size()) ?  true : false;
}
bool SecondChildExit(int Parentindex){
   return ( (Parentindex*2 + 2) < Heap.size())?  true : false;
}
int FirstChildindex(int Parentindex){
    return Parentindex*2 + 1;
}
int SecondChildindex(int Parentindex){
   return Parentindex*2 + 2;
}
int ParentIndex(int index){
    return (index-1)/2;
}
void Swap(pair<int,int>& a , pair<int,int>& b){
  UpdateVertexIndex(Vertex_and_Index[a.first],Vertex_and_Index[b.first]);
    pair<int,int> c;
    c = a;
    a = b;
    b = c;
}
void HeapifyUp(int index){
    while(hasParent(index) && Heap[ParentIndex(index)].second > Heap[index].second){
        Swap(Heap[ParentIndex(index)],Heap[index]);
        index = ParentIndex(index);
    }
}
void HeapifyDown(int index){
    while(FirstChildExit(index)){
      int SmallChildIndex = FirstChildindex(index);
      if(Heap[SecondChildindex(index)].second < Heap[FirstChildindex(index)].second){
        SmallChildIndex = SecondChildindex(index);
      }
      if(Heap[index].second < Heap[SmallChildIndex].second){
        break;
      }else{
        Swap(Heap[SmallChildIndex],Heap[index]);
      }
      index = SmallChildIndex;
    }
}

public:
  int Index_of(int StartVertex){
    return Vertex_and_Index[StartVertex];
  }

  void UpdateHeapAt(int index,int CurrentScore){
    pair<int,int> temp;
    temp = Heap[index];
    temp.second = CurrentScore;
    Heap[index] = temp;

    Swap(Heap[index],Heap[Heap.size() - 1]);

    HeapifyDown(index);
    HeapifyUp(Heap.size() - 1);
  }

  int CurrenetGreedyScoreOf(int index){
      return Heap[index].second;
  }
  void Print_VertexAndIndex(){
      unordered_map<int ,int >::iterator it1;
      cout<<endl;
      for(it1 = Vertex_and_Index.begin() ; it1 != Vertex_and_Index.end() ;it1++){
          cout<<it1->first<<" ";
          cout<<it1->second<<endl;
      }
  }

  void Print_Heap(){
       vector<pair<int,int> >::iterator it;
       for(it = Heap.begin() ; it != Heap.end() ; it++){
           cout<<"("<<it->first<<",";
           cout<<it->second<<")"<<" ";
           cout<<endl;
       }
       cout<<endl;
  }

  void initialize(unordered_map<int,vector<Node> >& graph){
    unordered_map<int , vector<Node> >::iterator it;
    int i = 0;
    for(it = graph.begin() ; it != graph.end() ; it++,i++){
        pair<int,int> temp;
        pair<int,int> temp1;
        temp.first = it->first;
        temp1.first = it->first;
        temp.second = INF;
        temp1.second = i;
        Heap.push_back(temp);
        Vertex_and_Index.insert(temp1);
    }
    // Print_VertexAndIndex();
    // Print_Heap();
  }
  void insert(int vertex,int value){
    pair<int,int> temp;
    temp.first = vertex;
    temp.second = value;
    Heap.push_back(temp);
    HeapifyUp(Heap.size() - 1);
}
void UpdateVertexIndex(int a,int b){
    Vertex_and_Index[Heap[a].first] = b;
    Vertex_and_Index[Heap[b].first] = a;
}
pair<int,int> get_min(){
    pair<int,int> temp;
    temp.first = Heap[0].first;
    temp.second = Heap[0].second;
    Heap[0] = Heap[Heap.size() - 1];
    Vertex_and_Index.erase(temp.first);
    Vertex_and_Index[Heap[0].first] = 0;
    Heap.pop_back();
    HeapifyDown(0);
    return temp;
}
void Print(){
      if(isempty()){
        cout<<endl<<"Heap is Empty"<<endl;
        return;
      }
      vector<pair<int,int> >::iterator it;
      for(it = Heap.begin() ; it != Heap.end() ; it++){
          cout<<"("<<it->first<<",";
          cout<<it->second<<")"<<" ";
      }
      cout<<endl;
}
    bool isempty(){
      return Heap.empty();
    }
};

#endif
