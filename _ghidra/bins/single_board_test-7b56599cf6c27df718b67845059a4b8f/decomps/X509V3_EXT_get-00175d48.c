
X509V3_EXT_METHOD * X509V3_EXT_get(X509_EXTENSION *ext)

{
  ASN1_OBJECT *o;
  int nid;
  X509V3_EXT_METHOD *pXVar1;
  
  o = X509_EXTENSION_get_object(ext);
  nid = OBJ_obj2nid(o);
  if (nid != 0) {
    pXVar1 = X509V3_EXT_get_nid(nid);
    return pXVar1;
  }
  return (X509V3_EXT_METHOD *)0x0;
}

