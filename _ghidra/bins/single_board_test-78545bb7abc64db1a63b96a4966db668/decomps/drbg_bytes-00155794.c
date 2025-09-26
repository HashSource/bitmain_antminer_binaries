
void drbg_bytes(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = RAND_DRBG_get0_public();
  if (iVar1 != 0) {
    RAND_DRBG_bytes(iVar1,param_1,param_2,param_4);
    return;
  }
  return;
}

