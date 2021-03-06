/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-09-25 15:06:14
 * Problem   : 1041 - Road Construction
 * CPU       : 0.008
 * Memory    : 1700
**/
#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (ll i = a; i < n; i += step)
#define repd(i,a,n,step) for (ll i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {int n=0,sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
ll readl () {ll n=0;int sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
//
class cmp {
	public:
		bool operator() (pair<pair<ll,ll>,ll> &a, pair<pair<ll,ll>,ll> &b) {
			return a.first.second > b.first.second;
		}
};
ll prims (vector<pair<ll,ll> > graph[], ll n) {
	priority_queue <pair<pair<ll,ll>,ll>, vector<pair<pair<ll,ll>,ll> >, cmp > pq;
	//cout<<n<<"\n";
	bool vis[n+1];
	fill( vis, vis+n+1, false);
	pq.push(mp(mp(0,0),1));
	ll id=1, cost=0,ans=0;
	while (!pq.empty()) {
		id = pq.top().second;
		cost = pq.top().first.first;

		if (vis[id]) {
			pq.pop();
			continue;
		}
		ans += pq.top().first.second;
		vis[id] = true;
	//	cout<<id<<" "<<cost<<" "<<pq.top().first.second<<"\n";
		pq.pop();
		for (ll i=0; i < graph[id].size(); i++) {
			//cout<<"This:";
			if (!vis[graph[id][i].first]) {
				pq.push(mp(mp(graph[id][i].second+cost,graph[id][i].second), graph[id][i].first));
				//cout<<graph[id][i].second+cost<<" "<<graph[id][i].second<<" "<<graph[id][i].first<<"\n";
			}
		}
	}
	repu(i,1,n+1,1) {
		//cout<<i<<" ";
		if (!vis[i]) return -1;
	}

	return ans;
}
void printmap (map<string, ll> mapper) {
	map<string, ll> :: iterator it;
	for (it = mapper.begin(); it != mapper.end(); it++) {
		cout<<it->first<<" "<<it->second<<"\n";
	}
}
void printgr(vector <pair<ll,ll> > graph[], ll n) {
	for (ll i=1; i <= n; i++) {
		cout<<i<<":";
		for (ll j=0; j < graph[i].size(); j++) {
			cout<<graph[i][j].first<<","<<graph[i][j].second<<"\n";
		}
		cout<<"\n";
	}
}
int main() {
	ll t,m,cost,id;
	string city1,city2;
	t=readi();
	repu(tc,1,t+1,1) {
		map<string, ll> mapper;
		vector <pair<ll,ll> > graph[1010];
		id = 0;
		m=readi();
		while (m--) {
			cin>>city1>>city2>>cost;
			if (!mapper[city1])
				mapper[city1] = ++id;
			if (!mapper[city2])
				mapper[city2] = ++id;
			graph[mapper[city1]].pb(mp(mapper[city2],cost));
			graph[mapper[city2]].pb(mp(mapper[city1],cost));
		}
//		printmap(mapper);
//		printgr(graph,id);
		ll ans = prims(graph, id);

		if (ans == -1)
			printf("Case %lld: Impossible\n", tc);
		else
			printf("Case %lld: %lld\n", tc, ans);

	}
	return 0;
}
