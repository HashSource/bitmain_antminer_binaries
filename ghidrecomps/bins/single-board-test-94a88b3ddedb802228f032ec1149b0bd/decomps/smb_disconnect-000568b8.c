
undefined4 smb_disconnect(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*param_1 + 0x14c);
  (*Curl_cfree)(param_1[0xf2]);
  param_1[0xf2] = 0;
  (*Curl_cfree)(param_1[0xf7]);
  param_1[0xf7] = 0;
  if (iVar3 != 0) {
    (*Curl_cfree)(*(undefined4 *)(iVar3 + 4));
    pcVar1 = Curl_cfree;
    iVar2 = *param_1;
    *(undefined4 *)(iVar3 + 4) = 0;
    (*pcVar1)(*(undefined4 *)(iVar2 + 0x14c));
    *(undefined4 *)(*param_1 + 0x14c) = 0;
  }
  return 0;
}

