fname = 'UTF16LE.txt'
with open(fname, encoding='utf-16') as f:
    content = f.read().splitlines()
    print (content)
print (content[0].split())
a = content[0].split()

fp =  open("UTF16LEoutput.txt","w", encoding='utf-16')

for i in range (0, len (a)):
    #print (content[0].split()[i])
    #print (content[1].split()[i])
    print (type (content[0].split()[i]))
    fp.write("{L'%s',L'%s'}," % (content[0].split()[i], content[1].split()[i]))
    if (i%10 == 9):
        fp.write ("\n")

fp.close()
