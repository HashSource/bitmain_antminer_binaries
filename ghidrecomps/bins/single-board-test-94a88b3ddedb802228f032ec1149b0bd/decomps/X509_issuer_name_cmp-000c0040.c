
int X509_issuer_name_cmp(X509 *a,X509 *b)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  X509_NAME *a_00;
  X509_NAME *a_01;
  
  a_00 = a->cert_info->issuer;
  a_01 = b->cert_info->issuer;
  if (((a_00->canon_enc == (uchar *)0x0) || (a_00->modified != 0)) &&
     (iVar2 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar2 < 0)) {
    return -2;
  }
  if ((a_01->canon_enc == (uchar *)0x0) || (a_01->modified != 0)) {
    iVar2 = i2d_X509_NAME(a_01,(uchar **)0x0);
    if (iVar2 < 0) {
      return -2;
    }
    iVar2 = a_00->canon_enclen;
    iVar1 = iVar2 - a_01->canon_enclen;
  }
  else {
    iVar2 = a_00->canon_enclen;
    iVar1 = iVar2 - a_01->canon_enclen;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar2 = (*(code *)PTR_memcmp_00194160)(a_00->canon_enc,a_01->canon_enc,iVar2,in_r3);
  return iVar2;
}

