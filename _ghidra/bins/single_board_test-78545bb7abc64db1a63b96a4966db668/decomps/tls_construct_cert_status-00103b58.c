
int tls_construct_cert_status(void)

{
  int iVar1;
  
  iVar1 = tls_construct_cert_status_body();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

