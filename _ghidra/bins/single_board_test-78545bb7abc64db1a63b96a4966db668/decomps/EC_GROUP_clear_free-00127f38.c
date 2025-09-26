
void EC_GROUP_clear_free(EC_GROUP *group)

{
  code *pcVar1;
  
  if (group == (EC_GROUP *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*(int *)group + 0x10);
  if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*(int *)group + 0xc), pcVar1 != (code *)0x0))
  {
    (*pcVar1)();
  }
  EC_pre_comp_free(group);
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0x5c));
  EC_POINT_clear_free(*(EC_POINT **)(group + 4));
  BN_clear_free(*(BIGNUM **)(group + 8));
  BN_clear_free(*(BIGNUM **)(group + 0xc));
  CRYPTO_clear_free(*(undefined4 *)(group + 0x20),*(undefined4 *)(group + 0x24),"crypto/ec/ec_lib.c"
                    ,0x7e);
  CRYPTO_clear_free(group,0x68,"crypto/ec/ec_lib.c",0x7f);
  return;
}

