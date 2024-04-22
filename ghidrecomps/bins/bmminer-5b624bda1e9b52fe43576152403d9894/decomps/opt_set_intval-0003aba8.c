
/* WARNING: Unknown calling convention */
/* Local variable err:char *[r0:4] conflicts with parameter, skipped. */

char * opt_set_intval(char *arg,int *i)

{
  char *pcVar1;
  long l;
  int local_c;
  
  pcVar1 = opt_set_longval(arg,&local_c);
  if (pcVar1 == (char *)0x0) {
    *i = local_c;
  }
  return pcVar1;
}

