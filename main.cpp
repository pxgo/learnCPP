#include <iostream>
#include <utility>
using namespace std;

enum Day {MON = 1, TUE, WED, THU, FRI, SAT, SUN};

void printArrayItem(const int arr[], int arrSize) {
    // arr 为指向数组第一个元素的指针
    for(int i = 0; i < arrSize; i++) {
        int target = *(arr + i);
        cout << "array item: " << target << endl;
    }
}

void printStringArrayItem(const string arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        string target = *(arr + i);
        cout << "string array item: " << target << endl;
    }
}

struct Person {
    string name;
    int age;
    void hello(const string &targetName) const {
        cout << "Hello " << targetName << ", I am " << this -> name << endl;
    }
    [[nodiscard]] string getInfo() const {
        return "name: " + name + ", age: " + to_string(age);
    }
    [[nodiscard]] int getAge() const;

    Person(string name, int age) {
        this->name = std::move(name);
        this->age = age;
    }
};

int Person::getAge() const {
    return age;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    Day day = FRI;

    cout << "枚举---" << endl;
    cout << "Today: " << day << endl;

    cout << "指针---" << endl;
    int pointerValue = 10;
    int *pointer = &pointerValue;
    cout << "指针：" << pointer << endl;
    cout << "指针所指值：" << *pointer << endl;
    int *pointerNext = pointer + 1;
    cout << "指针地址+1所指的值（越界访问）：" << *pointerNext << endl;

    cout << "迭代器---" << endl;
    int arr[5] = {1, 2, 3 ,4 ,5};
    int arrSize = size(arr);
    cout << "arr size: " << arrSize << endl;
    for(int i = 0; i < arrSize; i++) {
        int target = arr[i];
        cout << "传统for: " << target << endl;
    }
    for(auto item: arr) {
        cout << "范围for: " << item << endl;
    }

    cout << "命令行参数---" << endl;
    cout << "参数个数：" << argc << endl;

    for(int i = 0; i < argc; i++) {
        auto target = *(argv + i);
        cout << "参数 " << i + 1 << ": " << target << endl;
    }

    cout << "数组形参---" << endl;
    // 传递到函数内后会被自动转化为指向数组第一个元素的指针
    int arrParams[] = {11, 22, 33, 44, 55};
    printArrayItem(arrParams, size(arrParams));
    string names[] = {"spark", "jerry", "li", "Jiaqi Li"};
    printStringArrayItem(names, size(names));

    cout << "返回数组指针---" << endl;
    int numArr[10]; // numArr 是一个含有10个整数的数组
    int *p1[10];    // p1 是一个包含10个指针的数组
    int (*p2)[10];  // p2 是一个指针，指向包含10个整数的数组

    cout << "类---" << endl;

    Person jerry = {"Jerry", 12};
    jerry.hello("SPARK");
    string jerryInfo = jerry.getInfo();
    cout << "Jerry Info: " << jerryInfo << endl;

    cout << "在类外部定义成员函数---" << endl;
    int jerryAge = jerry.getAge();
    cout << "Jerry Age: " << jerryAge << endl;

    cin.get();
    return 0;
}
