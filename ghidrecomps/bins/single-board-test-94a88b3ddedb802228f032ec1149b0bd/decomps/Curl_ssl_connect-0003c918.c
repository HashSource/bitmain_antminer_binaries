
int Curl_ssl_connect(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(uint *)(iVar1 + 0x280) < 7) {
    *(undefined *)(param_1 + param_2 * 6 + 0x5e) = 1;
    param_1[param_2 * 6 + 0x5f] = 1;
    iVar1 = Curl_ossl_connect();
    if (iVar1 == 0) {
      Curl_pgrsTime(*param_1,5);
    }
    return iVar1;
  }
  Curl_failf(iVar1,DAT_0003c95c,param_3,iVar1,param_4);
  return 0x23;
}

