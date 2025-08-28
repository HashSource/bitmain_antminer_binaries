
/* WARNING: Unknown calling convention */

char * opt_set_intval(char *arg,int *i)

{
  char *pcVar1;
  int local_c;
  
  pcVar1 = opt_set_longval(arg,&local_c);
  if (pcVar1 == (char *)0x0) {
    *i = local_c;
  }
  return pcVar1;
}

