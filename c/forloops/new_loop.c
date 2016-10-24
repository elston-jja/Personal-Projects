# include <stdio.h>
 
int help() {
   printf("Usage: myprogram [-s ] [-n ] [-true]\n");
   printf("\t-s: a string a\n");
   printf("\t-n: a number\n");
   printf("\t-true: a single parameter\n");
   return 1;
}
 
int main(int argc,char *argv[])
{
  int i =1;
  
  if (argc < 2){
    return help();
    
  } else if(argc > 10){
    return help();
    
  } else{
    
    for(i = 1; argc>i;i++){
      printf("Argument %d was: %s \n",i,argv[i]);
    }
  }
  return 0;
}
