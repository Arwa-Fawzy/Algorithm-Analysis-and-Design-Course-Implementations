#sorting 10000 string 

with open('./10000Words.txt') as f:
    lines = f.read().splitlines()
l=[]
for i in lines:
    l.append(int(i))

def countingSort(l, exp1):

	n = len(l)
	output = [0] * (n)

	count = [0] * (10)
	for i in range(0, n):
		index = l[i] // exp1
		count[index % 10] += 1
	for i in range(1, 10):
		count[i] += count[i - 1]
	i = n - 1
	while i >= 0:
		index = l[i] // exp1
		output[count[index % 10] - 1] = l[i]
		count[index % 10] -= 1
		i -= 1
	i = 0
	for i in range(0, len(l)):
		l[i] = output[i]

def radixSort(l):
	max1 = max(l)
	exp = 1
	while max1 / exp >= 1:
		countingSort(l, exp)
		exp *= 10

radixSort(l)




