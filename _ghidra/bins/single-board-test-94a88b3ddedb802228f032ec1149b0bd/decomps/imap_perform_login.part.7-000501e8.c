
int imap_perform_login_part_7(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  puVar1 = (undefined1 *)imap_atom(*(undefined4 *)(param_1 + 0x120),0);
  puVar2 = (undefined1 *)imap_atom(*(undefined4 *)(param_1 + 0x124),0);
  puVar5 = puVar2;
  if (puVar2 == (undefined1 *)0x0) {
    puVar5 = &DAT_0013a6fc;
  }
  puVar4 = &DAT_0013a6fc;
  if (puVar1 != (undefined1 *)0x0) {
    puVar4 = puVar1;
  }
  iVar3 = imap_sendf(param_1,"LOGIN %s %s",puVar4,puVar5);
  (*Curl_cfree)(puVar1);
  (*Curl_cfree)(puVar2);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 6;
  }
  return iVar3;
}

