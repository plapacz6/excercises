def FindIntersection(strArr):

  # code goes here
  listA = strArr[0].split(",")
  listB = strArr[1].split(",")
  setA = set()
  setB = set()
  print(listA)
  print(listB)
  for nr in listA:
    setA.add(nr.strip())
  for nr in listB:
    setB.add(nr.strip())    
  print(setA)
  print(setB)
  setC = setA.intersection(setB)
  print(setC)
  listC = []
  for nr in setC:
    listC.append(nr)
  listC.sort()
  print(listC)
  listD = []
  for nr in listC:
    listD.append(str(nr))
    print(listD)
  str1 = ""
  for snr in listD:
    if(str1 != ""):
      str1 += ","
    str1 += snr
    
  print(str1)

  return strArr

# keep this function call here 
print(FindIntersection(input()))
