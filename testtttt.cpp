#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define gcd __gcd
#define nof1 __builtin_popcountll
#define nofleading_zerosull __builtin_clzll

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<long long int> vl;

const double pi = 2 * acos(0.0);
const int inf = 0x3f3f3f3f;//(ll) 9e18
const double infd = 1.0/0.0;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a+n
//#define endl "\n"

long long power(long long x, long long y,long long MOD)
{
	long long res = 1; 
	x = x % MOD; 

	while (y > 0)
	{
		if (y & 1)
		res = (res*x) % MOD;
		y = y>>1;
		x = (x*x) % MOD;
	}
	return res;
}
long long mul(long long a,long long b,long long MOD)
{
	if(b==1)
	{
		return a;
	}	
	if(b%2==0)
	{
		return 2*(mul(a,b/2,MOD)%MOD);
	}
	else
	{
		return (a+(2*(mul(a,b/2,MOD))%MOD))%MOD;
	}
}

/*ll ncr[6001][6001];
void nCr(long long MOD)
{
	for(ll i=0;i<=6000;i++)
	{
		for(ll k=0;k<=6000;k++)
		{
			if(k<=i)
			{
				if((k==0)||(k==i))
				ncr[i][k]=1;
				else
				ncr[i][k]=(ncr[i-1][k-1]+ncr[i-1][k])%MOD;
			}
		}
	} 
}

ll inv[100005];
void mulmodinv(long long MOD)
{
	inv[1]=1;
	inv[0]=1;
	for(int i = 2; i <= 100005; i++)
	inv[i] = inv[MOD % i]*(MOD-MOD / i) % MOD;
}*/

bool ispow2(ll n)
{
	if(((n & (n-1)) == 0) && n!=0)
	{
		return true;
	}
	return false;
}
bool prime(int x)
{
	if(x==1)
	{
		return false;
	}
	if(x==2)
	{
		return true;
	}
	if(x%2==0)
	{
		return false;
	}
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			return false;
		}
	}
 return true;
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
int coprime(int a, int b) 
{ 
	if(a==b)
		return 0;
    if(prime(a) && prime(b)) 
        return 1; 
    if((a==2 && b%2!=0) ||(b==2 && a%2!=0))
		return 1;
	if((a%2!=0 && prime(b) && a<b ) || (b%2!=0 && prime(a) && a>b))
		return 1;
	if(abs(a-b)==1)
		return 1;
	if(a==1 || b==1)
		return 1;
	return gcd(a,b);
}
unsigned long long lcm (unsigned a, unsigned b)
{
    return ((unsigned long long) a) * (b / gcd(a, b));
}
//======================================================================
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	string s1, s2;
	cin>>s1;
	cin>>s2;

	vector<int>c1(27, 0), c2(27, 0);
	vector<int> ind1[27], ind2[27];
	for(int i=0;i<n;i++)
	{
		if(s1[i]!='?')
		{
			c1[s1[i]-'a']++;
			ind1[s1[i]-'a'].pb(i);
		}
		else{
			c1[26]++;
			ind1[26].pb(i);
		}
		if(s2[i]!='?')
		{
			c2[s2[i]-'a']++;
			ind2[s2[i]-'a'].pb(i);
		}
		else
		{
			c2[26]++;
			ind2[26].pb(i);
		}
	}
	
	vector<int> ap1(27, 0), ap2(27, 0);
	ll ans = 0;
	vector<pair<int, int> > p;
	for(int i=0;i<26;i++)
	{
		int c = min(c1[i], c2[i]);
		for(int j=c;j<c;j++)
		{
			int r = ind1[i][ap1[i]];
			int q = ind2[i][ap2[i]];
			p.pb(mp(r, q));
			ap1[i]++;
			ap2[i]++;
		}
		ans += c;

		c1[i] -= c;
		c2[i] -= c;

		c = min(c1[i], c2[26]);

		for(int j=1;j<c;j++)
		{
			int r = ind1[i][ap1[i]];
			int q = ind2[26][ap2[26]];
			p.pb(mp(r, q));
			ap1[i]++;
			ap2[26]++;
		}
		ans += c;
		c1[i] -= c;
		c2[26] -= c;

		c = min(c1[26], c2[i]);
		for(int j=1;j<=c;j++)
		{
			int r = ind1[26][ap1[26]];
			int q = ind2[i][ap2[i]];
			p.pb(mp(r, q));
			ap1[26]++;
			ap2[i]++;
		}

		ans += c;
		c1[26] -= c;
		c2[i] -= c;


		
	}
	cout<<ans<<endl;

	n = p.size();
	for(int i=0;i<n;i++)
	{
		cout<<p[i].fr+1<<" "<<p[i].sc+1<<endl;
	}
	return 0;
    
	return 0;
}
