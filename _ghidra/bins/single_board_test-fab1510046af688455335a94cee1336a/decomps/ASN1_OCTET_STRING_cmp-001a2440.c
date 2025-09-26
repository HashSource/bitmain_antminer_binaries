
int ASN1_OCTET_STRING_cmp(ASN1_STRING *a,ASN1_STRING *b)

{
  int iVar1;
  
  iVar1 = a->length - b->length;
  if ((iVar1 == 0) && (iVar1 = memcmp(a->data,b->data,a->length), iVar1 == 0)) {
    iVar1 = a->type - b->type;
  }
  return iVar1;
}

