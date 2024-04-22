
X509_EXTENSION *
X509_EXTENSION_create_by_NID(X509_EXTENSION **ex,int nid,int crit,ASN1_OCTET_STRING *data)

{
  ASN1_OBJECT *obj;
  X509_EXTENSION *pXVar1;
  
  obj = OBJ_nid2obj(nid);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x6c,0x6d,DAT_000c35a0,0xc2);
    pXVar1 = (X509_EXTENSION *)0x0;
  }
  else {
    pXVar1 = X509_EXTENSION_create_by_OBJ(ex,obj,crit,data);
    if (pXVar1 == (X509_EXTENSION *)0x0) {
      ASN1_OBJECT_free(obj);
    }
  }
  return pXVar1;
}

