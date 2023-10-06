def is_strictly_increasing(sequence: list) -> bool:
    for i in range(1, len(sequence)):
        if sequence[i] <= sequence[i-1]:
            return False
    return True

if __name__ == '__main__':
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    print('Prime sequence is ', end='')
    if not is_strictly_increasing(primes): print('not ', end='')
    print('strictly increasing.')

    fibonacci = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    print('Fibonacci sequence is ', end='')
    if not is_strictly_increasing(fibonacci): print('not ', end='')
    print('strictly increasing.')