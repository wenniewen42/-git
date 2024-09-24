#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture {
    int start;
    int end;
};

struct CompareEndTime {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.start < b.start;
}

int findMinClassrooms(vector<Lecture>& lectures) {
    sort(lectures.begin(), lectures.end(), compareLectures);

    priority_queue<int, vector<int>, CompareEndTime> classrooms;

    for (size_t i = 0; i < lectures.size(); ++i) {
        const Lecture& lecture = lectures[i];
        if (!classrooms.empty() && classrooms.top() <= lecture.start) {
            classrooms.pop();
        }
        classrooms.push(lecture.end);
    }

    return classrooms.size();
}



int main() {
    vector<Lecture> lectures;
    
    // 睰量畒计沮
    lectures.push_back({900, 1000});
    lectures.push_back({1100, 1600});
    lectures.push_back({1230, 1330});
    lectures.push_back({1030, 1600});
    lectures.push_back({930, 1400});
    lectures.push_back({1030, 1300});
    lectures.push_back({1130, 1530});
    lectures.push_back({1230, 1630});
    lectures.push_back({1100, 1200});
    lectures.push_back({930, 1400});
    lectures.push_back({1130, 1700});
    lectures.push_back({930, 1530});
    lectures.push_back({1200, 1730});
    lectures.push_back({1130, 1400});
    lectures.push_back({1230, 1500});
    lectures.push_back({1100, 1600});
    lectures.push_back({1200, 1700});
    lectures.push_back({1530, 1630});
    lectures.push_back({1630, 1730});
    lectures.push_back({900, 1600});
        
    int minClassrooms = findMinClassrooms(lectures);
    cout << "程ぶ惠璶毙计秖: " << minClassrooms << endl;

    return 0;
}

