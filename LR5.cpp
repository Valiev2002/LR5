#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <vector>

using namespace std;
//ad1

typedef unordered_multimap<int, string>::iterator umit; 
int main()
{
unordered_multimap<int,string> umm2 ({{1,"swag"}, 
                                           {2,"grrrrpow"}, 
                                           { 3,"hustle"}, 
                                    
                                           {3,"hustle"}, 
                                           {2,"grrrrpow"}, 
                                           {1,"swag"}}); 
  
umm2.erase(3);
umm2.erase(2);
umm2.insert(make_pair(1,"kchao") );
umm2.insert(make_pair(1,"ya skorost") );
umm2.insert(make_pair(1,"samosval ") );
map <int, string> umm2;

    umit i = umm2.begin();
    for (; i != umm2.end(); i++) umm2.insert(pair<int, string>(i->first, i->second));
    auto printU = [](const pair<int,string> n)
     { 
        cout << "<" << n.first << ", " << n.second << ">  ";
    };
    
    for_each (umm2.cbegin(), umm2.cend(), printU);
    cout << endl;
    //ad 2
    auto cnt1 = [](const pair<int, string> n) {return n.first > 1; };
    int cnt = 0;
    cnt=count_if(umm2.cbegin(), umm2.cend(), cnt1);
   cout << cnt << endl;

  vector<int> v0;
    auto make_vctr = [](const pair<int, string> n) {return n.first; };
    transform(umm2.cbegin(), umm2.cend(), back_inserter(v0), make_vctr);
    auto printV = [](int n) { cout << n << " "; };
  for_each(v0.cbegin(), v0.cend(), printV);
    cout <<endl;
//ad 3
 auto fnd1 =find(v0.cbegin(), v0.cend(), 4);
    if (fnd1 != v0.cend()) cout << "yo u right\' \n";
    else cout << "act a fool";
    replace_if(v0.begin(), v0.end(), bind(less<int>(), placeholders::_1, 0), 3);
    for_each(v0.cbegin(), v0.cend(), printV);
   cout << endl;
    
     sort(v0.begin(), v0.end(), [](int a, int b) {return a > b; });
     for_each(v0.cbegin(), v0.cend(), printV);
     cout << std::endl;
     set<int> st0(v0.begin(), v0.end());

    for_each(st0.cbegin(), st0.cend(), printV);
    cout <<endl;
    

  
return 0;
}