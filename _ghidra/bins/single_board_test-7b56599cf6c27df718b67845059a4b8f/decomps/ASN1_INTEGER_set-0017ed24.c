
int ASN1_INTEGER_set(ASN1_INTEGER *a,long v)

{
  int iVar1;
  
  iVar1 = ASN1_INTEGER_set_int64(a,v,v,v >> 0x1f);
  return iVar1;
}

