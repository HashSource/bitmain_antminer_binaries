
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_NID(X509_ATTRIBUTE **attr,int nid,int atrtype,void *data,int len)

{
  ASN1_OBJECT *obj;
  X509_ATTRIBUTE *pXVar1;
  
  obj = OBJ_nid2obj(nid);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x88,0x6d,"crypto/x509/x509_att.c",0xb1);
    pXVar1 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    pXVar1 = X509_ATTRIBUTE_create_by_OBJ(attr,obj,atrtype,data,len);
    if (pXVar1 == (X509_ATTRIBUTE *)0x0) {
      ASN1_OBJECT_free(obj);
    }
  }
  return pXVar1;
}

