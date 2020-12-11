/*
 * @lc app=leetcode.cn id=874 lang=c
 *
 * [874] 模拟行走机器人
 */

// @lc code=start

/*
算法ok，但是超时。在判断是否为障碍时需要二分查找
*/
// #include<math.h>

// int isObstacle(int* pos, int** obstacles, int obstaclesSize, int* obstaclesColSize){
//     int *obstacle;
//     for (int i = 0; i < obstaclesSize; i++){
//         obstacle = (int *)malloc(sizeof(int) * obstaclesColSize[i]);
//         obstacle = obstacles[i];
//         if(pos[0] == obstacle[0] && pos[1] == obstacle[1]){
//             return 1;
//         }
//     }
//     return 0;
// }

// // int isBoundary(int *pos, int xmax, int ymax){
// //     if(pos[0] >= -1*xmax && pos[0] <= xmax && pos[1] >= -1*ymax, && pos[1] <= ymax)
// //         return 0;
// //     return 1;
// // }

// int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize){
//     int dirx[] = {0, -1, 0, 1};
//     int diry[] = {1, 0, -1, 0};
//     //0:east, 1:north, 2:west, 3:south
//     int dir = 0, step, dis, res = 0;
//     int pos[2] = {0, 0};
//     for (int i = 0; i < commandsSize; i++){
//         //改变方向
//         if(commands[i] == -1){
//             dir = dir - 1 >= 0 ? dir - 1 : 3;
//         }
//         else if(commands[i] == -2){
//             dir = dir + 1 < 4 ? dir + 1 : 0;
//         }
//         //向前走
//         else{
//             step = commands[i];
//             while(step--){
//                 pos[0] += dirx[dir];
//                 pos[1] += diry[dir];
//                 // 是障碍物就往回走
//                 if(isObstacle(pos, obstacles, obstaclesSize, obstaclesColSize)){
//                     pos[0] -= dirx[dir];
//                     pos[1] -= diry[dir];
//                     break;
//                 }
//             }
//             dis = pow(pos[0], 2) + pow(pos[1], 2);
//             res = res > dis ? res : dis;
//         }
//     }
//     return res;
// }
#define max(a,b) ((a) > (b))?(a):(b)

typedef struct node {
    int x;
    int y;
}node;

int cmpfunc(const void*a,const void*b)
{
    node* ap = (node*)a;
    node* bp = (node*)b;
    if(ap->x != bp->x)
    {
        return ap->x - bp->x;
    }
    return ap->y - bp->y;
}

int getNextDir(int cur_dir, int command) {
    if(command == -1) {
        cur_dir++;
    } else {
        cur_dir--;
    }
    int tmp = cur_dir % 4;
    return (tmp >= 0)?tmp:(tmp + 4);
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) 
{
    int max_dir = 0;
    int curX = 0;
    int curY = 0;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //上右下左
    int cur_dir = 0;

    node next;
    node *ob = (node *)malloc(sizeof(node) * obstaclesSize);
    
    for(int i = 0; i < obstaclesSize; i++)
    {
        ob[i].x = obstacles[i][0];
        ob[i].y = obstacles[i][1];
    }

    qsort(ob, obstaclesSize,sizeof(node),cmpfunc);
    
    for(int i = 0; i < commandsSize; i++) {
        if(commands[i] == -1 || commands[i] == -2) {
            cur_dir = getNextDir(cur_dir, commands[i]);
        } else if(commands[i] >= 1 && commands[i] <= 9) {
            while(commands[i]--) {
                next.x = curX + dir[cur_dir][0];
                next.y = curY + dir[cur_dir][1];
                node *item = (node*)bsearch(&next, ob, obstaclesSize, sizeof(node), cmpfunc);
                if(item != NULL) {
                    break;
                } else{
                    curX = next.x;
                    curY = next.y;
                }
            }
        }
        max_dir = max(max_dir,(curX * curX) + (curY * curY));
    }
    return max_dir;
}

// @lc code=end

