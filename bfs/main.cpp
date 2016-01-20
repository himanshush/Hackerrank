#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

void bfs(int s,list<int> *graph,int N)
{
    int ans[N+1];
    int visit[N+1];
    for(int i=1;i<=N;i++)
    {
        ans[i]=-1;
        visit[i]=-1;
    }
    queue<pair <int,int> > q;
    q.push(make_pair(s,0));
    ans[s]=0;
    visit[s]=1;
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        ans[u.first]=u.second;
        visit[u.first]=1;
        list<int>::iterator it;
        for(it=graph[u.first].begin();it!=graph[u.first].end();++it)
        {
            if(visit[*it]==-1)
            {
                //cout << *it << endl;
                int level = u.second+1;
                q.push(make_pair(*it,level));
                visit[*it]=1;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(i!=s)
        {
            if(ans[i]==-1)
                cout << ans[i] << ' ';
            else
                cout << ans[i]*6 <<' ';
        }
    }
    cout << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int N,M;
        cin >> N >> M;
        list<int>  graph[N+1];
        for(int j=0;j<M;j++)
        {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s;
        cin >> s;
        bfs(s,graph,N);
        /*list<int>::iterator it;
        for(int j=1;j<=N;j++)
        {
            for(it=graph[j].begin();it!=graph[j].end();++it)
                cout << *it;
            cout << endl;
        }*/
    }
    return 0;
}
