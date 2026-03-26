print('What do you want the scaling factor to be for your shape?')
scalingFactor = int(input())
print('Please enter your shape (type "!quit: to leave"):')

shape = []
userInput = ""
while True:
    userInput = input()
    if userInput == "!quit":
        break
    shape.append(userInput)

for line in shape:
    for i in range(0, scalingFactor):
        for letter in line:
            for j in range(0, scalingFactor*2):
                print(letter, end='')
        print()           

