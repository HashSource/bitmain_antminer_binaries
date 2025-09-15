
int imap_perform_list(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  if (*(int *)(iVar2 + 0x1c) == 0) {
    if (*(int *)(iVar2 + 4) == 0) {
      iVar2 = (*Curl_cstrdup)(&DAT_0013a6fc);
    }
    else {
      iVar2 = imap_atom(*(int *)(iVar2 + 4),1);
    }
    if (iVar2 == 0) {
      return 0x1b;
    }
    iVar1 = imap_sendf(param_1,"LIST \"%s\" *",iVar2);
    (*Curl_cfree)(iVar2);
  }
  else {
    puVar3 = *(undefined1 **)(iVar2 + 0x20);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_0013a6fc;
    }
    iVar1 = imap_sendf(param_1,"%s%s",*(int *)(iVar2 + 0x1c),puVar3);
  }
  if (iVar1 == 0) {
    param_1[0xfe] = 7;
  }
  return iVar1;
}

