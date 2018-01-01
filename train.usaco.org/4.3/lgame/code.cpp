/*
ID: neeyant2
PROG: lgame
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int x[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 
                   2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

struct node {
    string p;
    int q;
};

int z[26], zz[26];
vector<node> dictionary;

bool compare(const node &a, const node &b) {
    if (a.q > b.q) return true;
    if (a.q == b.q) return a.p < b.p;
    return false;
}


int main() {
    ifstream fin("lgame.in");
    ofstream fout("lgame.out");
    ifstream dict("lgame.dict");
    string p;
    fin >> p;
    for (int i = 0; i < p.size(); ++i) ++z[p[i] - 'a'];
    dict >> p;
    while (p != ".") {
        memset(zz, 0, sizeof(zz));
        for (int i = 0; i < p.size(); ++i) ++zz[p[i] - 'a'];
        bool flag = true;
        for (int i = 0; i < 26; ++i) flag &= (zz[i] <= z[i]);
        
        if (flag) {
            node new_node;
            new_node.p = p;
            new_node.q = 0;
            for (int i = 0; i < p.size(); ++i) new_node.q += x[p[i] - 'a'];
            dictionary.push_back(new_node);
        }
        
        dict >> p;
    }
    
    int len = dictionary.size();
    for (int i = 0; i < len; ++i)
     for (int j = i+1; j < len; ++j) {
         node new_node;
         if (dictionary[i].p < dictionary[j].p) 
             new_node.p = dictionary[i].p + " " + dictionary[j].p;
         else 
             new_node.p = dictionary[j].p + " " + dictionary[i].p;
             
         memset(zz, 0, sizeof(zz));
         for (int k = 0; k < dictionary[i].p.size(); ++k) ++zz[dictionary[i].p[k] - 'a'];
         for (int k = 0; k < dictionary[j].p.size(); ++k) ++zz[dictionary[j].p[k] - 'a'];
         bool flag = true;
         for (int k = 0; k < 26; ++k) flag &= (zz[k] <= z[k]);
         new_node.q = dictionary[i].q + dictionary[j].q;
         
         if (flag) dictionary.push_back(new_node);
     }
    
    sort(dictionary.begin(), dictionary.end(), compare);
    
    fout << dictionary[0].q << endl;
    for (int i = 0; i < dictionary.size(); ++i) {
        if (dictionary[i].q != dictionary[0].q) break;
        fout << dictionary[i].p << endl;
    }
    
    return 0;
}