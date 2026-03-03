#include <iostream>
using namespace std;
#include "Student.h"
#include "Comparators.h"

int main() 
{
    Student s1, s2;

    s1.SetName("Maria");
    s1.SetMathGrade(10.0f);
    s1.SetEnglishGrade(5.0f);
    s1.SetHistoryGrade(8.5f);

    s2.SetName("Ion");
    s2.SetMathGrade(6.0f);
    s2.SetEnglishGrade(8.0f);
    s2.SetHistoryGrade(9.6f);

    cout << "Comparare Matematica: " << CompareMathGrade(s1, s2) << "\n";
    cout << "Comparare Engleza: " << CompareEnglishGrade(s1, s2) << "\n";
    cout << "Comparare Medie: " << CompareAverage(s1, s2) << "\n";

    return 0;
}