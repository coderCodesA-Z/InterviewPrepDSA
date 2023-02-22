#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;


void file_i_o() {
  	std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void findUnion(int *a1, int *a2, int n, int m) {
	int *res = new int[n + m];

	for(int i = 0; i<n+m;i++) res[i] = 0;

	int i = 0, j = 0, k = 0;
	while(i < n and j < m) {
		cout<<i<<" "<<j<<" "<<k<<"\n";
		if(a1[i] == a2[j]) {
			res[k] = a1[i];
			k++;
			i++;
			j++;
		}

		else if(a1[i] < a2[j]) {
			res[k] = a1[i];
			k++;
			i++;
		} else {
			res[k] = a2[j];
			k++;
			j++;
		}

		// union array not empty and last element inserted in union array is not equal to current
		// element of a1 / a2
		while(res[k - 1] == a1[i]) i++;
		while(res[k - 1] == a2[j]) j++;
		cout<<i<<" "<<j<<" "<<k<<"\n";

	}

	while(i < n) {
		if(res[k - 1] != a1[i]) {
			res[k] = a1[i];
			k++;
		}
		i++; 
	}

	while(j < m) {
		if(res[k - 1] != a2[j]) {
			res[k] = a2[j];
			k++;
		}
		j++; 
	}


	logarr(res, 0, k-1);
}

int main() {
    clock_t begin = clock();
    file_i_o();

    int n, m;
    cin>>n>>m;

    int *a1, *a2;

    a1 = new int[n];
    a2 = new int[m];

    for(int i =0; i< n; i++) cin>>a1[i];
    for(int i =0; i< m; i++) cin>>a2[i];

    findUnion(a1, a2, n , m);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}