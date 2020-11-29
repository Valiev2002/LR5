#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
typedef unordered_multimap<string, int>::iterator umit;
void printUmm(unordered_multimap<string, int> umm)
{
    umit it = umm.begin();

    for (; it != umm.end(); it++)
        cout << "<" << it->first << ", " << it->second
             << ">  ";

    cout << endl;
}

int main() {
    unordered_multimap<string, int> umm1;
    unordered_multimap<string, int> umm2(
            {{"apple", 1},
             {"ball",  2},
             {"apple", 10},
             {"cat",   8},
             {"dog",   9},
             {"cat",   6},
             {"apple", 1}});
    auto printU = [](const pair<int, string> n) {
        std::cout << "<" << n.first << ", " << n.second << ">  ";
    };

    for_each(umm2.cbegin(), umm2.cend(), printU);
    cout << std::endl;

    umm1 = umm2;
    umm2.insert({{"alpha", 2},
                 {"beta",  2},
                 {"gamma", 2}});
    umm2.erase("apple");
    umm2.erase("cat");
    umit i = umm2.begin();
    for_each(umm2.cbegin(), umm2.cend(), printU);
    cout << endl;
    map <int, std::string> mymap;

    umit n = umm2.begin();
    for (; n != umm2.end(); n++) mymap.insert(pair<int, string>(n->first, n->second));

  for_each(mymap.begin(), mymap.end(), printU);
    cout << endl;
    //zadanie 2
    auto vvs0 = [](const pair<int, string> n) {return n.first > 0; };
    int vvs = 0;
    vvs=count_if(mymap.begin(), mymap.end(), vvs0);
    cout << vvs << endl;
    vector<int> v0;
    auto make_vector = [](const pair<int, string> n) {return n.first; };
    transform(mymap.begin(), mymap.end(), back_inserter(v0), make_vector);
    auto printV = [](int n) { cout << n << " "; };
    for_each(v0.begin(), v0.end(), printV);
    cout << endl;
    //find
    auto find2 = find(v0.begin(), v0.end(), 2);
    if (find2 != v0.end()) cout << "This element exist";
    else cout << "There is no such element ";
    //replace
    replace_if(v0.begin(), v0.end(), bind(less<int>(), placeholders::_1, 0), 10);
    for_each(v0.begin(), v0.end(), printV);
    cout <<endl;
    //sort
    sort(v0.begin(), v0.end(), [](int a, int b) {return a > b; });
  for_each(v0.begin(), v0.end(), printV);
   cout << endl;
   //set
   set <int> timati;
    copy(v0.begin(), v0.end(), inserter(timati, timati.end()));
    for_each(timati.cbegin(), timati.cend(), printV);
    cout << endl;
    return 0;
}
