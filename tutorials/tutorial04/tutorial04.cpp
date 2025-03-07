#include <iostream>
class Engine {
public:
    Engine() { std::cout << "Engine created!" << std::endl; }
};

class Animal {
public:
    Animal(int age = 10) : age(age)
    {
        std::cout << "Animal created with age " << age << std::endl;
    }
    void speak() {
        std::cout << "Animal speaks" << std::endl;
    }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
    friend void showAge(Animal a);
    Animal operator+(Animal other) {
        return Animal(this->age + other.age);
    }
private:
    int age;
    Engine engine;

};

void showAge(Animal a) {
    std::cout << "Age: " << a.age << std::endl;
}

int main() {
	Animal a;
   
    return 0;
}
