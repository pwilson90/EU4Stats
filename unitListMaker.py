import sys, os

def main(argv):
  saveFileName = sys.argv[1]
  
  if not os.path.isfile(saveFileName):
    print("File not found at {}".format(saveFileName))
    sys.exit()

  with open(saveFileName) as saveFile:
    count = 0
    for currentLine, line in enumerate(saveFile):
      for splitLine in line.split(','):
        count += 1
        splitLine = splitLine.replace('"',"").strip().upper()
        if splitLine == '':
          continue
        else:
          print("{} = {}".format(splitLine, count))


#############################
# Starts Program
#############################
main(sys.argv[1:])