
int by_file_ctrl(X509_LOOKUP *param_1,int param_2,char *param_3,int param_4)

{
  char *file;
  int iVar1;
  
  if (param_2 == 1) {
    if (param_4 == 3) {
      X509_get_default_cert_file_env();
      file = (char *)ossl_safe_getenv();
      if (file == (char *)0x0) {
        file = X509_get_default_cert_file();
      }
      iVar1 = X509_load_cert_crl_file(param_1,file,1);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      if (iVar1 == 0) {
        ERR_put_error(0xb,0x65,0x68,"crypto/x509/by_file.c",0x3c);
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    else {
      if (param_4 == 1) {
        iVar1 = X509_load_cert_crl_file(param_1,param_3,1);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        return iVar1;
      }
      iVar1 = X509_load_cert_file(param_1,param_3,param_4);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

