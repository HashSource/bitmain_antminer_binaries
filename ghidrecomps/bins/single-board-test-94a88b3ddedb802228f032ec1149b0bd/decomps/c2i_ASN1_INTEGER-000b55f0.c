
ASN1_INTEGER * c2i_ASN1_INTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  byte bVar1;
  byte *__dest;
  byte *pbVar2;
  size_t sVar3;
  ASN1_STRING *a_00;
  byte *__src;
  byte *pbVar4;
  byte *pbVar5;
  size_t local_2c;
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    a_00->type = 2;
  }
  __src = *pp;
  __dest = (byte *)CRYPTO_malloc(length + 1,DAT_000b5740,0xd0);
  pbVar4 = __src + length;
  if (__dest == (byte *)0x0) {
    ERR_put_error(0xd,0xc2,0x41,DAT_000b5740,0x10d);
    if ((a != (ASN1_INTEGER **)0x0) && (*a == a_00)) {
      return (ASN1_INTEGER *)0x0;
    }
    ASN1_STRING_free(a_00);
    return (ASN1_INTEGER *)0x0;
  }
  if (length == 0) {
    a_00->type = 2;
    sVar3 = length;
    goto LAB_000b5626;
  }
  if (-1 < (char)*__src) {
    a_00->type = 2;
    if ((*__src == 0) && (length != 1)) {
      __src = __src + 1;
      length = length - 1;
    }
    memcpy(__dest,__src,length);
    sVar3 = length;
    goto LAB_000b5626;
  }
  a_00->type = 0x102;
  local_2c = length;
  if (*__src == 0xff) {
    if (length == 1) {
      bVar1 = 0xff;
      pbVar5 = __dest;
    }
    else {
      sVar3 = length - 1;
      bVar1 = __src[length + -1];
      __src = __src + length + -1;
      pbVar2 = __dest + length + -2;
      local_2c = sVar3;
      length = sVar3;
      pbVar5 = pbVar2;
      if (bVar1 == 0) goto joined_r0x000b571e;
LAB_000b56b8:
      length = sVar3;
      pbVar5 = pbVar2;
      if (sVar3 == 0) goto LAB_000b5720;
    }
  }
  else {
    __src = __src + length + -1;
    pbVar5 = __dest + length + -1;
    bVar1 = *__src;
    if (bVar1 == 0) {
      do {
        __src = __src + -1;
        pbVar2 = pbVar5 + -1;
        *pbVar5 = 0;
        bVar1 = *__src;
        sVar3 = length - 1;
        length = sVar3;
        pbVar5 = pbVar2;
        if (bVar1 != 0) goto LAB_000b56b8;
joined_r0x000b571e:
      } while (length != 0);
LAB_000b5720:
      *__dest = 1;
      sVar3 = local_2c + 1;
      __dest[local_2c] = 0;
      goto LAB_000b5626;
    }
  }
  *pbVar5 = -bVar1;
  sVar3 = local_2c;
  if (1 < length) {
    pbVar2 = __src + (1 - length);
    do {
      __src = __src + -1;
      pbVar5 = pbVar5 + -1;
      *pbVar5 = ~*__src;
    } while (__src != pbVar2);
  }
LAB_000b5626:
  if (a_00->data != (uchar *)0x0) {
    CRYPTO_free(a_00->data);
  }
  a_00->data = __dest;
  a_00->length = sVar3;
  if (a != (ASN1_INTEGER **)0x0) {
    *a = a_00;
  }
  *pp = pbVar4;
  return a_00;
}

