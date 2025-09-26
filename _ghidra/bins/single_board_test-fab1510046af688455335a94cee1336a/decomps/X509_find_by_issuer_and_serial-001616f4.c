
X509 * X509_find_by_issuer_and_serial(stack_st_X509 *sk,X509_NAME *name,ASN1_INTEGER *serial)

{
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  X509_CINF *pXVar4;
  X509_NAME *a;
  
  if (sk != (stack_st_X509 *)0x0) {
    for (iVar3 = 0; iVar1 = sk_num(&sk->stack), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      pXVar2 = (X509 *)sk_value(&sk->stack,iVar3);
      pXVar4 = pXVar2->cert_info;
      iVar1 = ASN1_STRING_cmp(pXVar4->serialNumber,serial);
      if (((iVar1 == 0) &&
          (((a = pXVar4->issuer, a->canon_enc != (uchar *)0x0 && (a->modified == 0)) ||
           (iVar1 = i2d_X509_NAME(a,(uchar **)0x0), -1 < iVar1)))) &&
         ((((name->canon_enc != (uchar *)0x0 && (name->modified == 0)) ||
           (iVar1 = i2d_X509_NAME(name,(uchar **)0x0), -1 < iVar1)) &&
          ((a->canon_enclen == name->canon_enclen &&
           (iVar1 = memcmp(a->canon_enc,name->canon_enc,a->canon_enclen), iVar1 == 0)))))) {
        return pXVar2;
      }
    }
  }
  return (X509 *)0x0;
}

