student = ""
grade = ""
studentList = [] 
nameList = []  
Alist = []
exit = True
total_grade = 0
numOfGrades = 0
avgGrades = 0


def custom_sort(t):
    return t[1]



while exit:
    student = input("Student's name: ")

    if student == "end":
        studentList.sort(key=custom_sort)

        for a_tuple in studentList:
            nameList.append(a_tuple[0])
            Alist.append(a_tuple[1])

        for i in range(len(studentList)):
            if Alist[0] == Alist[i]:
                print("Students that gets the lowest grade: " ,nameList[i])

        for i in range(len(studentList)):
            if Alist[len(studentList) - 1] == Alist[i]:
                print("Students that gets the highest grade: ", nameList[i])

        print("Class average is ", float(avgGrades))

        break

    grade = input(student + "'s grade: ")

    if grade != "end":
        studentList.append(tuple([student, grade]))
        total_grade += int(grade)
        numOfGrades += 1
        avgGrades = float(total_grade/numOfGrades)

    else:
        studentList.sort(key=custom_sort)

        for a_tuple in studentList:
            nameList.append(a_tuple[0])
            Alist.append(a_tuple[1])

        for i in range(len(studentList)):
            if Alist[0] == Alist[i]:
                print("Students that gets the lowest grade: " ,nameList[i])

        for i in range(len(studentList)):
            if Alist[len(studentList) - 1] == Alist[i]:
                print("Students that gets the highest grade: ", nameList[i])

        print("Class average is ", float(avgGrades))


        break



