/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int sumImp = 0;
    int getImportance(vector<Employee*> employees, int id) {
        // It is given that each employee has at most one leader -> shape trees
        // All the subordinates can be found under its node
        // 1. find the id, the node
        // 2. add all the subordinates' importance
        dfs(employees, id);
        return sumImp;
    }
    // Find the subordinates of leader and add sumImp
    void dfs(const vector<Employee*> &employees, int id){
        for (auto leader : employees){
            if (leader->id == id){
                sumImp += leader->importance;
                for (auto subordID : leader->subordinates){
                    dfs(employees, subordID);
                }
            }
        }
    }

};
