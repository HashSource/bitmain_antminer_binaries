
undefined4 telnet_done(int *param_1)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  if (iVar2 != 0) {
    curl_slist_free_all(*(undefined4 *)(iVar2 + 0x1cac));
    ppcVar1 = DAT_000493b4;
    iVar3 = *param_1;
    *(undefined4 *)(iVar2 + 0x1cac) = 0;
    (**ppcVar1)(*(undefined4 *)(iVar3 + 0x14c));
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  return 0;
}

