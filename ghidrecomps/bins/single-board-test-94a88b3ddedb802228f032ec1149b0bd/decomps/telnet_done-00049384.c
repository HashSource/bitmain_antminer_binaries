
undefined4 telnet_done(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*param_1 + 0x14c);
  if (iVar1 != 0) {
    curl_slist_free_all(*(undefined4 *)(iVar1 + 0x1cac));
    iVar2 = *param_1;
    *(undefined4 *)(iVar1 + 0x1cac) = 0;
    (*Curl_cfree)(*(undefined4 *)(iVar2 + 0x14c));
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  return 0;
}

