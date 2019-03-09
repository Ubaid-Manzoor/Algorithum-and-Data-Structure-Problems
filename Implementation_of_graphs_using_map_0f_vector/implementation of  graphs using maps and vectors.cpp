#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
public:
    char Des;
    char Scr;
    int Weight;
};
class Graphs{
private:
         unordered_map<char , vector<Node> > Graph;
public:
         Node CreateNode(char scr,char des,int weight){
            Node temp;
            temp.Des = des;
            temp.Weight = weight;
            temp.Scr = scr;
            return temp;
         }
         void Push_value(char scr , char des ,int weight){
         if(Graph.find(scr) == Graph.end()){
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
        else{
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
};
int main(){
    Graphs graph;
    graph.Push_value('a','b',10);
    graph.Push_value('a','c',20);
    graph.Push_value('b','e',30);
    graph.Push_value('b','d',40);
    graph.Push_value('c','e',50);
    graph.Push_value('d','c',60);
    graph.print();
}
