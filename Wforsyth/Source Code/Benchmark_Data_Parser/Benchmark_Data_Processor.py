import platform

class ProcessorBenchmark:
    def __init__(self, benchmark, processor, headers):
        self.processor = processor
        self.benchmark = benchmark
        if platform.system() == "Windows":
            self.fname = "tmp\\" + processor + "_" + benchmark + ".csv"
        else:
            self.fname = "tmp/" + processor + "_" + benchmark + ".csv"
        self.fout = open(self.fname, 'w')
        self.fout.write(benchmark)
        self.fout.write(",")
        self.fout.write(processor)
        self.fout.write("\n")
        self.fout.write(headers)
        self.fout.write("\n")

    def write(self, data):
        self.fout.write(data)
        self.fout.write("\n")

    def is_blank(self):
        if self.processor == "BLANK":
            return True
        else:
            return False

    def close(self):
        self.fout.close()


def get_pb(o_list, benchmark, processor):
    for o in o_list:
        if o.processor == processor and o.benchmark == benchmark:
            return o
    return ProcessorBenchmark("", "BLANK", "")

pb_list = []
pb = ProcessorBenchmark("", "BLANK", "")
fin = open("benchmarks.csv")
temp = fin.readline()
while temp != "":
    temp = temp.strip()
    tempData = temp.split(",")
    if tempData[0] == "Benchmark":
        temp = fin.readline()
        temp = temp.strip()
        pb = get_pb(pb_list, tempData[1], tempData[3])
        if pb.is_blank():
            pb = ProcessorBenchmark(tempData[1], tempData[3], temp)
            pb_list.append(pb)
    elif tempData[0] == "END":
        pass
    else:
        pb.write(temp)
    temp = fin.readline()
fin.close()

for p in pb_list:
    p.close()


for p in pb_list:
    fin = open(p.fname)
    temp = fin.readline().strip()
    tempData = temp.split(",")
    if platform.system() == "Windows":
        out_path = "output\\" + tempData[1] + "_" + tempData[0] + ".csv"
    else:
        out_path = "output/" + tempData[1] + "_" + tempData[0] + ".csv"

    if tempData[0] == "AES_Encode_Decode":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Delta T")
        fout.write(",")
        fout.write("Encode Bytes / millisecond")
        fout.write(",")
        fout.write("Decode Bytes / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            fout.write(str(float(tempData[2]) - float(tempData[1])))
            fout.write(",")
            fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write(",")
            fout.write(str(float(tempData[0]) / float(tempData[2])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Run_Time_Encode":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Bytes / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            fout.write(str((float(tempData[0]) * float(tempData[1])) / float(tempData[2])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Prime_Number":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Checks / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[2] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[2])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Integer_Subtraction":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Subtractions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Integer_Multiplication":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Multiplications / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Integer_Division":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Divisions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Integer_Addition":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Additions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Fourier_Transform":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Functions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Decimal_Subtraction":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Subtractions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Decimal_Multiplication":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Multiplications / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Decimal_Division":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Divisions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
    elif tempData[0] == "Decimal_Addition":
        print(tempData[1], ": ", tempData[0])
        fout = open(out_path, 'w')
        fout.write(temp)
        fout.write("\n")
        fout.write(fin.readline().strip())
        fout.write(",")
        fout.write("Additions / millisecond\n")
        temp = fin.readline().strip()
        tempData = temp.split(",")
        while temp != "":
            fout.write(temp)
            fout.write(",")
            if tempData[1] == "0":
                fout.write("NAN")
            else:
                fout.write(str(float(tempData[0]) / float(tempData[1])))
            fout.write("\n")
            temp = fin.readline().strip()
            tempData = temp.split(",")
        fout.close()
        fin.close()
