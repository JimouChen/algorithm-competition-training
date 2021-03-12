# include <iostream>

using namespace std;

class Student {
private:
    int age;
    char *name;
public:
    Student(int m, char *n) : age(m), name(n) {}

    Student() {}

    void SetName(int m, char *n) {
        age = m;
        name = n;
    }

    int GetAge() {
        return age;
    }

    char *GetName() {
        return name;
    }

};

int main() {
    Student stuArray[3] = {Student(12, "Tom"), Student(13, "Peter")};
//    char name1[] = "Tom";
//    char name2[] = "Peter";
//    char name3[] = "Lucy";

//    stuArray[0].SetName(12, name1);//    stuArray[0] = Student(12, name1);
//    stuArray[1].SetName(13, name2);
    stuArray[2].SetName(14, "Lucy");
    for (int i = 0; i < 3; i++)
        cout << "ĞÕÃû: " << stuArray[i].GetName() << " ÄêÁä: " << stuArray[i].GetAge() << "Ëê" << endl;

    return 0;
}