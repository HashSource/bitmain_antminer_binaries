
int X509_EXTENSION_set_object(X509_EXTENSION *ex,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  
  if (ex != (X509_EXTENSION *)0x0 && obj != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(ex->object);
    pAVar1 = OBJ_dup(obj);
    ex->object = pAVar1;
  }
  return (uint)(ex != (X509_EXTENSION *)0x0 && obj != (ASN1_OBJECT *)0x0);
}

