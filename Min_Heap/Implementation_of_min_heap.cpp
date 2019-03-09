#include<iostream>
#include<vector>
using namespace std;
class MinHeap{


private:
    vector<int> Heap;
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
void Swap(int &a , int &b){
    int c;c = a;a = b;b = c;
}
void HeapifyUp(){
    int index  = Heap.size() - 1;
    while(hasParent(index) && Heap[ParentIndex(index)] > Heap[index]){
        Swap(Heap[ParentIndex(index)],Heap[index]);
        index = ParentIndex(index);
    }
}
void HeapifyDown(){
    int index = 0;
    while(FirstChildExit(index)){
      int SmallChildIndex = FirstChildindex(index);
      if(Heap[SecondChildindex(index)] < Heap[FirstChildindex(index)]){
        SmallChildIndex = SecondChildindex(index);
      }
      if(Heap[index] < Heap[SmallChildIndex]){
        break;
      }else{
        Swap(Heap[SmallChildIndex],Heap[index]);
      }
      index = SmallChildIndex;
    }
}


public:
    void insert(int value){
        Heap.push_back(value);
        HeapifyUp();
    }
    int get_min(){
      if(isempty()){
        cout<<endl<<"Heap is empty->";
        return 0;
      }
        int Min = Heap[0];
        Heap[0] = Heap[Heap.size() - 1];
        Heap.pop_back();
        HeapifyDown();
        return Min;
    }
    void Print(){
        vector<int>::iterator it;
        for(it = Heap.begin() ; it != Heap.end() ; it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    bool isempty(){
      return Heap.empty();
    }
};
int main(){
    MinHeap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(6);
    heap.insert(100);
    heap.insert(1);
    heap.insert(0);
    heap.Print();
   int min  =  heap.get_min();
   heap.Print();
   cout<<min;
}
