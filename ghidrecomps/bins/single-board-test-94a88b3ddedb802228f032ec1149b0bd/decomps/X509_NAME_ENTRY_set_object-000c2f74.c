
int X509_NAME_ENTRY_set_object(X509_NAME_ENTRY *ne,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *pAVar1;
  ASN1_OBJECT *pAVar2;
  
  if (ne == (X509_NAME_ENTRY *)0x0 || obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x73,0x43,DAT_000c2fb4,0x160);
    pAVar2 = (ASN1_OBJECT *)0x0;
  }
  else {
    ASN1_OBJECT_free(ne->object);
    pAVar1 = OBJ_dup(obj);
    pAVar2 = pAVar1;
    if (pAVar1 != (ASN1_OBJECT *)0x0) {
      pAVar2 = (ASN1_OBJECT *)0x1;
    }
    ne->object = pAVar1;
  }
  return (int)pAVar2;
}

