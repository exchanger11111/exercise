#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> ret = {0, 1};
        
        for(int i=2; i<=n; i++)
            for(int j=ret.size()-1; j>=0; j--)
                ret.push_back(ret[j]+(1<<i-1));
        
        return ret;
}

void printBits(int n, int len){
    for(int i=len-1; i>=0; i--) {
        if (n & (1<<i)) {
            printf("1");
        }else{
            printf("0");
        }
    }
}

void printVector(vector<int>& v, int bit_len)
{
    vector<int>::iterator it;

    for(it=v.begin(); it!=v.end(); ++it){
        //bitset<bit_len> bin(*it);
        printBits(*it, bit_len);
        cout <<  " ";
        //cout << *it <<  " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int n = 4;
    if (argc>1){
        n = atoi(argv[1]); 
    }
    vector<int> v = grayCode(n);
    printVector(v, n);
    return 0;
}
