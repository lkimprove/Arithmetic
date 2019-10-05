//LeetCode

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int DFS(unordered_map<int, Employee*>& em, int id){
        //获取当前员工的重要度
        int curRet = em[id]->importance;
        
        //获取当前员工所有下属的重要度
        for(auto& e : em[id]->subordinates){
            curRet += DFS(em, e);
        }
        
        return curRet;
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
        //创建unordered_map，便于搜索
        unordered_map<int, Employee*> em;
        
        for(auto& e : employees){
            em[e->id] = e;
        } 
        
        return DFS(em, id);
    }
};
