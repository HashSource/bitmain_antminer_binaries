
void * Curl_copy_header_value(byte *param_1)

{
  ushort **ppuVar1;
  void *__dest;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  
  bVar2 = *param_1;
  if (bVar2 != 0x3a && bVar2 != 0) {
    pbVar3 = param_1 + 1;
    do {
      param_1 = pbVar3;
      bVar2 = *param_1;
      pbVar3 = param_1 + 1;
    } while (bVar2 != 0x3a && bVar2 != 0);
  }
  pbVar3 = param_1 + 1;
  if (bVar2 == 0) {
    pbVar3 = param_1;
  }
  uVar6 = (uint)*pbVar3;
  if (uVar6 != 0) {
    ppuVar1 = __ctype_b_loc();
    do {
      pbVar4 = pbVar3 + 1;
      if (-1 < (int)((uint)(*ppuVar1)[uVar6] << 0x12)) break;
      uVar6 = (uint)pbVar3[1];
      pbVar3 = pbVar4;
    } while (uVar6 != 0);
  }
  pbVar4 = (byte *)strchr((char *)pbVar3,0xd);
  if (((pbVar4 == (byte *)0x0) &&
      (pbVar4 = (byte *)strchr((char *)pbVar3,10), pbVar4 == (byte *)0x0)) &&
     (pbVar4 = (byte *)__rawmemchr(pbVar3,0), pbVar4 == (byte *)0x0)) {
    __dest = (void *)0x0;
  }
  else {
    if (pbVar3 < pbVar4) {
      ppuVar1 = __ctype_b_loc();
      do {
        pbVar5 = pbVar4 + -1;
        if (-1 < (int)((uint)(*ppuVar1)[*pbVar4] << 0x12)) break;
        pbVar4 = pbVar5;
      } while (pbVar5 != pbVar3);
    }
    __dest = (void *)(**DAT_000401bc)(pbVar4 + (2 - (int)pbVar3));
    if (__dest != (void *)0x0) {
      memcpy(__dest,pbVar3,(size_t)(pbVar4 + (1 - (int)pbVar3)));
      *(byte *)((int)__dest + (int)(pbVar4 + (1 - (int)pbVar3))) = 0;
    }
  }
  return __dest;
}

