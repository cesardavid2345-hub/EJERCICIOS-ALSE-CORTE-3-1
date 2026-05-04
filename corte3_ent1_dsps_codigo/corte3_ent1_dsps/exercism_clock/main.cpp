#include <bits/stdc++.h>
using namespace std;

class Clock {
    int minutesFromMidnight;

    static int normalize(int minutes) {
        const int day = 24 * 60;
        minutes %= day;
        if (minutes < 0) minutes += day;
        return minutes;
    }

public:
    Clock(int hour, int minute) {
        minutesFromMidnight = normalize(hour * 60 + minute);
    }

    Clock plus(int minutes) const {
        Clock copy(0, minutesFromMidnight + minutes);
        return copy;
    }

    Clock minus(int minutes) const {
        return plus(-minutes);
    }

    string toString() const {
        int h = minutesFromMidnight / 60;
        int m = minutesFromMidnight % 60;
        ostringstream out;
        out << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m;
        return out.str();
    }

    bool operator==(const Clock& other) const {
        return minutesFromMidnight == other.minutesFromMidnight;
    }
};

int main() {
    Clock c1(23, 30);
    Clock c2 = c1.plus(90);
    Clock c3 = c2.minus(45);
    cout << "Inicial: " << c1.toString() << "\n";
    cout << "+90 min: " << c2.toString() << "\n";
    cout << "-45 min: " << c3.toString() << "\n";
    cout << "00:15 == 24:15 ? " << (Clock(0, 15) == Clock(24, 15) ? "si" : "no") << "\n";
    return 0;
}
