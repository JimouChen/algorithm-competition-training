# include <iostream>
# include<cstring>

using namespace std;

class Station {
protected:
    char from[20];
    char to[20];
public:
    Station(char *f, char *t);

    void disp();
};

Station::Station(char *f, char *t) {
    if (f) strcpy(from, f);
    if (t) strcpy(to, t);
}

void Station::disp() {
    cout << "起始地名: " << from << endl;
}

class Mile {
protected:
    double mile;
public:
    Mile(double m);

    void disp();
};

Mile::Mile(double m) : mile(m) {}

void Mile::disp() {
    cout << "里程数: " << mile << endl;
}

class Price : public Station, public Mile {
private:
    double price;
public:
    Price(char *f, char *t, double m);

    void disp();
};

Price::Price(char *f, char *t, double m) : Station(f, t), Mile(m) {
    if (m <= 3) price = 8;
    else price = 8 + (m - 3) * 2.0 * 0.7;
}

void Price::disp() {
    Station::disp();
    Mile::disp();
    cout << "总费用: " << price << endl;
}

int main() {
    Price price("仙林", "模范", 23.8);
    price.disp();
    return 0;
}