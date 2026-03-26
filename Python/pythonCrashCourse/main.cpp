import math
for i in range(1, 20):
	for o in range(1,20):
		if (math.sin(o)*10+10 > i):
			print("X ", end='')
		else:
			print("- ", end='')
	print("")
