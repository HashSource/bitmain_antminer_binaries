
int ASN1_STRING_to_UTF8(uchar **out,ASN1_STRING *in)

{
  int iVar1;
  uint uVar2;
  ASN1_STRING *local_24;
  ASN1_STRING local_20;
  
  local_24 = &local_20;
  if ((in == (ASN1_STRING *)0x0) || (0x1e < (uint)in->type)) {
    iVar1 = -1;
  }
  else {
    uVar2 = (uint)*(char *)(DAT_000b6aa8 + in->type + 0x94);
    if (uVar2 == 0xffffffff) {
      iVar1 = -1;
    }
    else {
      local_20.data = (uchar *)0x0;
      local_20.length = 0;
      local_20.flags = 0;
      iVar1 = ASN1_mbstring_copy(&local_24,in->data,in->length,uVar2 | 0x1000,0x2000);
      if (-1 < iVar1) {
        *out = local_20.data;
        iVar1 = local_20.length;
      }
    }
  }
  return iVar1;
}

