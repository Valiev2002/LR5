#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    cout << "Hello.Now you are watching how work task1" << endl;
    auto print = [](const pair<int, string> z) {
        cout << "<" << z.first << ", " << z.second << ">  ";
    };    //это было сделано для того,чтобы мы могли пользлваться принтом//cppreference

    unordered_multimap<int, string> laba({{1, "v"},//создвем массив с назщванием лаба и заполняем его
                                     {2,  "v1"},
                                     {-3, "v3"},
                                     {4,  "v4"},
                                     {-5, "v5"},
                                     {6,  "v6_good_sound"},
                                     {-7, "v7"},
                                     {8,  "v8_bi_turbo"},
                                     {-9, "v9"}});
    for_each(laba.cbegin(), laba.cend(), print);//печататем через for each
    cout << '\n';
    laba.erase({1});//удаляем значение 1 и 8
    laba.erase({8});
    for_each(laba.cbegin(), laba.cend(), print);//печататем через for each
    cout << '\n';
    laba.insert({{2, "abu bandit"},
                 {2, "proper12"},
                 {2, "nike"}});//вставвляем в масив новыеи значения на значение 2
    for_each(laba.cbegin(), laba.cend(), print);//печататем через for each
    cout << '\n';
    map<int, string> map;//для копирования в мэп сначала создаю мэп
    for (auto i : laba) {
        map.insert(make_pair(i.first, i.second));//копирую с помощью ключа и данных,first-ключ,second-данные
    }

    for_each(map.cbegin(), map.cend(), print);//печать с помощью for each(в дальнейшем этот пункт комм не буду)
    cout << "\n";
    cout << "The end of the task one.Thank you for waiting " << "\n";
    cout << "It is time for task 2" << endl;
    auto f = [](const pair<int, string> n) { return n.first > 0; };//это я сделал чтбы потом можно было пользоваться коунт иф
    int f1;
    f1 = count_if(map.cbegin(), map.cend(), f);//для начала и конца мэпа печать
    cout << f1 << endl;
    vector<int> v0;//создаем вектор
    auto make_vec = [](const pair<int,string> n) {return n.first; };//созадем вектор с ключом инт,значеним стринг
    transform(map.cbegin(), map.cend(),back_inserter(v0), make_vec);//передаем в этот вектор мэп
    auto printV = [](int n) {cout << n << " "; };//функция для печати
    for_each(v0.cbegin(), v0.cend(), printV);
    cout<<"  " <<endl;
    cout << "The end of task 2" << endl;
    cout << "Task 3" << endl;
    int y;
    auto find_el =find(v0.cbegin(), v0.cend(), 2);//ищем значение с ключом 2
    if (find_el != v0.cend())//пока не равно конечному элеименту
        cout << "This element exists";
    else cout << "There is no element";

    for_each(v0.begin(),v0.end(),printV);
    cout << endl;
    replace_if(v0.begin(), v0.end(),bind(less<int>(),placeholders::_1, 0),10);//заменяем значение//cppreference
    for_each(v0.cbegin(),v0.cend(), [](int n){std::cout << n << " ";});
    cout << "\n";
    sort(v0.begin(), v0.end(), [](int m, int n) {return m > n;});//сортируем по убыванию
    for_each(v0.begin(),v0.end(),printV);
    set<int>set (v0.begin(), v0.end());//копиркем с начала и до конца,то етсь весь вектор
    for_each (v0.begin(),v0.end(),printV);

 }
