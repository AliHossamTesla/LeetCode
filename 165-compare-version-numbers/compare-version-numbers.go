import (
    "fmt"
    "strings"
    "strconv"
)
func compareVersion(version1 string, version2 string) int {
    var a, b = [500]int{}, [500]int{}
    x, y := 0, 0
    A := strings.Split(version1, ".")
    B := strings.Split(version2, ".")
    for _, i := range A{
        a[x], _ = strconv.Atoi(i)
        x ++ 
    }
    for _, i := range B{
        b[y], _ = strconv.Atoi(i)
        y ++ 
    }
    for i := 0 ; i < 500 ; i ++{
        if a[i] > b[i]{
            return 1
        }else if a[i] < b[i]{
            return -1
        }
    }
    return 0 ;
}