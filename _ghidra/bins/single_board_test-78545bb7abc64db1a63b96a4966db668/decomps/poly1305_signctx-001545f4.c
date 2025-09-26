
undefined4 poly1305_signctx(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  *param_3 = 0x10;
  if (param_2 != 0) {
    Poly1305_Final(iVar1 + 0x10);
  }
  return 1;
}

