#include <iostream>
using namespace std;
int ToH4 ( int n ,char p , char q ,char r,char s) 
{
if(n==0)
return 0;
if(n==1)
{
cout << "Move disk 1 from rod "<< p << " to rod " << q << endl;
return 1;
}
 int n1=ToH4 (n - 2 , p , r , s ,q );
cout << "Move disk "<< n-1 << " from rod " << p << " to rod "<< s <<endl;
cout << "Move disk "<< n << " from rod " << p << " to rod "<< q<<endl;
cout << "Move disk "<< n-1 << " from rod " << s<< " to rod "<< q<<endl;
int n2=ToH4(n - 2, r , q , p ,s)+3;
return n1+n2;
}
int main()
{
   cout<< ToH4(8,'A','B','C','D');
}
