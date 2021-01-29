#define CLASSSIZE 35 // SINIFKAPASITE
#define STUDENTNUMBERLENGTH 10 // OGRENCINUMARAUZUNLUGU
#define NAMELENGTH 25 // ADIUZUNLUGU
#define COURSENAMELENGTH 50 // DERSADIUZUNLUGU
#define COURSECODELENGTH 10 // DERSKODUZUNLUGU
#define COURSESREGISTERED 5 // KAYITLIDERSLER
#define MIDTERMWEIGHT 30 // VIZEAGIRLIK
#define FINALWEIGHT 30 // FINALAGIRLIK
#define QUIZWEIGHT 20 // QUIZAGIRLIK
#define HOMEWORKWEIGHT 20 // ODEVAGIRLIK
#define SIZE(x)  (sizeof(x) / sizeof((x)[0]))
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct fullName{ //tam adi
	char *name; //adi
	char *surname; //soyadi
}name_t;

typedef struct examGrades{ //sinav not
	double midterm; //vize
	double final; //final
	double quiz; //quiz
	double homework; //odev
}grades_t;

typedef struct courseRegistered{ //kayitliDersler
	char courseName[COURSENAMELENGTH]; //ders adi
	char courseCode[COURSECODELENGTH]; //ders kodu
	grades_t grades; //notler
	char letterGrade[2]; //herf notu
	double numericGrade; //numerik notu
}courseReg_t;

typedef struct studentInfo{ //ogrenci bilgi
	name_t studentName; //ogrenci adi
	char *stNo; //ogrenci numara
	courseReg_t courses[COURSESREGISTERED]; //dersler
	double gpa; //ortalama
}student_t;

typedef struct courseInfo{ //ders bilgi
	char courseName[COURSENAMELENGTH]; //ders adi
	char courseCode[COURSECODELENGTH]; //ders kodu
	student_t students[CLASSSIZE]; //ogrenciler
	double courseAverage; //ders ortalama
}course_t;


void ogrenciEkle(course_t* yeniDers, char* name, char* surname, char* stNo, courseReg_t* courses, int* sira){
	
	
	yeniDers->students[*sira].studentName.name = name;
	yeniDers->students[*sira].studentName.surname =surname;
	
	yeniDers->students[*sira].stNo = stNo;
	int i = 0;
	for(i = 0; i < 5; i++){
		if(strcmp(courses[i].courseName,"") == 0){
			
			continue;
		}
		else{
			if(courses[i].grades.final < 0 || courses[i].grades.final > 100 || courses[i].grades.homework < 0 || courses[i].grades.homework > 100 || courses[i].grades.midterm < 0 || courses[i].grades.midterm > 100 || courses[i].grades.quiz < 0 || courses[i].grades.quiz > 100){
				printf("Notlar 0 ile 100 araliginde girilmemis...Ogrenci Eklenemiyor\n");
			}
			else{
				yeniDers->students[*sira].courses[i] = courses[i];	
			}
		}
	}
	*sira = *sira + 1;
}

course_t dersEkle(char* courseName, char* courseCode){
	course_t yeniDers;
	strcpy(yeniDers.courseName, courseName);
	strcpy(yeniDers.courseCode, courseCode);
	return yeniDers;
}

void OgrencininDersNotuHesapla(student_t* student){
	int i;
	double totalgrade = 0;
	
	for(i = 0; i < 5; i++){
		if(strcmp(student->courses[i].courseName,"") == 0){
			
			continue;
		}
		totalgrade = 0;
		totalgrade += student->courses[i].grades.quiz * QUIZWEIGHT / 100 + student->courses[i].grades.midterm * MIDTERMWEIGHT / 100 + student->courses[i].grades.homework * HOMEWORKWEIGHT / 100 + student->courses[i].grades.final * FINALWEIGHT / 100;
		printf("Ogrencinin %s dersinde ders notu ortalamasi : %lf \n", student->courses[i].courseName, totalgrade);
		if(totalgrade >= 90 && totalgrade <= 100){
			strcpy(student->courses[i].letterGrade,"AA");
			student->courses[i].numericGrade = 4.0;
		}
		else if(totalgrade >= 85 && totalgrade <= 89){
			strcpy(student->courses[i].letterGrade,"BA");
			student->courses[i].numericGrade = 3.5;
		}
		else if(totalgrade >= 80 && totalgrade <= 84){
			strcpy(student->courses[i].letterGrade,"BB");
			student->courses[i].numericGrade = 3.0;
		}
		else if(totalgrade >= 75 && totalgrade <= 79){
			strcpy(student->courses[i].letterGrade,"CB");
			student->courses[i].numericGrade = 2.5;
		}
		else if(totalgrade >= 70 && totalgrade <= 74){
			strcpy(student->courses[i].letterGrade,"CC");
			student->courses[i].numericGrade = 2.0;
		}
		else if(totalgrade >= 60 && totalgrade <= 69){
			strcpy(student->courses[i].letterGrade,"DC");
			student->courses[i].numericGrade = 1.5;
		}
		else if(totalgrade >= 50 && totalgrade <= 59){
			strcpy(student->courses[i].letterGrade,"DD");
			student->courses[i].numericGrade = 1.0;
		}
		else if(totalgrade >= 0 && totalgrade <= 49){
			strcpy(student->courses[i].letterGrade,"FF");
			student->courses[i].numericGrade = 0.0;
		}
	}	
}

void OgrenciOrtalamHesapla(student_t* student){
	int i;
	double gpa = 0;
	int size = 5;
	for(i = 0; i < 5; i++){
		if(strcmp(student->courses[i].courseName, "") == 0){
			size--;
			continue;
		}
		gpa += student->courses[i].numericGrade;
		
	}
	gpa = gpa / size;
	student->gpa = gpa;
}

void OgrenciBilgiGoster(student_t X){
	
	printf("Ogrencinin Adi Soyadi : %s %s\nOgrencinin Numarasi : %s\nOgrencinin GPA : %lf\nOgrencinin Aldigi Dersler :\n", X.studentName.name, X.studentName.surname, X.stNo, X.gpa);
	int i;
	for(i = 0; i < 5; i++){
		if(strcmp(X.courses[i].courseName, "") == 0){
			continue;
		}
		printf("Dersin ismi : %s\nDersin Kodu : %s\nDersin Harf Notu : %s\nDersin Numeric Degeri : %lf\n", X.courses[i].courseName, X.courses[i].courseCode, X.courses[i].letterGrade, X.courses[i].numericGrade);
	}
}

void DersBilgiGoster(course_t X, int *ptr){
	printf("Dersin Ismi : %s\nDersin Kodu : %s\nDersin Ortalamasi : %lf\n", X.courseName, X.courseCode, X.courseAverage);
	printf("Dersi alan ogrenciler :\n");
	int i;
	for(i = 0 ; i < *ptr ; i++){
		printf("Ad soyad : %s %s Numara : %s GPA : %lf\n", X.students[i].studentName.name, X.students[i].studentName.surname, X.students[i].stNo, X.students[i].gpa);
	}
}

void SinifGoster(course_t X, int* ptr){
	printf("Dersin Ismi : %s\nDersin Kodu : %s\nDersi Alan Ogrenci Sayisi : %d\n", X.courseName, X.courseCode, *ptr);
	printf("Dersi alan ogrenciler :\n");
	int i;
	for(i = 0 ; i < *ptr ; i++){
		printf("Ad soyad : %s %s Numara : %s GPA : %lf\n", X.students[i].studentName.name, X.students[i].studentName.surname, X.students[i].stNo, X.students[i].gpa);
	}
}

void DersOrtalamaHesapla(course_t* X, int* ptr){
	int i,y;
	double coursenot = 0;
	for(i = 0; i < *ptr; i++){
		
		for(y = 0; y < 5; y++){
			if(strcmp(X->students[i].courses[y].courseName, "") == 0){
				continue;
			}
			if(strcmp(X->students[i].courses[y].courseName, X->courseName) == 0){
				coursenot += X->students[i].courses[y].numericGrade;
			}
		}
		
	}
	coursenot /= *ptr;
	X->courseAverage = coursenot;
}



int main(){
	
	int sira = 0;
	int* ptr = &sira;
	course_t X = dersEkle("bilgisayar", "101");
	course_t* ders = &X;
	
	courseReg_t Y[5];
	
	strcpy(Y[0].courseCode, "101");
	strcpy(Y[0].courseName, "bilgisayar");
	printf("Sirasiyla final, homework, midterm, quiz degerlerini giriniz...");
	scanf("%lf", &(Y[0].grades.final));
	getchar();
	scanf("%lf", &(Y[0].grades.homework));
	getchar();
	scanf("%lf", &(Y[0].grades.midterm));
	getchar();
	scanf("%lf", &(Y[0].grades.quiz));
	getchar();
	
	
	
	
	strcpy(Y[1].courseCode, "202");
	strcpy(Y[1].courseName, "bilgisayar2");
	printf("Sirasiyla final, homework, midterm, quiz degerlerini giriniz...");
	scanf("%lf", &(Y[1].grades.final));
	getchar();
	scanf("%lf", &(Y[1].grades.homework));
	getchar();
	scanf("%lf", &(Y[1].grades.midterm));
	getchar();
	scanf("%lf", &(Y[1].grades.quiz));
	getchar();
	
	courseReg_t* yptr = &Y[0];
	
	ogrenciEkle(ders, "osman", "gultekin", "11111111", yptr, ptr);
	
	OgrencininDersNotuHesapla(&X.students[0]);

	OgrenciOrtalamHesapla(&X.students[0]);
	
	DersOrtalamaHesapla(&X, ptr);
	
	OgrenciBilgiGoster(X.students[0]);
	
	DersBilgiGoster(X, ptr);
	
	SinifGoster(X, ptr);
	
	
	return 0;
}

















