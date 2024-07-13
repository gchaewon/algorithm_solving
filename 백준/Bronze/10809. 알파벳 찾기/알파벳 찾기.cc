#include <iostream>
#include <vector>

using namespace std;
int main() {
    string str;
    cin >> str;
    
    for(int i=0; i<26; i++){
        int index = str.find(char('a'+i));
        if(index>100){
            cout << "-1";
        }
        else{
            cout << index;
        }
        cout << " ";
    }
}