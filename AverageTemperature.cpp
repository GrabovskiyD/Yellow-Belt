#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main(){
    uint32_t number_of_days;
    uint32_t greater_average_temperature = 0;
    vector<int> days_num_greater_then_average;
    vector<int> temperatures;
    int temperature;
    int64_t average_temperature = 0;
    cin >> number_of_days;
    for(int i = 0; i < number_of_days; ++i){
        cin >> temperature;
        temperatures.push_back(temperature);
        average_temperature += temperature;
    }
    average_temperature /= number_of_days;
    
    for(int i = 0; i < number_of_days; ++i){
        if(temperatures[i] > average_temperature){
            greater_average_temperature += 1;
            days_num_greater_then_average.push_back(i);
        }
    }
    cout << greater_average_temperature << endl;
    for(int d : days_num_greater_then_average){
        cout << d << " ";
    }
    cout << endl;
    return 0;
}