
int make_clone(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = make_work();
  _copy_work(iVar1,param_1,0);
  *(undefined *)(iVar1 + 0x111) = 1;
  cgtime(iVar1 + 0x1a0);
  *(undefined *)(iVar1 + 0x118) = 0;
  *(undefined *)(iVar1 + 0x11a) = 0;
  *(int *)(iVar1 + 0x108) = *(int *)(iVar1 + 0x108) + -1;
  return iVar1;
}

