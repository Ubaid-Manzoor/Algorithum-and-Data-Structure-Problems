#include<iostream>
#include<time.h>
#include<stdlib.h>
#define N 17
using namespace std;
class Chess_Board
{
//==============PRIVATE===========
private:
        char Board[N][N];//CHESS BOARD
// JUST TO DELAY RESULT A BIT
void Delay(int Milli_second)
{
    int Present_Time = clock();
    while(clock() < Present_Time + Milli_second);
}
//TO CHECK THAT AT A PARTICULAR POSITION  QUEEN IS SAFE
bool IsSafe(int row , int Column)
{
    int i,j;
    //CHECK FOR POSITION IN THE LEFT OF COLUMN
    for(int i = Column ; i >= 0 ; i--)
    {
        if(Board[row][i] == 'Q')
         return false;
    }
    //CHECK  VERTICALLY DOWN-LEFT
    for(i = row ,j = Column ; i >= 0 && j >= 0 ; i-- , j--)
    {
        if(Board[i][j] == 'Q')
         return false;
    }
    //CHECK VERTICALLY UP-LEFT
    for (i=row,j=Column ; j>=0 && i < N; i++ , j--){
        if (Board[i][j] == 'Q')
            return false;
    }
    return true;
}
//==========PUBLIC============
public:
        Chess_Board()
        {
          for(int i = 0 ; i < N ; i++)
            {
              for(int j = 0 ; j < N ; j++)
                {
                   Board[i][j] ='-';
                }
            }
        }
//PRINT THE CHESS BOARD AT THE TIME WHEN CALLED
void Print_The_Board()
{
    cout<<"================================="<<endl;
     cout<<"===============CHESS============="<<endl;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"===============CHESS============="<<endl;
    cout<<"=================================";
    cout<<endl;
}
bool Solution_Helper(int Column)
{
    if(Column >= N)
    {
        Print_The_Board();
      //  cout<<endl;
        return true;
    }
    else
    {
        for(int row = 0 ; row < N ; row++)
        {
             if(IsSafe(row,Column))
            {
                Board[row][Column]='Q';
               Delay(500000);
               Print_The_Board();
                bool Finished = Solution_Helper(Column + 1);
                if(Finished){
                    return true;}
                Board[row][Column]='-';
            }
        }
        return false;
    }
}
bool Print_N_Queens_Solution()
{
    int Column=0;
    bool Result = Solution_Helper(Column);
    return Result;
}
};

int main()
{
    Chess_Board board;
    if(!board.Print_N_Queens_Solution())
        cout<<"Solution Not Found"<<endl;
}
