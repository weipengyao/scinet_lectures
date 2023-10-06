def check_luhn(number: list) -> bool:
    sum = 0
    for (i, digit) in enumerate(number[-2::-1]):
        if i % 2 == 0:
            digit *= 2
        if digit > 9:
            digit -= 9
        sum += digit
    check_digit_calculated = (10 - (sum % 10)) % 10
    check_digit = number[-1]
    return check_digit_calculated == check_digit

def read_digits(prompt: str = 'Please enter the number:') -> list:
    input_string = input(prompt + ' ')
    output = [int(c) for c in input_string]
    return output

if __name__ == '__main__':
    #### Please do not save your real credit card information in this source file. ####
    # You may instead read it from standard input like so:
    #   number = read_digits()
    # In this case, the secret number only exists in RAM, which is relatively safe.
    number = [2, 4, 4, 5, 3, 9, 4, 2, 5, 8, 8, 1, 1, 3, 6, 9]

    if check_luhn(number):
        print('Validation succeeded.')
    else:
        print('Validation failed.')