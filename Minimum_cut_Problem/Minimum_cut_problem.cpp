#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Graph{
private:
    vector<pair<char,char> > Edges;
    unordered_set<char> Set_A;
    unordered_set<char> Set_B;
    vector<pair<char,char> > Merged_Edges;
    int E;
    int V;
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
void Push_Edge_in_Merged_List(pair<char,char> temp){
    cout<<endl<<"***"<<temp.first<<"   "<<temp.second<<endl;
    Merged_Edges.push_back(temp);
}
void  Push_vertex_in_Sets(pair<char,char> temp){
if(V > 2){
    if(Set_A.empty()){
        Set_A.insert(temp.first);
        Set_A.insert(temp.second);
    }
    else{
        if(Set_A.find(temp.first) != Set_A.end() || Set_A.find(temp.second) != Set_A.end()){
            Set_A.insert(temp.first);
            Set_A.insert(temp.second);
        }
        else{
            Set_B.insert(temp.first);
            Set_B.insert(temp.second);
        }
    }
}
else{
    if(Set_A.find(temp.first) != Set_A.end()){
        Set_B.insert(temp.second);
    }
    else{
         Set_A.insert(temp.first);
         Set_B.insert(temp.second);
    }
}
}
public:
Graph(int v,int e){
    V = v;
    E = e*2;
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
void print_Merged_Edges(){
     vector<pair<char,char> >::iterator it;
     cout<<"==========Merged_Edges==========="<<endl;
     for(it = Merged_Edges.begin(); it < Merged_Edges.end() ; it++){
        cout<<"("<<it->first<<"<-";
        cout<<it->second<<")"<<endl;
    }
}
void print_Set_A_and_B(){
    unordered_set<char>::iterator it;
    int i = 0;
    cout<<"===========Sets=============="<<endl;
    cout<<"(";
    for(it = Set_A.begin(); it != Set_A.end() ; it++,i++){
        cout<<*it;
        if(i < Set_A.size() - 1){
            cout<<",";
        }
    }
    cout<<") ->";
        cout<<"(";
    for(it = Set_B.begin(); it != Set_B.end() ; it++,i++){
        cout<<*it;
         if(i < Set_B.size() - 1){
            cout<<",";
        }
    }
    cout<<")"<<endl;
}
void minimum_cut(){
while(V > 2){
cout<<endl<<"E = "<<E<<endl;
        pair<char,char> temp = get_random_Edge();
        Push_Edge_in_Merged_List(temp);
        Push_vertex_in_Sets(temp);
        cout<<temp.first<<"  "<<temp.second<<endl;
        //For Loop to Pop The Edge Which is Chosed At Random
        for(int i = 0 ;i < E ; i++){
            pair<char,char> Temp = Edges[i];
            if((temp.first == Temp.first && temp.second == Temp.second) || (temp.first == Temp.second && temp.second == Temp.first)){
                swapEdges(i,E-1);
                i--;
            }
            cout<<endl<<"E ==== "<<E<<endl;
        }
        //For Loop To Change The Edges Attaches To B(Which is merged) To A(Whom which B is merged)
        for(int j = 0 ; j < E ; j++){
            if(Edges[j].first == temp.second){
                    Edges[j].first = temp.first;
            }
            else if(Edges[j].second == temp.second){
                    Edges[j].second = temp.first;
            }
            cout<<endl<<"j ===="<<j<<endl;
        }
        print_edges();
        V--;
    }
cout<<endl<<"Minimum is equal to >> "<<E/2<<endl;
cout<<"Edge Left  >> ("<<Edges[0].first<<"<->"<<Edges[0].second<<")"<<endl;

Push_vertex_in_Sets(Edges[0]);
}
};
int main(){
    int v,e;
    cout<<"Enter number of Vertex and Edges in Graph"<<endl;
    cin>>v>>e;
    Graph graph(v,e);
    graph.push_edge('a','b');
    graph.push_edge('a','d');
    graph.push_edge('a','c');
    graph.push_edge('c','d');
    graph.push_edge('d','b');
    graph.print_edges();
    graph.minimum_cut();
    graph.print_Merged_Edges();
    graph.print_Set_A_and_B();
}










