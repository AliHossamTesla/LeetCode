/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
using namespace std;
int n ;
int main()
{
    cin >>n;
    string s;
    cin >> s;
    int freq[26] = {};
    for (auto i : s)
        freq[i - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        while (freq[i])
        {
            cout << char(i + 'a');
            freq[i]--;
        }
    }
    cout << "\n";
    return 0;
}