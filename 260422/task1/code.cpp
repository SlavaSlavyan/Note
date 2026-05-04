#include <iostream>
#include <vector>
#include <string>

// константа для количества оценок
const int GRADES_COUNT = 5;

// наш класс
class Student {

    // поля класса
    std::string fullName;
    int group;
    int* grades = new int[GRADES_COUNT];

public:

    // конструктор класса
    Student(std::string name, int group, int g1, int g2, int g3, int g4, int g5)
    {
        this->fullName = name;
        this->group = group;
        this->grades[0] = g1;
        this->grades[1] = g2;
        this->grades[2] = g3;
        this->grades[3] = g4;
        this->grades[4] = g5;
    }

    // деструктор класса
    ~Student(){
        delete[] this->grades;
        std::cout << "Экземпляр класса Student был удалён." << std::endl;
    }

    // получение имени
    std::string getName(){
        return this->fullName;
    }

    // получение группы
    int getGroup(){
        return this->group;
    }

    // среднее арифметическое оценок
    float GetAverageGrade()
    {
        float avg = 0;

        for (int i = 0; i < GRADES_COUNT; i++){
            avg += this->grades[i];
        }

        return avg / GRADES_COUNT;
    }


    // вывод информации
    void DisplayInfo()
    {
        std::cout << "Fullname: " << this->fullName << "\nGroup: " << this->group << "\nGrades: [";
        
        for (int i = 0; i < GRADES_COUNT; i++){
            std::cout << grades[i];
            if (i != GRADES_COUNT - 1) { std::cout << ','; }
        }

        std::cout << "]" << std::endl;
    }
};

int main()
{
    std::string name;
    int group, grades[GRADES_COUNT];

    std::cout << "Name << ";
    std::getline(std::cin, name);
    std::cout << "Group << ";
    std::cin >> group;

    for (int i = 0; i < GRADES_COUNT; i++)
    {
        std::cout << "Grades[" << i << "] << ";
        std::cin >> grades[i];
    }

    // создаём экземпляр класса

    Student* stud = new Student(
        name,
        group,
        grades[0],
        grades[1],
        grades[2],
        grades[3],
        grades[4]
    );

    // вызываем его методы

    stud->DisplayInfo();

    float avg = stud->GetAverageGrade();

    std::cout << "AVG: " << avg << std::endl;
    
    // освобождаем память
    delete stud;

    return 0;
}