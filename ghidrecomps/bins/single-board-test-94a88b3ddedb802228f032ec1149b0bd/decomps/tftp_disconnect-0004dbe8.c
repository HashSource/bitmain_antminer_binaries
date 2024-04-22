
undefined4 tftp_disconnect(int param_1)

{
  code **ppcVar1;
  code *pcVar2;
  int iVar3;
  
  ppcVar1 = DAT_0004dc18;
  iVar3 = *(int *)(param_1 + 0x3c0);
  if (iVar3 != 0) {
    (**DAT_0004dc18)(*(undefined4 *)(iVar3 + 0x148));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(iVar3 + 0x148) = 0;
    (*pcVar2)(*(undefined4 *)(iVar3 + 0x14c));
    *(undefined4 *)(iVar3 + 0x14c) = 0;
    (**ppcVar1)(iVar3);
  }
  return 0;
}

