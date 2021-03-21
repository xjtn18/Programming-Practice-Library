def print_star_square(rows : int) -> None:
	for i in range(rows):
		print("*" * rows)


if __name__ == "__main__":
	rows = int(input())
	print_star_square(rows)
