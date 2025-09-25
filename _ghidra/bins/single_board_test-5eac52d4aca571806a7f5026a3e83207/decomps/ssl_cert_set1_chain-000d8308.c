
undefined4 ssl_cert_set1_chain(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    uVar3 = ssl_cert_set0_chain();
    return uVar3;
  }
  iVar1 = X509_chain_up_ref(param_3);
  if (iVar1 != 0) {
    iVar2 = ssl_cert_set0_chain(param_1,param_2,iVar1);
    if (iVar2 != 0) {
      return 1;
    }
    OPENSSL_sk_pop_free(iVar1,0x16a341);
    return 0;
  }
  return 0;
}

