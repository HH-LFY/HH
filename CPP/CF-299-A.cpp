#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;



map<int,string> p;
int n;

int main()
{
    /*
        freopen("output.txt","w",stdout);
        char s[100];
        int x;
        int i = 0;
        while(cin>>x>>s){
            printf("p[%d] = \"%s\";\n",i++,s);
        }
    */
    p[0] = "zero";
    p[1] = "one";
    p[2] = "two";
    p[3] = "three";
    p[4] = "four";
    p[5] = "five";
    p[6] = "six";
    p[7] = "seven";
    p[8] = "eight";
    p[9] = "nine";
    p[10] = "ten";
    p[11] = "eleven";
    p[12] = "twelve";
    p[13] = "thirteen";
    p[14] = "fourteen";
    p[15] = "fifteen";
    p[16] = "sixteen";
    p[17] = "seventeen";
    p[18] = "eighteen";
    p[19] = "nineteen";
    p[20] = "twenty";
    p[21] = "twenty-one";
    p[22] = "twenty-two";
    p[23] = "twenty-three";
    p[24] = "twenty-four";
    p[25] = "twenty-five";
    p[26] = "twenty-six";
    p[27] = "twenty-seven";
    p[28] = "twenty-eight";
    p[29] = "twenty-nine";
    p[30] = "thirty";
    p[31] = "thirty-one";
    p[32] = "thirty-two";
    p[33] = "thirty-three";
    p[34] = "thirty-four";
    p[35] = "thirty-five";
    p[36] = "thirty-six";
    p[37] = "thirty-seven";
    p[38] = "thirty-eight";
    p[39] = "thirty-nine";
    p[40] = "forty";
    p[41] = "forty-one";
    p[42] = "forty-two";
    p[43] = "forty-three";
    p[44] = "forty-four";
    p[45] = "forty-five";
    p[46] = "forty-six";
    p[47] = "forty-seven";
    p[48] = "forty-eight";
    p[49] = "forty-nine";
    p[50] = "fifty";
    p[51] = "fifty-one";
    p[52] = "fifty-two";
    p[53] = "fifty-three";
    p[54] = "fifty-four";
    p[55] = "fifty-five";
    p[56] = "fifty-six";
    p[57] = "fifty-seven";
    p[58] = "fifty-eight";
    p[59] = "fifty-nine";
    p[60] = "sixty";
    p[61] = "sixty-one";
    p[62] = "sixty-two";
    p[63] = "sixty-three";
    p[64] = "sixty-four";
    p[65] = "sixty-five";
    p[66] = "sixty-six";
    p[67] = "sixty-seven";
    p[68] = "sixty-eight";
    p[69] = "sixty-nine";
    p[70] = "seventy";
    p[71] = "seventy-one";
    p[72] = "seventy-two";
    p[73] = "seventy-three";
    p[74] = "seventy-four";
    p[75] = "seventy-five";
    p[76] = "seventy-six";
    p[77] = "seventy-seven";
    p[78] = "seventy-eight";
    p[79] = "seventy-nine";
    p[80] = "eighty";
    p[81] = "eighty-one";
    p[82] = "eighty-two";
    p[83] = "eighty-three";
    p[84] = "eighty-four";
    p[85] = "eighty-five";
    p[86] = "eighty-six";
    p[87] = "eighty-seven";
    p[88] = "eighty-eight";
    p[89] = "eighty-nine";
    p[90] = "ninety";
    p[91] = "ninety-one";
    p[92] = "ninety-two";
    p[93] = "ninety-three";
    p[94] = "ninety-four";
    p[95] = "ninety-five";
    p[96] = "ninety-six";
    p[97] = "ninety-seven";
    p[98] = "ninety-eight";
    p[99] = "ninety-nine";

    cin>>n;
    cout<<p[n]<<endl;

    return 0;
}
