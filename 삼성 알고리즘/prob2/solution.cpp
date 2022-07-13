#include <string.h>
class StudentNode {
    public:
        int mId;
        int mScore;
        StudentNode *next;
        StudentNode *prev;
};

class LinkedList {
    public:
        StudentNode *head;
        StudentNode *tail;

        void init();
        void insertNode(int id, int grade, char gender[7], int score); // 새로운 노드 생성 및 노드에 정보 입력
        int deleteNode(int id); // 노드 삭제
        int orderNode(StudentNode *node); // 성적 오름차순으로 정렬된 연결리스트에서 알맞는 위치 찾아서 넣기
        StudentNode* findAndDelete(int id);
        StudentNode* getLowestScore(int score); // 가장 낮은 성적 찾기
};

LinkedList *firstGradeBookM; // 1학년 남학생 성적부
LinkedList *firstGradeBookF; // 1학년 여학생 성적부
LinkedList *secondGradeBookM; // 2학년 남학생 성적부
LinkedList *secondGradeBookF; // 2학년 여학생 성적부
LinkedList *thirdGradeBookM; // 3학년 남학생 성적부
LinkedList *thirdGradeBookF; // 3학년 여학생 성적부

void LinkedList::init() {
    this->head = new StudentNode;
    this->tail = new StudentNode;

    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

int LinkedList::orderNode(StudentNode *node) {
    StudentNode *current = head->next;
    while(current != tail && current->mScore <= node->mScore) {
        if(current->mScore == node->mScore && current->mId > node->mId) {
            break;
        } else {
            current = current->next;
        }
    }

    // 노드 연결
    node->next = current;
    node->prev = current->prev;

    current->prev->next = node;
    current->prev = node;

    return 0;
}

// 새로운 노드 생성 및 노드에 정보 입력
void LinkedList::insertNode(int id, int grade, char gender[7], int score) { // 학생 추가
    StudentNode* new_node = new StudentNode;
    new_node->mId = id;
    new_node->mScore = score;

    this->orderNode(new_node);
}

StudentNode* LinkedList::findAndDelete(int id) {
    StudentNode *curr = this->head->next;

    while(curr != this->tail && curr->mId != id) {
        curr = curr -> next;
    }

    if(curr == tail) {
        return NULL;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;

    return this->head->next;
}

StudentNode* LinkedList::getLowestScore(int score) {
    StudentNode *curr = this->head->next;

    while(curr != this->tail && curr->mScore < score) {
        curr = curr->next;
    }

    if(curr == tail) {
        return NULL;
    }
    
    return curr;
}

int findLowest(int *score, int *id, int cnt) {
    int lowest = *(score);
    int lowIdx = 0;
    int i;
    for(i = 1; i < cnt; i ++) {
        if(*(score+i) < lowest) {
            lowest = *(score+i);
            lowIdx = i;
        } else if(*(score+i) == lowest) {
            lowIdx = (*(id+i) < *(id+lowIdx)) ? i : lowIdx;
        }
    }
    return *(id+lowIdx);
}

int queryHelper(StudentNode *tmp, int *tmpScore, int *tmpId, int *cntStudent) {
    if(tmp == NULL) {
       return -1;
    } else {
        *(tmpScore+*(cntStudent)) = tmp->mScore;
        *(tmpId+*(cntStudent)) = tmp->mId;
        *(cntStudent) = *(cntStudent) + 1;
        return 0;
    }
}

void init() {
    firstGradeBookM = new LinkedList; 
    firstGradeBookF = new LinkedList; 
    secondGradeBookM = new LinkedList;
    secondGradeBookF = new LinkedList;
    thirdGradeBookM = new LinkedList; 
    thirdGradeBookF = new LinkedList; 

    firstGradeBookM->init();
    firstGradeBookF ->init();
    secondGradeBookM->init();
    secondGradeBookF->init();
    thirdGradeBookM ->init();
    thirdGradeBookF ->init();
    
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int returnId;
    if(strcmp("male", mGender) == 0) {
        if(mGrade == 1) {
            firstGradeBookM->insertNode(mId, mGrade, mGender, mScore);
            returnId = firstGradeBookM->tail->prev->mId;
        } else if(mGrade == 2) {
            secondGradeBookM->insertNode(mId, mGrade, mGender, mScore);
            returnId = secondGradeBookM->tail->prev->mId;
        } else if(mGrade == 3) {
            thirdGradeBookM->insertNode(mId, mGrade, mGender, mScore);
            returnId = thirdGradeBookM->tail->prev->mId;
        }
    } else if(strcmp("female", mGender) == 0) {
        if(mGrade == 1) {
            firstGradeBookF->insertNode(mId, mGrade, mGender, mScore);
            returnId = firstGradeBookF->tail->prev->mId;
        } else if(mGrade == 2) {
            secondGradeBookF->insertNode(mId, mGrade, mGender, mScore);
            returnId = secondGradeBookF->tail->prev->mId;
        } else if(mGrade == 3) {
            thirdGradeBookF->insertNode(mId, mGrade, mGender, mScore);
            returnId = thirdGradeBookF->tail->prev->mId;
        }
    }

	return returnId;
}

int remove(int mId) {
    StudentNode *node;

    if((node = firstGradeBookM->findAndDelete(mId)) !=  NULL) return (firstGradeBookM->head->next == firstGradeBookM->tail) ? 0 : node->mId;
    if((node = secondGradeBookM->findAndDelete(mId)) !=  NULL) return (secondGradeBookM->head->next == secondGradeBookM->tail) ? 0 : node->mId;
    if((node = thirdGradeBookM->findAndDelete(mId)) !=  NULL) return (thirdGradeBookM->head->next == thirdGradeBookM->tail) ? 0 : node->mId;

    if((node = firstGradeBookF->findAndDelete(mId)) !=  NULL) return (firstGradeBookF->head->next == firstGradeBookM->tail) ? 0 : node->mId;
    if((node = secondGradeBookF->findAndDelete(mId)) !=  NULL) return (secondGradeBookF->head->next == secondGradeBookM->tail) ? 0 : node->mId;
    if((node = thirdGradeBookF->findAndDelete(mId)) !=  NULL) return (thirdGradeBookF->head->next == thirdGradeBookM->tail) ? 0 : node->mId;

	return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    int lowestScore = 0;
    int lowestId = 0;
    int tmpScore[6];
    int tmpId[6];
    int cntStudent = 0;
    StudentNode *tmp;

    for(int i = 0; i < mGradeCnt; i ++) {
        switch(mGrade[i]){
            case 1:
                if(mGenderCnt == 2) {
                    // 여학생
                    tmp = firstGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                    // 남학생
                    tmp = firstGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else if(strcmp(mGender[0],"female")==0) {
                    // 여학생
                    tmp = firstGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else {
                    // 남학생
                    tmp = firstGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                }
                break;
            case 2:
                if(mGenderCnt == 2) {
                    // 여학생
                    tmp = secondGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                    // 남학생
                    tmp = secondGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else if(strcmp(mGender[0],"female")==0) {
                    // 여학생
                    tmp = secondGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else {
                    // 남학생
                    tmp = secondGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                }
                break;
            case 3:
                if(mGenderCnt == 2) {
                    // 여학생
                    tmp = thirdGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                    // 남학생
                    tmp = thirdGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else if(strcmp(mGender[0],"female")==0) {
                    // 여학생
                    tmp = thirdGradeBookF->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                } else {
                    // 남학생
                    tmp = thirdGradeBookM->getLowestScore(mScore);
                    queryHelper(tmp, tmpScore, tmpId, &cntStudent);
                }
                break;
        }
    }
    if(cntStudent == 0) return 0;
	return findLowest(tmpScore, tmpId, cntStudent);
}