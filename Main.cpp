
#include "String.h"
#include "string"
#include "math.h"
#include "iostream"
using namespace std;
int main()
{
    String s3;
    String s1("Hello");
    String s2(s1);
    int i;
    char c;

    cout << s2 << endl;
    cin >> s2;

    if (s1 < s2)
        cout << s1 << " < " << s2 << endl;
    else if (s1 > s2)
        cout << s1 << " > " << s2 << endl;
    if (s1 == s2)
        cout << s1 << " = " << s2 << endl;
    s3 = s1 + s2;

    cout << s1 << " + " << s2 << " = " << s3 << endl;
    cout << "Character index: ";
    cin >> i;
    cout << s3[i] << endl << endl;




    String s__("tatatatata lllll aaafdfdsf");
    String s("lol pps imho");
    String s_("pps");
    String* token;
    cout << s << endl;
    cout << "index a - " << s.FindChar('a') << endl;
    int index = s.Find(s_);
    cout << "index baba - " << index << endl;
    token = s.Strtok(" ");
    for (int i = 0; i < sizeof(token) - 1; i++)
    {
        cout << token[i] << endl;
    }
    cout<<"dublicate str: "<<s1.Dublicate(3)<<" ";
    cout << "find podstr:\n";
    s__.FindPodstr("ta");
    cout<<s__.Poisk();
    String __s("abcabd");
    __s.Set();
    return 0;
}