
undefined4 tftp_disconnect(int param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3c0);
  if (iVar2 != 0) {
    (*Curl_cfree)(*(undefined4 *)(iVar2 + 0x148));
    pcVar1 = Curl_cfree;
    *(undefined4 *)(iVar2 + 0x148) = 0;
    (*pcVar1)(*(undefined4 *)(iVar2 + 0x14c));
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    (*Curl_cfree)(iVar2);
  }
  return 0;
}

