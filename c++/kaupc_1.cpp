#include <iostream>

using namespace std;

class Board {
    public:
        int a;
        int b;
        int c;
        int totalGroup;
};

int main() {
    Board board;

    // 대회 정보 입력
    cin >> board.a >>  board.b >> board.c >> board.totalGroup;

    // 동아리 회원 정보 입력
    int a, b, c, max = 0;
    for(int i = 0; i < board.totalGroup; i ++) {
        int total = 0;
        for(int j = 0; j < 3; j ++) {
            cin >> a >> b >> c;
            total += (a*board.a) + (b*board.b) + (c*board.c);
        }
        if(max < total) {
            max = total;
        }
    }

    cout << max;
}