
void BUF_MEM_new_ex(size_t param_1)

{
  BUF_MEM *pBVar1;
  
  pBVar1 = BUF_MEM_new();
  if (pBVar1 != (BUF_MEM *)0x0) {
    pBVar1[1].length = param_1;
  }
  return;
}

