/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start
/*
思路：先找最高峰，然后分别遍历左侧和右侧。每次记住当前最高峰。
        如果height小于当前最高峰，就可以接住雨水。
*/
// int trap(int* height, int heightSize){
//     int i = 0;
//     int max_index = 0, max = 0;
//     int water_lvl = 0;
//     int water = 0;

//     // 找最高峰
//     for ( i = 0; i < heightSize; i++)
//     {
//         if(height[i] > max)
//         {
//             max_index = i;
//             max = height[i];
//         }
//     }
//     // 水位是递增的，当前水位即为当前最大高度
//     // 雨水量=水位-当前高度
//     water_lvl = 0;
//     for ( i = 0; i < max_index; i++)
//     {
//         if(height[i] > water_lvl)
//         {
//             water_lvl = height[i];
//         }
//         water += water_lvl - height[i];
//     }

//     // 右坡同样过程
//     water_lvl = 0;
//     for(i = heightSize - 1; i > max_index ; i--)
//     {
//         if(height[i] > water_lvl)
//         {
//             water_lvl = height[i];
//         }
//         water += water_lvl - height[i];
//     }

//     return water;
// }

/*
思路：单调栈
*/
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

int trap(int* height, int heightSize){
    //特判
    if (height == NULL || heightSize < 3) {
        return 0;
    }

    int *stack = malloc(heightSize * sizeof(int));
    int stackTop = 0;
    int water = 0;

    memset(stack, 0, heightSize * sizeof(int));
    stack[stackTop++] = 0;
    for (int i = 1; i < heightSize; i++) {
        //小于栈顶的入栈，栈中的数一定递减，栈中储存的是位置而不是高度
        if(height[i] <= height[stack[stackTop - 1]]) {
            stack[stackTop++] = i;
            continue;
        }
        //当前高度大于栈顶，可以接雨水了
        int curheight = height[i];
        while (stackTop > 0 && curheight > height[stack[stackTop - 1]]) {
            //栈顶出栈，接满雨水
            int lastHeight = height[stack[stackTop - 1]];
            stackTop--;
            //如果栈顶高度与当前高度一样，就都可以出栈了
            while (stackTop > 0 && (height[stack[stackTop - 1]] == lastHeight)) {
                stackTop--;
            }

            if (stackTop > 0) {
                water  +=  (i - stack[stackTop - 1] - 1) * (MIN(curheight, height[stack[stackTop - 1]]) - lastHeight);
            }
        }
  

        stack[stackTop++] = i;
    } 

    free(stack);
    return water;
}

/**方法三：
 * 
 * 
 * 
 */
int trap(int* height, int heightSize){
    if(heightSize < 3)
        return 0;
    int peak[heightSize], pos = -1, water = 0;
    if(height[0] > height[1])
        peak[++pos] = 0;
    for (int i = 1; i < heightSize - 1; i++){
        if(height[i] >= height[i-1] && height[i] >= height[i+1]){
            peak[++pos] = i;
        }
    }
    if(height[heightSize - 1] >= height[heightSize - 2])
        peak[++pos] = heightSize - 1;
    for (int i = 0; i <= pos; i++){

    }
    return water;  
}
// @lc code=end

