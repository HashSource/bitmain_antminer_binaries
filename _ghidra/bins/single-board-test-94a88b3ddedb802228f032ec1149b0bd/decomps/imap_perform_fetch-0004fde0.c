
int imap_perform_fetch(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 == 0) {
    Curl_failf(*param_1,"Cannot FETCH without a UID.");
    iVar1 = 3;
  }
  else {
    puVar3 = *(undefined1 **)(iVar2 + 0x10);
    if (*(int *)(iVar2 + 0x14) == 0) {
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_0013a6fc;
      }
      iVar1 = imap_sendf(param_1,"FETCH %s BODY[%s]",iVar1,puVar3);
    }
    else {
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_0013a6fc;
      }
      iVar1 = imap_sendf(param_1,"FETCH %s BODY[%s]<%s>",iVar1,puVar3,*(int *)(iVar2 + 0x14));
    }
    if (iVar1 == 0) {
      param_1[0xfe] = 9;
    }
  }
  return iVar1;
}

