
int X509_signature_print(BIO *bp,X509_ALGOR *alg,ASN1_STRING *sig)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  uint uVar3;
  int local_20;
  int aiStack_1c [2];
  
  iVar1 = BIO_puts(bp,"    Signature Algorithm: ");
  if ((iVar1 < 1) || (iVar1 = i2a_ASN1_OBJECT(bp,alg->algorithm), iVar1 < 1)) {
    uVar3 = 0;
  }
  else {
    iVar1 = OBJ_obj2nid(alg->algorithm);
    if ((((iVar1 == 0) || (iVar1 = OBJ_find_sigid_algs(iVar1,aiStack_1c,&local_20), iVar1 == 0)) ||
        (pEVar2 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_20), pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar2 + 0x54) == (code *)0x0)) {
      if (sig != (ASN1_STRING *)0x0) {
        iVar1 = X509_signature_dump(bp,sig,9);
        return iVar1;
      }
      iVar1 = BIO_puts(bp,"\n");
      uVar3 = (uint)(0 < iVar1);
    }
    else {
      uVar3 = (**(code **)(pEVar2 + 0x54))(bp,alg,sig,9,0);
    }
  }
  return uVar3;
}

