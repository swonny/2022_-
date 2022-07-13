#include<iostream>
#include <stdio.h>

using namespace std;

struct stack {
	int arr[1000][2];
	int top;

	void init() {
		top = -1;
	}

	int push(int i, int j) {
		arr[++top][0] = i;
		arr[top][1] = j;

		return 1;
	}

	int *pop() {
		if(top < 0) {
			return 0;
		}
		int tmp[2] = {arr[top][0], arr[top--][1]};
		// cout << *tmp <<' '<< *(tmp+1) << endl;
		return tmp;
	}

	int isEmpty() {
		if(top < 0) {
			return 1;
		}
		return -1;
	}
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
		cin >> N;
		stack s;
		s.init();

		// 2차원 배열 입력
		int samsung[N*N];
		for(int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> samsung[(N*i)+j];
			}
		}

		// year보다 낮은 땅은 물에 잠김(음수로 표현)
		int year = 1;
		int maxCnt = 0;
		int cnt;
		while(year != 100) {
			cnt = 0;
			int flag = -1;
			for(int i = 0; i < N*N; i ++) {
				if(samsung[i] > 0) {
					flag = 0;
					if(samsung[i] <= year) {
						samsung[i] = 0; // 수정
					}
				}
			}

			if(flag == -1) {
				year -= 1;
				break;
			}

			// 잠기지 않은 영역 묶기
			int iPrev = 0;
			int jPrev = 0;
			for(int i = 0; i < N; i ++) {
				for(int j = 0; j < N; j ++){
					if(samsung[N*i+j] <= 0) { // 빈 땅 또는 방문한 땅 건너뛰기
						continue;
					} else {
						samsung[N*i+j] = samsung[N*i+j]*(-1); // 방문 처리
						if(i != 0) {
							if(samsung[(N*(i-1))+j] > 0) s.push(i-1, j);
						}
						if(j != 0) {
							if(samsung[(N*i)+j-1] > 0) s.push(i, j-1);
						}
						if(i != N-1) {
							if(samsung[(N*(i+1))+j] > 0) s.push(i+1, j);
						}
						if(j != N-1) {
							if(samsung[(N*i)+j+1] > 0) s.push(i, j+1);
						}

						if(s.isEmpty() == -1){ // stack is not empty
							int *tmp = s.pop();
							iPrev = i;
							jPrev = j;
							i = *tmp;
							j = *(tmp + 1) - 1;

							continue;
						} else {
							cnt++;
							if(cnt > maxCnt) maxCnt = cnt;
							i = iPrev;
							j = jPrev;
							break;
						}
					}
				}
			}
			if(maxCnt == 0) maxCnt++;
			for(int i = 0; i < N*N; i ++) {
				samsung[i] *= -1;
			}
			year++;
		}
		
		// 2차원 배열 출력
		// for(int i = 0; i < N; i ++) {
		// 	cout << '\n';
		// 	for(int j = 0; j < N; j ++){
		// 		cout << samsung[N*i+j] << ' ';
		// 	} 
		// }
		cout << "#" << test_case << ' ' << maxCnt << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


