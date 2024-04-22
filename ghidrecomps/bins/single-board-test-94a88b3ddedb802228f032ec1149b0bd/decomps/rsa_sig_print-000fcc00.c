
uint rsa_sig_print(BIO *param_1,ASN1_OBJECT **param_2,ASN1_STRING *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  RSA_PSS_PARAMS *a;
  ASN1_OBJECT *pAVar3;
  ASN1_STRING *pAVar4;
  bool bVar5;
  X509_ALGOR *pXVar6;
  uchar *local_28;
  uchar *local_24 [2];
  
  iVar1 = OBJ_obj2nid(*param_2);
  if (iVar1 != 0x390) {
    if (param_3 == (ASN1_STRING *)0x0) {
      iVar1 = BIO_puts(param_1,DAT_000fce28);
      return (uint)(0 < iVar1);
    }
    goto LAB_000fcc1e;
  }
  pAVar3 = param_2[1];
  if ((pAVar3 == (ASN1_OBJECT *)0x0) || (pAVar3->sn != (char *)0x10)) {
LAB_000fccca:
    iVar1 = BIO_puts(param_1,DAT_000fce2c);
    bVar5 = 0 < iVar1;
  }
  else {
    local_28 = (uchar *)pAVar3->ln[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,&local_28,(long)*pAVar3->ln);
    if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_000fccca;
    pXVar6 = a->maskGenAlgorithm;
    if (((pXVar6 == (X509_ALGOR *)0x0) || (iVar1 = OBJ_obj2nid(pXVar6->algorithm), iVar1 != 0x38f))
       || (pXVar6->parameter->type != 0x10)) {
      pXVar6 = (X509_ALGOR *)0x0;
    }
    else {
      pAVar4 = (pXVar6->parameter->value).asn1_string;
      local_24[0] = pAVar4->data;
      pXVar6 = d2i_X509_ALGOR((X509_ALGOR **)0x0,local_24,pAVar4->length);
    }
    iVar1 = BIO_puts(param_1,DAT_000fce28);
    if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
       (iVar1 = BIO_puts(param_1,DAT_000fce30), iVar1 < 1)) {
LAB_000fcca6:
      bVar5 = false;
    }
    else {
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,DAT_000fce44);
        if (0 < iVar1) goto LAB_000fcd1a;
        goto LAB_000fcca6;
      }
      iVar1 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar1 < 1) goto LAB_000fcca6;
LAB_000fcd1a:
      iVar1 = BIO_puts(param_1,DAT_000fce28);
      if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
         (iVar1 = BIO_puts(param_1,DAT_000fce34), iVar1 < 1)) goto LAB_000fcca6;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,DAT_000fce48);
      }
      else {
        iVar1 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar1 < 1) || (iVar1 = BIO_puts(param_1,DAT_000fce38), iVar1 < 1)) goto LAB_000fcca6;
        if (pXVar6 == (X509_ALGOR *)0x0) {
          iVar1 = BIO_puts(param_1,DAT_000fce4c);
        }
        else {
          iVar1 = i2a_ASN1_OBJECT(param_1,pXVar6->algorithm);
        }
      }
      if (iVar1 < 1) goto LAB_000fcca6;
      BIO_puts(param_1,DAT_000fce28);
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,DAT_000fce3c), iVar1 < 1)) goto LAB_000fcca6;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,DAT_000fce54);
        if (0 < iVar1) goto LAB_000fcda4;
        goto LAB_000fcca6;
      }
      iVar1 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar1 < 1) goto LAB_000fcca6;
LAB_000fcda4:
      BIO_puts(param_1,DAT_000fce28);
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,DAT_000fce40), iVar1 < 1)) goto LAB_000fcca6;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,DAT_000fce50);
      }
      else {
        iVar1 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar1 < 1) goto LAB_000fcca6;
      BIO_puts(param_1,DAT_000fce28);
      bVar5 = true;
    }
    RSA_PSS_PARAMS_free(a);
    if (pXVar6 != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(pXVar6);
    }
  }
  if (!bVar5) {
    return 0;
  }
  if (param_3 == (ASN1_STRING *)0x0) {
    return 1;
  }
LAB_000fcc1e:
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

