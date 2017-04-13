# import random
# foutA = open("/Users/bill/Library/Developer/Xcode/DerivedData/BenchMark_Functions-cfsxbvinexujznawrykhsnaabgdw/Build/Products/Debug/MatrixA.txt", "w")
# foutB = open("/Users/bill/Library/Developer/Xcode/DerivedData/BenchMark_Functions-cfsxbvinexujznawrykhsnaabgdw/Build/Products/Debug/MatrixB.txt", "w")
#
# size = int(input("How big an array?: "))
#
# for i in range(0, size):
#     for j in range(0, size):
#         t = random.randint(1, 65535)
#         foutA.write(str(t))
#         foutA.write("\n")
#         foutB.write(str(t))
#         foutB.write("\n")
# foutA.close()
# foutB.close()
#
# fout = open("/Users/bill/Library/Developer/Xcode/DerivedData/BenchMark_Functions-cfsxbvinexujznawrykhsnaabgdw/Build/Products/Debug/Strings.txt", "w")
#
# size = int(input("How many strings?: "))
# for i in range(0, size):
#     for j in range(0, 512):
#         fout.write(str(random.randint(0, 1)))
#     fout.write("\n")
# fout.close()



import random
from decimal import *
fout = open("2d_Int_Arrays.txt", "w")

size = int(input("How big an array?: "))

fout.write("int a[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("] = {\n")


for i in range(0, size):
    fout.write("{")
    fout.write(str(random.randint(1, 65535)))
    for j in range(0, size-1):
        fout.write(", ")
        fout.write(str(random.randint(1, 65535)))
    fout.write("},\n")
fout.write("};")
fout.write("\n\n")

fout.write("int b[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("] = {\n")
for i in range(0, size):
    fout.write("{")
    fout.write(str(random.randint(1, 32767)))
    for j in range(0, size-1):
        fout.write(", ")
        fout.write(str(random.randint(1, 32767)))
    fout.write("},\n")
fout.write("};")
fout.write("\n\n")

fout.write("int c[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("];")

fout.close()

fout = open("Double_Arrays.txt", "w")

fout.write("double a[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("] = {\n")


for i in range(0, size):
    fout.write("{")
    fout.write(str(Decimal(random.randint(1, 32767)/2)))
    for j in range(0, size-1):
        fout.write(", ")
        fout.write(str(Decimal(random.randint(1, 32767)/2)))
    fout.write("},\n")
fout.write("};")
fout.write("\n\n")

fout.write("double b[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("] = {\n")
for i in range(0, size):
    fout.write("{")
    fout.write(str(Decimal(random.randint(1, 32767)/2)))
    for j in range(0, size-1):
        fout.write(", ")
        fout.write(str(Decimal(random.randint(1, 32767)/2)))
    fout.write("},\n")
fout.write("};")
fout.write("\n\n")

fout.write("double c[")
fout.write(str(size))
fout.write("][")
fout.write(str(size))
fout.write("];")

fout.close()

fout = open("1d_Int_Arrays.txt", "w")

fout.write("int a[")
fout.write(str(size))
fout.write("] = {")

for i in range(0, size-1):
    fout.write(str(random.randint(1, 32767)))
    fout.write(", ")
fout.write(str(random.randint(1, 32767)))
fout.write("};")
fout.write("\n\n")

fout.write("int c[")
fout.write(str(size))
fout.write("];")

fout.close()



fout = open("Strings.txt", "w")
length = 512
size = int(input("How many strings?: "))
fout.write("char line[")
fout.write(str(size))
fout.write("][")
fout.write(str(length))
fout.write("] = {\n")

for i in range(0, size):
    fout.write("\"")
    for j in range(0, length):
        fout.write(str(random.randint(0, 1)))
    fout.write("\"")
    fout.write(",")
    fout.write("\n")
fout.write("};")
fout.close()

