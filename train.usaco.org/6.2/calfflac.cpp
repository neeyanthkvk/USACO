#include <bits/stdc++.h>
/*
PROB: calfflac
LANG: C++
*/
using namespace std;

string s;
char pal[20000];
int punc[20000];

pair<int, int> palPair(char *str, int len)
{
    int maxLength = 1; 
    int start = 0;
 
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
	return make_pair(start, start+maxLength-1);
}

int main() {
	ofstream out;
	out.open("calfflac.out");
    freopen("calfflac.in", "r", stdin);
    string s2;
    while(getline(cin, s2)) {
        s = s + '\n' + s2;
    }
    int len = s.length();
    int curpal = 0;
    int puncnum = 0;
    for(int i = 0; i < len; i++) {
        if(isalpha(s[i])) {
            punc[curpal] = i;
            pal[curpal] = tolower(s[i]);
            curpal += 1;
        }
    }
    cout << pal;
    pair<int, int> palNums = palPair(pal, curpal);
    int low = punc[palNums.first];
	int high = punc[palNums.second];
    out << (palNums.second-palNums.first + 1) << endl;
	for(int i = low; i <= high; i++) {
		out << s[i];
	}
	out << endl;
   
}

