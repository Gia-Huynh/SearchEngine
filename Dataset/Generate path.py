import glob
with open ('test.txt', 'w') as f:
    for a in glob.glob ('*/*/*.*'):
        #print (a)
        f.write (a + '\n')
