from random import randint

def generate():
	numbers = 5
	for i in range(0, numbers):
		if (i == numbers - 1):
			print(randint(0, 100), end='')
		else:
			print(randint(0, 100), end=' ')


if __name__ == '__main__':
	generate()

