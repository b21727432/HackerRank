def glassHour(stars):

 bottomPyramid = 1
 bottomPyramidSpace = int(stars/2)
 height=int(stars/2)
 temp=""
 for i in range(height):
     for j in range(i):
         temp+=" "
     for a in range(stars):
         temp+="*"
     stars-=2
     temp+="\n"
 for i in range(height + 1):
     for j in range(bottomPyramidSpace):
         temp+=" "
     for j in range(bottomPyramid):
         temp+="*"
     bottomPyramid+=2
     bottomPyramidSpace-=1
     temp+="\n"

 print(temp)


glassHour(11)
