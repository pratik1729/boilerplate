"""
This function converts each line:
abc,123
to
["abc","123"],
below the topic in the given file. 
"""
def convert_file(topic,f):
    file = open(f)
    flag=0
    for line in file:
        line = line.replace('\n','')
        if(line != topic and flag==0):
            continue
        elif flag==0:
            line=next(file)
            line = line.replace('\n','')
            flag=1
        elif len(line)==0 or (flag==1 and line[0]=='#'):
            break

        line_split = line.split("%")
        print('["'+line_split[0]+'","'+line_split[1]+'"],')
    file.close()
    
convert_file("#dpkg","/home/pratik/Documents/boilerplate/package_man.txt")