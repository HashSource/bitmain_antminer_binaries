
void Curl_failf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  __s = (char *)(param_1 + 0x59c);
  uStack_8 = param_3;
  uStack_4 = param_4;
  curl_mvsnprintf(__s,0x4000,param_2,&uStack_8);
  if ((*(int *)(param_1 + 0x158) != 0) && (*(char *)(param_1 + 0x85c8) == '\0')) {
    curl_msnprintf(*(int *)(param_1 + 0x158),0x100,DAT_00042eb8,__s);
    *(undefined *)(param_1 + 0x85c8) = 1;
  }
  if (*(char *)(param_1 + 0x310) != '\0') {
    sVar1 = strlen(__s);
    sVar2 = sVar1;
    if (sVar1 < 0x3fff) {
      sVar2 = sVar1 + 1;
      *(undefined *)(param_1 + sVar1 + 0x59c) = 10;
      *(undefined *)(param_1 + sVar2 + 0x59c) = 0;
    }
    Curl_debug(param_1,0,__s,sVar2,0);
  }
  return;
}

