def create_hollow_square(rows : int) -> None:
	for i in range(rows):
		if i == 0 or i == rows-1:
			print("*" * rows)
		else:
			print("*" + " " * (rows-2) + "*")


if __name__ == "__main__":
	rows = int(input())
	create_hollow_square(rows)
