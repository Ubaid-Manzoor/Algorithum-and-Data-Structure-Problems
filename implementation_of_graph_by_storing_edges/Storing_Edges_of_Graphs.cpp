#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Graph{
private:
    vector<pair<char,char> > Edges;
public:
void push_edge(char scr, char des){
    pair<char,char> edge;
    edge.first = scr;
    edge.second = des;
    Edges.push_back(edge);
}
void print_edges(){
    vector<pair<char,char> >::iterator it;
    cout<<"===========>Edges in Graph<==========="<<endl;
    for(it = Edges.begin() ; it < Edges.end() ; it++){
        cout<<"("<<it->first<<",";
        cout<<it->second<<")"<<endl;
    }
}
};
int main(){
    Graph graph;
    graph.push_edge('a','b');
    graph.push_edge('a','c');
    graph.push_edge('b','c');
    graph.push_edge('c','d');
    graph.push_edge('b','d');
    graph.push_edge('c','a');
    graph.print_edges();
}

