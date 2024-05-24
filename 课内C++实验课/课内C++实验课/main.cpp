//
//  main.cpp
//  课内C++实验课
//
//  Created by 张旭洋 on 2024/4/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Information {
private:
    int age;
    std::string sex;

public:
    Information() : age(0), sex("Unknown") {}
    Information(int age, const std::string& sex) : age(age), sex(sex) {}

    void setAge(int age) {
        this->age = age;
    }

    int getAge() const {
        return age;
    }

    void setSex(const std::string& sex) {
        this->sex = sex;
    }

    std::string getSex() const {
        return sex;
    }
};

class Student {
private:
    int studentId;
    std::string name;
    int mathScore;
    int chineseScore;
    int totalScore;
    Information info;

public:
    Student() : studentId(0), name("Unknown"), mathScore(0), chineseScore(0), totalScore(0) {}
    Student(int id, const std::string& name, int mathScore, int chineseScore, const Information& info)
        : studentId(id), name(name), mathScore(mathScore), chineseScore(chineseScore), totalScore(mathScore + chineseScore), info(info) {}

    int getTotalScore() const {
        return totalScore;
    }

    Information getInformation() const {
        return info;
    }

    void displayInfo() const {
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Math Score: " << mathScore << std::endl;
        std::cout << "Chinese Score: " << chineseScore << std::endl;
        std::cout << "Total Score: " << totalScore << std::endl;
        std::cout << "Information - Age: " << info.getAge() << ", Sex: " << info.getSex() << std::endl;
    }
};

// Function to calculate the average score of all students
double calculateAverageScore(const std::vector<Student>& students) {
    int totalScore = 0;
    for (const auto& student : students) {
        totalScore += student.getTotalScore();
    }
    return static_cast<double>(totalScore) / students.size();
}

// Function to get the student with the highest total score
Student getTopScorer(const std::vector<Student>& students) {
    auto it = std::max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getTotalScore() < b.getTotalScore();
    });
    return *it;
}

// Function to sort students by total score using bubble sort
void sortStudentsByScore(std::vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].getTotalScore() > students[j + 1].getTotalScore()) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    std::vector<Student> students;
    for (int i = 0; i < numStudents; ++i) {
        int id, math, chinese, age;
        std::string name, sex;

        std::cout << "Enter student ID, name, math score, chinese score, age and sex for student " << i+1 << ": ";
        std::cin >> id >> name >> math >> chinese >> age >> sex;

        Information info(age, sex);
        Student student(id, name, math, chinese, info);
        students.push_back(student);
    }

    // Calculate and output average score
    double avgScore = calculateAverageScore(students);
    std::cout << "Average score of all students: " << avgScore << std::endl;

    // Output information of top scorer
    Student topScorer = getTopScorer(students);
    std::cout << "Top Scorer Information:" << std::endl;
    topScorer.displayInfo();

    // Sort students by total score and output
    sortStudentsByScore(students);
    std::cout << "Students sorted by total score:" << std::endl;
    for (const auto& student : students) {
        student.displayInfo();
        std::cout << std::endl;
    }

    return 0;
}
