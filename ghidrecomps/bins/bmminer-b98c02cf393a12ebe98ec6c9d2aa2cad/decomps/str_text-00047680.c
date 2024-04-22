
byte * str_text(byte *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  byte bVar5;
  byte *__s;
  char acStack_818 [2052];
  
  if (param_1 == (byte *)0x0) {
    puVar4 = (undefined4 *)malloc(7);
    uVar1 = DAT_00057988;
    if (puVar4 == (undefined4 *)0x0) {
      snprintf(acStack_818,0x800,"Failed to malloc null in %s %s():%d","util.c",DAT_0004773c,0xd6e);
      _applog(3,acStack_818,1);
      _quit(1);
    }
    else {
      *puVar4 = DAT_00057984;
      *(short *)(puVar4 + 1) = (short)uVar1;
      *(char *)((int)puVar4 + 6) = (char)((uint)uVar1 >> 0x10);
    }
  }
  sVar2 = strlen((char *)param_1);
  pbVar3 = (byte *)_cgmalloc(sVar2 * 4 + 5,"util.c",DAT_0004773c,0xd73);
  __s = pbVar3;
  do {
    while (0x5e < *param_1 - 0x20) {
      sprintf((char *)__s,"0x%02x");
      bVar5 = *param_1;
      __s = __s + 4;
      param_1 = param_1 + 1;
      if (bVar5 == 0) goto LAB_000476dc;
    }
    *__s = *param_1;
    __s = __s + 1;
    bVar5 = *param_1;
    param_1 = param_1 + 1;
  } while (bVar5 != 0);
LAB_000476dc:
  *__s = bVar5;
  return pbVar3;
}

