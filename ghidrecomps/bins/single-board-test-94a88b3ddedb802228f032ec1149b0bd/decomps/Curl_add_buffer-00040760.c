
undefined4 Curl_add_buffer(int *param_1,void *param_2,uint param_3)

{
  code **ppcVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  ppcVar1 = DAT_0004080c;
  uVar2 = param_1[2];
  if (~param_3 < uVar2) {
    (**DAT_0004080c)(*param_1);
    pcVar3 = *ppcVar1;
    *param_1 = 0;
    (*pcVar3)(param_1);
    return 0x1b;
  }
  iVar4 = *param_1;
  if ((iVar4 == 0) || (param_1[1] - 1U < param_3 + uVar2)) {
    if (((int)param_3 < 0) || (((int)uVar2 < 0 || (~(param_3 << 1) < uVar2 << 1)))) {
      iVar5 = -1;
    }
    else {
      iVar5 = (param_3 + uVar2) * 2;
    }
    if (iVar4 == 0) {
      iVar4 = (**DAT_00040810)(iVar5);
    }
    else {
      iVar4 = (**DAT_00040808)(iVar4,iVar5);
    }
    ppcVar1 = DAT_0004080c;
    if (iVar4 == 0) {
      (**DAT_0004080c)(*param_1);
      pcVar3 = *ppcVar1;
      *param_1 = 0;
      (*pcVar3)(param_1);
      return 0x1b;
    }
    uVar2 = param_1[2];
    *param_1 = iVar4;
    param_1[1] = iVar5;
  }
  memcpy((void *)(iVar4 + uVar2),param_2,param_3);
  param_1[2] = param_1[2] + param_3;
  return 0;
}

