#include <fstream> 
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip> //setprecision
#include <map> // map
#include <unordered_map> //unordered_map
#include <queue> // queue, priority_queue
#include <set> // set,multiset
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
#include <numeric> //accumulate,,,
#include <sstream>
#define endl "\n";
using namespace std;

const long long MAXIMUM = INFINITY;

string convert_base(long long FROMbase , long long TObase , string &from , bool zero_offset){
    // 変換前及び変換後はlong long,2^64に収まる範囲でしか変換できません（かなしいね）
    // 変換先の進数は10以下でないといけません（stringじゃなくて各桁をvectorに保存したらいいかも）
    string converted = "";
    long long base_10 = 0;
    vector<long long> power(1,1);
    long long now = 1;
    while(true){
        if(now > MAXIMUM / TObase) break;
        power.push_back(now*TObase);
        now *= TObase;
    }
    long long base_10 = 0;
    for(long long i = 0;i<from.size();i++){
        base_10 += powl(FROMbase,i);
    }
    for(int i = power.size()-1;i>=0;i--){
        converted = converted + to_string(base_10/power.at(i));
        base_10 -= (base_10/power.at(i))*power.at(i);
    }
    if(zero_offset){
        while(from.size() > converted.size()){
            converted = '0' + converted;
        }
        while(from.size() < converted.size()){
            from = '0' + from;
        }
    }
    return converted;
}
