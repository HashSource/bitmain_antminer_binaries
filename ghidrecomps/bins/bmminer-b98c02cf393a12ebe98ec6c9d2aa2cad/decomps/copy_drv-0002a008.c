
int copy_drv(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_0002a048;
  iVar2 = _cgmalloc(0x78,"cgminer.c",DAT_0002a048,0x2bc8);
  _cg_memcpy(iVar2,param_1,0x78,"cgminer.c",uVar1,0x2bc9);
  *(undefined *)(iVar2 + 100) = 1;
  return iVar2;
}

