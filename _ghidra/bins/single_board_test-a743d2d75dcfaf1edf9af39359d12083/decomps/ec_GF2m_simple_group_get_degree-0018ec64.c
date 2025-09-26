
int ec_GF2m_simple_group_get_degree(int param_1)

{
  int iVar1;
  
  iVar1 = BN_num_bits((BIGNUM *)(param_1 + 0x48));
  return iVar1 + -1;
}

