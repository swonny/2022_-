/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <stdio.h>

using namespace std;

// void fillSamsung(int *ptr, int N) {

// }

// void isSinked(int *ptr, int N) {

// }

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
		int tmp[2] = {arr[top][0], arr[top--][1]};
		cout << *tmp <<' '<< *(tmp+1) << endl;
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
	stack s;
    s.init();
	s.push(5,10);
	s.push(11, 20);
	int *tmp = s.pop();
	int i = *tmp;
	int j = *(tmp + 1);
	cout << i << ' ' << j << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}