
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_OBJ(stack_st_X509_ATTRIBUTE **x,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  X509_ATTRIBUTE *attr;
  stack_st_X509_ATTRIBUTE *psVar1;
  
  attr = X509_ATTRIBUTE_create_by_OBJ((X509_ATTRIBUTE **)0x0,obj,type,bytes,len);
  if (attr == (X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x0;
  }
  else {
    psVar1 = X509at_add1_attr(x,attr);
    X509_ATTRIBUTE_free(attr);
  }
  return psVar1;
}

