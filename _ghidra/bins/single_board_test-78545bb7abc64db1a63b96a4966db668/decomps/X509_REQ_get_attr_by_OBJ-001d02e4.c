
int X509_REQ_get_attr_by_OBJ(X509_REQ *req,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_OBJ((stack_st_X509_ATTRIBUTE *)req[1].signature,obj,lastpos);
  return iVar1;
}

