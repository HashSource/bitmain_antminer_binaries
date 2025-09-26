
X509_ATTRIBUTE *
X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,char *atrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *obj;
  X509_ATTRIBUTE *pXVar1;
  
  obj = OBJ_txt2obj(atrname,0);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,"crypto/x509/x509_att.c",0xe3);
    ERR_add_error_data(2,"name=",atrname);
    pXVar1 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    pXVar1 = X509_ATTRIBUTE_create_by_OBJ(attr,obj,type,bytes,len);
    ASN1_OBJECT_free(obj);
  }
  return pXVar1;
}

