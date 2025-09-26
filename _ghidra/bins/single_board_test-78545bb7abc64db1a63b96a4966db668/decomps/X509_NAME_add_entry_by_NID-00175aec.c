
int X509_NAME_add_entry_by_NID
              (X509_NAME *name,int nid,int type,uchar *bytes,int len,int loc,int set)

{
  X509_NAME_ENTRY *ne;
  int iVar1;
  
  ne = X509_NAME_ENTRY_create_by_NID((X509_NAME_ENTRY **)0x0,nid,type,bytes,len);
  if (ne != (X509_NAME_ENTRY *)0x0) {
    iVar1 = X509_NAME_add_entry(name,ne,loc,set);
    X509_NAME_ENTRY_free(ne);
    return iVar1;
  }
  return 0;
}

