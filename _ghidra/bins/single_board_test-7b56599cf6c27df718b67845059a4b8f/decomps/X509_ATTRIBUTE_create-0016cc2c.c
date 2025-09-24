
X509_ATTRIBUTE * X509_ATTRIBUTE_create(int nid,int atrtype,void *value)

{
  ASN1_OBJECT *pAVar1;
  X509_ATTRIBUTE *a;
  ASN1_TYPE *a_00;
  int iVar2;
  
  pAVar1 = OBJ_nid2obj(nid);
  if ((pAVar1 != (ASN1_OBJECT *)0x0) && (a = X509_ATTRIBUTE_new(), a != (X509_ATTRIBUTE *)0x0)) {
    a->object = pAVar1;
    a_00 = ASN1_TYPE_new();
    if ((a_00 != (ASN1_TYPE *)0x0) && (iVar2 = OPENSSL_sk_push(a->single,a_00), iVar2 != 0)) {
      ASN1_TYPE_set(a_00,atrtype,value);
      return a;
    }
    X509_ATTRIBUTE_free(a);
    ASN1_TYPE_free(a_00);
  }
  return (X509_ATTRIBUTE *)0x0;
}

