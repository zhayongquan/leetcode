#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    //记录先序课程的依赖边，e.g:edges[1]={0,2},表示0，2课程需要先序课程1.
    vector<vector<int>>edges;
    //记录该课程有几个先序课程，e.g:indeg[0] = 1,表示第0号课程还有1个先序课程
    vector<int>indeg;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(auto info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        queue<int> q;
        for(int i = 0; i < indeg.size(); ++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int visited = 0;
        while(!q.empty()){
            ++visited;
            int u = q.front();
            q.pop();
            for(int v : edges[u]){
                --indeg[v];
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return numCourses == visited;
    }
};
int main(){
    Solution sol;
    int numCourse = 2;
    vector<vector<int>>input = {{0,1}};
    if(sol.canFinish(numCourse,input))
        cout<<"can finish"<<endl;
    return 0;
}