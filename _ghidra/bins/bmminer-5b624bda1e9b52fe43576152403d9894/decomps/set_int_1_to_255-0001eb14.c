
/* WARNING: Unknown calling convention */

char * set_int_1_to_255(char *arg,int *i)

{
  char *pcVar1;
  
  pcVar1 = set_int_range(arg,i,1,0xff);
  return pcVar1;
}

