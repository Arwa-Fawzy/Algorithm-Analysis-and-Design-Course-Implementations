import csv
def radix_sort(arr):

    max_digits = max([len(str(x)) for x in arr])
    for i in range(max_digits):
        buckets = [[] for _ in range(10)]
        
        for x in arr:
            digit = (x // 10**i) % 10
            buckets[digit].append(x)

        arr = [x for bucket in buckets for x in bucket]

    return arr

with open('4M_random_numbers.csv', newline='./') as f:
    reader = csv.reader(f)
    arr = [int(line) for line in f]


arr = radix_sort(arr)

for x in arr:
    print(x)
