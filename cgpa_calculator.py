def calculate_cgpa(student_id):
    total_gpa = 0
    missing_sem = 0
    for i in range(8):
        try:
            total_gpa = total_gpa + get_gpa(student_id, i+1)
        except KeyError:
            return -1
        except ValueError:
            total += 3.0
        except IndexError:
            missing_sem = missing_sem + 1
            continue
    total_gpa = total_gpa / (8 - missing_sem)
    return round(total, 2)