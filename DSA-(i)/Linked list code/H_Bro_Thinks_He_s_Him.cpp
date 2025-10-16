#include<iostream>
using namespace std;
using ll=long long;
using ld=long double;
#define int ll
using pii=pair<int,int>;
const int N=2e5+5,mod=998244353;
int n,pw[N];
struct BIT
{
	int tr[N];
	void clear(){for(int i=0;i<=n;i++)tr[i]=0;}
	void update(int s,int x){for(;s<=n;s+=s&(-s))tr[s]=((tr[s]+x)%mod+mod)%mod;}
	int query(int s){int res=0;for(;s;s-=s&(-s))res=(res+tr[s])%mod;return (res+mod)%mod;}
}tr[2];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=2ll*pw[i-1]%mod;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s,n=s.length(),s=" "+s;
		tr[0].clear(),tr[1].clear();
		int ans=(pw[n]+mod-1)%mod;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				ans=(ans+1ll*(pw[i-1]+mod-1+mod-tr[0].query(i-1))*pw[n-i]%mod)%mod;
				tr[0].update(i,pw[i-1]),tr[1].update(i,pw[n-i]);
			}
			else ans=(ans+1ll*pw[n-i]*tr[0].query(i)%mod)%mod;
		}
		int q;
		cin>>q;
		while(q--)
		{
			int p;
			cin>>p;
			if(s[p]=='1')
			{
				s[p]='0';
				ans=(ans+mod-1ll*(pw[p-1]+mod-1+mod-tr[0].query(p-1))*pw[n-p]%mod)%mod;
				ans=(ans+mod-1ll*(pw[n-p]+mod-1+mod-(tr[1].query(n)+mod-tr[1].query(p))%mod)*pw[p-1]%mod)%mod;
				tr[0].update(p,mod-pw[p-1]),tr[1].update(p,mod-pw[n-p]);
				ans=(ans+1ll*tr[0].query(p-1)*pw[n-p]%mod)%mod;
				ans=(ans+1ll*(tr[1].query(n)+mod-tr[1].query(p))%mod*pw[p-1]%mod)%mod;
			}
			else if(s[p]=='0')
			{
				s[p]='1';
				ans=(ans+1ll*(pw[p-1]+mod-1+mod-tr[0].query(p-1))*pw[n-p]%mod)%mod;
				ans=(ans+1ll*(pw[n-p]+mod-1+mod-(tr[1].query(n)+mod-tr[1].query(p))%mod)*pw[p-1]%mod)%mod;
				tr[0].update(p,pw[p-1]),tr[1].update(p,pw[n-p]);
				ans=(ans+mod-1ll*tr[0].query(p-1)*pw[n-p]%mod)%mod;
				ans=(ans+mod-1ll*(tr[1].query(n)+mod-tr[1].query(p))%mod*pw[p-1]%mod)%mod;
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
	return 0;
}