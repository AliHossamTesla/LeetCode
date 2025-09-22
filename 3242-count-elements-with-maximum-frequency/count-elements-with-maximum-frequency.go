func maxFrequencyElements(nums []int) int {
    var cnt = [105]int{};
    for i := 0 ; i < len(nums); i ++{
        cnt[nums[i]] ++ ;
    }
    mx := -1 ;
    for i := 0 ; i < len(nums); i ++{
        if mx == -1 || mx < cnt[nums[i]]{
            mx = cnt[nums[i]]
        }
    }
    var ans int ;
    for i := 0 ; i < len(nums); i ++{
        if cnt[nums[i]] == mx{
            ans ++ ;
        }
    }
    return ans ;
}