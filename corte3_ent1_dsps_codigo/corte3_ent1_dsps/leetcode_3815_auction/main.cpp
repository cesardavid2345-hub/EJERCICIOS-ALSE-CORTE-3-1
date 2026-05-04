#include <bits/stdc++.h>
using namespace std;

class AuctionSystem {
    unordered_map<int, set<pair<int, int>>> itemBids;
    unordered_map<int, unordered_map<int, int>> userBids;

public:
    void addBid(int userId, int itemId, int bidAmount) {
        if (userBids[userId].count(itemId)) removeBid(userId, itemId);
        userBids[userId][itemId] = bidAmount;
        itemBids[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = userBids[userId][itemId];
        itemBids[itemId].erase({oldAmount, userId});
        itemBids[itemId].insert({newAmount, userId});
        userBids[userId][itemId] = newAmount;
    }

    void removeBid(int userId, int itemId) {
        int oldAmount = userBids[userId][itemId];
        itemBids[itemId].erase({oldAmount, userId});
        userBids[userId].erase(itemId);
    }

    int getHighestBidder(int itemId) {
        auto it = itemBids.find(itemId);
        if (it == itemBids.end() || it->second.empty()) return -1;
        return it->second.rbegin()->second;
    }
};

int main() {
    AuctionSystem auction;
    auction.addBid(1, 7, 5);
    auction.addBid(2, 7, 6);
    cout << "Mayor postor item 7: " << auction.getHighestBidder(7) << "\n";
    auction.updateBid(1, 7, 8);
    cout << "Mayor postor item 7: " << auction.getHighestBidder(7) << "\n";
    auction.removeBid(2, 7);
    cout << "Mayor postor item 7: " << auction.getHighestBidder(7) << "\n";
    cout << "Mayor postor item 3: " << auction.getHighestBidder(3) << "\n";
    return 0;
}
