
void * X509at_get0_data_by_OBJ(stack_st_X509_ATTRIBUTE *x,ASN1_OBJECT *obj,int lastpos,int type)

{
  int iVar1;
  X509_ATTRIBUTE *attr;
  void *pvVar2;
  int iVar3;
  
  iVar1 = X509at_get_attr_by_OBJ(x,obj,lastpos);
  if (iVar1 == -1) {
    return (void *)0x0;
  }
  if (lastpos + 1 < 0 == SCARRY4(lastpos,1)) {
    attr = X509at_get_attr(x,iVar1);
  }
  else {
    iVar3 = X509at_get_attr_by_OBJ(x,obj,iVar1);
    if (iVar3 != -1) {
      return (void *)0x0;
    }
    attr = X509at_get_attr(x,iVar1);
    if ((lastpos != -2) && (iVar1 = X509_ATTRIBUTE_count(attr), iVar1 != 1)) {
      return (void *)0x0;
    }
  }
  pvVar2 = X509_ATTRIBUTE_get0_data(attr,0,type,(void *)0x0);
  return pvVar2;
}

