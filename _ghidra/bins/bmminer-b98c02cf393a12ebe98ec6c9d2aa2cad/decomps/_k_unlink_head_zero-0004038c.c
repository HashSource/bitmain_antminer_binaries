
int _k_unlink_head_zero(int param_1)

{
  int iVar1;
  
  iVar1 = _k_unlink_head();
  if (iVar1 != 0) {
    memset(*(void **)(iVar1 + 0xc),0,*(size_t *)(param_1 + 0x14));
  }
  return iVar1;
}

