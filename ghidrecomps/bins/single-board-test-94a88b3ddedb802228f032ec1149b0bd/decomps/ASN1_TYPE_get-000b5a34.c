
int ASN1_TYPE_get(ASN1_TYPE *a)

{
  int iVar1;
  
  if ((a->value).ptr == (char *)0x0) {
    if (a->type == 5) {
      iVar1 = 5;
    }
    else {
      iVar1 = 0;
    }
    return iVar1;
  }
  return a->type;
}

