
int X509_load_cert_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  int iVar1;
  
  if (type != 1) {
    iVar1 = X509_load_cert_file(ctx,file,type);
    return iVar1;
  }
  iVar1 = X509_load_cert_crl_file_part_0();
  return iVar1;
}

