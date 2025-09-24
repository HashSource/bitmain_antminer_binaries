
void * X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr,int idx,int atrtype,void *data)

{
  ASN1_TYPE *a;
  int iVar1;
  char *pcVar2;
  
  a = X509_ATTRIBUTE_get0_type(attr,idx);
  if (a == (ASN1_TYPE *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    if (((atrtype & 0xfffffffbU) == 1) || (iVar1 = ASN1_TYPE_get(a), atrtype != iVar1)) {
      ERR_put_error(0xb,0x8b,0x7a,"crypto/x509/x509_att.c",0x140);
      return (void *)0x0;
    }
    pcVar2 = (a->value).ptr;
  }
  return pcVar2;
}

