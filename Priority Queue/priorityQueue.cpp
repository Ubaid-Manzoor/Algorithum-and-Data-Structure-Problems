#include<iostream>
using namespace std;
class item{
public:
  int priority;
  int data;
};
class PriQueue{
private:
  item Pqueue[100];
  int front;
  int size;
public:
  int getindexof(int a){
    for(int i = front ; i < size+front ; i++ ){
      int Psedoindex = i;
      int index = Psedoindex%100;
      if(a < Pqueue[index].priority){
        return Psedoindex;
      }
    }
  }
  PriQueue(){
    front = 0;
    size = 0;
  }
  void enqueue(int pri,int data){
    if(size >= 100){
      cout<<"Queue is Full";
      return;
    }
    int Psedoindex = getindexof(pri);
    int index = Psedoindex%100;
    cout<<"|"<<index<<"|";
    for(int i = front+size-1 ; i >= Psedoindex ; i--){
      int index = i%100;
      Pqueue[index+1] = Pqueue[index];
    }
    Pqueue[index].data = data;
    Pqueue[index].priority = pri;
    size++;
  }
  int dequeue(){
    int temp = Pqueue[front].data;
    front++;
    size--;
    return temp;
  }
  void PrintQueue(){
    for(int i = front ; i < size+front ; i++){
      int index = i%100;
      cout<<Pqueue[index].data<<"  ";
    }
    cout<<endl;
  }
};
int main(){
  PriQueue Q;
  Q.enqueue(1,22);
  Q.enqueue(2,221);
  Q.enqueue(-1,222);
  Q.enqueue(4,212);
  Q.enqueue(0,2112);
  Q.enqueue(11,2122);
  Q.enqueue(22,2221);
  Q.enqueue(-13,21122);
  Q.enqueue(-4,213332);
  Q.enqueue(111,2112112);
  Q.PrintQueue();
  cout<<(Q.dequeue());
  cout<<endl;
  Q.PrintQueue();
}
