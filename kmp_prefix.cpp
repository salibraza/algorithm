#include <iostream>
#include <string>
using namespace std;
void kmp_prefix(int pie[], string p, int length){
    pie[0] = 0; //because the value for first character is always zero
    int j = 0;
    for(int i=1; i<length; i++){
        again:
        if (p[i] == p[j]){
            j++;
            pie[i] = j;
        }
        else{
            j = 0;
            if (p[i] == p[j]){
            j++;
            }
            pie[i] = j;
        }
    }
}
int main(){
    string s = "aabaabcab";
    int pie[9];
    kmp_prefix(pie, s, 9);
    for(int i=0; i<9; i++)
        cout<<pie[i]<<" ";
    return 0;
}