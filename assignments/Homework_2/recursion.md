Part 1
Q1 , Q2
void A (char ch){
  if(('A'<= ch) && (ch <= 'H')){
    A(ch-1);
    cout<<ch<<endl;
  }else{
    cout<<endl;
  }
}
Trace A(‘C’) and Trace A(‘3’)
1. A(‘C’)=>A(‘B’)=>A(‘A’)=> A(‘@’) -prints out end line=>A(‘A’)-prints out A and end line=>
A(‘B’)-prints out B and end line=>A(‘C’)-prints out C and end line

2. A(‘3’)-prints out end line
Q3
Trace B(4)
int B (int n){
  if(n==0)
    return 1;
  else{
    cout<<n<<endl;
    return n * B(n-1);
  }
}

3. B(4)-prints out 4 and end line=>4*B(3)-print out 3 and end line =>
3*B(2)-prints out 2 and end line =>2*B(1)-prints out 1 and end line =>
1*B(0)-returns 1,1*1=>2*B(1)-2*1=>3*B(2)-3*2=>4*B(3)-4*6 returns 24

Q4
Trace C(16)
int C (int n){
  if(n<2)
    return 0;
  else
    cout<<n<<endl;
    return (1 + C(n/2));
}
4. C(16)-prints out 16 and end line=>1+C(8)-prints out 8 and end line=>
1+C(4)-prints out 4 and end line=>1+C(2)-prints out two and end line=>
1+C(1)-returns 0 1+0=>1+C(2)-1+1=>1+C(4)-1+2=>1+C(8)-1+3=>1+C(16)-1+4 returns 5

Q5
Trace D(-2365)
int D (int n){
  if(n<0)
    return D(-n);
    if(n<10){
      cout<<n<<endl;
      return n;
    }else{
      cout<<n<<endl;
      return D(n/10);
  }
}
5. D(-2365)=>D(2365)-prints out 2365 and end line=>D(236)-prints out 236 and end line=>
D(23)-prints out 23 and end line=>D(2)-prints 2 and end line, returns 2

Q6
Write a function that will count the number of digits in a nonnegative integer. Trace for 5679.
int NumDigits(int num){
    // Returns the "length" of an integer
}
6. if(num==0)
	return 0;
else 
return 1+NumDigits(num/10);
Trace 5679
1+NumDigits(567)=>1+NumDigits(56)=>1+NumDigits(5)=>1+NumDigits(0)=>0=>1+0=>1+1=>1+2=>1+3=>return 4


Q7
Write a function MyPow() - Which will raise a given number to a power. Trace for 23.
int MyPow(int base, int exp)
    // Returns base^exp


)
if(exp==1)
	return base;
else
return base*MyPow(base,exp-1);
Trace 2^3
2*MyPow(2,2)=>2*MyPow(2,1)=>2=>2*2=>2*4=>return 8

Q8
Complete the function and trace for A[2,4,5,7,8,11]
int SumArray(int A[], int n)
    // Return sum of A[0] + A[1] + … + A[n-1]


)
if(n==1)
  return A[n-1];
else
  return A[n-1]+SumArray(A[],n--);
Trace A[2,4,5,7,8,11]
11+SumArray(A[],5)=>8+SumArray(A[],4)=>7+SumArray(A[],3)=>5+SumArray(A[],2)=>
4+SumArray(A[],1)=>2=>4+2=>5+6=>7+11=>8+18=>11+26=>return 37
