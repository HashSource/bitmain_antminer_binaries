
undefined * ser_string(char *param_1,int *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  undefined *puVar3;
  
  uVar1 = DAT_00047c44;
  sVar2 = strlen(param_1);
  puVar3 = (undefined *)_cgmalloc(sVar2 + 9,"util.c",uVar1,0x3e4);
  if (sVar2 < 0xfd) {
    *puVar3 = (char)sVar2;
    _cg_memcpy(puVar3 + 1,param_1,sVar2,"util.c",uVar1,1000);
    *param_2 = sVar2 + 1;
    return puVar3;
  }
  if (0xffff < sVar2) {
    *puVar3 = 0xfe;
    *(size_t *)(puVar3 + 1) =
         sVar2 << 0x18 | (sVar2 >> 8 & 0xff) << 0x10 | (sVar2 >> 0x10 & 0xff) << 8 | sVar2 >> 0x18;
    _cg_memcpy(puVar3 + 5,param_1,sVar2,"util.c",uVar1,0x3fb);
    *param_2 = sVar2 + 5;
    return puVar3;
  }
  *puVar3 = 0xfd;
  *(ushort *)(puVar3 + 1) = (ushort)((sVar2 & 0xff) << 8) | (ushort)(sVar2 >> 8) & 0xff;
  _cg_memcpy(puVar3 + 3,param_1,sVar2,"util.c",uVar1,0x3f1);
  *param_2 = sVar2 + 3;
  return puVar3;
}

