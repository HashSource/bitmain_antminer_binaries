
int OBJ_cmp(ASN1_OBJECT *a,ASN1_OBJECT *b)

{
  int iVar1;
  
  iVar1 = a->length - b->length;
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = memcmp(a->data,b->data,a->length);
  return iVar1;
}

