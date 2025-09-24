import (
    "fmt"
    "strconv"
)
func fractionToDecimal(a int, b int) string {
    if a == 0{
        return "0";
    }

    var ans string;
    if((a < 0) != (b < 0)){
        ans += "-" ;
    }

    a = abs(a)
    b = abs(b)
    ans += strconv.Itoa(a/b)
    if a % b == 0{
        return ans ;
    }
    ans += "."
    m := map[int]int{}
    rem := a % b
    for rem != 0{
        if pos, ok := m[rem]; ok {
            return ans[:pos] + "(" + ans[pos:] + ")"
        }
        m[rem] = len(ans) // mark position
        rem *= 10
        ans += strconv.Itoa(rem / b)
        rem %= b
    }
    return ans ;
}
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}