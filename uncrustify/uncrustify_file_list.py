import os


def writeFiles(f) :
    exclude = set(['FreeRTOS'])

    for root, dirs, files in os.walk("..\src"):
        dirs[:] = [d for d in dirs if d not in exclude]
        for file in files:
            if file.endswith(".h"):
                f.write(os.path.join(root, file)+ '\n')
            if file.endswith(".cpp"):
                f.write(os.path.join(root, file)+ '\n')
    return


#### Main ####
SaveFilename = "uncrustify_files.txt"
f = open(SaveFilename,'w')
writeFiles(f)
f.close()
