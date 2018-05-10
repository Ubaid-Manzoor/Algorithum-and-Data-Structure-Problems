#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<queue>
#include <sstream>
#include <iterator>
using namespace std;
class Graphs{
private:
    unordered_map<int,vector<int> > Graph;
    unordered_map<int,bool> marked;
    unordered_map<int,vector<int>> Component_Map;
    queue<int> Q;
    int N;
public:
    void Push_value(int scr , int des){
        if(Graph.find(scr) == Graph.end()){
            vector<int> Temp1;
            Temp1.push_back(des);
            Graph[scr] = Temp1;
        }
        else{
            vector<int>& X = Graph[scr];
            X.push_back(des);
        }
    }
    void ReadFile(){
        vector<int> vertex;
        int index;
        ifstream input;
        string s;
        input.open("GraphVertexs.txt");
        while(getline(input,s)){
            int mark = 0,scr,des;
            while(s.length() > 0){
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
                Push_value(scr,des);//push to Graph
                string sub = s.substr(index+1,s.length()-1);
                s = sub;
            }
        }
    }
    void print(){
        unordered_map<int ,vector<int> >::iterator it;
        for(it = Graph.begin() ; it!= Graph.end() ; it++){
            cout<<it->first<<":- ";
            for( int i = 0 ; i < it->second.size() ; i++){
                cout<<it->second[i]<<" ";
            }
            cout<<endl;
        }
    }
    void markallVerticesUnvisited(){
        unordered_map<int,vector<int> >::iterator it;
        for(it = Graph.begin() ; it != Graph.end() ; it++){
            pair<int,bool> temp;
            temp.first = it->first;
            temp.second = false;
            marked.insert(temp);
        }
    }
    void BFS(int sourceVertex){
        markallVerticesUnvisited();
        Q.push(sourceVertex);
        marked[sourceVertex] = true;
        while(!Q.empty()) {
            int CurrentVertex = Q.front();
            Q.pop();
            vector<int>& RelatedVerticies = Graph[CurrentVertex];
            vector<int>::iterator it;
            for(it = RelatedVerticies.begin() ; it != RelatedVerticies.end() ; it++){
                if(marked[*it] == false){
                    marked[*it] = true;
                    Q.push(*it);
                }
            }
            pair<int,vector<int>> temp;
            temp.first = N;
            Component_Map.insert(temp);
            vector<int>& CurrentVector = Component_Map[N];
            CurrentVector.push_back(CurrentVertex);
        }
        N++;
    }
void GetComponents(){
    N = 1;
    unordered_map<int,vector<int> >::iterator it;
    for(it = Graph.begin() ; it != Graph.end() ; it++){
        if(marked[it->first] == false){
          BFS(it->first);
        }
      }
    }
  void PrintComponents(){
    unordered_map<int,vector<int>>::iterator it;
    for(it = Component_Map.begin() ; it != Component_Map.end() ; it++){
      cout<<it->first<<"->";
      vector<int>::iterator it1;
      for(it1= it->second.begin() ; it1 != it->second.end(); it1++){
          cout<<*it1<<" ";
      }
      cout<<endl;
    }
  }
};
int main(){
    int sourceVertex;
    sourceVertex = 1;
    Graphs graph;
    graph.ReadFile();
    // graph.print();
    graph.GetComponents();
    graph.PrintComponents();
}
