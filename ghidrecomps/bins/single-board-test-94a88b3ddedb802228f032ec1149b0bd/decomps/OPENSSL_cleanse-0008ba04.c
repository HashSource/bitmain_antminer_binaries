
void OPENSSL_cleanse(void *ptr,size_t len)

{
  void *pvVar1;
  undefined1 *puVar2;
  char cVar4;
  uint uVar5;
  undefined1 *puVar3;
  
  uVar5 = (uint)cleanse_ctr;
  if (len != 0) {
    puVar3 = (undefined1 *)ptr;
    do {
      puVar2 = puVar3 + 1;
      *puVar3 = (char)uVar5;
      uVar5 = uVar5 + ((uint)puVar2 & 0xf) + 0x11;
      puVar3 = puVar2;
    } while (puVar2 != (undefined1 *)((int)ptr + len));
  }
  cVar4 = (char)uVar5;
  pvVar1 = memchr(ptr,uVar5 & 0xff,len);
  if (pvVar1 != (void *)0x0) {
    cVar4 = (char)pvVar1 + cVar4 + '?';
  }
  cleanse_ctr = cVar4;
  return;
}

