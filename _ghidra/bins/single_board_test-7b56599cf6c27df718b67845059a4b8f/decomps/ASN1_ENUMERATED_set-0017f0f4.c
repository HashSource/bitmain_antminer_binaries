
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a,long v)

{
  int iVar1;
  
  iVar1 = ASN1_ENUMERATED_set_int64(a,v,v,v >> 0x1f);
  return iVar1;
}

