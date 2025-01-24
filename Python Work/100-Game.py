import os
# ---------------------------------------------------


def clear_screen():
    if os.name == 'nt':
        _ = os.system('cls')
# ---------------------------------------------------


def valid_input(input_number):
    while True:
        if input_number.isdigit():
            input_number = int(input_number)
            break
        else:
            input_number = input('Please enter a number: ')
    while True:
        if input_number < 1 or input_number > 10:
            input_number = input('Please enter a number from 1 to 10: ')
            while True:
                if input_number.isdigit():
                    input_number = int(input_number)
                    break
                else:
                    input_number = input('Please enter a number: ')
        else:
            break
    return input_number
# ---------------------------------------------------


def after90(sum, num):
    mx_addition = 100 - sum
    if num <= mx_addition:
        return num
    else:
        if mx_addition > 1:
            print("You must choose an integer number less than or equal to ", mx_addition)
        elif mx_addition == 1:
            print("You must choose 1 because it is the maximum addition you can do now")
        while True:
            num = input('Please enter a valid number: ')
            num = valid_input(num)
            if mx_addition >= num >= 1:
                break
        return num
# ---------------------------------------------------


def header():
    print("--------------------")
    print("Welcome in 100 Game!")
    print("--------------------")
    print("Playing Instructions:")
    print("- This is two-player game.")
    print("- Two players start from 0 and alternatively add a number from 1 to 10 to the sum.")
    print("- The first player who reaches 100 wins.")
    print("- Notice that:")
    print("     When the sum pf numbers is >= 90 the player who will play the next turn")
    print("     must choose a number that doesn't make the sum over 100, eg. when sum = 93")
    print("     the player can choose any number from 1 to 7 but not greater than 7.")
    input("\nPress enter to continue...")
    clear_screen()
# ---------------------------------------------------


def play(Name, Sum):
    player = input(Name + ' Enter your number: ')
    player = valid_input(player)
    if Sum < 90:
        Sum += player
        print("The sum = ", Sum)
    elif Sum >= 90:
        player = after90(Sum, player)
        Sum += player
        print("The sum = ", Sum)
        if Sum == 100:
            print("Congratulations! " + Name + " is The Winner.")
    return Sum

# ---------------------------------------------------


def THE_GAME():
    header()
    Sum = 0
    Count = 0
    Players = ["Player 1", "Player 2"]
    print("The sum =", Sum, ", Let's start now...")
    while Sum < 100:
        Sum = play(Players[Count], Sum)
        if Count == 0:
            Count = 1
        else:
            Count = 0

    print('I hope you enjoyed my game ;)')
# ---------------------------------------------------


THE_GAME()
