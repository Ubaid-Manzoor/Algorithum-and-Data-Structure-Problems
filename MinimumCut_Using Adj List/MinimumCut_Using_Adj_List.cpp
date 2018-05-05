#include<iostream>
#include <string>
#include <iterator>
#include<fstream>
#include<vector>
#include <sstream>
#include<unordered_map>
#include<set>
#define INF 100000
using namespace std;
class Node{
public:
    int Des;
    int Scr;
};
class Graphs{
private:
         unordered_map<int , vector<int> > Graph;
         vector<Node> Edges;
         int MinimalCut;
         int N;
public:
    Graphs(){
        MinimalCut = INF;
    }
         Node CreateNode(int scr,int des){
            Node temp;
            temp.Des = des;
            temp.Scr = scr;
            return temp;
         }
         void Push_value(int scr , int des){
             if(Graph.find(scr) == Graph.end()){
//                Node temp1 = CreateNode(scr,des);
                vector<int> Temp1;
                Temp1.push_back(des);
                Graph[scr] = Temp1;
            }
            else{
//                Node temp1 = CreateNode(scr,des);
                 vector<int>& X = Graph[scr];
                 X.push_back(des);
             }
         }
void print(){
    unordered_map<int ,vector<int> >::iterator it;
        for(it = Graph.begin() ; it != Graph.end() ;it++){
            cout<<it->first<<":- "<<endl;
                for( int i = 0 ; i < it->second.size() ; i++){
                        cout<<it->second[i]<<" ";
                    }
                    cout<<endl;
        }
}
void ReadFile(){
     set<pair<int,int> > HelperEdge;
    vector<int> vertex;
    int index;
    ifstream input;
    string s;
    input.open("GraphVertexs.txt");
    while(getline(input,s)){
        int mark = 0,scr,des;
        while(s.length() > 1){
            index = s.find_first_of("\t");
            string number = s.substr(0,index);
            if(mark == 0){
                stringstream stoi(s);
                stoi>>scr;
                mark = 1;
                 string sub = s.substr(index+1,s.length()-1);
                 s = sub;
                continue;
            }
            stringstream stoi(s);
            stoi>>des;
            pair<int,int> t;
            t.first = scr;
            t.second = des;
            pair<int,int> t_reverse;
            t_reverse.second = scr;
            t_reverse.first = des;
            if((HelperEdge.find(t_reverse) == HelperEdge.end())){
                Node temp = CreateNode(scr,des);
                Edges.push_back(temp);//push in vector of edges;
            }
            HelperEdge.insert(t);
            Push_value(scr,des);//push to Graph
            string sub = s.substr(index+1,s.length()-1);
            s = sub;
        }
        cout<<endl;
      }
}
//void PrintEdges(){
//    vector<Node>::iterator it;
//    for(it = Edges.begin() ; it != Edges.end() ; it++){
//        cout<<it->Scr<<" "<<it->Des<<endl;
//    }
//    cout<<Edges.size()<<endl;
//}
Node Get_Random_Edge(){
    srand(time(NULL));
	int index=rand()%(Edges.size());
	Node temp = Edges[index];
	vector<Node>::iterator it;
	for(it = Edges.begin() ; it != Edges.end() ; it){
        if((it->Scr == temp.Scr && it->Des == temp.Des) || (it->Des == temp.Scr && it->Scr == temp.Des)){
            *it = Edges[Edges.size() - 1];
             Edges.pop_back();
             continue;
        }
        if(it->Scr == temp.Des){
            it->Scr = temp.Scr;
        }
        else if(it->Des == temp.Des){
            it->Des = temp.Scr;
        }
        it++;
	}
    return temp;
}
void Delete_Des_Vertex(Node Temp){
    vector<int>& CurrentVertex = Graph[Temp.Scr];
    vector<int>::iterator it;
    for(it = CurrentVertex.begin() ; it != CurrentVertex.end() ;it){
        if(*it == Temp.Des){
            *it = CurrentVertex[CurrentVertex.size() - 1];
            CurrentVertex.pop_back();
            continue;
        }
        it++;
    }
    vector<int>& CV = Graph[Temp.Des];
    for(it = CV.begin() ; it != CV.end() ; it){
        if(*it == Temp.Scr){
            *it = CV[CV.size() - 1];
            CV.pop_back();
            continue;
        }
        it++;
    }
}
int HelperMinCut(){
    N = 0;
    while(Graph.size()>2){
        Node Random_Edge = Get_Random_Edge();
        vector<int>& CurrentVertex = Graph[Random_Edge.Scr];
        vector<int>& CV = Graph[Random_Edge.Des];
        Delete_Des_Vertex(Random_Edge);//For 1->2 Delete Two from 1's verticies & ViceVersa
        vector<int>::iterator it;
        for(it = CV.begin() ; it != CV.end() ; it++){
            vector<int>& CurrentVertex1 = Graph[*it];
            vector<int>::iterator it1;
            for(it1 = CurrentVertex1.begin() ; it1 != CurrentVertex1.end() ;it1++){
                if(*it1 == Random_Edge.Des){
                    *it1 = Random_Edge.Scr;
                }
            }
            CurrentVertex.push_back(*it);
        }
        Graph.erase(Random_Edge.Des);
    }
    Node LeftEdge = Edges[0];
    return Graph[LeftEdge.Scr].size();
}
int GetMinCut(){
    //Do it N^2*logn Time To get the Correct Result And Remember the Smallest
    for(int i = 0 ; i < 1000 ; i++){
        Graph.clear();
        ReadFile();
        int Cut = HelperMinCut();
        cout<<Cut<<endl;
        if(Cut < MinimalCut){
            MinimalCut = Cut;
        }
    }
    return MinimalCut;
}
};
int main(){
    Graphs graph;
    int MinCut = graph.GetMinCut();
    cout<<MinCut<<endl;
    graph.print();
}
