
PKCS7 * PKCS12_pack_p7data(stack_st_PKCS12_SAFEBAG *sk)

{
  PKCS7 *a;
  ASN1_OBJECT *pAVar1;
  ASN1_OCTET_STRING *pAVar2;
  ASN1_STRING *pAVar3;
  
  a = PKCS7_new();
  if (a == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x72,0x41,"crypto/pkcs12/p12_add.c",0x33);
  }
  else {
    pAVar1 = OBJ_nid2obj(0x15);
    a->type = pAVar1;
    pAVar2 = ASN1_OCTET_STRING_new();
    (a->d).data = pAVar2;
    if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
      ERR_put_error(0x23,0x72,0x41,"crypto/pkcs12/p12_add.c",0x38);
    }
    else {
      pAVar3 = ASN1_item_pack(sk,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,&(a->d).data);
      if (pAVar3 != (ASN1_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x72,100,"crypto/pkcs12/p12_add.c",0x3d);
    }
    PKCS7_free(a);
  }
  return (PKCS7 *)0x0;
}

