class Int_wrapper:
    def __init__(self, num):
        self.num = num
    def __mul__(self, other):
        return Int_wrapper(self.num * other)
    def __imul__(self, other):
        self.num *= other
    def __str__(self):
        return str(self.num)
    def __repr__(self):
        return str(self)

def my_func_assignment(a):
    a = a * 2

def my_func_augmented_assignment(a):
    a *= 2

if __name__ == '__main__':
    a_int = 8
    a_cls = Int_wrapper(8)

    print('Original values')
    print(f'{a_int=}')
    print(f'{a_cls=}')

    my_func_assignment(a_int)
    my_func_assignment(a_cls)
    print('After calling my_func_assignment')
    print(f'{a_int=}')
    print(f'{a_cls=}')

    print('After calling my_func_augmented_assignment')
    my_func_augmented_assignment(a_int)
    my_func_augmented_assignment(a_cls)
    print(f'{a_int=}')
    print(f'{a_cls=}')