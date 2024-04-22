
BUF_MEM * mem_new(int param_1)

{
  BUF_MEM *pBVar1;
  
  pBVar1 = BUF_MEM_new();
  if (pBVar1 != (BUF_MEM *)0x0) {
    *(BUF_MEM **)(param_1 + 0x20) = pBVar1;
    pBVar1 = (BUF_MEM *)0x1;
    *(undefined4 *)(param_1 + 0x10) = 1;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  }
  return pBVar1;
}

