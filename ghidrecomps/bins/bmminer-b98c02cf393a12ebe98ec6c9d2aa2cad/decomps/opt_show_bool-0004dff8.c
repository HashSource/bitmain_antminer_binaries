
void opt_show_bool(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = "true";
  if (*param_2 == '\0') {
    pcVar1 = "false";
  }
  (*(code *)PTR_strncpy_0007cfc4)(param_1,pcVar1,0x50);
  return;
}

