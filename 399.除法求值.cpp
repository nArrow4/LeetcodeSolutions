/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        std::unordered_map<std::string, int> variables;
        int nvars = 0;// numbers of variables
        int n = equations.size();
        for (int i = 0; i < n; i++){
            if(variables.find(equations[i][0]) == variables.end()){
                variables[equations[i][0]] = nvars++;
            }
            if(variables.find(equations[i][1]) == variables.end()){
                variables[equations[i][1]] = nvars++;
            }
        }
        std::vector<int> f(nvars);
        std::vector<double> w(nvars, 1.0);
        for (int i = 0; i < nvars; i++){
            f[i] = i;
        }
        for (int i = 0; i < n; i++){
            int va = variables[equations[i][0]];
            int vb = variables[equations[i][1]];
            merge(f, w, va, vb, values[i]);
        }
        std::vector<double> ret;
        for(const auto& q : queries){
            double result = -1.0;
            if(variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()){
                int ia = variables[q[0]];
                int ib = variables[q[1]];
                int fa = findf(f, w, ia);
                int fb = findf(f, w, ib);
                if(fa == fb){
                    result = w[ia] / w[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
private:
    void merge(std::vector<int>& f, std::vector<double>& w, int x, int y, double val){
        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
    }
    int findf(std::vector<int>& f, std::vector<double>& w, int x){
        if(f[x] != x){
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];  
    }
};
// @lc code=end

