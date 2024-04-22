
char * set_int_22_to_55(undefined4 param_1,int *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)opt_set_intval();
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  pcVar1 = "Value out of range";
  if (*param_2 - 0x16U < 0x22) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

