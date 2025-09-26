
int X509_issuer_name_cmp(X509 *a,X509 *b)

{
  int iVar1;
  size_t __n;
  X509_NAME *a_00;
  X509_NAME *a_01;
  
  a_00 = a->cert_info->issuer;
  a_01 = b->cert_info->issuer;
  if (((a_00->canon_enc == (uchar *)0x0) || (a_00->modified != 0)) &&
     (iVar1 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar1 < 0)) {
    return -2;
  }
  if ((a_01->canon_enc == (uchar *)0x0) || (a_01->modified != 0)) {
    iVar1 = i2d_X509_NAME(a_01,(uchar **)0x0);
    if (iVar1 < 0) {
      return -2;
    }
    __n = a_00->canon_enclen;
    iVar1 = __n - a_01->canon_enclen;
  }
  else {
    __n = a_00->canon_enclen;
    iVar1 = __n - a_01->canon_enclen;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = memcmp(a_00->canon_enc,a_01->canon_enc,__n);
  return iVar1;
}

