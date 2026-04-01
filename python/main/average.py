def simple_average(quantity_of_grades):
    total = 0
    for i in range(1, quantity_of_grades + 1):
        while True:
            try:
                grade = float(input(f"grade {i}:\n"))
                if grade >= 0:
                    break
                else:
                    print("Please, insert a grade greater than or equal to 0.")
            except ValueError:
                print("Please, type '0' or a positive number.")
        total = total + grade
    return total / quantity_of_grades

def weighted_average(quantity_of_grades):
    total = 0
    sum_of_weights = 0
    for i in range(1, quantity_of_grades + 1):
        while True:
            try:
                weight = float(input(f"weight of grade {i}:\n"))
                if weight > 0:
                    break
                else:
                    print("Please, insert a weight greater than 0.")
            except ValueError:
                print("Please, type a positive number for the weight.")
        sum_of_weights = sum_of_weights + weight
        while True:
            try:
                grade = float(input(f"grade {i}:\n"))
                if grade >= 0:
                    break
                else:
                    print("Please, insert a grade greater than or equal to 0.")
            except ValueError:
                print("Please, type '0' or a positive number.")
        total = total + grade * weight
    return total / sum_of_weights

while True:
    while True:
        try:
            quantity_of_grades = int(input("type the quantity of grades:\n"))
            if quantity_of_grades >= 1:
                break
            else:
                print("Please, insert a quantity of grades greater than 0.")
        except ValueError:
            print("Please, type a positive integer number.")

    while True:
        average_type = str(input("Insert the type of average ('s' for simple and 'w' for weighted):\n")).strip().lower()
        if average_type != "s" and average_type != "w":
            print("please, type 's' or 'w'.")
        else:
            break

    if average_type == "s":
        total = simple_average(quantity_of_grades)
    else:
        total = weighted_average(quantity_of_grades)

    print(total)

    while True:
        continue_calculation = input("Do you want to calculate another average?(s/n) ").strip().lower()
        if continue_calculation == "n":
            print("Thank you for using my script! :)")
            exit()
        elif continue_calculation == "s":
            break
        else:
            print("Invalid option. Please, type 's' or 'n'.")
