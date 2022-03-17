#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;

template<class Key, class Value> Value& GetRefStrict(map<Key, Value>& m, Key k);

template<class Key, class Value> Value& GetRefStrict(map<Key, Value>& m, Key k){
    if(m.count(k) == 0){
        throw runtime_error("no such key in dictionary");
    }
    return m[k];
}

int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue   
    return 0;
}