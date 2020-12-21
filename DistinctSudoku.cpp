//IaMaNanBord//

#include <bits/stdc++.h>
using namespace std;

//Macro Shorthands
#define F                       first
#define S                       second
#define f(i,n)                  for(ll i=0;i<=n;i++)
#define rf(i,n)                 for(ll i=n;i>=0;i--)
#define Cf(i,a,b)               for(ll i=a;i<=b;i++)
#define Crf(i,b,a)              for(ll i=b;i>=a;i--)
// #define endl                    '\n'           
#define pb                      push_back
#define mp                      make_pair
#define z                       ((ll)1e9 + 7)  
#define every(it,x)             for(auto &it:x)
#define SET(it,x)               for(auto &it:x){cin>>it;}
#define ins                     insert
#define INF						((ll)1e18)
#define Test                    ll T; cin>>T; while(T--)
#define all(v)                  v.begin(),v.end()
#define nline                   cout<<endl
#define SZ(v)                   (ll)v.size()
#define pll                     pair<ll,ll>  
 
//Macro Shorthands
#ifndef ONLINE_JUDGE
    #define revelio(args...)        { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
    #define revelio(args...)        {}
#endif

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl; err(++it, args...);}

//Data types
typedef long long               ll;
typedef vector<ll>              vll;
typedef vector<string>          vstr;
typedef vector<char>            vchar;
typedef vector<pair<ll,ll> >    vpll;
typedef vector<vector<ll> >     vvll;
typedef set<ll>                 sll;
typedef set<string>             sstr;
typedef set<pair<ll,ll> >       spll;
typedef map<ll,ll>              mllll;
typedef map<string,ll>          mstrll;
typedef queue<ll>               qll;

// --------------------------------Useful Code Starts From Here---------------------//

ll n = 9;
set<vvll> ss;
ll itr = 0;
void printSudoku(vvll &x){
    f(i,n){
        if(i%3==0){
            for(int j=0 ; j<25 ; j++){
                cout<<'-';
            }
            cout<<"\n";
        }
        if(i!=9)
            f(j,n){  
                if(j%3==0)cout<<"| ";
                if(j!=9)
                cout<<x[i][j]<<" ";
            }
            cout<<"\n";
    }
    nline;
    ss.ins(x);
    itr++;
}

//-----------------------------------Operation Functions Starts-------------------//
vvll rot90(vvll &x, ll time){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
            t[i][j] = x[(n-j-1)][(i)];
        }
    }
    if(time>1){
        return rot90(t, time-1);
    }
    else{
        return t;
    }
}



vvll vflip(vvll &x){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
            t[i][j] = x[(n-i-1)][(j)];
        }
    }
    return t;
}

vvll LTRBflip(vvll &x){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
            t[i][j] = x[j][i]; 
        }
    }
    return t;
}

vvll LBRTflip(vvll &x){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
            t[i][j] = x[n-1-j][n-1-i];
        }
    }
    return t;
}

vvll hflip(vvll &x){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
           t[i][j] = x[(i)][(n-1-j)];
        }
    }
    return t;
}

vvll dangerflip(vvll &x){
    vvll t(n, vll(n));
    f(i,n-1){
        f(j,n-1){
            t[i][j] = x[3*(i/3+1)-1-i%3][3*(j/3+1)-1-j%3];
        }
    }
    return t;
}
//-----------------------------------Operation Functions Ends-------------------//

void solve(){
    
    vvll a(n,vll(n));
    f(i,n-1){
        f(j,n-1){
            a[i][j] = (i*3 + (i/3)*2 +j)%n + 1;
        }
    }
    vvll tmp ;

    
//--------------------------You May Comment from this Part--------------------//
    cout<<"Identity"<<endl;
    printSudoku(tmp = a);
    cout<<"ROT90"<<endl;
    printSudoku(tmp = rot90(a,1));
    cout<<"ROT180"<<endl;
    printSudoku(tmp = rot90(a,2));
    cout<<"ROT270"<<endl;
    printSudoku(tmp = rot90(a,3));
    cout<<"Vertical Flip"<<endl;
    printSudoku(tmp = vflip(a));
    cout<<"Horizontal Flip"<<endl;
    printSudoku(tmp = hflip(a));
    cout<<"LTRB Flip"<<endl;
    printSudoku(tmp = LTRBflip(a));
    cout<<"LBRT Flip"<<endl;
    printSudoku(tmp = LBRTflip(a));
    cout<<"Dang Flip"<<endl;
    printSudoku(tmp = dangerflip(a));
    cout<<"Composite 7 : Dang(Operation)"<<endl;
    printSudoku(tmp = dangerflip(tmp = rot90(a,1)));
    printSudoku(tmp = dangerflip(tmp = rot90(a,2)));
    printSudoku(tmp = dangerflip(tmp = rot90(a,3)));
    printSudoku(tmp = dangerflip(tmp = vflip(a)));
    printSudoku(tmp = dangerflip(tmp = hflip(a)));
    printSudoku(tmp = dangerflip(tmp = LTRBflip(a)));
    printSudoku(tmp = dangerflip(tmp = LBRTflip(a)));
//--------------------------You May Comment upto this Part--------------------//

//--------------------------Only make changes here-----------------------------//
    
    
    // cout<<"(Repeated)Composite : LTRBflip then ROT90"<<endl;
    // To print a sudoku after applying an operation 
    // printSudoku(tmp = operationFunction(a)));
    // For Composite operation
    // printSudoku(tmp = operationFunction1(tmp = operationFunction2(a))));





//-------------------------Only make changes upto here--------------------------//
    cout<<"Total Different Sudokus : "<<SZ(ss)<<" / "<<itr<<endl;

}
// --------------------------------Useful Code Ends Here--------------------------//


int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// freopen("error.txt","w",stderr);
    // #else
    
    // #endif
    solve();
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: "<<1.0*clock()/ CLOCKS_PER_SEC<<" Sec\n";
    #endif
    return 0;
}
