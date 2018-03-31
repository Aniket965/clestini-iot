#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define sec second
#define pii pair < ll, ll > 
#define N 100005
vector <list < pii > > a(N), b(N), c(N);
void insertinC( pii x , ll val)
{
	bool inserted = 0;
	list < pii > :: iterator it = c[x.fi].begin();
	while(it!=c[x.fi].end())
	{
		if ( (*it).fi > x.sec )
		{
			c[x.fi].insert(it,mp(x.sec,val));
			inserted = 1;
			break;
		}
		else if ( (*it).fi == x.sec )
		{
			(*it).sec += val;
			inserted = 1;
			break;
		}
		it++;
	}
	if ( !inserted )
		c[x.fi].insert(it,mp(x.sec,val));
}
void multiply( ll n )
{
	for ( ll i = 1; i <= n; i ++ )
	{
		for ( auto it : a[i] )
		{
			ll r = i;
			ll c = it.fi;
			for ( auto it2 : b[c] )
			{
				insertinC(mp(r,it2.fi),(it2.sec)*(it.sec));
			}
		}
	}
}
ll convolution( ll n )
{
	// returns a single element for both the kernel and matrix 
	// being n*n
	ll ans = 0;
	for ( ll i = 1; i <= n; i ++)
	{
		list < pii > :: iterator ita = a[i].begin();
		list < pii > :: iterator itb = b[i].begin();
		while( ita != a[i].end() and itb != b[i].end() )
		{
			if ( (*ita).fi == (*itb).fi )
			{
				ans += ((*ita).sec)*((*itb).sec);
				ita++;
				itb++;
			}
			else if ( (*ita).fi < (*itb).fi )
			{
				ita ++;
			}
			else
			{
				itb++;
			}

		}
	}
	return ans;
}
int main()
{
	//C is the final answer
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll n,m1,m2;
    cout << "Enter the value of n for nXn matrix\n";
    cin >> n;
    cout << "Enter the number of elements in first matrix\n";
    cin >> m1;
    cout << "Enter the number of elements in second matrix\n";
    cin >> m2;
    cout << "Enter the elements in first matrix in sorted form first on the basis of row then column\n";
    for ( ll i = 1; i <= m1; i ++)
    {
    	ll r,c,val;
    	cin >> r >> c >> val;
    	a[r].pb(mp(c,val));
    }
    cout << "Enter the elements in second matrix in sorted form first on the basis of row then column\n";
    for ( ll i = 1; i <= m2; i ++)
    {
    	ll r,c,val;
    	cin >> r >> c >> val;
    	b[r].pb(mp(c,val));
    }
    multiply(n);
    for ( ll i = 1; i <= n; i ++)
    {
    	cout << i <<":";// row number
    	for ( auto it : c[i] )
    	{
    		cout << "(" <<(it.fi) <<","<< (it.sec)<<") ";// column number and value
    	} 
    	cout <<"\n";
    }
    cout << convolution(n) << endl;
}