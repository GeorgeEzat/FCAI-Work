import os
# ---------------------------------------------------


def clear_screen():
    if os.name == 'nt':
        _ = os.system('cls')
# ---------------------------------------------------


def validate_num(num):
    while True:
        if num.isdigit():
            num = int(num)
            break
        else:
            num = input('Please enter a positive integer number: ')
    return num
# ---------------------------------------------------


def calc_factors():
    num = input('Enter your number: ')
    num = validate_num(num)
    factors = []
    for i in range(1, num + 1):
        if num % i == 0:
            factors.append(i)
        else:
            continue
    print('Factors of ', num, 'are', factors)
# ---------------------------------------------------


def header():
    clear_screen()
    print('------------------------------')
    print('Welcome in Factors_Calculator!')
    print('------------------------------')
# ---------------------------------------------------


def program():
    while True:
        header()
        calc_factors()
        calc_again = input(
            'Do you want to calculate factors of another number? [y/n]').upper()
        if calc_again == "Y":
            continue
        else:
            break
    print('Thanks for using my Factors_Calculator :)')
# ---------------------------------------------------


program()
