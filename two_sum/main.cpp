#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> my_map;
        vector<int>::iterator it_v;
        map<int,int>:: iterator it_m;
        int i=1;
        int tmp=0;
        vector<int> ans;
        for(it_v=nums.begin();it_v!=nums.end();++it_v)
        {
            //cout << "hello" << endl;
            tmp=target-*it_v;
            it_m=my_map.find(tmp);
            if(it_m!=my_map.end())
            {
                ans.push_back(it_m->second);
                ans.push_back(i);
                break;
            }
            my_map[*it_v]=i;
            i++;
        }
        return ans;
    }
    int maxArea(vector<int>& height) {
        int res=0;
        int l=0;
        int r=height.size()-1;
        while(r>l)
        {
            int curr = min(height[l],height[r])*(r-l);
            res = max(curr,res);
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
        return res;
    }
};

int main()
{

    int N,t;
    cin >> N >> t;
    vector<int> v;
    int tmp;
    for(int i=0;i<N;i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    Solution s;
    //vector<int> ans = s.twoSum(v,t);
    //cout << ans[0] <<' ' << ans[1] << endl;
    cout << s.maxArea(v) << endl;;
}
