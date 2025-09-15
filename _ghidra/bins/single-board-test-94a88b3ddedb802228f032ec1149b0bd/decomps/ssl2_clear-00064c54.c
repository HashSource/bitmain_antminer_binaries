
void ssl2_clear(undefined4 *param_1)

{
  void *__s;
  undefined4 uVar1;
  undefined4 uVar2;
  
  __s = (void *)param_1[0x15];
  uVar1 = *(undefined4 *)((int)__s + 0x30);
  uVar2 = *(undefined4 *)((int)__s + 0x34);
  memset(__s,0,0x120);
  *(undefined4 *)((int)__s + 0x34) = uVar2;
  *(undefined4 *)((int)__s + 0x30) = uVar1;
  *(undefined4 *)((int)__s + 4) = 1;
  param_1[0x13] = uVar1;
  *param_1 = 2;
  param_1[0x14] = 0;
  return;
}

