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

int maximize1(int *a, int n, int m) {
	int max1 = 0, right = 0, temp = m;

	if(n == 1) { // when only 1 element is present

		if(a[0] == 1 || a[0] == 0 and m > 0) return 1; // if the element is 1 then max 
		else return 0;
	}

	if(m == 0) { // no bits can be flipped
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) count++;
			if(a[i] == 0) count=0;
			max1 = max(max1, count);
		}
		return max1;
	}

	int left = 0;
	for(; left < n; left++) { // sliding window
		while(right < n and (a[right] == 1 || temp != 0)) {
			temp-=(a[right] == 0);
			right++;
		}

		max1 = max(max1, right - left);

		if(max1 == n) break; // all 0's can be flipped

		if(temp < m and a[left] == 0) temp++;
	}

	return max1;
}

int main() {
    clock_t begin = clock();
    file_i_o();

    int n, m;
    cin>>n>>m;

    int *a;
    a = new int[n];

    for(int i = 0; i < n; i++) cin>>a[i];

    cout<<maximize1(a, n, m);


    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}