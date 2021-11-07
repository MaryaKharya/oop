
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../People/CPupil.h"
#include "../People/CStudent.h"
#include "../People/CTeacher.h"
#include "../People/CWorker.h"
#include "../People/CAdvancedStudent.h"

using namespace std;

SCENARIO("create pupil")
{
	CPupil pupil("Vladimir", "Sidorkin", "Andreevish", "Polevaya, 20", "Novotoryalskaya", "9a");
	CHECK(pupil.GetAddress() == "Polevaya, 20");
	CHECK(pupil.GetFirstName()== "Vladimir");
	CHECK(pupil.GetLastName() == "Sidorkin");
	CHECK(pupil.GetPatronymic() == "Andreevish");
	CHECK(pupil.GetSchoolName() == "Novotoryalskaya");
	CHECK(pupil.GetClass() == "9a");
}

SCENARIO("create teacher")
{
	CTeacher teacher("Elena", "Shestakova", "Yuryevna", "Pervomayskaya, 3-5", "Russian language");
	CHECK(teacher.GetFirstName() == "Elena");
	CHECK(teacher.GetLastName() == "Shestakova");
	CHECK(teacher.GetPatronymic() == "Yuryevna");
	CHECK(teacher.GetAddress() == "Pervomayskaya, 3-5");
	CHECK(teacher.GetLessonName() == "Russian language");
}

SCENARIO("create student")
{
	CStudent student("Maria", "Korchemkina", "Vyacheslavovna", "Pervomayskaya, 19", "890789678", "Volgatech");
	CHECK(student.GetFirstName() == "Maria");
	CHECK(student.GetLastName() == "Korchemkina");
	CHECK(student.GetPatronymic() == "Vyacheslavovna");
	CHECK(student.GetAddress() == "Pervomayskaya, 19");
	CHECK(student.GetStudentIdNumber() == "890789678");
	CHECK(student.GetUniversityName() == "Volgatech");
}

SCENARIO("create anvanced student")
{
	CAdvancedStudent advancedStudent("Anna", "Korchemkina", "Vyacheslavovna", "Pervomayskaya, 19", "7896875677", "VyatGU", "The effect of proteins on the growth of cancer cells");
	CHECK(advancedStudent.GetFirstName() == "Anna");
	CHECK(advancedStudent.GetLastName() == "Korchemkina");
	CHECK(advancedStudent.GetPatronymic() == "Vyacheslavovna");
	CHECK(advancedStudent.GetAddress() == "Pervomayskaya, 19");
	CHECK(advancedStudent.GetStudentIdNumber() == "7896875677");
	CHECK(advancedStudent.GetUniversityName() == "VyatGU");
	CHECK(advancedStudent.GetDissertationTopic() == "The effect of proteins on the growth of cancer cells");
}

SCENARIO("create worker")
{
	CWorker worker("Ekaterina", "Sapeeva", "Vladimirovna", "Sovetskaya, 20-3", "freelancer");
	CHECK(worker.GetFirstName() == "Ekaterina");
	CHECK(worker.GetLastName() == "Sapeeva");
	CHECK(worker.GetPatronymic() == "Vladimirovna");
	CHECK(worker.GetAddress() == "Sovetskaya, 20-3");
	CHECK(worker.GetSpecialisation() == "freelancer");
}