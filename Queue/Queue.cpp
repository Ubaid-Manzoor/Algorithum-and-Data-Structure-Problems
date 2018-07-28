#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;
};
class Arr_Queue{
private:
  int queue[10];
  int front;
  int size;
public:
  Arr_Queue(){
    front = 0;
    size = 0;
  }
  void enqueue(int a){
    int position = (front+size)%10;
    queue[position] = a;
    size++;
  }
  int dequeue(){
    int temp = queue[front];
    size--;
    front = (front + 1)%10;
    return temp;
  }
  void PrintQueue(){
    for(int i = front ; i < size+front ; i++){
      int index = i%10;
      cout<<queue[index]<<"  ";
    }
    cout<<endl;
  }
};
int main(){
  Arr_Queue Q;
  Q.enqueue(1);
  Q.enqueue(2);
  Q.enqueue(3);
  Q.enqueue(4);
  Q.PrintQueue();
  Q.dequeue();
  Q.PrintQueue();
  Q.dequeue();
  Q.PrintQueue();
  Q.dequeue();
  Q.PrintQueue();
}
