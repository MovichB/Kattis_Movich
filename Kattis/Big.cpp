#include<stdio.h>
#include <stdlib.h> 
struct Arete { 
	       int noeud; 
	       int d; 
	       struct Arete* arete_suivant; 
	}; 
	 
	struct Noeud{ 
	       struct Arete* arete; 
	       int d; 
	};
	
typedef struct Arete* arete1; 
typedef struct Noeud* noeud1; 

Noeud** CreerGraphe(int taille){ 
	  noeud1* Newgraphe = (noeud1*)malloc(taille*sizeof(noeud1)); 
	  int i; 
	  for(i=0;i<taille;i++){ 
	    Newgraphe[i]=(noeud1)malloc(sizeof(struct Noeud)); 
	    Newgraphe[i]->d=i; 
	    Newgraphe[i]->arete=NULL; 
	  } 
	  return Newgraphe; 
	}
	
	 
noeud1* CreerArete(noeud1* graphe,int a,int b,int d){ 
	  if(graphe[a]->arete==NULL){ 
	    arete1 Newarete=(arete1)malloc(sizeof(struct Arete)); 
	    Newarete->d=d; 
	    Newarete->noeud=b; 
	    Newarete->arete_suivant=NULL; 
	    graphe[a]->arete=Newarete; 
	    return graphe;
		} 
	  else{ 
	    arete1 temp=graphe[a]->arete; 
	    while( !(temp->arete_suivant==NULL)){ 
	    temp=temp->arete_suivant; } 
	     arete1 Newarete=(arete1)malloc(sizeof(struct Arete)); 
	     Newarete->d=d; 
	     Newarete->noeud=b; 
	     Newarete->arete_suivant=NULL; 
	     if(temp->noeud>b){ 
	      Newarete->arete_suivant=temp->arete_suivant; 
	      Newarete->noeud=temp->noeud; 
	      temp->noeud=b; 
	      temp->arete_suivant=Newarete; 
	      return graphe; } 
	     temp->arete_suivant=Newarete; 
	    return graphe; } 
	}
	
void affiche(noeud1* graphe, int taille){ 
	  int i,j; 
	  arete1 temp; 
	  for(i=0;i<taille;i++){ 
	    printf("le sommet %d ",graphe[i]->d); 
	    if(!(graphe[i]->arete==NULL)){ 
	      printf("lie a  %d",graphe[i]->arete->noeud); 
	      temp=graphe[i]->arete; 
	      while(!(temp->arete_suivant==NULL)){ 
	      temp=temp->arete_suivant; 
	      printf(",%d",temp->noeud); 
	      } 
	    } 
	  printf("\n"); 
	  } 
	} 

	int main(int argc, char *argv[]) 
	{  
	  int a,b,d,i=0,N,arete;
	  noeud1* graphe=NULL; 
	  scanf("%d",&N);
	  graphe=CreerGraphe(N); 
	  scanf("%d",&arete);
	  while(arete){
	  	scanf("%d %d %d",&a,&b,&d);
	  	graphe=CreerArete(graphe,a,b,d);
	  	i++;
	  }
	  affiche(graphe,N); 
	  return 0; 
	}	

