#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Graph{
private:
    vector<pair<char,char> > Edges;
    int E;
pair<char,char> get_random_Edge(){
    srand(time(NULL));
	int index=rand()%E;
	cout<<endl<<index<<endl;
	return Edges[index];
}
void swapEdges(int i,int j){
    Edges[i].first = Edges[j].first;
    Edges[i].second = Edges[j].second;
    Edges.pop_back();
    E--;
}
public:
Graph(int e){
    E = e;
}
void push_edge(char scr, char des){
    pair<char,char> edge;
    edge.first = scr;
    edge.second = des;
    Edges.push_back(edge);
    edge.second = scr;
    edge.first = des;
    Edges.push_back(edge);
}
void print_edges(){
    vector<pair<char,char> >::iterator it;
    int i = 1;
    cout<<"===========>Edges in Graph<==========="<<endl;
    for(it = Edges.begin(); it < Edges.end() ; it++,i++){
        cout<<i<<" "<<"("<<it->first<<",";
        cout<<it->second<<")"<<endl;
    }
}
void minimum_cut(){
while(E > 4){
cout<<"het";
    pair<char,char> temp = get_random_Edge();
    cout<<temp.first<<"  "<<temp.second<<endl;
    for(int i = 0 ;i < E ; i++){
        pair<char,char> Temp = Edges[i];
        if((temp.first == Temp.first && temp.second == Temp.second) || (temp.first == Temp.second && temp.second == Temp.first)){
            swapEdges(i,E-1);
            i--;
        }
    }
    for(int j = 0 ; j < E ; j++){
        if(Edges[j].first == temp.second){
                Edges[j].first = temp.first;
        }
        else if(Edges[j].second == temp.second){
                Edges[j].second = temp.first;
        }
    }
    print_edges();
}
}
};
int main(){
    int e;
    cout<<"Enter number of Edges in Graph"<<endl;
    cin>>e;
    Graph graph(2*e);
    graph.push_edge('a','b');
    graph.push_edge('a','d');
    graph.push_edge('a','c');
    graph.push_edge('c','d');
    graph.push_edge('d','b');
    graph.print_edges();
    graph.minimum_cut();
}










