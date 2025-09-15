
int ec_GF2m_simple_is_at_infinity(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1 - *(uint *)(param_2 + 0x30);
  if (1 < *(uint *)(param_2 + 0x30)) {
    iVar1 = 0;
  }
  return iVar1;
}

