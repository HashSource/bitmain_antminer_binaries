
int ec_bits(int param_1)

{
  BIGNUM *order;
  EC_GROUP *group;
  int iVar1;
  
  order = BN_new();
  if (order != (BIGNUM *)0x0) {
    group = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x14));
    iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)0x0);
    if (iVar1 != 0) {
      iVar1 = BN_num_bits(order);
      BN_free(order);
      return iVar1;
    }
  }
  ERR_clear_error();
  return 0;
}

