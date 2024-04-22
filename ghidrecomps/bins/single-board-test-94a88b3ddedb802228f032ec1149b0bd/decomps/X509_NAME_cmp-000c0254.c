
int X509_NAME_cmp(X509_NAME *a,X509_NAME *b)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  
  if (((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) &&
     (iVar2 = i2d_X509_NAME(a,(uchar **)0x0), iVar2 < 0)) {
    return -2;
  }
  if ((b->canon_enc == (uchar *)0x0) || (b->modified != 0)) {
    iVar2 = i2d_X509_NAME(b,(uchar **)0x0);
    if (iVar2 < 0) {
      return -2;
    }
    iVar2 = a->canon_enclen;
    iVar1 = iVar2 - b->canon_enclen;
  }
  else {
    iVar2 = a->canon_enclen;
    iVar1 = iVar2 - b->canon_enclen;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar2 = (*(code *)PTR_memcmp_00194160)(a->canon_enc,b->canon_enc,iVar2,in_r3);
  return iVar2;
}

