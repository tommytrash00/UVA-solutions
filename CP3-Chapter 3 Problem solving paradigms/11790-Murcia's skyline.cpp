/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE

#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODR(d) ((d)>=MOD?(d)%MOD:(d))
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;


#define foreachb(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it!=(c).rend(); it++) 
#define MAX 100005
#define ll long long

using namespace std;
ll arr[MAX],sum[MAX],width[MAX];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int t;
	cin>>t;
	int caseno=1;
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){cin>>arr[i];sum[i]=0;}
		for(int i=0;i<n;i++){cin>>width[i];}
		
		ll LIS=0,LDS=0,best=0;
		
		//LIS
		
		for(int i=0;i<n;i++)
		{
			sum[i]=width[i];
			
			for(int j=0;j<i;j++)
			if(arr[j]<arr[i] && sum[i]<sum[j]+width[i])
			{
				sum[i]=sum[j]+width[i];
			}
			
			if(sum[i]>sum[best]) best=i;
		}
		
		LIS=sum[best];
		
		//LDS
		
		best=0;
		for(int i=0;i<n;i++)
		{
			sum[i]=width[i];
			
			for(int j=0;j<i;j++)
			if(arr[j] > arr[i] && sum[i]<sum[j]+width[i])
			{
				sum[i]=sum[j]+width[i];
			}
			
			if(sum[i]>sum[best]) best=i;
		}
		
		
		LDS=sum[best];
	
	
	if(LIS>=LDS)
	cout<<"Case "<<caseno<<". Increasing ("<<LIS<<"). Decreasing ("<<LDS<<")."<<"\n";
	else
	cout<<"Case "<<caseno<<". Decreasing ("<<LDS<<"). Increasing ("<<LIS<<")."<<"\n";
	caseno++;
		
	}
	
	
	

	return 0;
}
