
int ASN1_OCTET_STRING_cmp(ASN1_STRING *a,ASN1_STRING *b)

{
  size_t __n;
  int iVar1;
  
  __n = a->length;
  iVar1 = __n - b->length;
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((__n != 0) && (iVar1 = memcmp(a->data,b->data,__n), iVar1 != 0)) {
    return iVar1;
  }
  return a->type - b->type;
}

