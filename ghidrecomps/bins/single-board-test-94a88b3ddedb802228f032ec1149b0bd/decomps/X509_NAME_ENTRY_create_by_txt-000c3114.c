
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_txt(X509_NAME_ENTRY **ne,char *field,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *obj;
  X509_NAME_ENTRY *pXVar1;
  
  obj = OBJ_txt2obj(field,0);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x83,0x77,DAT_000c3170,0x127);
    ERR_add_error_data(2,DAT_000c3174,field);
    pXVar1 = (X509_NAME_ENTRY *)0x0;
  }
  else {
    pXVar1 = X509_NAME_ENTRY_create_by_OBJ(ne,obj,type,bytes,len);
    ASN1_OBJECT_free(obj);
  }
  return pXVar1;
}

