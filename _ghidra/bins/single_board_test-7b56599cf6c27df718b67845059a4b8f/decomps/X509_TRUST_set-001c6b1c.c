
int X509_TRUST_set(int *t,int trust)

{
  int iVar1;
  
  iVar1 = X509_TRUST_get_by_id(trust);
  if (iVar1 != -1) {
    *t = trust;
  }
  else {
    ERR_put_error(0xb,0x8d,0x7b,"crypto/x509/x509_trs.c",0x74);
  }
  return (uint)(iVar1 != -1);
}

