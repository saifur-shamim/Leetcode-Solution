///Bismillahir Rahmanir Rahim
///Happy Coding

/*

     * * * *             *              *  * * * * * *   *            *   * * * * *
    *                   * *             *  *             *            *   *         *
    *                  *   *            *  *             *            *   *          *
    *                 *     *           *  *             *            *   *           *
    *                *       *          *  *             *            *   *           *
     *              *         *         *  * * * * * *   *            *   *          *
       *           *           *        *  *             *            *   * * * * * *
         *        *             *       *  *             *            *   *  *
          *      * * * * * * * * *      *  *             *            *   *    *
           *    *                 *     *  *             *            *   *      *
           *   *                   *    *  *             *            *   *        *
           *  *                     *   *  *              *          *    *          *
    * * * *  *                       *  *  *                * * * * *     *            *


*/


#include<bits/stdc++.h>

using namespace std;


#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

///order_of_key (val) : Number of items strictly smaller than val.
///find_by_order(x) : x-th element in a set (zero based index).

typedef  long long ll;
typedef  long int li;
typedef  unsigned long long ull;
typedef  double dl;
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<pii>vpi;
typedef  vector<pll> vpl;

#define     pb        push_back
#define     dlt       pop_back
#define     MP        make_pair
#define     F         first
#define     S         second
#define     sz(x)     (int)x.size()
#define     all(a)    (a).begin(),(a).end()
#define     faster    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define     endl      '\n'
#define     mem(a,b)  memset(a,b,sizeof(a))
#define     mod       1000000007
#define     gcd(a,b)  __gcd(a,b)
#define     pf        printf
#define     YES       cout<<"YES\n"
#define     Yes       cout<<"Yes\n"
#define     NO        cout<<"NO\n"
#define     No        cout<<"No\n"
#define     nl        cout<<endl
#define     mone      cout<<"-1\n"
#define    For(i,a,b)  for(i = a; i <= b; i++)
#define    Forr(i,a,b)  for(i = a; i >= b; i--)

// int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
// int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

//            { U  , D ,  L  , R , UL  , UR  , DL  , DR }

const dl PI=acos(-1);
const int inf=2e9;
const ll infll=900000000000000000;


class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {

        vi ans(n);

        ans[0]=0;
        int dis[n+2];
        sort(all(edges));

        vpi adj[n];

        for(int i=0; i<sz(edges); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            if(u==v)
                continue;
            adj[u].pb({v,w});
            adj[v].pb({u,w});

        }

        for(int i=0; i<n; i++)
        {
            dis[i]=inf;
        }
        dis[0]=0;
        priority_queue<pii,vpi,greater<pii>> pq;

        pq.push({0,0});
        while(!pq.empty())
        {
            ll curd=pq.top().F;
            ll node=pq.top().S;
            pq.pop();
            if(dis[node]<curd) continue;
            for(auto it:adj[node])
            {
                ll child=it.F;

                ll w=it.S;

                if(curd+w<dis[child] and curd+w<disappear[child])
                {
                    dis[child]=curd+w;
                    pq.push({dis[child],child});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(dis[i]!=inf)
            {
                ans[i]=dis[i];
            }
            else
            {
                ans[i]=-1;
            }
        }

        return ans;
    }


};
