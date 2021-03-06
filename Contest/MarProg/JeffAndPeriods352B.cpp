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

#define vi vector<int>
#define miv map<int,vi>
#define mii map<int,int>
#define vpii vector< pair<int,int> >

int main(){
  #ifdef SV
    freopen("in","r",stdin);
  #endif
  int n,num;
  miv sequence;
  while(cin>>n){
      
      For(i,n){
          cin>>num;
          sequence[num].pb(i);
      }
      
      miv::iterator it = sequence.begin();
      vpii res;
      int cont=0;
      while(it!=sequence.end()){
          int size=it->second.size();
          int diff=0;
          if(size==1){
              cont++;
              res.pb(mp((*it).first,0));
          }
          else{
              vi vector = it->second;
              diff = vector[1]-vector[0];
              if(size==2){
                  res.pb(mp(it->first,diff));
                  cont++;
              }
              else{
                  bool seguir = false;
                  int diff2;
                  Fori(i,1,size-1){
                      diff2 = vector[i+1]-vector[i];
                      if(diff!=diff2){
                          seguir=true;
                          break;
                      }
                  }
                  if(!seguir){
                      res.pb(mp(it->first,diff));
                      cont++;
                  }
                  
              }
          }
          ++it;
      }
      cout <<cont<<endl;
      For(i,res.size()){
          cout<<res[i].first<<" "<<res[i].second<<endl;
      }
      
  }
  return 0;
}

