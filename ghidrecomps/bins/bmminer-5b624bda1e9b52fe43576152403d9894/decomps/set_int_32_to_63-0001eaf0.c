
/* WARNING: Unknown calling convention */

char * set_int_32_to_63(char *arg,int *i)

{
  char *pcVar1;
  
  pcVar1 = set_int_range(arg,i,0x20,0x3f);
  return pcVar1;
}

