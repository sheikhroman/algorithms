#include <bits/stdc++.h>
using namespace std;
string int_to_binary(int decimal){
    if (decimal == 0)
        return "0";
    else if (decimal == 1)
        return "1";
    return int_to_binary(decimal / 2) + int_to_binary(decimal % 2);
}
int main(){
    int n = 9;
    string ans = int_to_binary(n);
    cout << "binary is " << ans << endl;
    return 0;
}