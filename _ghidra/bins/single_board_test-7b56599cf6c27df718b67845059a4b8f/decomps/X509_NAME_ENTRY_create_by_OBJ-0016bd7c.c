
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_OBJ(X509_NAME_ENTRY **ne,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  int iVar1;
  X509_NAME_ENTRY *ne_00;
  
  if ((ne == (X509_NAME_ENTRY **)0x0) || (ne_00 = *ne, ne_00 == (X509_NAME_ENTRY *)0x0)) {
    ne_00 = X509_NAME_ENTRY_new();
    if (ne_00 == (X509_NAME_ENTRY *)0x0) {
      return (X509_NAME_ENTRY *)0x0;
    }
    iVar1 = X509_NAME_ENTRY_set_object(ne_00,obj);
    if ((iVar1 != 0) && (iVar1 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar1 != 0)) {
      if (ne == (X509_NAME_ENTRY **)0x0) {
        return ne_00;
      }
      goto LAB_0016bdb8;
    }
    if (ne == (X509_NAME_ENTRY **)0x0) goto LAB_0016bd9c;
  }
  else {
    iVar1 = X509_NAME_ENTRY_set_object(ne_00,obj);
    if ((iVar1 != 0) && (iVar1 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar1 != 0)) {
LAB_0016bdb8:
      if (*ne != (X509_NAME_ENTRY *)0x0) {
        return ne_00;
      }
      *ne = ne_00;
      return ne_00;
    }
  }
  if (*ne == ne_00) {
    return (X509_NAME_ENTRY *)0x0;
  }
LAB_0016bd9c:
  X509_NAME_ENTRY_free(ne_00);
  return (X509_NAME_ENTRY *)0x0;
}

