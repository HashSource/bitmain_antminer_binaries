
void getFileSysComplieTime(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  FILE *__stream;
  size_t sVar4;
  uint local_14;
  
  __stream = fopen("/usr/bin/compile_time","r");
  uVar2 = s_unkown_version_001321d8._8_4_;
  uVar1 = s_unkown_version_001321d8._4_4_;
  if (__stream == (FILE *)0x0) {
    *param_1 = s_unkown_version_001321d8._0_4_;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    cVar3 = s_unkown_version_001321d8[14];
    *(undefined2 *)(param_1 + 3) = s_unkown_version_001321d8._12_2_;
    *(char *)((int)param_1 + 0xe) = cVar3;
  }
  else {
    memset(param_1,0,0x100);
    fgets((char *)param_1,0x100,__stream);
    for (local_14 = 0; sVar4 = strlen((char *)param_1), local_14 < sVar4; local_14 = local_14 + 1) {
      if ((*(char *)(local_14 + (int)param_1) == '\r') ||
         (*(char *)(local_14 + (int)param_1) == '\n')) {
        *(undefined *)(local_14 + (int)param_1) = 0;
      }
    }
  }
  return;
}

