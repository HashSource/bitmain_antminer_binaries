
undefined4 smb_disconnect(int *param_1)

{
  code **ppcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  ppcVar1 = DAT_000568fc;
  iVar4 = *(int *)(*param_1 + 0x14c);
  (**DAT_000568fc)(param_1[0xf2]);
  param_1[0xf2] = 0;
  (**ppcVar1)(param_1[0xf7]);
  param_1[0xf7] = 0;
  if (iVar4 != 0) {
    (**ppcVar1)(*(undefined4 *)(iVar4 + 4));
    iVar3 = *param_1;
    pcVar2 = *ppcVar1;
    *(undefined4 *)(iVar4 + 4) = 0;
    (*pcVar2)(*(undefined4 *)(iVar3 + 0x14c));
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  return 0;
}

