#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int hashFunc(string s, int index, int length){
    int sum = 0;
    int l = length;
    for(int i = 0; i < length; i++, l--, index++){
        int c = ((int)(s[index]))%48;   //converting the character into number
        sum += c * (pow(10, l-1));      // calculating value
    }
    return sum%11;  //Because q = 11
}
void rabinKarp(string t, string p){
    int m = p.length(); // length of pattern
    int n = t.length(); // length of text
    int i = 0, j = 0; // iterators for text and pattern respetively
    int hashScore = hashFunc(p, 0, 2); // hash score of pattern p
    for(i; i<= n-m; i++){
        if (hashFunc(t, i, m) == hashScore){
            int index = i;
            for(j; j<m; j++, i++){
                if (t[i] != p[j]){ //if spurious hit
                    j = 0;
                    cout<< "Spurious hit at index " << index << endl;
                    break;
                }
            }
            if(j == m){
                cout<< "Valid shift at s = " << index << endl; 
            }
        }
    }
}
int main(){
    rabinKarp("3141592653589793", "26");
    return 0;
}