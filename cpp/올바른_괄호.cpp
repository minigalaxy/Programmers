#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> br;
    
    for(char c: s){
        if(c == ')'){
            if(br.empty()) return false;
            else br.pop();
        } else br.push(c);
    }
    
    if(!br.empty()) return false;

    return true;
}
