/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define sp " "
#define el '\n'
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
using ll = long long;
using ld = long double;
using namespace std;
// generate sub sets of number n ;
// method 1 ;
//vector<vector<int>>v ;
//vector<int> ans ;
//int n ;
//void generateSubSets1(int k)
//{
//    if(k > n)
//   {
//       v.push_back(ans) ;
//       return ;
//   }else{
//       generateSubSets1(k + 1) ;
//       ans.push_back(k) ;
//       generateSubSets1(k + 1) ;
//       ans.pop_back() ;
//   }
//}
//// method 2 ;
//vector<vector<int>>v1 ;
//void generateSubSets2(int n)
//{
//    for(int i = 0 ; i < (1 << n) ; i ++)
//    {
//        vector<int>sub ;
//        for(int j = 0 ; j < n ; j ++)
//        {
//            if(i&(1<<j))
//                sub.push_back(j + 1) ;
//        }
//        v1.push_back(sub) ;
//    }
//}
//// with array or string
//// method 1 ;
//vector<vector<char>>v_ ;
//vector<char>ans_;
//int n_;
//string s ;
//void generateSubSets1_(int k)
//{
//    if(k == n_)
//    {
//        v_.push_back(ans_) ;
//        return ;
//    }else{
//        generateSubSets1_(k + 1) ;
//        ans_.push_back(s[k]) ;
//        generateSubSets1_(k + 1) ;
//        ans_.pop_back() ;
//    }
//}
//// method 2 ;
//vector<vector<char>>v1_;
//void generateSubSets2_(int n)
//{
//    for(int i = 0 ; i < (1 << n) ; i ++)
//    {
//        vector<char>sub ;
//        for(int j = 0 ; j < n ; j ++)
//        {
//            if(i&(1<<j))
//                sub.push_back(s[j]) ;
//        }
//        v1_.push_back(sub) ;
//    }
//}
//// generate pre
//void backTrack(vector<vector<int>>&res , vector<int>&nums,vector<int>&pre ,vector<bool>&ok)
//{
//    if(pre.size() == nums.size())
//    {
//        res.push_back(pre) ;
//        return ;
//    }
//    for(int i = 0 ; i < nums.size() ; i ++)
//    {
//        if(ok[i])
//            continue ;
//        ok[i] = 1 ;
//        pre.push_back(nums[i]) ;
//        backTrack(res,nums,pre,ok) ;
//        ok[i] = 0 ;
//        pre.pop_back() ;
//    }
//}
// move of Queen ;
//const int sz = 1000 ;
//int ans = 0 ,n;
//bool dig1[sz] , dig2[sz] , clm[sz] ;
//void search(int y)
//{
//    if(y == n)
//    {
//        ans ++ ;
//        return ;
//    }
//    for(int i = 0 ; i < n ; i ++)
//    {
//        if(clm[i] or dig1[i + y] or dig2[i - y + n - 1])
//            continue;
//        clm[i] = dig1[i + y] = dig2[i - y + n - 1] = 1 ;
//        search(y + 1) ;
//        clm[i] = dig1[i + y] = dig2[i - y + n - 1] = 0 ;
//    }
//}
//
int main()
{
    
    return 0;
}