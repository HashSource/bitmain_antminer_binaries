
void Curl_client_write(int *param_1,uint param_2,char *param_3,size_t param_4)

{
  char cVar1;
  char *__s1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = *param_1;
  if (param_4 == 0) {
    param_4 = strlen(param_3);
  }
  if (((((param_2 & 1) != 0) && ((*(uint *)(param_1[0x86] + 0x3c) & 0xc) != 0)) &&
      (*(char *)(param_1 + 0x106) == 'A')) && (param_3 != (char *)0x0 && param_4 != 0)) {
    if (*(char *)(iVar5 + 0x867e) != '\0') {
      if (*param_3 == '\n') {
        param_4 = param_4 - 1;
        memmove(param_3,param_3 + 1,param_4);
        uVar2 = *(uint *)(iVar5 + 0x8680);
        *(uint *)(iVar5 + 0x8680) = uVar2 + 1;
        *(uint *)(iVar5 + 0x8684) = *(int *)(iVar5 + 0x8684) + (uint)(0xfffffffe < uVar2);
      }
      *(undefined *)(iVar5 + 0x867e) = 0;
    }
    __s1 = (char *)memchr(param_3,0xd,param_4);
    if (__s1 != (char *)0x0) {
      pcVar4 = __s1;
      for (; __s1 < param_3 + (param_4 - 1); __s1 = __s1 + 1) {
        iVar3 = memcmp(__s1,DAT_0004316c,2);
        if (iVar3 == 0) {
          pcVar6 = __s1 + 1;
          __s1 = __s1 + 1;
          *pcVar4 = *pcVar6;
          uVar2 = *(uint *)(iVar5 + 0x8680);
          *(uint *)(iVar5 + 0x8680) = uVar2 + 1;
          *(uint *)(iVar5 + 0x8684) = *(int *)(iVar5 + 0x8684) + (uint)(0xfffffffe < uVar2);
        }
        else if (*__s1 == '\r') {
          *pcVar4 = '\n';
        }
        else {
          *pcVar4 = *__s1;
        }
        pcVar4 = pcVar4 + 1;
      }
      pcVar6 = param_3 + param_4;
      if (__s1 < pcVar6) {
        cVar1 = *__s1;
        if (cVar1 == '\r') {
          *pcVar4 = '\n';
        }
        else {
          *pcVar4 = cVar1;
        }
        pcVar4 = pcVar4 + 1;
        if (cVar1 == '\r') {
          *(undefined *)(iVar5 + 0x867e) = 1;
        }
      }
      param_4 = (int)pcVar4 - (int)param_3;
      if (pcVar4 < pcVar6) {
        *pcVar4 = '\0';
      }
    }
  }
  Curl_client_chop_write(param_1,param_2,param_3,param_4);
  return;
}

