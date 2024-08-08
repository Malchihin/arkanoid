import random

numbers = [] 


for i in range(10):  
    third_digit = '6'  
    other_digits = [str(random.randint(0, 9)) for _ in range(4)] 
    number = ''.join([other_digits[j] if j != 2 else third_digit for j in range(5)]) 
    numbers.append(int(number))
ordered_numbers = sorted(set(numbers), reverse=True)
if len(ordered_numbers) >= 5:
    fifth_largest = ordered_numbers[4]
    print(f"Пятый по величине элемент в последовательности: {fifth_largest}")
else:
    print("В последовательности меньше 5 уникальных чисел")