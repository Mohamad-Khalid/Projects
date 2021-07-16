#include <iostream>
#include <vector>
#include <time.h>
using namespace  std;

/*
 * This function is to generate different test cases needed for testing the code
 * using vector to store the numbers instead of array (dynamic size)
 * maxN = number of elements
 * maxM = maximum value of the single element
 * parameter testCases = number of test cases you want
 * srand((time(0)) to get different number in each run - call it once
 * rand generate random numbers from 0 to 32000
 * */

// n    1-1e5
// a1 a2 a3 a4 ...  0 - 1e9
void generateTestCases(int testCases){
    srand(time(0));
    int maxN = 1e5+5 , maxE = 1e9;
    while (testCases--){
        vector<int> v;
        int n = ( rand() * rand()) % maxN;
        for(int i =0 ;i<n ;i++)
            v.push_back((rand()*rand() % maxE));
        /*cout << n << endl;
        for(int i : v )
            cout << i << ' ';*/
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    generateTestCases(t);

    return 0;
}
