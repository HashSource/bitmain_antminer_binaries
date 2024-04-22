
undefined4 Curl_ssl_shutdown(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = Curl_ossl_shutdown();
  uVar2 = DAT_0003ccc0;
  uVar1 = DAT_0003ccbc;
  if (iVar3 != 0) {
    return 0x50;
  }
  iVar3 = param_1 + param_2 * 0x18;
  *(undefined *)(iVar3 + 0x178) = 0;
  *(undefined4 *)(iVar3 + 0x17c) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x5a) * 4) = uVar1;
  *(undefined4 *)(param_1 + (param_2 + 0x5c) * 4) = uVar2;
  return 0;
}

