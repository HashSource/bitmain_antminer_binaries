
int X509_NAME_cmp(X509_NAME *a,X509_NAME *b)

{
  int iVar1;
  size_t __n;
  
  if (((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) &&
     (iVar1 = i2d_X509_NAME(a,(uchar **)0x0), iVar1 < 0)) {
    return -2;
  }
  if ((b->canon_enc == (uchar *)0x0) || (b->modified != 0)) {
    iVar1 = i2d_X509_NAME(b,(uchar **)0x0);
    if (iVar1 < 0) {
      return -2;
    }
    __n = a->canon_enclen;
    iVar1 = __n - b->canon_enclen;
  }
  else {
    __n = a->canon_enclen;
    iVar1 = __n - b->canon_enclen;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = memcmp(a->canon_enc,b->canon_enc,__n);
  return iVar1;
}

