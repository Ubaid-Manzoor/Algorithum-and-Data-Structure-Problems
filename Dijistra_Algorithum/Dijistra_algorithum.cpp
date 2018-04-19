#include<iostream>
#include<vector>
#include<unordered_map>
#define INF 999999999
using namespace std;

class Node{
public:
    char Des;
    char Scr;
    int Weight;
};
class Min_Heap{
        private:
            vector<pair<char,int> > Heap;
            unordered_map<char,int> Vertex_and_Index;
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
        void Swap(pair<char,int>& a , pair<char,int>& b){
            pair<char,int> c;
            c = a;
            a = b;
            b = c;
        }
        void HeapifyDown(){
            int index = 0;
            while(FirstChildExit(index) || SecondChildExit(index)){
                if((SecondChildExit(index) && (FirstChildExit(index)== -1))  && Heap[SecondChildExit(index)].second  < Heap[index].second ){
                        Swap(Heap[SecondChildExit(index)],Heap[index]);
                        Update_VertexAndIndex(SecondChildExit(index),index);
                        index = SecondChildExit(index);
                        return;
                }
                else if(FirstChildExit(index)&& (SecondChildExit(index) == -1) && Heap[FirstChildExit(index)].second  < Heap[index].second ){
                        Swap(Heap[FirstChildExit(index)],Heap[index]);
                        Update_VertexAndIndex(FirstChildExit(index),index);
                        index = FirstChildExit(index);
                        return;
                }
                else{
                        if((Heap[FirstChildExit(index)].second  > Heap[SecondChildExit(index)].second ) &&  Heap[SecondChildExit(index)].second  < Heap[index].second ){
                                Swap(Heap[SecondChildExit(index)],Heap[index]);
                                Update_VertexAndIndex(SecondChildExit(index),index);
                                index = SecondChildExit(index);
                                return;
                        }
                        else if((Heap[FirstChildExit(index)].second  < Heap[SecondChildExit(index)].second ) &&  Heap[FirstChildExit(index)].second  < Heap[index].second ){
                                Swap(Heap[FirstChildExit(index)],Heap[index]);
                                Update_VertexAndIndex(FirstChildExit(index),index);
                                index = FirstChildExit(index);
                        }
                }
                return;
            }
        }
        public:
            void HeapifyUp(int indx){
                int index  = indx;
                while(hasParent(index) && Heap[ParentIndex(index)].second > Heap[index].second){
                    Swap(Heap[ParentIndex(index)],Heap[index]);
                    Update_VertexAndIndex(ParentIndex(index),index);
                    index = ParentIndex(index);
                }
            }
            void insert(char vertex,int value){
                pair<char,int> temp;
                temp.first = vertex;
                temp.second = value;
                Heap.push_back(temp);
                HeapifyUp(Heap.size());
            }
            void Update(int a,int b){
                Vertex_and_Index[Heap[a].first] = b;
                Vertex_and_Index[Heap[b].first] = a;
            }
            pair<char,int> get_min(){
                pair<char,int> temp;
                temp.first = Heap[0].first;
                temp.second = Heap[0].second;
                Heap[0] = Heap[Heap.size() - 1];
                Vertex_and_Index.erase(temp.first);
                Vertex_and_Index[Heap[0].first] = 0;
                Heap.pop_back();
                HeapifyDown();
                return temp;
            }
            void Print_Heap(){
                vector<pair<char,int> >::iterator it;
                for(it = Heap.begin() ; it != Heap.end() ; it++){
                    cout<<"("<<it->first<<",";
                    cout<<it->second<<")"<<" ";
                }
                cout<<endl;
            }
            void initialize_Heap(unordered_map<char , vector<Node> >::iterator it_begin ,unordered_map<char , vector<Node> >::iterator it_end){
                unordered_map<char , vector<Node> >::iterator it;
                for(it = it_begin ; it != it_end ; it++){
                    pair<char,int> temp;
                    temp.first = it->first;
                    temp.second = INF;
                    Heap.push_back(temp);
                }
            }
            void Update_at(int index,int value){
                pair<char,int> temp;
                temp = Heap[index];
                temp.second = value;
                Heap[index] = temp;
            }
            int find_index_of(char vertex){
                return Vertex_and_Index[vertex];
            }
            void Update_VertexAndIndex(int a,int b){
                Vertex_and_Index[Heap[a].first] = a;
                Vertex_and_Index[Heap[b].first] = b;
            }
            void Set_Vertex_and_Index(unordered_map<char , vector<Node> >::iterator it_begin ,unordered_map<char , vector<Node> >::iterator it_end){
                unordered_map<char , vector<Node> >::iterator it;
                int i = 0;
                for(it = it_begin ; it != it_end ;it++,i++){
                    Vertex_and_Index[it->first] = i;
                }
                Print_VertexAndIndex();
            }
            void Print_VertexAndIndex(){
                unordered_map<char ,int >::iterator it1;
                cout<<endl;
                for(it1 = Vertex_and_Index.begin() ; it1 != Vertex_and_Index.end() ;it1++){
                    cout<<it1->first<<" ";
                    cout<<it1->second<<endl;
                }
            }
            int Current_Score(char vertex){
                return Heap[Vertex_and_Index[vertex]].second;
            }
            bool isempty(){
                return Heap.empty();
            }
    };

//================================================================
//================================================================
//================================================================


class Graphs{
private:

         unordered_map<char,int> Vertex_and_distance;
         unordered_map<char , vector<Node> > Graph;
         Min_Heap heap;
         struct Node CreateNode(char scr,char des,int weight){
            Node temp;
            temp.Des = des;
            temp.Weight = weight;
            temp.Scr = scr;
            return temp;
         }
         pair<char,int> Update_VertexAndDistance(){
                pair<char,int> temp = heap.get_min();
                Vertex_and_distance.insert(temp);
                return temp;
         }

public:
                int isDone(char vertex){
                   return (Vertex_and_distance.find(vertex) == Vertex_and_distance.end())? 0:1;
                }
                void Print_Vertex_and_distance(){
                unordered_map<char,int>::iterator it;
                cout<<endl;
                    for(it = Vertex_and_distance.begin() ; it != Vertex_and_distance.end() ; it++){
                        cout<<"("<<it->first<<" ";
                        cout<<it->second<<")";
                    }
                }
                 void Push_value(char scr , char des ,int weight){
                     if(Graph.find(scr) == Graph.end()){//For first element
                        Node temp1 = CreateNode(scr,des,weight);
                        vector<Node> Temp1;
                        Temp1.push_back(temp1);
                        Graph[scr] = Temp1;
                        //TO MAKE GRAPH UNDIRECTED
                        Node temp2 = CreateNode(des,scr,weight);
                        vector<Node> Temp2;
                        Temp2.push_back(temp2);
                        Graph[des] = Temp2;
                    }
                    else{//for rest elements
                         Node temp1 = CreateNode(scr,des,weight);
                         vector<Node>& X = Graph[scr];
                         X.push_back(temp1);
                        //TO MAKE GRAPH UNDIRECTED
                        Node temp2 = CreateNode(des,scr,weight);
                        vector<Node>& Y = Graph[des];
                        Y.push_back(temp2);
                     }
                 }
                 void print(){
                 unordered_map<char ,vector<Node> >::iterator it;
                    for(it = Graph.begin() ; it != Graph.end() ;it++){
                        cout<<it->first<<":-";
                        for( int i = 0 ; i < it->second.size() ; i++){
                            cout<<"   "<<"("<<it->second[i].Des;
                            cout<<","<<it->second[i].Weight<<")";
                            if(i != it->second.size()-1)
                            cout<<",";
                        }
                        cout<<endl;
                    }
                 }
                 void initialize(){
                     unordered_map<char ,vector<Node> >::iterator it_begin;
                     unordered_map<char ,vector<Node> >::iterator it_end;
                     it_begin = Graph.begin();
                     it_end = Graph.end();
                     heap.initialize_Heap(it_begin,it_end);
                     heap.Set_Vertex_and_Index(it_begin,it_end);
                     heap.Print_Heap();
                 }
                 void For_Source(char source){
                    int index = heap.find_index_of(source);
                    heap.Update_at(index,0);
                    heap.HeapifyUp(index);
                 }
                void Dijistra_Algorithum(char source){
                    initialize();
                    For_Source(source);
                    while(!heap.isempty()){
                        pair<char,int> current = Update_VertexAndDistance();
                        vector<Node> neighbours = Graph[current.first];
                        vector<Node>::iterator it;
                        for(it = neighbours.begin() ; it != neighbours.end() ; it++){
                            int DG_Score = current.second + it->Weight;
                            if(!isDone(it->Des) && DG_Score < heap.Current_Score(it->Des)){
                                heap.Update_at(heap.find_index_of(it->Des),DG_Score);
                                heap.HeapifyUp(heap.find_index_of(it->Des));
                            }
                        }
                    }
                    Print_Vertex_and_distance();
                }
        };

//================================================================
//================================================================
//================================================================
int main(){
    Graphs graph;
    graph.Push_value('a','b',8);
    graph.Push_value('a','c',4);
    graph.Push_value('c','d',8);
    graph.Push_value('b','e',7);
    graph.Push_value('b','f',1);
    graph.Push_value('c','b',11);
    graph.Push_value('e','d',2);
    graph.Push_value('e','f',6);
    graph.Push_value('f','g',2);
    graph.Push_value('d','g',4);
    graph.Push_value('d','i',7);
    graph.Push_value('g','i',14);
    graph.Push_value('h','i',9);
    graph.Push_value('g','h',10);
    graph.print();
    graph.Dijistra_Algorithum('a');
}

