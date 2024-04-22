
int Curl_ssl_connect_nonblocking(int *param_1,int param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(uint *)(iVar1 + 0x280) < 7) {
    *(undefined *)(param_1 + param_2 * 6 + 0x5e) = 1;
    iVar1 = Curl_ossl_connect_nonblocking();
    if ((iVar1 == 0) && (*param_3 != '\0')) {
      Curl_pgrsTime(*param_1,5);
    }
    return iVar1;
  }
  Curl_failf(iVar1,DAT_0003c9a8,param_3,iVar1,param_4);
  return 0x23;
}

