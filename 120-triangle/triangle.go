import(
    "fmt"
)
func minimumTotal(a [][]int) (ans int) {
    n := len(a)
    dp := make([][]int, n)
    ans = 1_000_000_000
    for i := range dp {
        dp[i] = make([]int, n)
        for j := 0; j < n ; j ++{
            dp[i][j] = ans 
        }
    }

    dp[0][0] = a[0][0]
    if n == 1{
        ans = a[0][0]
        return 
    }
    for i := 1; i < n; i++ {
        for j := 0; j <= i; j++ {
            dp[i][j] = a[i][j] + dp[i-1][j]
            if j-1 >= 0 && dp[i][j] > a[i][j]+dp[i-1][j-1] {
                dp[i][j] = a[i][j] + dp[i-1][j-1]
            }
            if i == n-1 && ans > dp[i][j] {
                ans = dp[i][j]
            }
        }
    }
    return
}
