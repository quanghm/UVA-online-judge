import sys

while True:
    nbhw_ = sys.stdin.readline()
    if nbhw_ == '':
        break;
    nbhw = nbhw_.split()

    s = (int)(nbhw[1])+1;
    for h in range(0,int(nbhw[2])):
        p = int(sys.stdin.readline())
        a_ = sys.stdin.readline()
        a = a_.split()

        for i in range(0,int(nbhw[3])):
            if (int(a[i])>=int(nbhw[0]) ):
                temp = p*int(nbhw[0]);
                if (temp<s):
                    s = temp
    if (s>int(nbhw[1]) ):
        print("stay home")
    else:
        print(s)
