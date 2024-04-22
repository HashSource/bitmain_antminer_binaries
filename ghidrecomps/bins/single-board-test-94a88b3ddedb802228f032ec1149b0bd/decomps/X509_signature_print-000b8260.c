
int X509_signature_print(BIO *bp,X509_ALGOR *alg,ASN1_STRING *sig)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  int iVar5;
  uchar *puVar6;
  int local_20;
  int iStack_1c;
  
  iVar2 = BIO_puts(bp,DAT_000b8360);
  if ((0 < iVar2) && (iVar2 = i2a_ASN1_OBJECT(bp,alg->algorithm), 0 < iVar2)) {
    iVar2 = OBJ_obj2nid(alg->algorithm);
    if ((iVar2 != 0) &&
       (((iVar2 = OBJ_find_sigid_algs(iVar2,&iStack_1c,&local_20), iVar2 != 0 &&
         (pEVar4 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_20),
         pEVar4 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(code **)(pEVar4 + 0x50) != (code *)0x0)))) {
      iVar2 = (**(code **)(pEVar4 + 0x50))(bp,alg,sig,9,0);
      return iVar2;
    }
    if (sig == (ASN1_STRING *)0x0) {
      iVar2 = BIO_puts(bp,DAT_000b836c);
      return (uint)(0 < iVar2);
    }
    iVar2 = sig->length;
    puVar6 = sig->data;
    if (iVar2 < 1) {
LAB_000b834e:
      iVar2 = BIO_write(bp,DAT_000b836c,1);
      return (uint)(iVar2 == 1);
    }
    iVar5 = 0;
    do {
      if (iVar5 == (iVar5 / 0x12) * 0x12) {
        iVar3 = BIO_write(bp,DAT_000b836c,1);
        if (iVar3 < 1) {
          return 0;
        }
        iVar3 = BIO_indent(bp,9,9);
        if (iVar3 < 1) {
          return 0;
        }
      }
      pbVar1 = puVar6 + iVar5;
      iVar5 = iVar5 + 1;
      if (iVar2 == iVar5) {
        iVar2 = BIO_printf(bp,DAT_000b8364,(uint)*pbVar1,DAT_000b8370);
        if (iVar2 < 1) {
          return 0;
        }
        goto LAB_000b834e;
      }
      iVar3 = BIO_printf(bp,DAT_000b8364,(uint)*pbVar1,DAT_000b8368);
    } while (0 < iVar3);
  }
  return 0;
}

