import random

array = [x for x in range(10, 0, -1)]

str1 = "int array[100] = "

strend = ";"
strtt = str1 + str(array) + strend

print (strtt)   