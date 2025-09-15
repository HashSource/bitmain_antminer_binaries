
/* WARNING: Unknown calling convention */

char * set_int_range(char *arg,int *i,int min,int max)

{
  char *pcVar1;
  
  pcVar1 = opt_set_intval(arg,i);
  if ((pcVar1 == (char *)0x0) && ((*i < min || (max < *i)))) {
    return "Value out of range";
  }
  return pcVar1;
}

