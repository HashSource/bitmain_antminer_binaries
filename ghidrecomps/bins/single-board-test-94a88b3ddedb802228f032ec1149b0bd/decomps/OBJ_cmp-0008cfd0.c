
int OBJ_cmp(ASN1_OBJECT *a,ASN1_OBJECT *b)

{
  int iVar1;
  
  iVar1 = a->length - b->length;
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (*(code *)PTR_memcmp_00194160)(a->data,b->data);
  return iVar1;
}

