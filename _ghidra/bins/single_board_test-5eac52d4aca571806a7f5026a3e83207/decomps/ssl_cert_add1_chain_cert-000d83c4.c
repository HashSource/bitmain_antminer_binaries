
int ssl_cert_add1_chain_cert(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = ssl_cert_add0_chain_cert();
  if (iVar1 != 0) {
    X509_up_ref(param_3);
    iVar1 = 1;
  }
  return iVar1;
}

