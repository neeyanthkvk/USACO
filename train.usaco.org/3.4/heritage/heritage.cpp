/*
ID: neeyant2
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
string getPostOrder(string inOrder,string preOrder)
{
    int length = preOrder.size();
    if(length ==0) return "";
    char root = preOrder[0];
    int index = inOrder.find(root);
    int left = index;
    int right = length-index-1;
    return getPostOrder(inOrder.substr(0,left),preOrder.substr(1,left))
        +getPostOrder(inOrder.substr(index+1),preOrder.substr(index+1))+root;
    
}
int main(int argv,char*argc[])
{
    string inOrder,preOrder;
    fin >> inOrder >> preOrder;
    fout << getPostOrder(inOrder,preOrder) << '\n';
    fin.close();
    fout.close();
    return 0;
}
