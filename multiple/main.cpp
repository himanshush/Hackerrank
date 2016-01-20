#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
using namespace std;
int nthMultipleNumber(vector<int> arr, int n) {
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	int i, ret;

	if (arr.size() == 0 || n <= 0) return 0;

	for (i = 0;i < arr.size(); i++) {
		q.push(make_pair(arr[i], i));
	}

	ret = 0;
	while (n) {
		if (ret != q.top().first) n--;
		ret = q.top().first;
		i = q.top().second;
		q.pop();
		q.push(make_pair(ret + arr[i], i));
	}

	return ret;
}

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
    cout << nthMultipleNumber(v,t);
    //vector<int> ans = s.twoSum(v,t);
    //cout << ans[0] <<' ' << ans[1] << endl;
}
