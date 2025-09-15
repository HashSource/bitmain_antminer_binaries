
/* WARNING: Unknown calling convention */

void * str_text(char *ptr)

{
  size_t sVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  byte bVar4;
  byte *__s;
  byte *pbVar5;
  char tmp42 [2048];
  
  if (ptr == (char *)0x0) {
    puVar3 = (undefined4 *)malloc(7);
    if (puVar3 == (undefined4 *)0x0) {
      snprintf(tmp42,0x800,"Failed to malloc null in %s %s():%d","util.c","str_text",0xca3);
      _applog(3,tmp42,true);
      _quit(1);
    }
    else {
      *puVar3 = 0x6c756e28;
      *(undefined2 *)(puVar3 + 1) = 0x296c;
      *(undefined1 *)((int)puVar3 + 6) = 0;
    }
  }
  sVar1 = strlen(ptr);
  pbVar2 = (byte *)_cgmalloc(sVar1 * 4 + 5,"util.c","str_text",0xca8);
  __s = pbVar2;
  do {
    while( true ) {
      if ((byte)*ptr - 0x20 < 0x5f) break;
      sprintf((char *)__s,"0x%02x");
      bVar4 = *ptr;
      pbVar5 = __s + 4;
      ptr = (char *)((byte *)ptr + 1);
      __s = pbVar5;
      if (bVar4 == 0) goto LAB_00012366;
    }
    pbVar5 = __s + 1;
    *__s = *ptr;
    bVar4 = *ptr;
    ptr = (char *)((byte *)ptr + 1);
    __s = pbVar5;
  } while (bVar4 != 0);
LAB_00012366:
  *pbVar5 = bVar4;
  return pbVar2;
}

