
/* WARNING: Unknown calling convention */

char * set_int_0_to_9999(char *arg,int *i)

{
  char *pcVar1;
  
  pcVar1 = set_int_range(arg,i,0,9999);
  return pcVar1;
}

