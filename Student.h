#pragma once

class Student 
{
private:
    char name[100];
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void SetName(const char* n); 
    const char* GetName() const;
    bool SetMathGrade(float grade);
    float GetMathGrade() const;
    bool SetEnglishGrade(float grade);
    float GetEnglishGrade() const;
    bool SetHistoryGrade(float grade);
    float GetHistoryGrade() const;

    float GetAverage() const;
};