#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Graph;
struct Node{
    int vertex;
    struct Node *next;
};
class Graph{
private:
    int V;
    int E;
    vector<struct Node*> G;
public:
Graph(int v,int e){
    V = v;
    E = e;
    G.reserve(V);
    while(v != 0){
        G[V] = nullptr;
        v--;
    }
}
void Push_Edge(int scr,int des){
    struct Node* Temp = new struct Node;
    Temp->next = NULL;
    Temp->vertex = des;
    struct Node* temp = G[scr];
    //To Put Element in Graph
    if(temp == NULL){
        G[scr] = Temp;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
            }
            temp->next = Temp;
        }
    }
void Print(){
    for(int i = 0 ; i < V ; i++){
        struct Node* temp = G[i];
        cout<<i<<":-  (";
        while(temp != NULL){
            cout<<temp->vertex;
            temp = temp->next;
            if(temp !=NULL){
                cout<<",";
            }
        }
        cout<<")"<<endl;
    }
}
};

int main(){
  Graph graph(4,5);
  graph.Push_Edge(1,3);
  graph.Push_Edge(2,3);
  graph.Push_Edge(3,1);
  graph.Push_Edge(1,0);
  graph.Push_Edge(0,3);
  graph.Print();
}
