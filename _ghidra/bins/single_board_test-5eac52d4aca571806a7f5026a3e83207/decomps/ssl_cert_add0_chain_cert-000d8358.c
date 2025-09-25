
int ssl_cert_add0_chain_cert(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = **(int **)(param_2 + 0xc0);
  }
  else {
    iVar2 = **(int **)(param_1 + 0x404);
  }
  if (iVar2 == 0) {
    return 0;
  }
  iVar1 = ssl_security_cert();
  if (iVar1 != 1) {
    ERR_put_error(0x14,0x15a,iVar1,"ssl/ssl_cert.c",0x125);
    return 0;
  }
  iVar1 = *(int *)(iVar2 + 8);
  if (iVar1 == 0) {
    iVar1 = OPENSSL_sk_new_null();
    *(int *)(iVar2 + 8) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar2 = OPENSSL_sk_push(iVar1,param_3);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

