
int ASN1_STRING_copy(ASN1_STRING *dst,ASN1_STRING *str)

{
  uchar *data;
  int iVar1;
  
  if (str != (ASN1_STRING *)0x0) {
    iVar1 = str->length;
    data = str->data;
    dst->type = str->type;
    iVar1 = ASN1_STRING_set(dst,data,iVar1);
    if (iVar1 != 0) {
      dst->flags = str->flags;
      return 1;
    }
  }
  return 0;
}

