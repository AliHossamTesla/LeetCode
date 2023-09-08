/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
// Function to calculate the Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the Least Common Multiple (LCM) of two numbers
int lcm(int a, int b)
{
    // LCM(a, b) = (a * b) / GCD(a, b)
    return (a * b) / gcd(a, b);
}
int sequenceSum(int a, int b)
{
    // Calculate the number of terms in the sequence
    int n = b - a + 1;

    // Calculate the sum using the formula
    int sum = (n * (a + b)) / 2;

    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , A , B ; cin >> N >> A >> B ;
        int  l =N / lcm(A,B) ;
        A = N/A - l ;
        B = N/B - l ;
        // cout << A << " " << B << endl ;
        int sum = (A == 0 ? 0 : sequenceSum(N - A + 1,N)) - sequenceSum(0,0 + B) ;
        cout << sum << endl ;
    }
}
