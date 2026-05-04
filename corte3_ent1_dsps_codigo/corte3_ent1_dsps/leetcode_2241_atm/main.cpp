#include <bits/stdc++.h>
using namespace std;

class ATM {
    vector<long long> count;
    vector<int> value{20, 50, 100, 200, 500};

public:
    ATM() : count(5, 0) {}

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) count[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);
        int remaining = amount;
        for (int i = 4; i >= 0; --i) {
            long long take = min<long long>(count[i], remaining / value[i]);
            used[i] = static_cast<int>(take);
            remaining -= used[i] * value[i];
        }
        if (remaining != 0) return {-1};
        for (int i = 0; i < 5; ++i) count[i] -= used[i];
        return used;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]\n";
}

int main() {
    ATM atm;
    atm.deposit({0, 0, 1, 2, 1});
    cout << "Retiro 600: "; printVector(atm.withdraw(600));
    atm.deposit({0, 1, 0, 1, 1});
    cout << "Retiro 550: "; printVector(atm.withdraw(550));
    cout << "Retiro 80: "; printVector(atm.withdraw(80));
    return 0;
}
