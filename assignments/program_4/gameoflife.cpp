/**
* @ProgramName: Game of Life
* @Author: Sarah Beaver 
* @Description: 
*     The Game Of Life Based of of Jon Conway's Game of life
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: April 26 2017
*/
#include <iostream>
#include <string>
#include <fstream>

// #ifdef __cplusplus__
// #include <cstdlib>
// #else
// #include <stdlib.h>
// #endif

#include <unistd.h>

using namespace std;

class GameOfLife{
private:
    int **Board;
    int **Board2;
    int Rows;
    int Cols;
public:
    GameOfLife(string filename){
        string line;
        char ch;
        ifstream fin;
        fin.open(filename);
        fin >> Rows >> Cols;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        for (int i = 0; i < Rows; i++){
          fin.get(ch);
            for (int j = 0; j < Cols; j++){

               fin.get(ch);
               if (ch == 10)
               {
                    cout<<"j is "<<j<<endl;
                    continue;
               }
                Board[i][j] = int(ch)-48;
            }
            cout<<endl;
        }
        PrintBoard();
    }
    
    GameOfLife(int r, int c){
        Rows = r;
        Cols = c;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        PrintBoard();
    }
    
    void InitBoardArray(int **&b){
        b = new int*[Rows];
        for (int i = 0; i < Rows; i++){
            b[i] = new int[Cols];
        }
        ResetBoardArray(b);
    }
    
    void ResetBoardArray(int **&b){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                b[i][j] = 0;
            }
        }
    }
    
    void PrintBoard(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (Board[i][j] == 1)
                    cout << char('X');
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    
    int CountNeighbors(int row, int col){
        int neighbors = 0;
        int r,c=0;
        if (Board[row][col] == 1){
            neighbors--;
        }
        for (int i = row - 1; i <= row + 1; i++){
            for (int j = col - 1; j <= col + 1; j++){
              r=i;
              c=j;
              if(!OnBoard(i,j))
              {
                //cout<<"Not on Board"<<endl;
              if(i<0)
              {
               // cout<<"i<0"<<endl;
              //  cout<<r<<" "<<c<<endl;
                r=Rows+i;
                //cout<<r<<" "<<c<<endl;
              }
              else if(i>=Rows)
              {
                
               // cout<<"i>=Rows"<<endl;
                //cout<<r<<" "<<c<<endl;
                r=i%Rows;
                //cout<<r<<" "<<c<<endl;
              }
              if(j<0)
              {
                
             //   cout<<"j<0"<<endl;
               // cout<<r<<" "<<c<<endl;
                c=Cols+j;
                //cout<<r<<" "<<c<<endl;
              }
              else if(j>=Cols)
              {
                
              //  cout<<"j>=Cols"<<endl;
                //cout<<r<<" "<<c<<endl;
                c=j%Cols;
                //cout<<r<<" "<<c<<endl;
              }
              }
                    neighbors += Board[r][c];
            }
            //cout<<endl;
        }
        return neighbors;
    }
    
    bool OnBoard(int row, int col){
        return (row >= 0 && row < Rows && col >= 0 && col < Cols);
    }
    
    void RandomPopulate(int num){
        int r = 0;
        int c = 0;
        for (int i = 0; i<num; i++){
            r = rand() % Rows;
            c = rand() % Cols;
            Board[r][c] = 1;
        }
    }
    
    void SetCell(int r, int c, int val){
        Board[r][c] = val;
    }
    
    void AddGens(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                Board[i][j] += Board2[i][j];
            }
        }
        ResetBoardArray(Board2);
    }
    
    void clear_screen(int lines){
      for(int i=0;i<lines;i++){
        cout<<endl;
      }
    }
    void GliderGun()
    {
      if(Rows>10&&Cols>37)
      {
        ResetBoardArray(Board);
        SetCell(1,25,1);
        SetCell(2,25,1);    //right glider gun
        SetCell(6,25,1);
        SetCell(7,25,1);
        SetCell(2,23,1);
        SetCell(6,23,1);
        SetCell(3,22,1);
        SetCell(3,21,1);
        SetCell(4,22,1);
        SetCell(4,21,1);
        SetCell(5,22,1);
        SetCell(5,21,1);
      
        SetCell(6,18,1);
        SetCell(6,17,1);    //left glider Gun
        SetCell(5,17,1);
        SetCell(7,17,1);
        SetCell(4,16,1);
        SetCell(8,16,1);
        SetCell(6,15,1);
        SetCell(3,14,1);
        SetCell(3,13,1);
        SetCell(4,12,1);
        SetCell(5,11,1);
        SetCell(6,11,1);
        SetCell(7,11,1);
        SetCell(8,12,1);
        SetCell(9,13,1);
        SetCell(9,14,1);
      
        SetCell(5,1,1);
        SetCell(5,2,1);   //left box
        SetCell(6,1,1);
        SetCell(6,2,1);
      
        SetCell(3,35,1);
        SetCell(3,36,1);  //right box
        SetCell(4,35,1);
        SetCell(4,36,1);
      }
      return;
    }
    void Run(int generations=99999){
        int neighbors = 0;
        int g = 0;
        int stable=0;
        bool check=true;
        PrintBoard();
        while (g < generations&&stable!=2){
            for (int i = 0; i < Rows; i++){
                for (int j = 0; j < Cols; j++){
                 // cout<<"on spot "<<i<<","<<j<<endl;
                 if(((i==0&&j==0)||(i==Rows-1&&j==0)||(i==Rows-1&&j==Cols-1)||(i==0&&j==Cols-1))&&Board[i][j]==1)
                 {
                   Board2[i][j]=-1;
                   check = false;
                 }
                 else
                 {
                    neighbors = CountNeighbors(i, j);
                    if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                        Board2[i][j] = -1;
                        check=false;
                    }
                    else if (Board[i][j] == 0 && neighbors == 3){
                        Board2[i][j] = 1;
                        check=false;
                    }
                 }
                }
            }
            if(check==true)
              stable++;
            else{
              stable=0;
              check=true;
            }
            AddGens();
            usleep(100000);
            clear_screen(30);
            PrintBoard();
            g++;
        }
        
    }
};

int main(){
    int x=0;
    GameOfLife B("gen_one.txt");
    GameOfLife C(26,40);
    C.GliderGun();
    while(x!=3)
    {
      cout<<"Press 1 to run gen_one.txt 2 for glider gun or 3 to quit."<<endl;
      cin>>x;
      if(x==1)
      {
        B.Run(100);
      }
      else if(x==2)
      {
        C.Run(100);
      }
    }
    cout<<"Good Bye."<<endl;
    return 0;
}
