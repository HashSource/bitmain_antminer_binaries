
undefined4 inflateGetDictionary(int param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) {
    return 0xfffffffe;
  }
  if ((*(int *)(iVar1 + 0x2c) != 0) && (param_2 != (void *)0x0)) {
    memcpy(param_2,(void *)(*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x30)),
           *(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x30));
    memcpy((void *)((int)param_2 + (*(int *)(iVar1 + 0x2c) - *(size_t *)(iVar1 + 0x30))),
           *(void **)(iVar1 + 0x34),*(size_t *)(iVar1 + 0x30));
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar1 + 0x2c);
    return 0;
  }
  return 0;
}

