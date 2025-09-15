
int copy_drv(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _cgmalloc(0x78,"cgminer.c",__func___15811,0x2bc8);
  _cg_memcpy(iVar1,param_1,0x78,"cgminer.c",__func___15811,0x2bc9);
  *(undefined1 *)(iVar1 + 100) = 1;
  return iVar1;
}

