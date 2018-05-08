#!/usr/bin/env python3


def findInclude(dirName, fileName, resultFile):
    fileObj = open(os.path.join(dirName, fileName), 'r')
    for eachLine in fileObj:
        if(eachLine.startswith(r'#include') and '"' in eachLine):
            includeFile = eachLine.split('"')[1]
            if(includeFile not in resultFile):
                resultFile.append(includeFile)
                findInclude(dirName, includeFile, resultFile)


def main():
    dirName = "/home/xiaohai/perl5/codes"
    fileName = sys.argv[1]
    resultFile = []
    findInclude(dirName, fileName, resultFile)
    print(resultFile)


if __name__ == '__main__':
    import os
    import sys
    main()
