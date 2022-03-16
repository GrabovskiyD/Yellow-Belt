#include <iostream>
#include <cstdint>

using namespace std;

int main(){
    uint32_t N;
    uint16_t R;
    uint32_t W, H, D;
    uint64_t sum_mass;


    cin >> N >> R;

    for(int i = 0; i < N; ++i){
        cin >> W >> H >> D;
        sum_mass += static_cast<uint64_t>(W) * H * D * R;
    }
    cout << sum_mass << endl;

    return 0;
}