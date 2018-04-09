#include<iostream>
#include<vector>
using namespace std;
class Min_Heap{
private:
    vector<int> Heap;
bool hasParent(int index){
    return (ParentIndex(index) < 0) ? false : true;
}
int FirstChildExit(int Parentindex){
    return ( (Parentindex*2 + 1) < Heap.size())?  (Parentindex*2 + 1) : -1;
}
int SecondChildExit(int Parentindex){
   return ( (Parentindex*2 + 2) < Heap.size())?  (Parentindex*2 + 2) : -1;
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
    while(FirstChildExit(index) || SecondChildExit(index)){
        if((SecondChildExit(index) && FirstChildExit(index)) == -1 && Heap[SecondChildExit(index)] < Heap[index]){
                Swap(Heap[SecondChildExit(index)],Heap[index]);
                index = SecondChildExit(index);
                return;
        }
        else if(FirstChildExit(index)&& (SecondChildExit(index) == -1) && Heap[FirstChildExit(index)] < Heap[index]){
                Swap(Heap[FirstChildExit(index)],Heap[index]);
                index = FirstChildExit(index);
                return;
        }
        else{
                if((Heap[FirstChildExit(index)] > Heap[SecondChildExit(index)]) &&  Heap[SecondChildExit(index)] < Heap[index]){
                        Swap(Heap[SecondChildExit(index)],Heap[index]);
                        index = SecondChildExit(index);
                        return;
                }
                else if((Heap[FirstChildExit(index)] < Heap[SecondChildExit(index)]) &&  Heap[FirstChildExit(index)] < Heap[index]){
                        Swap(Heap[FirstChildExit(index)],Heap[index]);
                        index = FirstChildExit(index);
                }
        }
    }
}
public:
    void insert(int value){
        Heap.push_back(value);
        HeapifyUp();
    }
    int get_min(){
        int Min = Heap[0];
        Heap[0] = Heap[Heap.size() - 1];
        Heap.pop_back();
        HeapifyDown();
        return Min;
    }
    void Print_Heap(){
    vector<int>::iterator it;
    for(it = Heap.begin() ; it != Heap.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
};
int main(){
    Min_Heap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(6);
    heap.insert(100);
    heap.insert(1);
    heap.insert(0);
    heap.Print_Heap();
   int min  =  heap.get_min();
   heap.Print_Heap();
   cout<<min;
}
