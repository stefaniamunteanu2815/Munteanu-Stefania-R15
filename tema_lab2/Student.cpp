#include "Student.h"
#include <cstring>

void Student::SetName(const char* n) 
{
    strcpy_s(this->name, n);
}

const char* Student::GetName() const 
{
    return this->name;
}

bool Student::SetMathGrade(float grade) 
{
    if (grade>=1.0f && grade<=10.0f) 
    {
        mathGrade=grade;
        return true;
    }
    return false;
}
float Student::GetMathGrade() const 
{
    return mathGrade; 
}

bool Student::SetEnglishGrade(float grade) 
{
    if (grade>=1.0f && grade<=10.0f) 
    {
        englishGrade=grade;
        return true;
    }
    return false;
}
float Student::GetEnglishGrade() const 
{
    return englishGrade; 
}

bool Student::SetHistoryGrade(float grade) 
{
    if (grade>=1.0f && grade<=10.0f)
    {
        historyGrade=grade;
        return true;
    }
    return false;
}

float Student::GetHistoryGrade() const 
{ 
    return historyGrade; 
}

float Student::GetAverage() const 
{
    return (mathGrade+englishGrade+historyGrade)/3.0f;
}