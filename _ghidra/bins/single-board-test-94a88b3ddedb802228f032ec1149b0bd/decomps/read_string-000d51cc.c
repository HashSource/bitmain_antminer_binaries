
int read_string(undefined4 param_1,UI_STRING *param_2)

{
  FILE *__stream;
  UI_string_types UVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *__s2;
  
  UVar1 = UI_get_string_type(param_2);
  __stream = tty_out;
  if (UVar1 == UIT_VERIFY) {
    pcVar2 = UI_get0_output_string(param_2);
    fprintf(__stream,"Verifying - %s",pcVar2);
    fflush(tty_out);
    uVar3 = UI_get_input_flags(param_2);
    iVar4 = read_string_inner(param_1,param_2,uVar3 & 1,1);
    if (iVar4 < 1) {
      return iVar4;
    }
    pcVar2 = UI_get0_result_string(param_2);
    __s2 = UI_get0_test_string(param_2);
    iVar4 = strcmp(pcVar2,__s2);
    if (iVar4 != 0) {
      fwrite("Verify failure\n",1,0xf,tty_out);
      fflush(tty_out);
      return 0;
    }
  }
  else {
    if (UVar1 == UIT_BOOLEAN) {
      pcVar2 = UI_get0_output_string(param_2);
      fputs(pcVar2,tty_out);
      pcVar2 = UI_get0_action_string(param_2);
      fputs(pcVar2,tty_out);
      fflush(tty_out);
      uVar3 = UI_get_input_flags(param_2);
      iVar4 = read_string_inner(param_1,param_2,uVar3 & 1,0);
      return iVar4;
    }
    if (UVar1 == UIT_PROMPT) {
      pcVar2 = UI_get0_output_string(param_2);
      fputs(pcVar2,tty_out);
      fflush(tty_out);
      uVar3 = UI_get_input_flags(param_2);
      iVar4 = read_string_inner(param_1,param_2,uVar3 & 1,1);
      return iVar4;
    }
  }
  return 1;
}

