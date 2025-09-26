
uint rsa_sig_print(BIO *param_1,undefined4 *param_2,ASN1_STRING *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  RSA_PSS_PARAMS *a;
  int *piVar3;
  ASN1_STRING *pAVar4;
  bool bVar5;
  X509_ALGOR *pXVar6;
  uchar *local_28;
  uchar *local_24 [2];
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_2);
  if (iVar1 != 0x390) {
    if (param_3 == (ASN1_STRING *)0x0) {
      iVar1 = BIO_puts(param_1,"\n");
      return (uint)(0 < iVar1);
    }
    goto LAB_00197ebe;
  }
  piVar3 = (int *)param_2[1];
  if ((piVar3 == (int *)0x0) || (*piVar3 != 0x10)) {
LAB_00197f6a:
    iVar1 = BIO_puts(param_1," (INVALID PSS PARAMETERS)\n");
    bVar5 = 0 < iVar1;
  }
  else {
    local_28 = (uchar *)((long *)piVar3[1])[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,&local_28,*(long *)piVar3[1]);
    if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_00197f6a;
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
    iVar1 = BIO_puts(param_1,"\n");
    if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
       (iVar1 = BIO_puts(param_1,"Hash Algorithm: "), iVar1 < 1)) {
LAB_00197f46:
      bVar5 = false;
    }
    else {
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"sha1 (default)");
        if (0 < iVar1) goto LAB_00197fba;
        goto LAB_00197f46;
      }
      iVar1 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar1 < 1) goto LAB_00197f46;
LAB_00197fba:
      iVar1 = BIO_puts(param_1,"\n");
      if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
         (iVar1 = BIO_puts(param_1,"Mask Algorithm: "), iVar1 < 1)) goto LAB_00197f46;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"mgf1 with sha1 (default)");
      }
      else {
        iVar1 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar1 < 1) || (iVar1 = BIO_puts(param_1," with "), iVar1 < 1)) goto LAB_00197f46;
        if (pXVar6 == (X509_ALGOR *)0x0) {
          iVar1 = BIO_puts(param_1,"INVALID");
        }
        else {
          iVar1 = i2a_ASN1_OBJECT(param_1,pXVar6->algorithm);
        }
      }
      if (iVar1 < 1) goto LAB_00197f46;
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Salt Length: 0x"), iVar1 < 1))
      goto LAB_00197f46;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"14 (default)");
        if (0 < iVar1) goto LAB_00198044;
        goto LAB_00197f46;
      }
      iVar1 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar1 < 1) goto LAB_00197f46;
LAB_00198044:
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Trailer Field: 0x"), iVar1 < 1))
      goto LAB_00197f46;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"BC (default)");
      }
      else {
        iVar1 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar1 < 1) goto LAB_00197f46;
      BIO_puts(param_1,"\n");
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
LAB_00197ebe:
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

