import random
def TryInt(msg):
    while True:
        try:
            x = int(input(msg))
            if 0 <= x <= 100:
                return(x)
            else:
                msg = "please enter a number between 0 and 100."
        except ValueError:
            msg = "invalid input. please enter a valid number."
while True:
    y = random.randint(0, 100)
    p = 1
    x = TryInt("enter your guess (between 0 and 100): ")
    while x != y:
        p += 1
        if x < y:
            print("the number is higher than your guess")
        else:
            print("the number is lower than your guess")
        x = TryInt("try again: ")
    print(f"you won!! congratulations!! you tried {p} times")
    while True:
        pa = input("play again? (y/n) ").strip().lower()
        if pa == "n":
            print("Thanks for playing! :)")
            exit()
        elif pa == "y":
            break
        else:
            print("Invalid option. Please type 'y' or 'n'.")
