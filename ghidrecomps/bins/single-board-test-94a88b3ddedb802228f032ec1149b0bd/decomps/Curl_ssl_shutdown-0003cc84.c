
undefined4 Curl_ssl_shutdown(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = Curl_ossl_shutdown();
  if (iVar1 != 0) {
    return 0x50;
  }
  iVar1 = param_1 + param_2 * 0x18;
  *(undefined1 *)(iVar1 + 0x178) = 0;
  *(undefined4 *)(iVar1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x5a) * 4) = 0x43171;
  *(undefined4 *)(param_1 + (param_2 + 0x5c) * 4) = 0x431e1;
  return 0;
}

