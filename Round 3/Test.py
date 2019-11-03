import os
import glob

if __name__ == "__main__":
    os.system('g++ -Ofast Round\ 3/Generator.cpp -o Round\ 3/Generator.out -w')
    os.system('Round\ 3/Generator.out')
    os.chdir('Round 3')
    flist = glob.glob('in/*.txt')
    flist.sort()
    for file in flist:
        print(file)
        os.system('time ((./Solution1.out < '+file +
                  ') > out/'+file.split('/')[-1]+')')
        if file.split('/')[-1][0] == 'E':
            os.system('(./Solution0.out < '+file + ') > a0.txt')
            os.system('diff a0.txt '+'out/'+file.split('/')[-1])
        # os.system('cat a1.txt')
        print('\n')
