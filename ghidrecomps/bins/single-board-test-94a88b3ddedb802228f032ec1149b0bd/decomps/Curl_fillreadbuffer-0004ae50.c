
undefined4 Curl_fillreadbuffer(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  size_t __n;
  void *__dest;
  size_t __n_00;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  char *__s;
  undefined auStack_2c [16];
  
  iVar4 = *param_1;
  iVar1 = *(int *)(iVar4 + 0x144);
  if (*(char *)(iVar4 + 0x149) != '\0') {
    param_2 = param_2 - 0xc;
    iVar1 = iVar1 + 10;
    *(int *)(iVar4 + 0x144) = iVar1;
  }
  uVar2 = (**(code **)(iVar4 + 0x86c0))(iVar1,1,param_2,*(undefined4 *)(iVar4 + 0x86c4));
  if (uVar2 == 0x10000000) {
    Curl_failf(iVar4,DAT_0004af78);
    uVar3 = 0x2a;
    *param_3 = 0;
  }
  else if (uVar2 == 0x10000001) {
    if (*(int *)(param_1[0x86] + 0x40) << 0x1b < 0) {
      Curl_failf(iVar4,DAT_0004af7c);
      uVar3 = 0x1a;
    }
    else {
      *(uint *)(iVar4 + 0x130) = *(uint *)(iVar4 + 0x130) | 0x20;
      if (*(char *)(iVar4 + 0x149) != '\0') {
        *(int *)(iVar4 + 0x144) = *(int *)(iVar4 + 0x144) + -10;
      }
      uVar3 = 0;
      *param_3 = 0;
    }
  }
  else if (param_2 < uVar2) {
    *param_3 = 0;
    Curl_failf(iVar4,DAT_0004af74);
    uVar3 = 0x1a;
  }
  else {
    if ((*(char *)(iVar4 + 0x14b) == '\0') && (*(char *)(iVar4 + 0x149) != '\0')) {
      __s = DAT_0004af6c;
      if ((*(char *)(iVar4 + 0x2fb) == '\0') && (*(char *)(iVar4 + 0x24e) == '\0')) {
        __s = DAT_0004af80;
      }
      __n = curl_msnprintf(auStack_2c,0xb,DAT_0004af70,uVar2,__s);
      sVar5 = uVar2 + __n;
      __dest = (void *)(*(int *)(iVar4 + 0x144) - __n);
      *(void **)(iVar4 + 0x144) = __dest;
      memcpy(__dest,auStack_2c,__n);
      __n_00 = strlen(__s);
      memcpy((void *)(*(int *)(iVar4 + 0x144) + sVar5),__s,__n_00);
      uVar2 = sVar5 + __n_00;
      if (sVar5 == __n) {
        *(undefined *)(iVar4 + 0x134) = 1;
      }
    }
    uVar3 = 0;
    *param_3 = uVar2;
  }
  return uVar3;
}

