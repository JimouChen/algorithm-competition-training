# include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char *bookname;
    double price;
    long long number;
public:
    Book(char *name = 0, double p = 0, long long num = 0);
    ~Book();
    void display();
    void borrow();
    void restore();
};

Book::Book(char *name, double p, long long int num) {
    if (name) {
        bookname = new char[strlen(name) + 1];
        strcpy(bookname, name);
    } else *bookname = 0;
    price = p;
    number = num;
}

Book::~Book() {
    if (bookname) delete[]bookname;
}

void Book::display() {
    cout << "������ <<" << bookname << ">>" << endl;
    cout << "��ļ۸��� " << price << "Ԫ" << endl;
    cout << "��������� " << number << "��" << endl;
}

void Book::borrow() {
    number--;
    cout << "����֮����������� " << number << "��" << endl;
}

void Book::restore() {
    number++;
    cout << "�黹֮����������� " << number << "��" << endl;
}

int main() {
    Book book("�������������", 123.45, 2021);
    book.display();
    book.borrow();
    book.restore();
    return 0;
}