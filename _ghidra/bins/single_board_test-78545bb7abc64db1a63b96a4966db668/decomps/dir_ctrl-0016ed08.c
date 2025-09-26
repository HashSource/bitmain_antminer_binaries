
int dir_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 == 2) {
    iVar3 = *(int *)(param_1 + 0xc);
    if (param_4 != 3) {
      iVar3 = add_cert_dir_isra_0(iVar3 + 4,param_3,param_4);
      return iVar3;
    }
    X509_get_default_cert_dir_env();
    iVar1 = ossl_safe_getenv();
    if (iVar1 == 0) {
      pcVar2 = X509_get_default_cert_dir();
      iVar3 = add_cert_dir_isra_0(iVar3 + 4,pcVar2,1);
    }
    else {
      iVar3 = add_cert_dir_isra_0(iVar3 + 4,iVar1,1);
    }
    if (iVar3 == 0) {
      ERR_put_error(0xb,0x66,0x67,"crypto/x509/by_dir.c",0x54);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

