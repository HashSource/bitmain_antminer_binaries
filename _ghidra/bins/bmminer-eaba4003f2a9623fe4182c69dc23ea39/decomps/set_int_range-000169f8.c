
char * set_int_range(char *arg,int *i,int min,int max)

{
  char *pcVar1;
  int max_local;
  int min_local;
  int *i_local;
  char *arg_local;
  char *err;
  
  pcVar1 = opt_set_intval(arg,i);
  if (pcVar1 == (char *)0x0) {
    if ((*i < min) || (max < *i)) {
      pcVar1 = "Value out of range";
    }
    else {
      pcVar1 = (char *)0x0;
    }
  }
  return pcVar1;
}

