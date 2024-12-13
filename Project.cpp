#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
    private:
        int num;
        string name;
        string address;
    public:
        // Constructor
        Person(int num, string name, string address){
            this->num = num;
            this->name = name;
            this->address = address;
        }
    //Methodi za dostup
        //Getters
        int getNum() {
            return num;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }

        //Setters
        void setNum(int num) {
            this->num=num;
        }
        void setName(string name) {
            this->name=name;
        }
        void setAddress(string address) {
            this->address=address;
        }
        //Print
        void PrintPerson(){
            cout<<"num= "<<num<< ", name= "<<name<< ", address= " << address;
        }

        // Destructor
        // ~Person() {
        //     cout << "Destroying Person object with num: " << num << ", name: " << name << ", address: " << address;
        // }
};

class ContractEmpoyee : public Person {
private:
    int staj;
    double zaplata;
public:
    // Constructor
    ContractEmpoyee(int num, string name, string address, int staj, double zaplata)
        : Person(num, name, address) {  // Pass num, name, and address to the Person constructor
        this->staj = staj;
        this->zaplata = zaplata;
    }

    // Getters
    int getStaj() {
        return staj;
    }
    double getZaplata() {
        return zaplata;
    }

    // Setters
    void setStaj(int staj) {
        this->staj = staj;
    }
    void setZaplata(double zaplata) {
        this->zaplata = zaplata;
    }
    float fullSalary(){
        float result = zaplata+(0.2*staj);
        return result;
    }
    
    // Print
    void PrintEmpoyee() {
        cout << "Empoyee: ";
        PrintPerson();
        cout << ", staj= " << staj << ", zaplata= " << zaplata << endl;
    }

    // Destructor
    // ~ContractEmpoyee() {
    //     cout << "Destroying ContractEmpoyee object with staj: " << staj << ", zaplata: " << zaplata << endl;
    // }
};

int main() {
    int n;

    cout << "Enter the number of employees (<= 20): ";
    cin >> n;
    
    if (n > 20 || n <= 0) {
        cout << "Invalid number of employees. Exiting..." << endl;
        return 1;
    }

    vector<ContractEmpoyee> employees;

    // Input data for each employee
    for (int i = 0; i < n; i++) {
        int num, staj;
        double zaplata;
        string name, address;

        cout << "\n Enter details for employee " << (i + 1) << ":" << endl;
        cout << "ID: ";
        cin >> num;
        cin.ignore(); // Ignore leftover newline
        
        cout << "Name: ";
        getline(cin, name);

        cout << "Address: ";
        getline(cin, address);

        cout << "Years of Service: ";
        cin >> staj;
        
        cout << "Salary: ";
        cin >> zaplata;

        employees.emplace_back(num, name, address, staj, zaplata);
    }

    // Print information for all employees
    cout << "\nEmployee Information:\n";
    for (int i = 0; i < n; i++) {
        employees[i].PrintEmpoyee();
    }

    // Print names and recalculated salaries (including seniority supplement)
    cout << "\n Employee Names and Recalculated Salaries (Including Seniority Supplement):\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << employees[i].getName() << ", Recalculated Salary: " << employees[i].fullSalary() << endl;
    }

    // Add one-off bonus and print for employees with more than 15 years of service
    cout << "\n Employees with >15 years of service and their bonuses:\n";
    for (int i = 0; i < n; i++) {
        if (employees[i].getStaj() > 15) {
            double bonus = 200.0;
            double totalSalary = employees[i].fullSalary() + bonus;
            cout << "Name: " << employees[i].getName() << ", Total Salary (with Bonus): " << totalSalary << endl;
        }
    }

    return 0;
}
