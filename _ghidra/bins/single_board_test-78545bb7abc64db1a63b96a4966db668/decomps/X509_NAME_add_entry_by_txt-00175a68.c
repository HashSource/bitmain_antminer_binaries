
int X509_NAME_add_entry_by_txt
              (X509_NAME *name,char *field,int type,uchar *bytes,int len,int loc,int set)

{
  X509_NAME_ENTRY *ne;
  int iVar1;
  
  ne = X509_NAME_ENTRY_create_by_txt((X509_NAME_ENTRY **)0x0,field,type,bytes,len);
  if (ne != (X509_NAME_ENTRY *)0x0) {
    iVar1 = X509_NAME_add_entry(name,ne,loc,set);
    X509_NAME_ENTRY_free(ne);
    return iVar1;
  }
  return 0;
}

