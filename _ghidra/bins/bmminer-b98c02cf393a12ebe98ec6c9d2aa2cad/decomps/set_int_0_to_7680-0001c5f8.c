
char * set_int_0_to_7680(undefined4 param_1,uint *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)opt_set_intval();
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  pcVar1 = "Value out of range";
  if (*param_2 < 0x1e01) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

