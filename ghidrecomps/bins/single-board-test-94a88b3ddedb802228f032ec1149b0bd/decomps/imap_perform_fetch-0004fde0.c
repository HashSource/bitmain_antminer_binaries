
int imap_perform_fetch(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 == 0) {
    Curl_failf(*param_1,DAT_0004fe3c);
    iVar1 = 3;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x10);
    if (*(int *)(iVar2 + 0x14) == 0) {
      if (iVar3 == 0) {
        iVar3 = DAT_0004fe30;
      }
      iVar1 = imap_sendf(param_1,DAT_0004fe38,iVar1,iVar3);
    }
    else {
      if (iVar3 == 0) {
        iVar3 = DAT_0004fe30;
      }
      iVar1 = imap_sendf(param_1,DAT_0004fe34,iVar1,iVar3,*(int *)(iVar2 + 0x14));
    }
    if (iVar1 == 0) {
      param_1[0xfe] = 9;
    }
  }
  return iVar1;
}

