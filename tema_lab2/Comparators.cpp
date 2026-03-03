#include "Comparators.h"
#include <cstring>

int CompareName(const Student& s1, const Student& s2)
{
	int result = strcmp(s1.GetName(), s2.GetName());
	if (result==0) return 0;
	if (result>0) return 1;
	return -1;
}
int CompareMathGrade(const Student& s1, const Student& s2)
{
	if (s1.GetMathGrade() == s2.GetMathGrade()) return 0;
	if (s1.GetMathGrade() > s2.GetMathGrade()) return 1;
	return -1;
}
int CompareHistoryGrade(const Student& s1, const Student& s2)
{
	if (s1.GetHistoryGrade() == s2.GetHistoryGrade()) return 0;
	if (s1.GetHistoryGrade() > s2.GetHistoryGrade()) return 1;
	return -1;
}
int CompareEnglishGrade(const Student& s1, const Student& s2)
{
	if (s1.GetEnglishGrade() == s2.GetEnglishGrade()) return 0;
	if (s1.GetEnglishGrade() > s2.GetEnglishGrade()) return 1;
	return -1;
}
int CompareAverage(const Student& s1, const Student& s2)
{
	float a1 = s1.GetAverage();
	float a2 = s2.GetAverage();
	if (a1 == a2) return 0;
	if (a1 > a2) return 1;
	return -1;
}
