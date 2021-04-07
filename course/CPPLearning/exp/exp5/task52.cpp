# include <iostream>
# include <cstring>
using namespace std;

class Employee {
protected:
    char name[20];
    int workYears;
public:
    Employee(char *nm, int wy);
    char *getName();
    int getWorkYears();
    void display();
};

Employee::Employee(char *nm, int wy) {
    if (nm) strcpy(name, nm);
    workYears = wy;
}

char *Employee::getName() {
    return name;
}

int Employee::getWorkYears() {
    return workYears;
}

void Employee::display() {
    cout << "name: " << name << endl;
    cout << "working years: " << workYears << endl;
}


class Worker : public Employee {
private:
    double earnPerHour;//每小时工时额
    double workHourPerMonth;//每月工作时数
public:
    Worker(char *nm, int wy, double earn, double workHour);
    double getEarnPerHour();
    double getWorkHourMonth();
    double computePay();
    void display();
};

Worker::Worker(char *nm, int wy, double earn, double workHour) : Employee(nm, wy),earnPerHour(earn),
                                                                 workHourPerMonth(workHour) {}

double Worker::getEarnPerHour() {
    return earnPerHour;
}

double Worker::getWorkHourMonth() {
    return workHourPerMonth;
}

double Worker::computePay() {
    return getEarnPerHour() * getWorkHourMonth() + 35 * getWorkYears();
}

void Worker::display() {
    Employee::display();
    cout << "salary per hour:" << earnPerHour << endl;
    cout << "work hours per month: " << workHourPerMonth << endl;
    cout << "total salary: " << computePay() << endl << endl;
}

class SalesPerson : public Employee {
private:
    double earnPerHour;//每小时工时额
    double workHourPerMonth;//每月工作时数
    double saleMoney;//销售额提成
public:
    SalesPerson(char *nm, int wy, double earn, double workHour, double sale_money);
    double getEarnPerHour();
    double getWorkHourMonth();
    double getSaleMoney();
    double computePay();
    void display();
};

double SalesPerson::getEarnPerHour() {
    return earnPerHour;
}

double SalesPerson::getWorkHourMonth() {
    return workHourPerMonth;
}

double SalesPerson::getSaleMoney() {
    return saleMoney;
}

double SalesPerson::computePay() {
    return getEarnPerHour() * getWorkHourMonth() + 0.01 * getSaleMoney() + 35 * getWorkYears();
}

void SalesPerson::display() {
    Employee::display();
    cout << "salary per hour:" << earnPerHour << endl;
    cout << "work hours per month: " << workHourPerMonth << endl;
    cout << "sale money:" << saleMoney << endl;
    cout << "total salary: " << computePay() << endl << endl;
}

SalesPerson::SalesPerson(char *nm, int wy, double earn, double workHour, double sale_money) : Employee(nm, wy),
                                                                                              earnPerHour(earn),
                                                                                              workHourPerMonth(workHour),
                                                                                              saleMoney(sale_money) {}

class Manager : public Employee {
private:
    const double baseSalary;
public:
    Manager(char *nm, int wy);
    double getBaseSalary();
    double computePay();
    void display();
};

//基本工资固定1000
Manager::Manager(char *nm, int wy) : Employee(nm, wy), baseSalary(1000) {}

double Manager::getBaseSalary() {
    return baseSalary;
}

double Manager::computePay() {
    return getBaseSalary() + 35 * getWorkYears();
}

void Manager::display() {
    Employee::display();
    cout << "basic salary: " << baseSalary << endl;
    cout << "total salary: " << computePay() << endl << endl;
}

int main() {
    Worker worker("Peter", 10, 120, 250);
    SalesPerson salesPerson("Lucy", 15, 100, 200, 12000);
    Manager manager("Lay", 22);

    worker.display();
    salesPerson.display();
    manager.display();
    return 0;
}