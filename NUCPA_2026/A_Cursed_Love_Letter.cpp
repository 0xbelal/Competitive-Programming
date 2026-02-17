#include <iostream>
#include <string>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


   string s,res="";cin>>s;
   string ref="NUCPA";
   for(char c:s){
      res+= toupper(c);
   }
   cout<<((res==ref )? "Yes":"No");
    

    return 0;
}