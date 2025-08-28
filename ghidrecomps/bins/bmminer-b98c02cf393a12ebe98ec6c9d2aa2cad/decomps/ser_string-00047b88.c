
undefined1 * ser_string(char *param_1,int *param_2)

{
  size_t sVar1;
  undefined1 *puVar2;
  
  sVar1 = strlen(param_1);
  puVar2 = (undefined1 *)_cgmalloc(sVar1 + 9,"util.c","ser_string",0x3e4);
  if (sVar1 < 0xfd) {
    *puVar2 = (char)sVar1;
    _cg_memcpy(puVar2 + 1,param_1,sVar1,"util.c","ser_string",1000);
    *param_2 = sVar1 + 1;
    return puVar2;
  }
  if (0xffff < sVar1) {
    *puVar2 = 0xfe;
    *(size_t *)(puVar2 + 1) =
         sVar1 << 0x18 | (sVar1 >> 8 & 0xff) << 0x10 | (sVar1 >> 0x10 & 0xff) << 8 | sVar1 >> 0x18;
    _cg_memcpy(puVar2 + 5,param_1,sVar1,"util.c","ser_string",0x3fb);
    *param_2 = sVar1 + 5;
    return puVar2;
  }
  *puVar2 = 0xfd;
  *(ushort *)(puVar2 + 1) = (ushort)((sVar1 & 0xff) << 8) | (ushort)(sVar1 >> 8) & 0xff;
  _cg_memcpy(puVar2 + 3,param_1,sVar1,"util.c","ser_string",0x3f1);
  *param_2 = sVar1 + 3;
  return puVar2;
}

