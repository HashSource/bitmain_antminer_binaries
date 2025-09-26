
int pkey_cmac_copy(int param_1,int param_2)

{
  CMAC_CTX *out;
  int iVar1;
  CMAC_CTX *in;
  
  out = CMAC_CTX_new();
  *(CMAC_CTX **)(param_1 + 0x14) = out;
  if (out != (CMAC_CTX *)0x0) {
    in = *(CMAC_CTX **)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = CMAC_CTX_copy(out,in);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}

