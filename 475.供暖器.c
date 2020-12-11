/*
 * @lc app=leetcode.cn id=475 lang=c
 *
 * [475] 供暖器
 *
 * https://leetcode-cn.com/problems/heaters/description/
 *
 * algorithms
 * Easy (29.57%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 35.2K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 
 * 现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
 * 
 * 所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
 * 
 * 说明:
 * 
 * 
 * 给出的房屋和供暖器的数目是非负数且不会超过 25000。
 * 给出的房屋和供暖器的位置均是非负数且不会超过10^9。
 * 只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
 * 所有供暖器都遵循你的半径标准，加热的半径也一样。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3],[2]
 * 输出: 1
 * 解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4],[1,4]
 * 输出: 1
 * 解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
 * 
 * 
 */

// @lc code=start
/**方法一：找半径二分、找供暖器也二分
 * 超时了！！！！
 *
#define max(a, b) ((a)>(b))?(a):(b)
//判断pos位置的房子在半径为r的情况下是否能被加热
int findHeater(int* heaters, int heatersSize, int pos, int r){
    int left, right, mid;
    left = 0;
    right = heatersSize - 1;
    while(left <= right){
        mid = left + (right - left);
        if(heaters[mid]-r<=pos && pos<=heaters[mid]+r){
            return 1;
        }
        else if(pos>=heaters[mid]+r){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return 0;
}

//快排的比较函数
int cmp(const void *a, const void *b){
    return *(int*)a - *(int *)b;
}

//判断半径为r是否合适
int worked(int* heaters, int heatersSize, int housesSize, int* houses, int r){
    for (int i = 0; i < housesSize; i++){
        if( !findHeater(heaters, heatersSize, houses[i], r) ){
            return 0;
        }
    }
    return 1;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int left, right, mid;
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);
    //left, right, mid为半径
    left = 1;
    right = max(houses[housesSize - 1], heaters[heatersSize - 1]);
    while(left <= right){
        mid = left + (right - left) / 2;
        if(worked(heaters, heatersSize, housesSize, houses, mid) && !worked(heaters, heatersSize, housesSize, houses, mid-1)){
            return mid;
        }
        //r合适就减小
        else if (worked(heaters, heatersSize, housesSize, houses, mid)){
            right = mid - 1;
        }
        //不合适就增大
        else{
            left = mid + 1;
        }
    }
    return 0;
}
*/
/**方法二：两层遍历
 * 思路：找到每个房子对应的最小半径，再取最大。
 * 82.73%
 * 100%
 *
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    qsort(houses,housesSize,sizeof(int),cmp);
    qsort(heaters,heatersSize,sizeof(int),cmp);
    int i,j=0,count=0,sum=0,nums[housesSize];
    //遍历房子
    for(i=0;i<housesSize;i++)
    {
        //最大的半径
        //因为houses[i]后面第二个heater之后（如果有的话）都可以不用考虑了
        count=abs(houses[i]-heaters[0]);
        //遍历供暖器
        for(;j<heatersSize;j++)
        {
            //如果距离比最大半径大，说明是不需考虑的heater
            if(abs(houses[i]-heaters[j])>count)
                break;
            //找第i个房子需要的最小半径
            if(count>abs(houses[i]-heaters[j]))
                count=abs(houses[i]-heaters[j]);
        }
        nums[i]=count;
        //既然最小半径的位置在j处，那么当house的位置再增大时
        //不可能再使用j之前的heater了
        j--;
    }
    qsort(nums,housesSize,sizeof(int),cmp);
    return nums[housesSize-1];
}            
*/

// @lc code=end

