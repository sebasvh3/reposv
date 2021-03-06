#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define D(x) cout << #x << " : " << x << endl;

#define For(i,a) for(int i=0; i<a; i++)
#define Fori(i,a,b) for(int i=a; i<b; i++)
#define Forn(i,a,b,c) for(int i=a; i<b; i+=c)
#define pb push_back
#define mp make_pair

#define lli long long int 

int main(){
  #ifdef SV
    freopen("in","r",stdin);
  #endif
  int n,m;
  while(cin>>n>>m){
      int ini = 1,dest=0;
      lli times=0;
      For(i,m){
          cin>>dest;
          if(dest<ini) times+=(n-ini)+dest;
          else times+=dest-ini;
          ini=dest;
      }
      cout <<times<<endl;
  }
  return 0;
}


