
/* WARNING: Unknown calling convention */

void * str_text(char *ptr)

{
  size_t sVar1;
  byte *pbVar2;
  char *ret;
  undefined4 *puVar3;
  char *__retval;
  undefined4 uVar4;
  byte bVar5;
  uchar *uptr;
  byte *__s;
  byte *pbVar6;
  char tmp42 [2048];
  
  if (ptr == (char *)0x0) {
    puVar3 = (undefined4 *)malloc(7);
    if (puVar3 == (undefined4 *)0x0) {
      snprintf(tmp42,0x800,DAT_000123c8,DAT_000123b8,DAT_000123bc,0xca3);
      _applog(3,tmp42,true);
      _quit(1);
    }
    else {
      uVar4 = DAT_000123c4[1];
      *puVar3 = *DAT_000123c4;
      *(short *)(puVar3 + 1) = (short)uVar4;
      *(char *)((int)puVar3 + 6) = (char)((uint)uVar4 >> 0x10);
    }
  }
  sVar1 = strlen(ptr);
  pbVar2 = (byte *)_cgmalloc(sVar1 * 4 + 5,DAT_000123b8,DAT_000123bc,0xca8);
  __s = pbVar2;
  do {
    while( true ) {
      if ((byte)*ptr - 0x20 < 0x5f) break;
      sprintf((char *)__s,DAT_000123c0);
      bVar5 = *ptr;
      pbVar6 = __s + 4;
      ptr = (char *)((byte *)ptr + 1);
      __s = pbVar6;
      if (bVar5 == 0) goto LAB_00012366;
    }
    pbVar6 = __s + 1;
    *__s = *ptr;
    bVar5 = *ptr;
    ptr = (char *)((byte *)ptr + 1);
    __s = pbVar6;
  } while (bVar5 != 0);
LAB_00012366:
  *pbVar6 = bVar5;
  return pbVar2;
}

