def fusionner(a, b):
     i, j = 0, 0
     L = []
     while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            L.append(a[i])
            i=i+1
        else:
            L.append(b[j])
            j=j+1
     L.extend(a[i:])
     L.extend(b[j:])
     return L
    
def tri_fusion(L):
     if len(L) == 1 or len(L) == 0:
          return L[:len(L)] 
     L1 = L[:len(L)//2]
     L2 = L[len(L)//2:len(L)]
     A,B = tri_fusion(L1),tri_fusion(L2)
     return fusionner(A, B)
    
L = [14,12,1,30,2,19,21,40]
tri_fusion(L)
print(L)
print(tri_fusion(L))
