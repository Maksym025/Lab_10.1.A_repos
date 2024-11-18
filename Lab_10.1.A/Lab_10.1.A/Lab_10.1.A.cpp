#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_EKONOMIKA, FIZYKA_INFORMATYKA, TRUDOVE_NAVCHANNIA };
string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string prizv;
    int kurs;
    Specialnist spec;
    int fizyka;
    int matematika;
    int informatyka;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void PrintAverage(const Student* students, const int N);
double PercentHighPhysics(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);
    PrintAverage(students, N);
    cout << "Процент студентів, які отримали оцінку '5' або '4' з фізики: "
        << PercentHighPhysics(students, N) << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.ignore();
        cout << "  Прізвище: ";
        getline(cin, students[i].prizv);
        cout << "  Курс: ";
        cin >> students[i].kurs;
        cout << "  Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;
        cout << "  Оцінка з фізики: ";
        cin >> students[i].fizyka;
        cout << "  Оцінка з математики: ";
        cin >> students[i].matematika;
        cout << "  Оцінка з інформатики: ";
        cin >> students[i].informatyka;
        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "===============================================================================================" << endl;
    cout << "| №   | Прізвище          | Курс | Спеціальність          | Фізика | Математика | Інформатика |" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[i].prizv;
        cout << "| " << setw(4) << students[i].kurs << " ";
        cout << "| " << setw(23) << left << specStr[students[i].spec];
        cout << "| " << setw(6) << students[i].fizyka << " ";
        cout << "| " << setw(10) << students[i].matematika << " ";
        cout << "| " << setw(11) << students[i].informatyka << " |" << endl;
    }
    cout << "===============================================================================================" << endl;
}

void PrintAverage(const Student* students, const int N) {
    cout << "Середній бал кожного студента:" << endl;
    for (int i = 0; i < N; i++) {
        double avg = (students[i].fizyka + students[i].matematika + students[i].informatyka) / 3.0;
        cout << "  " << students[i].prizv << ": " << fixed << setprecision(2) << avg << endl;
    }
}

double PercentHighPhysics(const Student* students, const int N) {
    int countHigh = 0, total = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].fizyka == 4 || students[i].fizyka == 5) {
            countHigh++;
        }
        total++;
    }
    return (total > 0) ? (100.0 * countHigh / total) : 0.0;
}
