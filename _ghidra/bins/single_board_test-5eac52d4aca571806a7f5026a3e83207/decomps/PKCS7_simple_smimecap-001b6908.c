
int PKCS7_simple_smimecap(stack_st_X509_ALGOR *sk,int nid,int arg)

{
  X509_ALGOR *a;
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  ASN1_INTEGER *a_00;
  int iVar3;
  
  a = X509_ALGOR_new();
  if (a == (X509_ALGOR *)0x0) {
    ERR_put_error(0x21,0x77,0x41,"crypto/pkcs7/pk7_attr.c",0x38);
    return 0;
  }
  ASN1_OBJECT_free(a->algorithm);
  pAVar1 = OBJ_nid2obj(nid);
  a->algorithm = pAVar1;
  if (arg < 1) {
LAB_001b694c:
    iVar3 = OPENSSL_sk_push(sk,a);
    if (iVar3 != 0) {
      return 1;
    }
  }
  else {
    pAVar2 = ASN1_TYPE_new();
    a->parameter = pAVar2;
    if ((pAVar2 != (ASN1_TYPE *)0x0) && (a_00 = ASN1_INTEGER_new(), a_00 != (ASN1_INTEGER *)0x0)) {
      iVar3 = ASN1_INTEGER_set(a_00,arg);
      if (iVar3 == 0) goto LAB_001b6958;
      pAVar2 = a->parameter;
      pAVar2->type = 2;
      (pAVar2->value).integer = a_00;
      goto LAB_001b694c;
    }
  }
  a_00 = (ASN1_STRING *)0x0;
LAB_001b6958:
  ERR_put_error(0x21,0x77,0x41,"crypto/pkcs7/pk7_attr.c",0x50);
  ASN1_INTEGER_free(a_00);
  X509_ALGOR_free(a);
  return 0;
}

