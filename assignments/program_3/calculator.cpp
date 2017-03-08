/**
* @ProgramName: Postfix Calculator
* @Author: Sarah Beaver 
* @Description: 
*     Changes from infix to postfix and calculates the output
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2 2017
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a double stack
*/
class CalcStack{
  private:
  //////////////////////////////////////////////////////
  
  double *S;
  int top;
  int size;
  
  public:
  //////////////////////////////////////////////////////
  
  /**
  * @FunctionName: CalcStack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  CalcStack(int insize){
    size = insize;
    top = -1;
    S = new double[size];
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a double to the stack
  * @Params:
  *    double c - double to add 
  * @Returns:
  *    void
  */
  void push(double c){
    if(!full()){
      S[++top] = c;
    }else{
      cout<<"Stack Overflow!"<<endl;
    }
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a double from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  double pop(){
    if(!empty())
      return S[top--];
    else
      return -1;
  }
  
  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void printStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool empty(){
    return top == -1;
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool full(){
    return top == size-1;
  }
   /**
  * @FunctionName: Peek
  * @Description: 
  *     looks at top of stack
  * @Params:
  *    None 
  * @Returns:
  *    top of stack
  */
  int peek(){
    return S[top];
  }
};
/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a char stack
*/
class Stack{
  private:
  //////////////////////////////////////////////////////
  
  char *S;
  int top;
  int size;
  
  public:
  //////////////////////////////////////////////////////
  
  /**
  * @FunctionName: Stack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  Stack(int insize){
    size = insize;
    top = -1;
    S = new char[size];
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void push(char c){
    if(!full()){
      S[++top] = c;
    }else{
      cout<<"Stack Overflow!"<<endl;
    }
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char pop(){
    if(!empty())
      return S[top--];
    else
      return -1;
  }
  
  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void printStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool empty(){
    return top == -1;
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool full(){
    return top == size-1;
  }
   /**
  * @FunctionName: Peek
  * @Description: 
  *     looks at top of stack
  * @Params:
  *    None 
  * @Returns:
  *    top of stack
  */
  int peek(){
    if(S[top]=='(')
    {
      return 0;
    }
    else if(S[top]=='+'||S[top]=='-')
    {
      return 1;
    }
    else if(S[top]=='*'||S[top]=='/'||S[top]=='%')
    {
      return 2;
    }
    else if(S[top]=='^')
    {
      return 3;
    }
    else 
    return 4;
  }
};
/**
* @FunctionName: Queue
* @Description: 
*     Implementation of a char queue
*/
class Queue{
  private:
  //////////////////////////////////////////////////////
  
  int ArraySize;
  char *Q;
  int Front;
  int Rear;
  int NumItems;
  
  public:
  //////////////////////////////////////////////////////
  
  /**
  * @FunctionName: Queue
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial queue size
  * @Returns:
  *    void
  */
  Queue(int insize){
    ArraySize = insize;
    Q = new char[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c){
    if(Full()){
      cout<<"Queue Full!"<<endl;
      return;
    }
    Q[Rear] = c;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return;
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop(){
    if(Empty()){
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
  /**
  * @FunctionName: printQueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintQueue(){
    for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%ArraySize){
      cout<<Q[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty(){
    return (NumItems == 0);
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full(){
    return (NumItems == ArraySize);
  }
};

/*
This main reads an infix expression from stdin, puts the tokens
in a queue, then pops each item off the queue and prints it out.
This is not meant to influence your solution to the program, it 
is simply showing basic queue use.
*/
int main(){
  ifstream infile;
  infile.open("exp.txt");
  string infix;
  char temp;
  double num1=0;
  double num2=0;
  int mod1=0;
  int mod2=0;
  int priority=0;
  int check=0;
  double answer=0;
  int loop;
  infile>>loop;
  getline(infile,infix);
  for(int j=0;j<loop;j++)//loops for the number of expressions.
  {
    getline(infile,infix);
    Queue q1(infix.length()+1);
    Stack s1(infix.length()+1);
    CalcStack calculate(infix.length()+1);
    s1.push('(');
    for(int i=0;i<infix.length();i++){//checks what it is and sets it to a priority
                  //then checks stack and if priority is higher pushes it on else pops until it can push
      temp=infix[i];
      if(temp=='(')
      {
         priority=0;
      }
      else if((temp=='+'||temp=='-'))
      {
        priority=1;
      }
      else if(temp=='*'||temp=='/'||temp=='%')
      {
        priority=2;
      }
      else if(temp=='^')
      {
        priority=3;
      }
       if(48<=temp&&temp<=57)
      {
        q1.Push(temp);
      }
      else if(temp!=' ')
      {
        if(temp==')')
        {
          check=s1.peek();
          while(check!=0)
          {
            q1.Push(s1.pop());
            check=s1.peek();
          }
          s1.pop();
        }
        else if(temp=='(')
          s1.push(temp);
        else
        {
           check=s1.peek();
          while(check>=priority) 
          {
          q1.Push(s1.pop());
          check=s1.peek();
          }
          s1.push(temp);
        }
      }
    }
    while(!s1.empty()){//pushing whatever is left on the stack onto the queue except the (
      temp = s1.pop();
      if(temp!='(')
        q1.Push(temp);
      //we could simply do cout<<s1.pop(); as well. 
    }
    
    while(!q1.Empty()){ //checks what is being popped off the queue then does the appropiate calculation
      temp = q1.Pop();
      if(48<=temp&&temp<=57)
      {
        num1=temp-'0';
        calculate.push(num1);
      }
      else if(temp=='+')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        num2+=num1;
        calculate.push(num2);
      }
       else if(temp=='-')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        num2-=num1;
        calculate.push(num2);
      }
       else if(temp=='*')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        num2*=num1;
        calculate.push(num2);
      }
       else if(temp=='/')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        if(num1!=0)
        {
        num2/=num1;
        calculate.push(num2);
        }
        else
        {
          cout<<"You are not very smart. Can't divide by 0 but we will pretend it gives you 0."<<endl;
          calculate.push(0);
        }
      }
       else if(temp=='^')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        num2=pow(num2,num1);
        calculate.push(num2);
      }
       else if(temp=='%')
      {
        num1=calculate.pop();
        num2=calculate.pop();
        mod1=num1;
        mod2=num2;
        if(mod1==num1&&mod2==num2)
        {
          mod2%=mod1;
          calculate.push(mod2);
        }
        else
        {
          cout<<"Can not give a remainder of a double. Will replace with a 1 and move on with equation."<<endl;
          calculate.push(1);
        }
      }
    }
    answer=calculate.pop();
    for(int k=0;k<infix.length()-1;k++)
    {
      cout<<infix[k];
    }
    cout<<" = "<<answer<<endl;
 }
  return 0;
}
