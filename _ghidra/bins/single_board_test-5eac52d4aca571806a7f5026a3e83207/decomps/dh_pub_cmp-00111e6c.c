
bool dh_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 8),
                 *(BIGNUM **)(*(int *)(param_2 + 0x18) + 8));
  if (((iVar1 == 0) &&
      (iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 0xc),
                      *(BIGNUM **)(*(int *)(param_2 + 0x18) + 0xc)), iVar1 == 0)) &&
     ((*(undefined1 **)(param_1 + 0xc) != &dhx_asn1_meth ||
      (iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x24),
                      *(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x24)), iVar1 == 0)))) {
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x14),
                   *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x14));
    return iVar1 == 0;
  }
  return false;
}

