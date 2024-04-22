
int Curl_socket(int *param_1,int param_2,int *param_3,int *param_4)

{
  void *__src;
  int iVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  uint __n;
  code *pcVar5;
  int iVar6;
  int local_a8 [36];
  
  iVar6 = *param_1;
  if (param_3 == (int *)0x0) {
    param_3 = local_a8;
  }
  iVar1 = param_1[0x23];
  iVar3 = *(int *)(param_2 + 4);
  param_3[1] = iVar1;
  uVar2 = *(uint *)(param_2 + 0x10);
  *param_3 = iVar3;
  if (iVar1 == 2) {
    sVar4 = 0x11;
  }
  else {
    sVar4 = *(size_t *)(param_2 + 0xc);
  }
  __src = *(void **)(param_2 + 0x18);
  if (uVar2 < 0x81) {
    param_3[3] = uVar2;
  }
  param_3[2] = sVar4;
  __n = uVar2;
  if (0x80 < uVar2) {
    __n = 0x80;
    sVar4 = __n;
  }
  if (0x80 < uVar2) {
    param_3[3] = sVar4;
  }
  memcpy(param_3 + 4,__src,__n);
  pcVar5 = *(code **)(iVar6 + 0x1d8);
  if (pcVar5 == (code *)0x0) {
    iVar6 = socket(*param_3,param_3[1],param_3[2]);
    *param_4 = iVar6;
  }
  else {
    iVar6 = (*pcVar5)(*(undefined4 *)(iVar6 + 0x1dc),0,param_3);
    *param_4 = iVar6;
  }
  if (iVar6 == -1) {
    iVar6 = 7;
  }
  else {
    iVar6 = param_1[0x22];
    if (iVar6 != 0) {
      if (*param_3 == 10) {
        param_3[10] = iVar6;
      }
      iVar6 = 0;
    }
  }
  return iVar6;
}

