
int X509_PURPOSE_set(int *p,int purpose)

{
  int iVar1;
  
  iVar1 = X509_PURPOSE_get_by_id(purpose);
  if (iVar1 != -1) {
    *p = purpose;
  }
  else {
    ERR_put_error(0x22,0x8d,0x92,"crypto/x509v3/v3_purp.c",0x65);
  }
  return (uint)(iVar1 != -1);
}

