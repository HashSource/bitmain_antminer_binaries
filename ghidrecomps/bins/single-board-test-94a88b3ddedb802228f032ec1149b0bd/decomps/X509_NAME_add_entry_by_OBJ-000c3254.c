
int X509_NAME_add_entry_by_OBJ
              (X509_NAME *name,ASN1_OBJECT *obj,int type,uchar *bytes,int len,int loc,int set)

{
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  
  ne = X509_NAME_ENTRY_new();
  if (ne != (X509_NAME_ENTRY *)0x0) {
    if (obj == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xb,0x73,0x43,DAT_000c32c8,0x160);
    }
    else {
      ASN1_OBJECT_free(ne->object);
      pAVar1 = OBJ_dup(obj);
      ne->object = pAVar1;
      if ((pAVar1 != (ASN1_OBJECT *)0x0) &&
         (iVar2 = X509_NAME_ENTRY_set_data(ne,type,bytes,len), iVar2 != 0)) {
        iVar2 = X509_NAME_add_entry(name,ne,loc,set);
        X509_NAME_ENTRY_free(ne);
        return iVar2;
      }
    }
    X509_NAME_ENTRY_free(ne);
  }
  return 0;
}

