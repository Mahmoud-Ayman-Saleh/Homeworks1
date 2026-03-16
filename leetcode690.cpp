#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;





// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution
{
private:
unordered_map <int, Employee*> id_to_emp;


int dfs(int id)
{
    Employee *emp = id_to_emp[id];
    int ans = emp->importance;
    for (auto &i : emp->subordinates)
    {
        ans += dfs(i);
    }
    return ans;
}
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        for (auto &emp : employees)
        {
            id_to_emp[emp->id] = emp;
        }
        return dfs(id);
    }
};

