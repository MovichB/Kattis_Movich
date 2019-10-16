def echanger(L,i,j):
  L[i], L[j] = L[j], L[i]

def partitionner(L,Lg,Ld):
    for k in range(Lg,Ld):
        if L[k]<=L[Ld]:
            echanger(L,k,Lg)
            Lg=Lg+1
    echanger(L,Ld,Lg)
    return Lg

def tri_rapide(L,Lg,Ld):
    if Lg<Ld:
        pivot=partitionner(L,Lg,Ld)
        tri_rapide(L,Lg,pivot-1)
        tri_rapide(L,pivot+1,Ld)
    
t = [14,12,1,30,2,19,21,40]
print(t)
tri_rapide(t,0,len(t)-1)
print(t)
