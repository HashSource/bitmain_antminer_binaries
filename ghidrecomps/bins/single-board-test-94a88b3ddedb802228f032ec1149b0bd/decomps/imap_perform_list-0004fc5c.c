
int imap_perform_list(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  if (*(int *)(iVar2 + 0x1c) == 0) {
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = (**DAT_0004fcd0)(DAT_0004fcc0);
    }
    else {
      iVar2 = imap_atom(*(int *)(iVar2 + 4),1);
    }
    if (iVar2 == 0) {
      return 0x1b;
    }
    iVar1 = imap_sendf(param_1,DAT_0004fcc8,iVar2);
    (**DAT_0004fccc)(iVar2);
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x20);
    if (*(int *)(iVar2 + 0x20) == 0) {
      iVar1 = DAT_0004fcc0;
    }
    iVar1 = imap_sendf(param_1,DAT_0004fcc4,*(int *)(iVar2 + 0x1c),iVar1);
  }
  if (iVar1 == 0) {
    param_1[0xfe] = 7;
  }
  return iVar1;
}

