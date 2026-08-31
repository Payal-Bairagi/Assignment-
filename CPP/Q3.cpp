#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    char grade;
    double baseSalary;
    bool isActive;

    static int employeeCount;

public:
    Employee() {
        static int nextId = 1001;
        id = nextId++;
        isActive = true;
        employeeCount++;
    }
    void setName(string n) {
        if (n.empty()) cout << "Error: Name cannot be empty\n";
        else name = n;
    }

    void setDepartment(string d) {
        if (d == "Engineering" || d == "HR" || d == "Finance" || d == "Operations")
            department = d;
        else cout << "Error: Invalid department\n";
    }

    void setGrade(char g) {
        if (g=='A' || g=='B' || g=='C' || g=='D')
            grade = g;
        else cout << "Error: Invalid grade\n";
    }

    void setBaseSalary(double s) {
        if (s >= 10000 && s <= 500000)
            baseSalary = s;
        else cout << "Error: Salary must be between 10,000 and 5,00,000\n";
    }

    void deactivate() {
        isActive = false;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    char getGrade() const { return grade; }
    double getBaseSalary() const { return baseSalary; }
    bool getIsActive() const { return isActive; }

    static int getEmployeeCount() {
        return employeeCount;
    }
    double computeTax() const {
        if (grade == 'A') return baseSalary * 0.30;
        if (grade == 'B') return baseSalary * 0.20;
        if (grade == 'C') return baseSalary * 0.10;
        return baseSalary * 0.05;
    }
    double computeGrossSalary() const {
        return baseSalary + (0.20 * baseSalary);
    }
    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }
    void printPayslip() const {
        cout << "\n--- PAYSLIP ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Dept: " << department << endl;
        cout << "Grade: " << grade << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Gross Salary: " << computeGrossSalary() << endl;
        cout << "Tax: " << computeTax() << endl;
        cout << "Net Salary: " << computeNetSalary() << endl;
    }
};
int Employee::employeeCount = 0;
int main() {
    Employee e1, e2;

    e1.setName("Payal");
    e1.setDepartment("Engineering");
    e1.setGrade('A');
    e1.setBaseSalary(30000);

    e2.setName("Riya");
    e2.setDepartment("HR");
    e2.setGrade('C');
    e2.setBaseSalary(20000);

    e1.printPayslip();
    e2.printPayslip();

    cout << "\nTotal Employees: " << Employee::getEmployeeCount() << endl;

    return 0;
}
