
int X509at_get_attr_by_NID(stack_st_X509_ATTRIBUTE *x,int nid,int lastpos)

{
  ASN1_OBJECT *obj;
  int iVar1;
  
  obj = OBJ_nid2obj(nid);
  if (obj != (ASN1_OBJECT *)0x0) {
    iVar1 = X509at_get_attr_by_OBJ(x,obj,lastpos);
    return iVar1;
  }
  return -2;
}

