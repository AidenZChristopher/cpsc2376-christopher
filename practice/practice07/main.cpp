/*
This code may have been developed with the assistance of artificial intelligence (AI) tools,
which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Employee
{
protected:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const
    {
        std::cout << "ID: " << id << ", Name: " << name;
    }
    virtual ~Employee() = default;
};

class SalariedEmployee : public Employee
{
    double monthlySalary;
public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {
    }
    double calculateSalary() const override
    {
        return monthlySalary;
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Monthly Salary: $" << monthlySalary << '\n';
    }
};

class HourlyEmployee : public Employee
{
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Hourly Rate: $" << hourlyRate << ", Hours Worked: " << hoursWorked << '\n';
    }
};

class CommissionEmployee : public Employee
{
    double baseSalary, salesAmount, commissionRate;
public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {
    }
    double calculateSalary() const override
    {
        return baseSalary + (salesAmount * commissionRate);
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Base Salary: $" << baseSalary << ", Sales: $" << salesAmount
            << ", Commission Rate: " << commissionRate * 100 << "%\n";
    }
};

int main()
{
    std::ifstream file("employees.txt");
    if (!file)
    {
        std::cerr << "Error opening file\n";
        return 1;
    }

    std::vector<std::unique_ptr<Employee>> employees;
    std::string type, name;
    int id;

    while (file >> type >> id >> name)
    {
        if (type == "Salaried")
        {
            double salary;
            if (file >> salary)
                employees.push_back(std::make_unique<SalariedEmployee>(name, id, salary));
        }
        else if (type == "Hourly")
        {
            double rate;
            int hours;
            if (file >> rate >> hours)
                employees.push_back(std::make_unique<HourlyEmployee>(name, id, rate, hours));
        }
        else if (type == "Commission")
        {
            double base, sales, commission;
            if (file >> base >> sales >> commission)
                employees.push_back(std::make_unique<CommissionEmployee>(name, id, base, sales, commission));
        }
    }

    for (const auto& e : employees)
    {
        e->displayInfo();
        std::cout << "Calculated Salary: $" << e->calculateSalary() << "\n\n";
    }

    return 0;
}
