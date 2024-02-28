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

int SearchByRegistrationNumber(Student students[], int qtd, int registrationNumber) { // Total: qtd * 9
    for (int i = 0; i < qtd; i++) { // qtd * 8
        if (students[i].registrationNumber == registrationNumber) { // 2
            return i;
        }
    }
    return -1; // 1
}

int SearchByName(Student students[], int qtd, string name) { // Total: qtd * 9
    for (int i = 0; i < qtd; i++) { // qtd * 8
        if (students[i].name == name) { // 2
            return i;
        }
    }
    return -1; // 1
}

int CounterHigherGrade(Student students[], int qtd, int grade) { // Total: qtd * 11
    int counter = 0; // 1
    for (int i = 0; i < qtd; i++) { // qtd * 6
        if (grade < students[i].grade) { // 3
            counter++;
        }
    }
    return counter; // 1
}

int main() {
    int qtd = 0; // 1
    cout << "Enter the number of students to be registered:"; // 1
    cin >> qtd; // 1

    Student students[qtd];

    for (int i = 0; i < qtd; i++) { // 6 * qtd * 10' ... 60 * qtd
        cout << endl; // 1
        cout << "Student number " << i + 1 << ":" << endl; // 3
        cout << "Name:"; // 1
        cin.ignore(); // 0
        getline(cin, students[i].name); // 1
        cout << "Registration Number:"; // 1
        cin >> students[i].registrationNumber; // 1
        cout << "Grade:"; // 1
        cin >> students[i].grade; // 1
    }

    cout << endl; // 1

    int searchRegistrationNumber;
    cout << "Enter the registration number to search for:"; // 1
    cin >> searchRegistrationNumber; // 1
    int indexOfFoundStudentByRegistrationNumber = SearchByRegistrationNumber(students, qtd, searchRegistrationNumber); // 1 + qtd * 9
    if (indexOfFoundStudentByRegistrationNumber != -1) { // 1
        cout << "Name: " << students[indexOfFoundStudentByRegistrationNumber].name << endl;
        cout << "Registration number: " << students[indexOfFoundStudentByRegistrationNumber].registrationNumber << endl;
        cout << "Grade: " << students[indexOfFoundStudentByRegistrationNumber].grade << endl;
    } else {
        cout << "Student not located." << endl; // 1
    }

    cout << endl; // 1

    string searchName;
    cout << "Enter the name to search for:"; // 1
    cin >> searchName; // 1
    int indexOfFoundStudentByName = SearchByName(students, qtd, searchName); // 1 + qtd * 9
    if (indexOfFoundStudentByName != -1) { // 1
        cout << "Name: " << students[indexOfFoundStudentByName].name << endl;
        cout << "Registration number: " << students[indexOfFoundStudentByName].registrationNumber << endl;
        cout << "Grade: " << students[indexOfFoundStudentByName].grade << endl;
    } else {
        cout << "Student not located." << endl; // 1
    }

    cout << endl; // 1

    int higherGrade;
    cout << "Enter the grade to compare:"; // 1
    cin >> higherGrade; // 1
    int qtdOfHigherGrade = CounterHigherGrade(students, qtd, higherGrade); // 1 + qtd * 11
    cout << qtdOfHigherGrade << endl; // 2

    return 0; // 1
}

/* Pela análise de complexidade do modelo RAM, esse código possui uma pontuação de (22 + 89*qtd), sendo que quanto maior
 * o valor de 'qtd', maior a complexidade. Isso se dá por conta da quantidade de loops no script.
 * */
