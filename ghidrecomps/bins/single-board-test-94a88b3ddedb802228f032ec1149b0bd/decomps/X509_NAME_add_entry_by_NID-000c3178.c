
int X509_NAME_add_entry_by_NID
              (X509_NAME *name,int nid,int type,uchar *bytes,int len,int loc,int set)

{
  ASN1_OBJECT *obj;
  X509_NAME_ENTRY *ne;
  X509_NAME_ENTRY *pXVar1;
  
  obj = OBJ_nid2obj(nid);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x72,0x6d,DAT_000c31d8,0x139);
    pXVar1 = (X509_NAME_ENTRY *)0x0;
  }
  else {
    ne = X509_NAME_ENTRY_create_by_OBJ((X509_NAME_ENTRY **)0x0,obj,type,bytes,len);
    ASN1_OBJECT_free(obj);
    pXVar1 = ne;
    if (ne != (X509_NAME_ENTRY *)0x0) {
      pXVar1 = (X509_NAME_ENTRY *)X509_NAME_add_entry(name,ne,loc,set);
      X509_NAME_ENTRY_free(ne);
    }
  }
  return (int)pXVar1;
}

