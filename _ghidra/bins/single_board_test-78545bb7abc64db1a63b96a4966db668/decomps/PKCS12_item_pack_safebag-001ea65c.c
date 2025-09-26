
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  X509_SIG *a;
  ASN1_OBJECT *pAVar1;
  ASN1_STRING *pAVar2;
  PKCS12_SAFEBAG *pPVar3;
  int line;
  
  a = (X509_SIG *)PKCS12_BAGS_new();
  if (a == (X509_SIG *)0x0) {
    ERR_put_error(0x23,0x75,0x41,"crypto/pkcs12/p12_add.c",0x18);
  }
  else {
    pAVar1 = OBJ_nid2obj(nid1);
    a->algor = (X509_ALGOR *)pAVar1;
    pAVar2 = ASN1_item_pack(obj,it,&((_union_991 *)&a->digest)->x509cert);
    if (pAVar2 == (ASN1_STRING *)0x0) {
      line = 0x1d;
    }
    else {
      pPVar3 = PKCS12_SAFEBAG_new();
      if (pPVar3 != (PKCS12_SAFEBAG *)0x0) {
        (pPVar3->value).shkeybag = a;
        pAVar1 = OBJ_nid2obj(nid2);
        pPVar3->type = pAVar1;
        return pPVar3;
      }
      line = 0x21;
    }
    ERR_put_error(0x23,0x75,0x41,"crypto/pkcs12/p12_add.c",line);
    PKCS12_BAGS_free((PKCS12_BAGS *)a);
  }
  return (PKCS12_SAFEBAG *)0x0;
}

