#!/usr/bin/python

import sys, getopt
import os.path
from os import path


inputfile = ''

def main(argv):
    global inputfile
    try:
        opts, args = getopt.getopt(argv,"hi:",["ifile="])
    except getopt.GetoptError:
        print 'fcheck.py -i <inputfile>'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print 'Usage: fcheck.py -i <inputfile>'
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg

if __name__ == "__main__":
   main(sys.argv[1:])

if len(inputfile) == 0:
    print 'Usage fcheck.py -i <inputfile>'
    sys.exit(1)

if not path.isfile(inputfile):
    print("File path '{}' does not exist. Exiting...".format(inputfile))
    sys.exit(1)

line = ''

with open(inputfile) as fp:
    line = fp.readline()
# print line

line = line.rstrip('\r\n')
alen = len(line)
mid = alen//2
# print ("Length: {}; Mid: {}".format(alen, mid))

def fcheck(alist):
    if len(alist) < 2:
        return True
    for i in range(1,len(alist)):
        if alist[i-1] != alist[i]:
            return False
    return True;

subs = []
for i in range (1, mid):
    subs = []
    for j in range (0,alen,i):
        sub = line[j:j+i]
        subs.append(sub)
        # print ("i:{}; j:{}; sub:{}".format(i, j, sub))
    if fcheck(subs):
        print ("{}: The check is failed for: {}".format(inputfile, subs))
        sys.exit(1)
    #else:
        #print ("Ok: {}".format(i))
    # print subs

print "{}: The check succeeded.".format(inputfile)
