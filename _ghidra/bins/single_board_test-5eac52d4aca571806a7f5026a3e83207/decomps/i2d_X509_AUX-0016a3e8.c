
int i2d_X509_AUX(X509 *a,uchar **pp)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  bool bVar4;
  uchar *local_24 [2];
  
  if (pp == (uchar **)0x0) {
    puVar3 = (uchar *)0x0;
  }
  else {
    puVar3 = *pp;
    if (puVar3 == (uchar *)0x0) {
      iVar1 = i2d_X509(a,(uchar **)0x0);
      if (iVar1 < 1 || a == (X509 *)0x0) {
        if (iVar1 < 1) {
          return iVar1;
        }
      }
      else {
        iVar2 = i2d_X509_CERT_AUX((X509_CERT_AUX *)a[1].rfc3779_asid,(uchar **)0x0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar1 = iVar2 + iVar1;
      }
      puVar3 = (uchar *)CRYPTO_malloc(iVar1,"crypto/x509/x_x509.c",0xd6);
      *pp = puVar3;
      local_24[0] = puVar3;
      if (puVar3 != (uchar *)0x0) {
        iVar1 = i2d_X509(a,local_24);
        if (0 < iVar1 && a != (X509 *)0x0) {
          iVar2 = i2d_X509_CERT_AUX((X509_CERT_AUX *)a[1].rfc3779_asid,local_24);
          local_24[0] = puVar3;
          if (-1 < iVar2) {
            return iVar1 + iVar2;
          }
        }
        else {
          iVar2 = iVar1;
          if (0 < iVar1) {
            return iVar1;
          }
        }
        CRYPTO_free(*pp);
        *pp = (uchar *)0x0;
        return iVar2;
      }
      ERR_put_error(0xb,0x97,0x41,"crypto/x509/x_x509.c",0xd8);
      return -1;
    }
  }
  iVar1 = i2d_X509(a,pp);
  bVar4 = (int)a < 0;
  if (a != (X509 *)0x0) {
    bVar4 = iVar1 < 0;
  }
  iVar2 = iVar1;
  if ((a != (X509 *)0x0 && iVar1 != 0) && !bVar4) {
    iVar2 = i2d_X509_CERT_AUX((X509_CERT_AUX *)a[1].rfc3779_asid,pp);
    if (-1 < iVar2) {
      return iVar1 + iVar2;
    }
    if (puVar3 != (uchar *)0x0) {
      *pp = puVar3;
    }
  }
  return iVar2;
}

