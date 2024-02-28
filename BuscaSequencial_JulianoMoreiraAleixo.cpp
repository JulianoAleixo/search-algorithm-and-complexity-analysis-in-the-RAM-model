/**************************************************
 *                                                *
 *              Busca Sequencial e                *
 *             Analise no Modelo RAM              *
 *                                                *
 **************************************************
 *                                                *
 *  Autor: Juliano Moreira Aleixo                 *
 *  Disciplina: C03                               *
 *  Professor: Jonas Lopes de Vilas Boas          *
 *  Data: 22/02/2024                              *
 *                                                *
 **************************************************/

#include <iostream>

using namespace std;

struct Student {
    string name;
    int registrationNumber = 0; // 1 (assignment)
    double grade = 0.0; // 1 (assignment)
};

int SearchByRegistrationNumber(Student students[], int qtd, int registrationNumber) { // 0
    for (int i = 0; i < qtd; i++) { // 1 (attachment) + 6*qtd
        if (students[i].registrationNumber == registrationNumber) { // 4*qtd
            return i; // 0
        }
    }
    return -1; // 0
} // 10*qtd + 1 (time units)

int SearchByName(Student students[], int qtd, string name) { // 0
    for (int i = 0; i < qtd; i++) { // 1 (attachment) + 6*qtd
        if (students[i].name == name) { // 4*qtd
            return i; // 0
        }
    }
    return -1; // 0
} // 10*qtd + 1 (time units)

int CounterHigherGrade(Student students[], int qtd, int grade) { // 0
    int counter = 0; // 1
    for (int i = 0; i < qtd; i++) { // 1 (attachment) + 6*qtd
        if (grade < students[i].grade) { // 4*qtd
            counter++; // 3*qtd
        }
    }
    return counter; // 1
} // 13*qtd + 2

int main() {
    int qtd = 0; // 1
    cout << "Enter the number of students to be registered:"; // 1
    cin >> qtd; // 1

    Student students[qtd];

    for (int i = 0; i < qtd; i++) { // 1 (attachment) + 6*qtd
        cout << endl; // 1*qtd
        cout << "Student number " << i + 1 << ":" << endl; // 3*qtd
        cout << "Name:"; // 1*qtd
        cin.ignore(); // 0
        getline(cin, students[i].name); // 1*qtd
        cout << "Registration Number:"; // 1*qtd
        cin >> students[i].registrationNumber; // 2*qtd
        cout << "Grade:"; // 1*qtd
        cin >> students[i].grade; // 2*qtd
    }

    cout << endl; // 1

    int searchRegistrationNumber;
    cout << "Enter the registration number to search for:"; // 1
    cin >> searchRegistrationNumber; // 1
    int indexOfFoundStudentByRegistrationNumber = SearchByRegistrationNumber(students, qtd, searchRegistrationNumber); // 10*qtd + 1
    if (indexOfFoundStudentByRegistrationNumber != -1) { // 1
        cout << "Name: " << students[indexOfFoundStudentByRegistrationNumber].name << endl; // 3
        cout << "Registration number: " << students[indexOfFoundStudentByRegistrationNumber].registrationNumber << endl; // 3
        cout << "Grade: " << students[indexOfFoundStudentByRegistrationNumber].grade << endl; // 3
    } else {
        cout << "Student not located." << endl; // 1
    }

    cout << endl; // 1

    string searchName;
    cout << "Enter the name to search for:"; // 1
    cin >> searchName; // 1
    int indexOfFoundStudentByName = SearchByName(students, qtd, searchName); // 10*qtd + 1
    if (indexOfFoundStudentByName != -1) { // 1
        cout << "Name: " << students[indexOfFoundStudentByName].name << endl; // 3
        cout << "Registration number: " << students[indexOfFoundStudentByName].registrationNumber << endl; // 3
        cout << "Grade: " << students[indexOfFoundStudentByName].grade << endl; // 3
    } else {
        cout << "Student not located." << endl; // 1
    }

    cout << endl; // 1

    int higherGrade;
    cout << "Enter the grade to compare:"; // 1
    cin >> higherGrade; // 1
    int qtdOfHigherGrade = CounterHigherGrade(students, qtd, higherGrade); // 13*qtd + 2
    cout << qtdOfHigherGrade << endl; // 2

    return 0; // 1
}

/* Pela análise de complexidade do modelo RAM, esse código possui uma pontuação de (42 + 31*qtd), sendo que quanto maior
 * o valor de 'qtd', maior a complexidade. Isso se dá por conta da quantidade de loops no script.
 * */
