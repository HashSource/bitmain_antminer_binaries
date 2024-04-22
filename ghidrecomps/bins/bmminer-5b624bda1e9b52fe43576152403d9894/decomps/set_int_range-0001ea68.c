
/* WARNING: Unknown calling convention */

char * set_int_range(char *arg,int *i,int min,int max)

{
  char *pcVar1;
  char *err;
  
  pcVar1 = opt_set_intval(arg,i);
  if ((pcVar1 == (char *)0x0) && ((*i < min || (max < *i)))) {
    return DAT_0001ea88;
  }
  return pcVar1;
}

