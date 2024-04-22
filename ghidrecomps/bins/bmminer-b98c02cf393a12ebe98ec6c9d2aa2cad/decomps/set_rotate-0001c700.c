
char * set_rotate(undefined4 param_1)

{
  char *pcVar1;
  
  pool_strategy = 2;
  pcVar1 = (char *)opt_set_intval(param_1,&opt_rotate_period);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  pcVar1 = "Value out of range";
  if (opt_rotate_period < 10000) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

