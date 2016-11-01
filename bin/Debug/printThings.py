import sys
f = open(sys.argv[1],"r")
for x in f.readlines():
	print x
f.close()