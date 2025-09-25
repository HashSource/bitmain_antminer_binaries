
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  bool bVar1;
  X509 *a_00;
  X509_CERT_AUX *pXVar2;
  int len;
  uchar *local_24 [2];
  
  local_24[0] = *pp;
  bVar1 = true;
  if (a != (X509 **)0x0) {
    bVar1 = *a == (X509 *)0x0;
  }
  a_00 = d2i_X509(a,local_24,length);
  if (a_00 != (X509 *)0x0) {
    len = length - ((int)local_24[0] - (int)*pp);
    if ((len < 1) ||
       (pXVar2 = d2i_X509_CERT_AUX((X509_CERT_AUX **)&a_00[1].rfc3779_asid,local_24,len),
       pXVar2 != (X509_CERT_AUX *)0x0)) {
      *pp = local_24[0];
      return a_00;
    }
    if ((bVar1) && (X509_free(a_00), a != (X509 **)0x0)) {
      *a = (X509 *)0x0;
      return (X509 *)0x0;
    }
  }
  return (X509 *)0x0;
}

