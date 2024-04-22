
int by_file_ctrl(X509_LOOKUP *param_1,int param_2,char *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if (param_4 == 3) {
      pcVar1 = X509_get_default_cert_file_env();
      pcVar1 = getenv(pcVar1);
      if (pcVar1 == (char *)0x0) {
        pcVar1 = X509_get_default_cert_file();
      }
      iVar2 = X509_load_cert_crl_file_part_0(param_1,pcVar1);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      if (iVar2 == 0) {
        ERR_put_error(0xb,0x65,0x68,DAT_000c55c8,0x6f);
      }
    }
    else if (param_4 == 1) {
      iVar2 = X509_load_cert_crl_file_part_0();
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = X509_load_cert_file(param_1,param_3,param_4);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

