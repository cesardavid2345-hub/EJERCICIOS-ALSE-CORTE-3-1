#include <bits/stdc++.h>
using namespace std;

enum class Weekday { Sunday = 0, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum class Schedule { First, Second, Third, Fourth, Last, Teenth };

class Meetup {
    int month, year;

    static bool isLeap(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    static int daysInMonth(int m, int y) {
        static int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if (m == 2 && isLeap(y)) return 29;
        return days[m];
    }

    static int dayOfWeek(int d, int m, int y) {
        // Zeller ajustado para retornar 0=domingo ... 6=sabado.
        if (m < 3) { m += 12; --y; }
        int K = y % 100, J = y / 100;
        int h = (d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
        return (h + 6) % 7;
    }

public:
    Meetup(int m, int y) : month(m), year(y) {}

    int day(Weekday weekday, Schedule schedule) const {
        int target = static_cast<int>(weekday);
        vector<int> candidates;
        for (int d = 1; d <= daysInMonth(month, year); ++d) {
            if (dayOfWeek(d, month, year) == target) candidates.push_back(d);
        }
        switch (schedule) {
            case Schedule::First: return candidates[0];
            case Schedule::Second: return candidates[1];
            case Schedule::Third: return candidates[2];
            case Schedule::Fourth: return candidates[3];
            case Schedule::Last: return candidates.back();
            case Schedule::Teenth:
                for (int d : candidates) if (d >= 13 && d <= 19) return d;
        }
        return -1;
    }
};

int main() {
    Meetup may2026(5, 2026);
    cout << "Primer lunes de mayo de 2026: " << may2026.day(Weekday::Monday, Schedule::First) << "\n";
    cout << "Ultimo viernes de mayo de 2026: " << may2026.day(Weekday::Friday, Schedule::Last) << "\n";
    cout << "Teenth martes de mayo de 2026: " << may2026.day(Weekday::Tuesday, Schedule::Teenth) << "\n";
    return 0;
}
