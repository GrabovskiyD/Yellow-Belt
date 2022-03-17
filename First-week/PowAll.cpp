#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<class T> vector<T> operator* (const vector<T>& first_vector, const vector<T>& second_vector);

template<class First, class Second> pair<First, Second> operator* (const pair<First, Second>& first_pair, const pair<First, Second>& second_pair);

template<class Key, class Value> map<Key, Value> operator* (map<Key, Value> first_map, map<Key, Value> second_map);

template<class T> T Sqr(const T& item);

template<class T>
vector<T> operator* (const vector<T>& first_vector, const vector<T>& second_vector){
    vector<T> new_vector;
    for(int i = 0; i < first_vector.size(); ++i){
        new_vector.push_back(first_vector[i] * second_vector[i]);
    }
    return new_vector;
}

template<class First, class Second>
pair<First, Second> operator* (const pair<First, Second>& first_pair, const pair<First, Second>& second_pair){
    return make_pair(first_pair.first * second_pair.first, first_pair.second * second_pair.second);
}

template<class Key, class Value>
map<Key, Value> operator* (map<Key, Value> first_map, map<Key, Value> second_map){
    map<Key, Value> new_map;
    for(const auto& item : first_map){
        new_map[item.first] = first_map[item.first] * second_map[item.first]; 
    }
    return new_map;
}

template<class T>
T Sqr(const T& item){
    return item * item;
}

int main(){
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

     map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}