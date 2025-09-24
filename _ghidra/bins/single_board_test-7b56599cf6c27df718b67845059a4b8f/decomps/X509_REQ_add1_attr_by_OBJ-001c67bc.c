
int X509_REQ_add1_attr_by_OBJ(X509_REQ *req,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_OBJ((stack_st_X509_ATTRIBUTE **)&req[1].signature,obj,type,bytes,len)
  ;
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
    req->signature = (ASN1_BIT_STRING *)0x1;
  }
  return (int)psVar1;
}

