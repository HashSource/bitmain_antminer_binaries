
char * set_int_range(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  char *pcVar1;
  
  pcVar1 = (char *)opt_set_intval();
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "Value out of range";
    if (param_3 <= *param_2 && *param_2 <= param_4) {
      pcVar1 = (char *)0x0;
    }
    return pcVar1;
  }
  return pcVar1;
}

