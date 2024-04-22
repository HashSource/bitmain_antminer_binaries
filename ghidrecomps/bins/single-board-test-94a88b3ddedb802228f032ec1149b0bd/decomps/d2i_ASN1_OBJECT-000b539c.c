
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  uchar *local_28;
  long local_24;
  int local_20;
  int aiStack_1c [2];
  
  local_28 = *pp;
  iVar1 = ASN1_get_object(&local_28,&local_24,&local_20,aiStack_1c,length);
  if (iVar1 << 0x18 < 0) {
    iVar1 = 0x66;
  }
  else {
    if (local_20 == 6) {
      pAVar2 = c2i_ASN1_OBJECT(a,&local_28,local_24);
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
        return (ASN1_OBJECT *)0x0;
      }
      *pp = local_28;
      return pAVar2;
    }
    iVar1 = 0x74;
  }
  ERR_put_error(0xd,0x93,iVar1,DAT_000b53f4,0x108);
  return (ASN1_OBJECT *)0x0;
}

