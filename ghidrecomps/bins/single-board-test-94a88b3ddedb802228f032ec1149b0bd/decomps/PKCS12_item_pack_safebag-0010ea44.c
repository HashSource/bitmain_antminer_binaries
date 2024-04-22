
PKCS12_SAFEBAG * PKCS12_item_pack_safebag(void *obj,ASN1_ITEM *it,int nid1,int nid2)

{
  X509_SIG *pXVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  PKCS12_SAFEBAG *pPVar4;
  int line;
  
  pXVar1 = (X509_SIG *)PKCS12_BAGS_new();
  if (pXVar1 == (X509_SIG *)0x0) {
    ERR_put_error(0x23,0x75,0x41,DAT_0010eab8,0x48);
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar2 = OBJ_nid2obj(nid1);
    pXVar1->algor = (X509_ALGOR *)pAVar2;
    pAVar3 = ASN1_item_pack(obj,it,&((_union_991 *)&pXVar1->digest)->x509cert);
    line = 0x4d;
    if (pAVar3 != (ASN1_STRING *)0x0) {
      pPVar4 = PKCS12_SAFEBAG_new();
      if (pPVar4 != (PKCS12_SAFEBAG *)0x0) {
        (pPVar4->value).shkeybag = pXVar1;
        pAVar2 = OBJ_nid2obj(nid2);
        pPVar4->type = pAVar2;
        return pPVar4;
      }
      line = 0x51;
      pAVar3 = (ASN1_STRING *)0x0;
    }
    ERR_put_error(0x23,0x75,0x41,DAT_0010eab8,line);
  }
  return (PKCS12_SAFEBAG *)pAVar3;
}

