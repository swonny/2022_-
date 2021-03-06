# 2022\_-

# winter_2022: linkedList.c

22.01.05 (수)

- 연결리스트 이용하여 주소록 만들기
  - 🔴 (해결) error
    주소록 전체삭제 시 이름 또는 학번만 삭제됨.
    ==> 해결 - delete_all을 하면 노드를 연결시키지 않아도 된다고 생각했는데, t->prev->next를 저장하기 위해서는 연결해줘야함.

# winter_2022: filePractice.c

22.01.06 (목)

- file 입출력 연습
  [ 새롭게 알게된 것 ]
- file 작성
  - fopen("파일이름.txt", "w"); // 파일 새로 추가, "w" == write
- file close
  - fopen을 한다면 반드시 fclose(fi); 를 통해 파일을 닫아야한다.
- 문자 추가
  - fopen시 "w" -> "a"로 변경
  - "w"는 기존의 내용은 삭제되고 무조건 새로 덮어씀, "a"는 add
- 문자 읽어오기

  - fgetc(fi);

- 문자열 쓰기
  - fputs(a[i], fi);

# winter_2022

22.01.11

- 이중 연결리스트 구현 (꼼꼼히 생각하기)

- 이중포인터 개념 이해하기
- 이해가 안됐던 부분
  Q. 포인터를 조작할 때 : 1. 포인터 변수에는 포인터가 가리키는 주소가 저장되어있음 2. 포인터변수 a에(*없이) 포인터변수 b를 대입하면 b가 가리키는 주소값을 a에 저장 3. 포인터변수가 가리키는 곳의 값을 조작할 때 : *a = 1; (?)
  Q. \*\*a 의 경우
  Q. 주소값으로 넘겨주는 이유 (#59)

      (**a)->(*b)->C
      - 예를 들어 int C = 5; 라고 선언하고 C를 출력하면 a에 담겨있는 5가 출력되는 것처럼
        포인터변수 그 자체를 출력하면 포인터 변수가 담고있는 값, 즉 포인터변수가 가리키는 곳의 위치를 출력한다.
        마찬가지로 포인터변수 그 자체에 대입하면 포인터변수가 가리키는 곳의 위치(주소)를 대입하는 것이다.
      - a : a가 가리키는 곳의 주소 (포인터변수 b의 주소)
      - *a : a가 가리키는 곳이 담고있는 주소, 즉, b가 가리키는 곳의 주소 (int C의 주소)
      - **a : a가 가리키는 곳(b)이 가리키는 곳(C)이 담고있는 값

      - b : b가 가리키는 곳의 주소(C의 주소)
      - *b : b가 가리키는 곳의 값 (C의 값)

      **head -> *newNode -> struct Node
      - struct node **head = &List
      - head : head가 가리키는 곳의 주소 (List의 주소)
      - *head : struct Noded의 주소
      - **head : struct Node 값

      - (*head) : head가 가리키는 곳이 가리키는 값
      - 🔴 연산자 우선순위?
        - 포인터 x 역참조(*x)가 -> 보다 우선순위가 낮아서?
        head가 가리키고 있는 곳의 값 : 구조체의 주소

  - 🔴 (해결) 환형LinkedList.c 오류
    - AppendNode()에서 if문 내부부터 출력이 되지 않음
      오류 발생 코드 : if((\*head)->next == NULL)
      ==> 해결
      - (*head)->next는 head가 가리키는 곳의 포인터가 가리키는 구조체의 next를 의미한다.
        하지만 (*head)는 main함수의 List이기 때문에 구조체를 메모리할당받지 않았고 따라서 (\*head)->next는 존재하지 않는다.

# 22.01.12 (수)

## winter_2022

- 🔴 (해결) 환형LinkedList.c 오류
  - AppendNode()실행 시 head와 newNode는 환형으로 연결되지만 다른 두 개 이상 제대로 연결되지 않음
    ==> 해결
  - switch문을 통해 모든 케이스 검토 후 코드 수정
- 마지막 노드가 출력되지 않는 문제 발생 후 해결
  - 환형이기 때문에 종결조건이 헷갈렸음
  - 순서가 중요!!!
    1. 먼저 head를 출력하고 tail이 next노드를 가리키게 하면 처음 head일 때 if문에서 걸리지 않음.
    2. 이후 next되어 돌아온 노드가 head인 경우 브레이크

## addressBook\_완.c

- 주소록 완성한 파일 이름 변경 (practiceStructure.c -> addressBook\_완.c)
- 🔴 (해결)ddressBook.(완).c 오류 발견 - 학생 삭제 기능
  검색 기능을 실행한 뒤 학생 이름을 입력받아 삭제하면 입력받은 학생이 아닌 검색한 학생 삭제 (검색 기능 실행 안 하고 바로 삭제하면 정상 작동) - 원인 발견
  ==> 해결

```
// 기존 코드
// main함수 -> switch문 case3 -> scanf 변경
  scanf("%s", t->name);
  name_delete_student(t->name);

// 변경 코드
  char name[100];
  scanf("%s, name);
  name_delete_student(name);
```

- 변경 코드 설명
  t->name으로 입력 받아서 t->name으로 넘겼지만 구조체 t는 변하지 않았기 때문에 검색 기능에서 return 받았던 t의 name이 name_delete_student() 함수로 전달된다! 따라서 검색 실행 시에는 검색학생이 삭제되었던 것.

  - 파일 입출력
  - file_print_all() : 파일에서 입력받아 주소록 전체 출력 기능
    - 전체 출력은 완성
    - 🔴 (해결) file_print_all()함수 해결 필요
      추가한 학생은 마지막에 두 번 출력됨
  - file_find_str() : 파일에서 찾는 학생 이름으로 검색
    - 기능 구현은 정상 작동
  - 🔴 (해결) 삭제기능 추가 필요

# 22.01.13 (목)

## winter_2022 > adderessBookwFile.c

- 삭제 기능

1. 2차원 배열로 기존 주소록 저장
2. 만약 입력받은 이름과 같다면 해당 문자열에서는 continue( 배열에 저장 x )

## winter_2022 > stack.c

#### 스택 생성, push, pop, isEmpty, int Top, destroyStack 구현

- 기본기능 구현 완성

# 22.01.15 (토)

## winter_2022 > addressBookwFile.c

- 학생 추가, 검색, 삭제, 출력, 전체삭제 기능 구현
- 🔴 (해결) 오류

  1. (해결) 추가 후 출력 시 마지막 추가된 사람은 두 번 출력됨
     ==> 원인 ?
  2. (해결) 학생 추가 시 전화번호에 0이 입력안됨
     ==> 정수형으로 폰번호를 저장했기 때문에 앞에 0이 있을 때 0은 무시되었다.
     따라서 %010d라고 지정해두면 해결 가능하다.
  3. (해결) 학생 삭제 시 마지막 학생은 전화번호가 삭제가 안됨
     ==> 입력받은 숫자보다 하나 더 printf했기 때문

- 주소록 파일 입출력 기능 보완 모두 완성

1. 검색이 안되는 경우 무한루프 도는 것 변경
2. 삭제할 경우 학생이 존재하지 않을 때 프로그램 종료되는 것 변경
3. file_print_all() 함수 호출 시 아무것도 없을 때 이상한 값이 출력되는 것 변경
4. file_delete_all() 함수 호출 시 아무것도 없을 때 무한루프 도는 것 변경

### 🟡 addressBookwFile.c 모든 기능 구현 완료 및 addressBookwFile\_완.c로 파일명 변경

# 22.01.16 (월)

    ## winter_2022 > postfixStackCalc.c
    - 중위표기법에서 후위표기법으로 변환 기능 구현 완성
    - 후위표기법 수식 계산 기능 구현 완성
    - 🔴 (해결) 10의 자릿수 이상의 숫자 계산 가능하도록 수정 필요
      - datastructure > test2.c 로 테스트 중
        - 중위표기법 > 후위표기법 변환할 때 공백을 추가하는 것은 성공.
        - 후위표기법 계산 수정 필요

# 22.01.19 (수)

## datastructure > test2.c

- 후위표기법 수식 계산기 10자릿수 이상인 수 수정
  [ 순서 ]

  1. 띄어쓰기 하지 않은 상태로 수식 문자열 입력

- 🔴 오류 발생 (test2.c)
  - str_to_int() 함수에서 공백을 기준으로 while문을 돌리면 첫 번째 return값을 받는 result1은 띄어쓰기를 pop하기 때문에 while문을 거치지 않고 바로 return된다.
    pop() 먼저 하고 while문을 돌리면 stack underflow 로 무한루프를 돈다.
    ==> ‼️‼️‼️ 문자열을 반복문으로 대입한 뒤 반드시 마지막에는 '\0'를 넣어줘야한다.
    - pop을 하여 비교를 하면 다음 띄어쓰기가 없어지니까 stack underflow 발생
  - 연산자가 두 번 연속으로 오면 (예를 들어 12+(3\*2)는 '+'와 '('가 연속됨) 띄어쓰기가 두 번 발생하고, 그렇지 않은 경우에는 띄어쓰기가 저장되지 않음.
    ==> 띄어쓰기가 저장되지 않는 이유는 pop할 때의 문제같다.
    ==> 괄호가 없을 때는 정상적으로 띄어쓰기 됨. 괄호가 있을 때는 이전과 동일

## REMINDER!!

     - 후위표기법 계산기 코드구현에서 발생하는 대부분의 오류는 pop() 함수에서 top의 역할을 명확히 지정하지 않았기 때문이다. 작아보이는 문제가 점점 뒤로 갈수록 겉잡을 수 없이 커진다. 어느 것 하나도 놓치지 말고 코드를 짜야한다.

    ### 스택 > postfix_edit.c
    - 두 자릿수 이상 후위표기법으로 변환 완료
    [ 알고리즘 ] - 두 자릿수 이상의 수를 후위표기법으로 변환하여 저장하기
    1. 숫자가 나오면 숫자가 아닐 때까지 postfix[j++]에 대입
    2. 숫자가 아니어서 반복문을 빠져나오면 공백 추가
    3. 연산자일 때
        3.1 우선순위를 따져서 pop되어 나온 연산자는 추가
        3.2 연산자를 대입하면 공백추가
    4. 마지막으로 남은 연산자 모두 pop할 때 공백도 배열에 추가

# 22.01.20 (목)

## 스택 > postfix_edit.c

- 🔴 postfix_edit.c > num_token() 함수

  - 어느 위치에서 pop을 해야 논리적으로 맞는지 헷갈림
  - 코드의 의도

    1. 후위표기법 수식 계산하는 과정에서 호출되는 함수이다.
    2. 후위표기법 수식에서 연산자를 만나면 스택에서 최상위 요소 두 개를 pop하여 계산한 뒤 스택에 다시 푸시하게 되는데, 이때 최상위 두 개의 수를 pop하여 배열에 저장하는 역할을 한다.

  - 문제점
    1. 숫자를 스택에 push할 때 문자로 된 숫자를 자릿수 당 한 개씩 나눠서 push하고 모든 자릿수의 수를 다 push한 뒤 마지막에 공백을 넣어 각 숫자를 구분해줌.

  ==> 어딘가에서 top이 -1까지 pop되었기 때문에 그 다음 push를 할 때 top이 -1부터 시작해서 코드가 꼬였음. -> pop을 할 때 return 조건을 -1에서 0으로 변경하면 stack underflow 무한루프를 돈다.
  -> 🔴 (해결) 임시로 get_postfix_result() while문 시작 전 top++을 해주어 기존의 코드와 top의 논리가 일치하도록 만들어놓음.
  ==> 전체적인 흐름을 기억하면서 짜기 !!!
  예를 들어 postfix 배열에는 공백을 포함하여 수식을 표현했는데 그걸 기억 못하고 공백을 포함하지 않은 배열로 간주하여 코드를 짜서 이상한 코드가 나왔음.

[ 변경전 코드 ]

```
void num_token(char temp[]) // 스택에서 숫자 최소단위로 잘라주는 함수
{
    int i=0;
    printf("top : %d\n", top);
    while(stack[top-1] != ' ' &&  top > 0) {
        printf("pop :%c\n", stack[top-1]);
        temp[i++] = pop();
    }
    temp[i] = '\0';
}
```

[ 변경 후 코드 ]
get_postfix_result() 변경 - top+1 추가 - 공백 푸시할 때 postfix 에 있던 공백을 삽입하여 postfix[i]가 공백 다음을 가리키도록 수정하여 이어지도록 수정

    - 해결 후
      1. 숫자 두 개만 있을 때는 자릿수를 고려하여 정상적으로 계산
      2. 🔴 (해결) 숫자 세 개 이상일 때는 계산하지 못함
      3. 🔴 (해결) 10은 10이 아닌 '1','0'으로 저장됨
        ==> while문 돌릴 때 숫자인 경우를 postfix[i] > '0'  && postfix[i] < '9'로 설정했음.

    ==> infix_to_postfix() 함수에서 postfix배열을 지역함수로 선언했기 때문에 return되면서 배열을 읽을 수 없게됨. 따라서 배열을 포인터로 넘겨주어 넘겨받은 배열에 strcpy를 통해 복사해두면 해결.
    ==> 계산한ㅜ 값을 push()할 때는 +'0'을 해주고 return 시 -'0'을 안해줌 ***(크게 보기)***

### 🟡 스택 > postfixStackCalc*두자릿수.c, postfixStackCalc*한자릿수.c 기능 구현 완료

      - 🔴 (해결) 스택 > postfixStackCalc_두자릿수.c 숫자 10은 수정 필요

### postfix_edit.c : postfix_edit.c

      - 🔴 postfixStackCalc_두자릿수 수정 전 코드 _ 아직 왜 안되는지 원인 제대로 파악 못해서 다시 읽어보고자 남겨둠

# 22.01.21 (금)

## 🟡 스택 > infixCalc.c

# 22.01.25 (화)

## 🟡 정렬 > bubbleSort.c

- 기능 구현 완성

# 22.01.26 (금)

## 🟡 정렬 > insertionSort.c

- 기능 구현 완성

# 22.01.27 (목)

## 🟡 정렬 > quickSort_recursive.c

- 재귀호출을 이용한 퀵정렬 구현
- 현재
  - 수정 필요 부분 두번째 케이스를 제외한 나머지 경우 정렬 정상 작동
    [ 수정 필요 ]
- 🔴 (해결)recursive() 함수에서 left와 right를 update하지 않아도 정상적으로 돌아가는 이유
  ==> 함수 재귀호출 시 계속 returnq받은 pivot값을 이용하여 left와 right를 조정해주었기 때문!
- 🔴 (해결) 제일 작은 수가 idx 0에 위치하거나 제일 큰 수가 가장 마지막에 위치하면 정상적으로 정렬되지 않음.
  ==> 숫자 2개만 비교할 때는 left < right 조건을 만족하지 못해서 right가 pivot이 있는 자리로 움직이지 않고 swap해버리니까 정렬이 잘못됐었음!

# 22.01.28 (금)

## 🟡 정렬 > quickSort.c

- 비재귀호출을 이용한 퀵정렬 구현
  [ 알고리즘 ]

1. 배열 분할 (left와 right로 분할)
2. partition() 함수에서 return 받은 pivot을 기준으로 오른쪽 영역 (pivot+1 ~ right)은 push
3. return 받은 pivot을 기준으로 왼쪽 영역으로 left와 right 구분하여 다시 partition() 함수 호출
4. return 받은 pivot을 기준으로 오른쪽 push, 왼쪽 분할 반복 -> 비교할 숫자가 1개가 될 때까지

5. pop()
6. pop()한 결과인 left와 right로 partition 호출
7. partition() 함수에서 return 받은 pivot을 기준으로 오른쪽 영역 (pivot+1 ~ right)은 push
8. return 받은 pivot을 기준으로 왼쪽 영역으로 left와 right 구분하여 다시 partition() 함수 호출
9. return 받은 pivot을 기준으로 오른쪽 push, 왼쪽 분할 반복 -> 비교할 숫자가 1개가 될 때까지

- partition() 함수
  - 배열, left, right를 인자로 받아 정렬한 뒤 축을 반환
- recursive() 함수
  - 더이상 정렬할 숫자가 없을 때까지 반복하여 partition() 함수 호출
  - partition() 함수를 호출하여 축을 반환받고, 축을 기준으로 왼쪽과 오른쪽 영역으로 나눠 다시 partition() 함수 호출

[ 기능 구현 완료 알고리즘 _ 정렬 > quickSort.c ]

- partition() 함수
  ( 재귀와 동일 )

  - 인자로 배열, left, right를 넘겨줌
  - 정렬된 Pivot의 위치 반환

- recursive() 함수
  1. 가장 바깥 while문은 더이상 stack에 남아있는 노드가 없고, 남은 숫자의 개수가 1개일 때 빠져나온다.
  2. 첫 번째 if문은 내부 while문에서 왼쪽 영역에 대한 모든 숫자를 partition()함수를 통해 정렬한 뒤에 정렬해야하는 수가 한 개 남았을 때 빠져나온 이후에 들어가게 된다.
  3. 2번이 수행된 이후 내부 while문에서 오른쪽 영역에 대해 push한 left와 right로 update하고 다시 내부 while문으로 들어가 partition함수를 통해 분할하며 2, 3번을 반복하여 수행한다.

# 22.02.03 (목)

## 🟡 탐색 > binarySearchTree.c

- 이진트리탐색 기능 구현 \_ 규칙에 맞게 노드 삽입, 삭제 및 출력하기
- insert_node() : 노드 삽입
- delete_node() : 노드 삭제

🔴 (해결) delete_node() - 루트노드만 삭제 -> 정상 작동
루트노드 이외의 노드만 또는 루트노드 이외의 여러노드 삭제 -> 정상 작동
루트노드 삭제 + 루트노드 이외의 노드 삭제 -> 수정 필요

    ==> temp->right->left != NULL일 때랑 temp->right->left == NULL일 때 자식노드 연결해주는 부분에서 잘못된 부분 수정

# 22.02.04 (금)

## 구조체 배열 내용 정리

- 헷갈렸던 부분

  - 연결리스트를 구현할 때 새로운 노드를 삽입하기 위해서는 동적메모리할당(malloc)이 필수였다. 하지만 배열에서의 동적메모리할당은 말 그대로 배열의 사이즈를 동적으로 조절해야할 때 필요한 것이기 때문에 배열의 크기를 넘어갔을 때만 동적메모리할당을 하면 된다. 연결리스트에서 동적메모리할당이 필요했던 이유는 노드를 삽입하려고 할 때는 늘 기존에 선언되었던 리스트의 크기보다 하나씩 늘어나야하기 때문에 연결리스트의 사이즈가 동적으로 늘어나기 때문이다!

  --> x

  - 포인터 변수에 담기 위해서는 동적메모리를 할당해야함

## 🟡 트리 > calcTree.c

    - 이진트리를 이용한 수식트리 계산기 만들기 중 후위표기법 수식을 이진트리로 구축하기 기능 구현 완성
    - 🔴 (해결) 컴파일을 할 때마다 노드가 NULL을 가리키고 있다는 에러가 날 때가 있고 정상 작동 할 때가 있음 -> 생성한 트리를 free()시키지 않아서인 것 같은데 정확한 이유를 모르겠다.....
      ==> create_node()로 노드를 생성하고 전달받아서 트리에 연결하는데, create_node()함수에서 동적메모리할당한 노드의 자식노드 포인터를 NULL로 초기화하지 않아서 언제는 NULL이 들어가있고, 언제는 들어가있지 않아서 언제는 제대로 작동하고 언제는 제대로 작동하지 않았음!
      --> 이때 create_node()를 가지고 NULL 이 아니라면 조건문이 들어가있어서 스택 언더플로우가 발생했던 것이 문제.
    수식트리 구현 완료

---

# 22.02.07 (월)

## 힙 > heapWarr.c

- upheap(), downheap() 기능 구현 완성

- 🔴 (해결) 내부노드 개념 이용해서 수정해보기!

기존 코드

```
void downheap(void)
{
    int tempIdx = front;
    swap(front, rear);
    rear--;
    while(heap[tempIdx] > heap[tempIdx*2] || heap[tempIdx] > heap[tempIdx*2+1]){
        if(tempIdx*2 > rear) { // 자식노드 인덱스가 개수보다 클 때
            break;
        }
        if((tempIdx*2+1) <= rear && heap[tempIdx*2] > heap[tempIdx*2+1]) {
            swap(tempIdx, tempIdx*2+1);
            tempIdx = tempIdx*2+1;
        } else {
            swap(tempIdx, tempIdx*2);
            tempIdx *= 2;
        }
    }
}
```

=> 기존코드는 이용할 수 있는 트리의 특징을 고려하지 않고 구현했다. 따라서 조건분기문 코드가 복잡해짐!

개선 코드

```
void downheap(void)
{
    int tempIdx = front;
    int smaller;
    swap(front, rear);
    rear--;
    while(tempIdx <= rear/2) {
        if(tempIdx*2+1 <= rear) {
            smaller = heap[tempIdx*2] | heap[tempIdx*2+1];
        } else {
            smaller = heap[tempIdx*2];
        }
        swap(tempIdx, smaller);
        tempIdx = smaller;
    }
}

```

==> 내부노드일 때만 자식노드와 비교하면 된다. 따라서 내부노드일 때만 while문을 반복하게 하고, while문 내부에서도 오른쪽과 왼쪽 자식을 비교한다. 이때 내부노드이므로 왼쪽 자식은 무조건 존재하고, 오른쪽 자식이 존재하는지 확인하기 위한 조건문을 추가하였다.
최종 개선 코드

```
void downheap(void)
{
    int tempIdx = front;
    int smaller;
    swap(front, rear);
    rear--;
    while(tempIdx <= rear/2) {
        if(tempIdx*2+1 <= rear && heap[tempIdx*2+1] < heap[tempIdx*2]) {
            smaller = tempIdx*2+1;
        } else if(heap[tempIdx*2] < heap[tempIdx]){
            smaller = tempIdx*2;
        }
        swap(tempIdx, smaller);
        tempIdx = smaller;
    }
}
```

# 22.02.08

## 힙 > heapWarr.c

- downheap() 함수 구현 완료

# 22.03.01

## 영화예매

- RowDataPacket

# 22.03.02
## my-roomchat
  - 🔴(해결) db에서 찾는 정보가 없을 때도 true를 return함
    ==> if(!result) 가 아니라 if(!result[0])으로 해야함!

# 22.07.11
삼성 알고리즘 문제

1) 테스트케이스 개수 입력 & for문으로 테스트케이스 별 처리
  각 for문 내부
  1. N입력
  2. 1 ~ 100(year에 해당)까지 for문 돌리면서 모든 땅이 잠길 때(음수일 때)까지 maxCnt 찾기
    2.1 잠기는 땅 음수 처리
      2.1.1 모두 음수인 경우를 찾기 위해 flag를 0으로 초기화 (flag가 -1이면 모든 땅이 잠겨있는 상태)
      2.2.2 year과 같거나 작은 값을 갖는 땅 -1 대입 : 땅이 잠기는 것
    2.2 잠기지 않은 영역의 개수 세기 - 이중 for문 i와 j 사용
      2.2.1 만약 현재 인덱스에 해당하는 요소가 음수라면, 다음 땅으로 넘어감 (continue)
            만약 음수가 아니라면 오른쪽, 아래 땅을 확인하여 -1이 아니라면 스택에 push (왼쪽, 위쪽 땅은 이미 지나온 땅이므로 패스)
      2.2.2 같은 영역을 확인하기 위해 

  3. #x에 대한 출력