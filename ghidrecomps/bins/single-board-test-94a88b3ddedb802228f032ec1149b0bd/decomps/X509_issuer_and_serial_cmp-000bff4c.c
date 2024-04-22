
int X509_issuer_and_serial_cmp(X509 *a,X509 *b)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  X509_CINF *pXVar3;
  X509_NAME *a_00;
  X509_CINF *pXVar4;
  X509_NAME *a_01;
  
  pXVar4 = a->cert_info;
  pXVar3 = b->cert_info;
  iVar1 = ASN1_STRING_cmp(pXVar4->serialNumber,pXVar3->serialNumber);
  if (iVar1 != 0) {
    return iVar1;
  }
  a_01 = pXVar4->issuer;
  a_00 = pXVar3->issuer;
  if (((a_01->canon_enc == (uchar *)0x0) || (a_01->modified != 0)) &&
     (iVar1 = i2d_X509_NAME(a_01,(uchar **)0x0), iVar1 < 0)) {
    return -2;
  }
  if ((a_00->canon_enc == (uchar *)0x0) || (a_00->modified != 0)) {
    iVar1 = i2d_X509_NAME(a_00,(uchar **)0x0);
    if (iVar1 < 0) {
      return -2;
    }
    iVar1 = a_01->canon_enclen;
    iVar2 = iVar1 - a_00->canon_enclen;
  }
  else {
    iVar1 = a_01->canon_enclen;
    iVar2 = iVar1 - a_00->canon_enclen;
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar1 = (*(code *)PTR_memcmp_00194160)(a_01->canon_enc,a_00->canon_enc,iVar1,in_r3);
  return iVar1;
}

