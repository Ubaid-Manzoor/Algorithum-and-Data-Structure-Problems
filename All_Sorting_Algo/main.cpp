#include<iostream>
#include<vector>
using namespace std;
void PrintVector(vector<int> list){
  for(int i = 0 ; i < list.size() ; i++){
    cout<<i<<"->"<<list[i]<<endl;
  }
  cout<<"============================================"<<endl;
}
class Sort{
private:
public:
  int Max_Item(vector<int> list){
    int Max = 0;
    for(int i = 0 ; i < list.size() ; i++){
      if(list[i] > Max){
        Max = list[i];
      }
    }
    return Max;
  }
  vector<int> count_sort(vector<int> list){
    int Max = Max_Item(list) + 1;
    vector<int> count(Max,0);
    for(int i = 0 ; i < list.size() ; i++)
      count[list[i]]++;
    for(int i = 1 ; i < Max ; i++)
      count[i] = count[i] + count[i-1];
    for(int i = Max-1 ; i > 0  ; i--)
      count[i] =  count[i-1];
    count[0] = 0;
    vector<int> Sorted(list.size(),0);
    for(int i = 0 ; i < list.size() ; i++){
      Sorted[count[list[i]]] = list[i];
      count[list[i]]++;
    }
    return Sorted;
  }
  vector<int> insertion_sort(vector<int> list){
    for(int i = 1 ; i < list.size() ; i++){
      for(int j = i ; j > 0 ; j--){
        if(list[j] >= list[j-1]){break;}
          int temp = list[j];
          list[j] = list[j-1];
          list[j-1] = temp;
      }
    }
    return list;
  }
  vector<int> selection_sort(vector<int> list){
    for(int i = 0 ; i < list.size()-1 ; i++){
     int index = i;
     for(int j = i+1; j < list.size() ; j++){
       if(list[j] < list[index]){
         index = j;
       }
     }
     int temp = list[i];
     list[i] = list[index];
     list[index] = temp;
    }
    return list;
  }
  vector<int> shell_sort(vector<int> list){
    for(int h = list.size()/2 ; h > 0 ; h = h/2){
      //LOOP THROUGH EACH GROUP
      for(int i = 0 ; i < h ; i++){
        //ISERTION SORT ON EACH GROUP
        for(int j = i; j < list.size()-h ; j = j + h){
          for(int k = j + h ; k > i  ; k = k - h){
            if(list[k] >= list[k-h]){break;}
              int temp = list[k];
              list[k] = list[k-h];
              list[k-h] = temp;
          }
        }
      }
    }
    return list;
  }
  vector<int> Heap_Sort(){

  }
};
int main(){
  Sort S;
  int n = 10;
  vector<int> list;
  for(int i = 0 ; i < n ; i++){
    list.push_back(rand()%50);
  }
//  PrintVector(list);
  vector<int> CountSort_list = S.count_sort(list);
  cout<<"BY COUNTSORT"<<endl;
  PrintVector(CountSort_list);
  vector<int> insertSort_list = S.insertion_sort(list);
  cout<<"BY INSERTIONSORT"<<endl;
  PrintVector(insertSort_list);
  vector<int> selectionsort_list = S.selection_sort(list);
  cout<<"BY SELECTIONSORT"<<endl;
  PrintVector(selectionsort_list);
  vector<int> Shellsort_list = S.shell_sort(list);
  cout<<"BY SHELLSORT"<<endl;
  PrintVector(Shellsort_list);
}
