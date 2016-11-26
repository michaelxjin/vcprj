#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, s, p, q;
    unsigned int v, m;
    
    cin >> n >> s >> p >> q;
    
    v = m = s;
    // first calculate max number
    for (int i = 1; i < n; i++) {
        v = (v * p + q) % (1 << 31);
        if (v > m)
            m = v;
    }
    int ARRAY_SIZE = m / 32 + 1;
       
    int *arr = new int[ARRAY_SIZE];
    if (arr == NULL) {
        cout << "Not enough memory" << endl;
        return 1;
    }
    // init array
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = 0;
    
    /// start
    v = s;
    arr[v/32] = 1 << (v % 32);
    for (int i = 1; i < n; i++) {
        v = (v * p + q) % (1 << 31);
        // or bitmap
        arr[v/32] = arr[v/32] | (1 << (v % 32));
    }
    // cout number of 1's
    v = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                v++;
            }
        }
    }
    cout << v << endl;
    delete [] arr;
    return 0;
}
