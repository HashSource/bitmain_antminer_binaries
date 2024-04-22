
int imap_perform_login_part_7(int param_1)

{
  code **ppcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = imap_atom(*(undefined4 *)(param_1 + 0x120),0);
  uVar3 = imap_atom(*(undefined4 *)(param_1 + 0x124),0);
  ppcVar1 = DAT_00050244;
  iVar4 = DAT_00050240;
  if (iVar2 != 0) {
    iVar4 = iVar2;
  }
  iVar4 = imap_sendf(param_1,DAT_00050248,iVar4);
  (**ppcVar1)(iVar2);
  (**ppcVar1)(uVar3);
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 6;
  }
  return iVar4;
}

