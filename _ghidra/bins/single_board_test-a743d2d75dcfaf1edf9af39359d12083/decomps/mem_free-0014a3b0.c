
undefined4 mem_free(int param_1)

{
  BUF_MEM *a;
  char *pcVar1;
  bool bVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  if (((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (a = *(BUF_MEM **)(param_1 + 0x20), a != (BUF_MEM *)0x0)) {
    pcVar1 = *(char **)(param_1 + 0x14);
    bVar2 = (int)pcVar1 << 0x16 < 0;
    if (bVar2) {
      pcVar1 = (char *)0x0;
    }
    if (bVar2) {
      a->data = pcVar1;
    }
    BUF_MEM_free(a);
    *(undefined4 *)(param_1 + 0x20) = 0;
    return 1;
  }
  return 1;
}

