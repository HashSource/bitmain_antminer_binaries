
undefined4 shake_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *__s;
  
  uVar3 = *(uint *)(*param_1 + 0x24);
  if (0xa8 < uVar3) {
    return 0;
  }
  __s = (void *)param_1[3];
  memset(__s,0,200);
  iVar1 = *param_1;
  *(uint *)((int)__s + 200) = uVar3;
  *(undefined4 *)((int)__s + 0xd0) = 0;
  uVar2 = *(undefined4 *)(iVar1 + 8);
  *(undefined1 *)((int)__s + 0x17c) = 0x1f;
  *(undefined4 *)((int)__s + 0xcc) = uVar2;
  return 1;
}

