
undefined4 Curl_add_buffer(int *param_1,void *param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = param_1[2];
  if (~param_3 < uVar2) {
    (*Curl_cfree)(*param_1);
    pcVar1 = Curl_cfree;
    *param_1 = 0;
    (*pcVar1)(param_1);
    return 0x1b;
  }
  iVar3 = *param_1;
  if ((iVar3 == 0) || (param_1[1] - 1U < param_3 + uVar2)) {
    if (((int)param_3 < 0) || (((int)uVar2 < 0 || (~(param_3 << 1) < uVar2 << 1)))) {
      iVar4 = -1;
    }
    else {
      iVar4 = (param_3 + uVar2) * 2;
    }
    if (iVar3 == 0) {
      iVar3 = (*Curl_cmalloc)(iVar4);
    }
    else {
      iVar3 = (*Curl_crealloc)(iVar3,iVar4);
    }
    if (iVar3 == 0) {
      (*Curl_cfree)(*param_1);
      pcVar1 = Curl_cfree;
      *param_1 = 0;
      (*pcVar1)(param_1);
      return 0x1b;
    }
    uVar2 = param_1[2];
    *param_1 = iVar3;
    param_1[1] = iVar4;
  }
  memcpy((void *)(iVar3 + uVar2),param_2,param_3);
  param_1[2] = param_1[2] + param_3;
  return 0;
}

