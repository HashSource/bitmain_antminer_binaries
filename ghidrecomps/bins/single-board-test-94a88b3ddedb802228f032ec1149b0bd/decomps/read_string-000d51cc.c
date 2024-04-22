
int read_string(undefined4 param_1,UI_STRING *param_2)

{
  UI_string_types UVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *__s2;
  FILE *__stream;
  
  UVar1 = UI_get_string_type(param_2);
  iVar4 = DAT_000d52b8;
  if (UVar1 == UIT_VERIFY) {
    __stream = *(FILE **)(DAT_000d52b8 + 8);
    pcVar2 = UI_get0_output_string(param_2);
    fprintf(__stream,DAT_000d52bc,pcVar2);
    fflush(*(FILE **)(iVar4 + 8));
    uVar3 = UI_get_input_flags(param_2);
    iVar5 = read_string_inner(param_1,param_2,uVar3 & 1,1);
    if (iVar5 < 1) {
      return iVar5;
    }
    pcVar2 = UI_get0_result_string(param_2);
    __s2 = UI_get0_test_string(param_2);
    iVar5 = strcmp(pcVar2,__s2);
    if (iVar5 != 0) {
      fwrite(DAT_000d52c0,1,0xf,*(FILE **)(iVar4 + 8));
      fflush(*(FILE **)(iVar4 + 8));
      return 0;
    }
  }
  else {
    if (UVar1 == UIT_BOOLEAN) {
      pcVar2 = UI_get0_output_string(param_2);
      fputs(pcVar2,*(FILE **)(iVar4 + 8));
      pcVar2 = UI_get0_action_string(param_2);
      fputs(pcVar2,*(FILE **)(iVar4 + 8));
      fflush(*(FILE **)(iVar4 + 8));
      uVar3 = UI_get_input_flags(param_2);
      iVar4 = read_string_inner(param_1,param_2,uVar3 & 1,0);
      return iVar4;
    }
    if (UVar1 == UIT_PROMPT) {
      pcVar2 = UI_get0_output_string(param_2);
      fputs(pcVar2,*(FILE **)(iVar4 + 8));
      fflush(*(FILE **)(iVar4 + 8));
      uVar3 = UI_get_input_flags(param_2);
      iVar4 = read_string_inner(param_1,param_2,uVar3 & 1,1);
      return iVar4;
    }
  }
  return 1;
}

