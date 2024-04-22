
ASN1_STRING * d2i_ASN1_type_bytes(ASN1_STRING **a,uchar **pp,long length,int type)

{
  int iVar1;
  ulong uVar2;
  uchar *__dest;
  ASN1_BIT_STRING *pAVar3;
  ASN1_STRING *a_00;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  int iStack_1c;
  
  local_28 = *pp;
  iVar1 = ASN1_get_object(&local_28,(long *)&local_24,&local_20,&iStack_1c,length);
  if (iVar1 << 0x18 < 0) {
    iVar1 = 0;
  }
  else if (local_20 < 0x20) {
    uVar2 = ASN1_tag2bit(local_20);
    if ((uVar2 & type) != 0) {
      if (local_20 == 3) {
        pAVar3 = d2i_ASN1_BIT_STRING(a,pp,length);
        return pAVar3;
      }
      if (((a == (ASN1_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) &&
         (a_00 = ASN1_STRING_new(), a_00 == (ASN1_STRING *)0x0)) {
        return (ASN1_STRING *)0x0;
      }
      __dest = local_24;
      if (local_24 != (uchar *)0x0) {
        __dest = (uchar *)CRYPTO_malloc((int)(local_24 + 1),DAT_0010a088,0x66);
        if (__dest == (uchar *)0x0) {
          ERR_put_error(0xd,0x95,0x41,DAT_0010a088,0x7b);
          if ((a != (ASN1_STRING **)0x0) && (a_00 == *a)) {
            return (ASN1_STRING *)0x0;
          }
          ASN1_STRING_free(a_00);
          return (ASN1_STRING *)0x0;
        }
        memcpy(__dest,local_28,(size_t)local_24);
        __dest[(int)local_24] = '\0';
        local_28 = local_28 + (int)local_24;
      }
      if (a_00->data != (uchar *)0x0) {
        CRYPTO_free(a_00->data);
      }
      a_00->data = __dest;
      a_00->length = (int)local_24;
      a_00->type = local_20;
      if (a != (ASN1_STRING **)0x0) {
        *a = a_00;
      }
      *pp = local_28;
      return a_00;
    }
    iVar1 = 0xa9;
  }
  else {
    iVar1 = 0x99;
  }
  ERR_put_error(0xd,0x95,iVar1,DAT_0010a088,0x7b);
  return (ASN1_STRING *)0x0;
}

