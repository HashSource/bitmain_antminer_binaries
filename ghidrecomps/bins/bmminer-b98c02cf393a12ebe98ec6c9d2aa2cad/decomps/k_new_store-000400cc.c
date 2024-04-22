
undefined4 * k_new_store(undefined4 *param_1)

{
  undefined uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char acStack_810 [2048];
  
  puVar2 = (undefined4 *)calloc(1,0x40);
  if (puVar2 == (undefined4 *)0x0) {
    snprintf(acStack_810,0x800,"Failed to calloc store for %s in %s %s():%d",*param_1,"klist.c",
             DAT_00040134,0x55);
    _applog(3,acStack_810,1);
    _quit(1);
  }
  uVar3 = *param_1;
  uVar1 = *(undefined *)(param_1 + 0xb);
  puVar2[2] = param_1[2];
  *puVar2 = uVar3;
  *(undefined *)(puVar2 + 0xb) = uVar1;
  *(undefined *)(puVar2 + 1) = 1;
  return puVar2;
}

