#include <iostream>
#include <string>
#include <unordered_map> 
using namespace std;
int Towerofhanoi3rods(int disc, char r1, char r2, char r3, unordered_map<int, int> hashtable={}){
   //base case of dp
    if (hashtable.find(disc) != hashtable.end()) 
        return hashtable[disc];

    //base case 1
    if (disc == 0)
        return disc;
    
    //base case 2
    if (disc == 1){
        cout << disc << " Moved from rod " << r1 << " To " << r2 << endl;       
        return disc;
    }
    
    //recursive case:
    int T1 = Towerofhanoi3rods(disc - 1, r1, r3, r2, hashtable);
    cout << disc << " Moved from rod " << r1 << " To " << r2 << endl;
    int T2 = Towerofhanoi3rods(disc - 1, r3, r2, r1, hashtable);
    hashtable.emplace(disc, T1 + T2 + 1); 
    return T1 + T2 + 1;
}

int Towerofhanoi4rods(int disc, char r1, char r2, char r3, char r4, unordered_map<int, int> hashtable={}){
   //base case of dp
    if (hashtable.find(disc) != hashtable.end()) // to see if value inside hash (storage element) or not
        return hashtable[disc];

    //base case 1
    if (disc == 0)
        return disc;
    
    //base case 2
    if (disc == 1){
        cout << disc << " Moved from rod " << r1 << " To " << r2 << endl;       
        return disc;
    }
    //base case 3
    if (disc == 2){
        cout << disc - 1 << " Moved from rod " << r1 << " To " << r4 << endl; // disc disc-1 smaller than n
        cout << disc << " Moved from rod " << r1 << " To " << r2 << endl;     // disc n bigger than disc-1
        cout << disc - 1 << " Moved from rod " << r4 << " To " << r2 << endl; // get smaller above bigger
        return 3;
    }
    int T1 = Towerofhanoi4rods(disc - 2, r1, r3, r4, r2, hashtable);
    
    //for purpose of visualization
    cout << disc - 1 << " Moved from rod " << r1 << " To " << r4 << endl; // disc disc-1 smaller than disc
    cout << disc << " Moved from rod " << r1 << " To " << r2 << endl;     // disc disc bigger than disc-1
    cout << disc - 1 << " Moved from rod " << r4 << " To " << r2 << endl; // get smaller above bigger
    // then move this the small discs (n-2 = 2) discs above this 2 biggest           =========== Tower_of_hanoi_4rods(discs - 2)
    int T2 = Towerofhanoi4rods(disc - 2, r3, r2, r1, r4, hashtable);
    hashtable.emplace(disc, T1 + T2 + 3); 
    return T1 + T2 + 3;
}

int FS (int i , int j ,char a , char b, char c, char d, int k){ // Much better than ToH41 by taking as input from user.
    int n1,n2,n3;
    int m = j - i + 1;
    if ( m <= k)
        return Towerofhanoi3rods(m, a, b, c);
    else {
        n1 = Towerofhanoi4rods(m - k, a, d, b, c);
        n2 = Towerofhanoi3rods(k, a, b, c);
        n3 = Towerofhanoi4rods(m- k, d, b, a, c);
    }
    return n1 + n2 + n3;
}
int main()
{
    int n ,k;

    n = 8;
    cout << "---------------the steps-------------" << endl;
    int arr[8];
    for(int i = 1; i < n + 1; i++){
        cout << "\nValue of K = " << i << endl;
        arr[i - 1] = FS(1, n, 'A', 'B', 'C', 'D', i);
    }
    for (int i = 0; i < 8; i++){
        cout << "Number of steps for 4 rods and " << 8 << " discs is: " << arr[i] << " steps with k = " << i+1 <<endl;
    }
    
    return 0;
}