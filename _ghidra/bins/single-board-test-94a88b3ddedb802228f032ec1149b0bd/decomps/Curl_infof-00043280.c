
void Curl_infof(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  char acStack_81c [2052];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 0x310) != '\0')) {
    uStack_8 = param_3;
    uStack_4 = param_4;
    curl_mvsnprintf(acStack_81c,0x801,param_2,&uStack_8);
    sVar1 = strlen(acStack_81c);
    Curl_debug(param_1,0,acStack_81c,sVar1,0);
  }
  return;
}

