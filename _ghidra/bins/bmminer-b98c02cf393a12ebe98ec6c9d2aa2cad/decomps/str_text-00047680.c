
byte * str_text(byte *param_1)

{
  size_t sVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  byte bVar4;
  byte *__s;
  char acStack_818 [2052];
  
  if (param_1 == (byte *)0x0) {
    puVar3 = (undefined4 *)malloc(7);
    if (puVar3 == (undefined4 *)0x0) {
      snprintf(acStack_818,0x800,"Failed to malloc null in %s %s():%d","util.c","str_text",0xd6e);
      _applog(3,acStack_818,1);
      _quit(1);
    }
    else {
      *puVar3 = 0x6c756e28;
      *(undefined2 *)(puVar3 + 1) = 0x296c;
      *(undefined1 *)((int)puVar3 + 6) = 0;
    }
  }
  sVar1 = strlen((char *)param_1);
  pbVar2 = (byte *)_cgmalloc(sVar1 * 4 + 5,"util.c","str_text",0xd73);
  __s = pbVar2;
  do {
    while (0x5e < *param_1 - 0x20) {
      sprintf((char *)__s,"0x%02x");
      bVar4 = *param_1;
      __s = __s + 4;
      param_1 = param_1 + 1;
      if (bVar4 == 0) goto LAB_000476dc;
    }
    *__s = *param_1;
    __s = __s + 1;
    bVar4 = *param_1;
    param_1 = param_1 + 1;
  } while (bVar4 != 0);
LAB_000476dc:
  *__s = bVar4;
  return pbVar2;
}

