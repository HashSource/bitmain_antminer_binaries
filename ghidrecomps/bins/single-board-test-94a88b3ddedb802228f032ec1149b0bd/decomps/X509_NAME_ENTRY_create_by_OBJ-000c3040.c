
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_OBJ(X509_NAME_ENTRY **ne,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_NAME_ENTRY *ne_00;
  
  if (((ne != (X509_NAME_ENTRY **)0x0) && (ne_00 = *ne, ne_00 != (X509_NAME_ENTRY *)0x0)) ||
     (ne_00 = X509_NAME_ENTRY_new(), ne_00 != (X509_NAME_ENTRY *)0x0)) {
    if (obj == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xb,0x73,0x43,DAT_000c30c4,0x160);
    }
    else {
      ASN1_OBJECT_free(ne_00->object);
      pAVar1 = OBJ_dup(obj);
      ne_00->object = pAVar1;
      if ((pAVar1 != (ASN1_OBJECT *)0x0) &&
         (iVar2 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar2 != 0)) {
        if (ne == (X509_NAME_ENTRY **)0x0) {
          return ne_00;
        }
        if (*ne != (X509_NAME_ENTRY *)0x0) {
          return ne_00;
        }
        *ne = ne_00;
        return ne_00;
      }
    }
    if ((ne == (X509_NAME_ENTRY **)0x0) || (*ne != ne_00)) {
      X509_NAME_ENTRY_free(ne_00);
      return (X509_NAME_ENTRY *)0x0;
    }
  }
  return (X509_NAME_ENTRY *)0x0;
}

