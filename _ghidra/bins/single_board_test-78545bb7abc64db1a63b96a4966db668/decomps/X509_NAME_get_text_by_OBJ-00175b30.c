
int X509_NAME_get_text_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,char *buf,int len)

{
  int loc;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar1;
  size_t __n;
  
  loc = X509_NAME_get_index_by_OBJ(name,obj,-1);
  if (loc < 0) {
    return -1;
  }
  ne = X509_NAME_get_entry(name,loc);
  pAVar1 = X509_NAME_ENTRY_get_data(ne);
  if (buf != (char *)0x0) {
    if (0 < len) {
      __n = pAVar1->length;
      if (len <= (int)__n) {
        __n = len - 1;
      }
      memcpy(buf,pAVar1->data,__n);
      buf[__n] = '\0';
      return __n;
    }
    return 0;
  }
  return pAVar1->length;
}

