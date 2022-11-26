#include < stdio.h>
#include < stdlib.h>
#include < string.h>

char *preorden="GEAIBMCLDFKJH";
char *inorden="IABEGLDCFMKHJ";
char *postorden;

/*---------------------------------------*/

void post(char *pre,char *in,char *pos,int n)
{
  int longIzqda;

  if(n!=0){
    pos[n-1]=pre[0];
    longIzqda=strchr(in,pre[0])-in;
    post (pre+1,in,pos,longIzqda);
    post (pre+1+longIzqda,in+1+longIzqda,pos+longIzqda,n-1-longIzqda);
  }
}

/*----------------------------------------*/

int main(int argc,char *argv[])
{
  int aux;

  aux=strlen(preorden);
  postorden=(char *)malloc(aux*sizeof(char));
  if (postorden){
    printf("El preorden es: %s\n",preorden);
    printf("El inorden es: %s\n",inorden);
    post(preorden,inorden,postorden,aux);
    postorden[aux]='\0';
    printf("El postorden calculado es: %s\n",postorden);
    free(postorden);
  }
  else{
    fprintf(stderr,"Error: Sin memoria\n");
    return 1;
  }

  return 0;
}

