
char * set_int_32_to_63(undefined4 param_1,int *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)opt_set_intval();
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  pcVar1 = "Value out of range";
  if (*param_2 - 0x20U < 0x20) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

