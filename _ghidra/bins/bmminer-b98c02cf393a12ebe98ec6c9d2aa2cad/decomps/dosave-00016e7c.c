
void dosave(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  FILE *__stream;
  char *pcVar1;
  char acStack_1018 [4096];
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    default_save_file(acStack_1018);
    param_3 = acStack_1018;
  }
  __stream = fopen(param_3,"w");
  if (__stream == (FILE *)0x0) {
    pcVar1 = (char *)escape_string(param_3,param_4);
    message(param_1,0x2b,0,pcVar1,param_4);
    if (param_3 != pcVar1) {
      free(pcVar1);
      return;
    }
  }
  else {
    write_config();
    fclose(__stream);
    pcVar1 = (char *)escape_string(param_3,param_4);
    message(param_1,0x2c,0,pcVar1,param_4);
    if (param_3 != pcVar1) {
      free(pcVar1);
    }
  }
  return;
}

