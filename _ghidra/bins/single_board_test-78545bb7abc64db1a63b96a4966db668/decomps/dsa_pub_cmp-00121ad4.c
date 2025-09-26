
bool dsa_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x14),
                 *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x14));
  return iVar1 == 0;
}

