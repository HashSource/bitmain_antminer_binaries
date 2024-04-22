
void OPENSSL_cleanse(void *ptr,size_t len)

{
  byte *pbVar1;
  void *pvVar2;
  undefined *puVar3;
  byte bVar5;
  uint uVar6;
  undefined *puVar4;
  
  pbVar1 = DAT_0008ba34;
  uVar6 = (uint)*DAT_0008ba34;
  if (len != 0) {
    puVar4 = (undefined *)ptr;
    do {
      puVar3 = puVar4 + 1;
      *puVar4 = (char)uVar6;
      uVar6 = uVar6 + ((uint)puVar3 & 0xf) + 0x11;
      puVar4 = puVar3;
    } while (puVar3 != (undefined *)((int)ptr + len));
  }
  bVar5 = (byte)uVar6;
  pvVar2 = memchr(ptr,uVar6 & 0xff,len);
  if (pvVar2 != (void *)0x0) {
    bVar5 = (char)pvVar2 + bVar5 + 0x3f;
  }
  *pbVar1 = bVar5;
  return;
}

