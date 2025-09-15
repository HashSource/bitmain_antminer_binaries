
/* WARNING: Unknown calling convention */

char * set_int_1_to_65535(char *arg,int *i)

{
  char *pcVar1;
  
  pcVar1 = set_int_range(arg,i,1,0xffff);
  return pcVar1;
}

