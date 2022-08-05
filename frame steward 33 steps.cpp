#include <bits/stdc++.h>
using namespace std;
int ToH3 (int m ,char p, char q, char r) // The basic 3 pegs ToH problem
{
if(m==1)
{
cout << "Move disk 1 from rod "<< p << " to rod "<< q<<endl;
return 1;
}
int n1=ToH3(m - 1, p, r, q);
cout <<"Move disk "<< m << " from rod " << p << " to rod "<<q<<endl;
int n2=ToH3 (m - 1 , r, q, p)+1;
return n1+n2;
}
int ToH4 ( int n ,char p , char q ,char r,char s) // Similarly 4 pegs ToH problem solved
{
if(n==0)
return 0;
if(n==1)
{
cout << "Move disk 1 from rod "<< p << " to rod " << q << endl;
return 1;
}
int n1= ToH4 (n - 2 , p , r , s ,q );
cout << "Move disk "<< n-1 << " from rod " << p << " to rod "<< s <<endl;
cout << "Move disk "<< n << " from rod " << p << " to rod "<< q<<endl;
cout << "Move disk "<< n-1 << " from rod " << s<< " to rod "<< q<<endl;
int n2=ToH4(n - 2, r , q , p ,s)+3;
return n1+n2;
}
int ToH42 (int i , int j ,char a , char b, char c, char d, int k) 
{
    int n1,n2,n3;
int m = j - i + 1;
if ( m <= k)
return ToH3 ( m,a,b,c);
else
{
 n1=ToH4 (m - k ,a , d , b ,c);
 n2=ToH3 (k , a , b , c);
 n3=ToH4 (m- k , d ,b , a,c);
}
return n1+n2+n3;
}
int main(){
int n ,k;
cout << "Enter the no. of disks "<< endl;
cin >> n ;
cout << endl;
cout <<"---------------the steps-------------" <<endl;
cout<<ToH42 (1, n, 'A', 'B', 'C','D' , (n/2));
return 0;
}
