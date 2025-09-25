
int ssl_security_cert_chain(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_3 == 0) {
    param_3 = OPENSSL_sk_value(param_2,0);
    iVar3 = 1;
    if (param_3 == 0) {
      return 0x44;
    }
  }
  iVar1 = ssl_security_cert(param_1,0,param_3,param_4,1);
  while( true ) {
    if (iVar1 != 1) {
      return iVar1;
    }
    iVar1 = OPENSSL_sk_num(param_2);
    if (iVar1 <= iVar3) break;
    uVar2 = OPENSSL_sk_value(param_2,iVar3);
    iVar1 = ssl_security_cert(param_1,0,uVar2,param_4,0);
    iVar3 = iVar3 + 1;
  }
  return 1;
}

