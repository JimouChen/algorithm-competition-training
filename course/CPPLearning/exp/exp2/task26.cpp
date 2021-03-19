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
    cout << "书名是 <<" << bookname << ">>" << endl;
    cout << "书的价格是 " << price << "元" << endl;
    cout << "书的数量是 " << number << "本" << endl;
}

void Book::borrow() {
    number--;
    cout << "借阅之后，书的数量是 " << number << "本" << endl;
}

void Book::restore() {
    number++;
    cout << "归还之后，书的数量是 " << number << "本" << endl;
}

int main() {
    Book book("面向对象程序设计", 123.45, 2021);
    book.display();
    book.borrow();
    book.restore();
    return 0;
}