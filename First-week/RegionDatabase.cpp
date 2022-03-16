#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdint>
#include <tuple>

using namespace std;

enum class Lang{
    DE, FR, IT
};

struct Region{
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs){
    return make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < 
            make_tuple(rhs.std_name, rhs.parent_std_name,rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    int max_repetitions_number = 0;
    map<Region, int> repetitions_of_regions;
    for(const Region& region:regions){
        max_repetitions_number = max(max_repetitions_number, ++repetitions_of_regions[region]);
    }
    return max_repetitions_number;
}

int main(){
    cout << FindMaxRepetitionCount({
        {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
        }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
        }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
        }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
        }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
        },
    }) << endl;

    cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

    return 0;
}