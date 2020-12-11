/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

int romanToInt(char *s){
    int res = 0;
	while (*s){
		if (*s == 'V')         res += 5;
		else if (*s == 'L')    res += 50;
		else if (*s == 'D')    res += 500;
		else if (*s == 'M')    res += 1000;
		else if (*s == 'I')
			res = (*(s + 1) == 'V' || *(s + 1) == 'X') ? res - 1 : res + 1;
		else if (*s == 'X')
			res = (*(s + 1) == 'L' || *(s + 1) == 'C') ? res - 10 : res + 10;
		else
			res = (*(s + 1) == 'D' || *(s + 1) == 'M') ? res - 100 : res + 100;
		s++;
	}
	return res;
}

/*一直报错
runtime error: load of null pointer of type 'char' (solution.c)
后来发现是设置输入数据时没加引号
*/

/*解法二 先将罗马字符转换为数字，然后判断前一个是大或小
int reverse2num(char s){
    int num[] = {1,5,10,50,100,500,1000},i = 0;
    char *roman = "IVXLCDM";

    while(s != roman[i]){
        i++;
    }

    return num[i];
}

int romanToInt(char * s){
    int count = reverse2num(s[0]),pre = reverse2num(s[0]);
    for(int i = 1;s[i] != '\0';i++){
        if(pre < reverse2num(s[i])){
            count = count + reverse2num(s[i]) - pre*2;
        }else
            count += reverse2num(s[i]);
        pre = reverse2num(s[i]);
    }

    return count;
}*/



// @lc code=end

