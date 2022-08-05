#include <unordered_map>
#include <iostream>
using namespace std;
//dp n
int ToH4 ( int n ,char p , char q ,char r,char s,unordered_map<int, int> hashtable={}) 
{

    //base case of dp
if (hashtable.find(n) != hashtable.end()) // if n is stored at Hastabke so dont calculate it again using calls
     return hashtable[n];
if(n==0)
   return 0;
if(n==1)
{
 cout << "Move disk 1 from rod "<< p << " to rod " << q << endl;
return 1;
}
 int n1= ToH4 (n - 2 , p , r , s ,q,hashtable);
 cout << "Move disk "<< n-1 << " from rod " << p << " to rod "<< s <<endl;
 cout << "Move disk "<< n << " from rod " << p << " to rod "<< q<<endl;
 cout << "Move disk "<< n-1 << " from rod " << s<< " to rod "<< q<<endl;
 int n2= ToH4(n - 2, r , q , p ,s,hashtable)+3;
 hashtable.emplace(n, n1 + n2); 
 return n1+n2;
}
int main(){
cout<<ToH4 (8 ,'A','B','C','D');
return 0;
}
