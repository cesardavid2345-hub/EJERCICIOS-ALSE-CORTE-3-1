#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> activeTrips;
    map<pair<string, string>, pair<long long, int>> routeStats;

public:
    void checkIn(int id, string stationName, int t) {
        activeTrips[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = activeTrips[id];
        activeTrips.erase(id);
        auto &stat = routeStats[{startStation, stationName}];
        stat.first += (t - startTime);
        stat.second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        auto [totalTime, count] = routeStats[{startStation, endStation}];
        return static_cast<double>(totalTime) / count;
    }
};

int main() {
    UndergroundSystem us;
    us.checkIn(45, "Leyton", 3);
    us.checkIn(32, "Paradise", 8);
    us.checkIn(27, "Leyton", 10);
    us.checkOut(45, "Waterloo", 15);
    us.checkOut(27, "Waterloo", 20);
    us.checkOut(32, "Cambridge", 22);
    cout << fixed << setprecision(2);
    cout << "Promedio Leyton -> Waterloo: " << us.getAverageTime("Leyton", "Waterloo") << "\n";
    cout << "Promedio Paradise -> Cambridge: " << us.getAverageTime("Paradise", "Cambridge") << "\n";
    return 0;
}
