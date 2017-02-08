```cpp
/**
* @ProgramName:tail_insertion.cpp
* @Author: Sarah Beaver
* @Description: 
*     This program creates a lists and works with it. 
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 03 02 2017
*/
#include <iostream>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
      Tail = Head; 
    }
/**
* @FunctionName: FrontSert
* @Description: 
*     Inserts nodes onto the front of the list.
* @Params:
*     int x- the date put into the node.
* @Returns:
*    void
*/
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(!Head){
        Head=Temp;
        Tail=Temp;
      }
      else{
        Temp->Next=Head;
        Head = Temp;
     }

    }
    /**
* @FunctionName: BackSert
* @Description: 
*     Inserts Nodes onto the Back of the List
* @Params:
*    int x - date put into the node
* @Returns:
*    void
*/
    void BackSert(int x)
    {
      Node *Temp = new Node;
      Temp->Data=x;
      Temp->Next=NULL;
      if(!Head)
      {
        Head=Temp;
        Tail=Temp;
      }
      else
     {
        Tail->Next=Temp;
        Tail=Temp;
        Tail->Next=NULL;
      }
    } 

    //Not Done
    void OrderedSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(!Head){
        Head = Temp;
      }else{
        //X is less than head node
        if(x < Head->Data){
          Temp->Next = Head;
          Head = Temp;
        }else{
          Node *Curr = Head;
          Node *Prev = Head;
          
          while(Curr && x > Curr->Data){
            Prev = Curr;
            Curr = Curr->Next;
          }
          
          Prev->Next = Temp;
          Temp->Next = Curr;
        }
      }
    }
    
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        Node *Temp = Head;
        while(Temp != NULL){
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
    }

};


int main() {
    srand(97097807);
    List L;
    for(int i=0;i<10;i++){
      L.BackSert(rand()%100);
    }
    L.PrintList();
    
    
    return 0;
}
```
