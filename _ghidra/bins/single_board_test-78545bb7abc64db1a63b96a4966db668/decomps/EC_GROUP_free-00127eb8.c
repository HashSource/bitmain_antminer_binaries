
void EC_GROUP_free(EC_GROUP *group)

{
  if (group != (EC_GROUP *)0x0) {
    if (*(code **)(*(int *)group + 0xc) != (code *)0x0) {
      (**(code **)(*(int *)group + 0xc))();
    }
    EC_pre_comp_free(group);
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(group + 0x5c));
    EC_POINT_free(*(EC_POINT **)(group + 4));
    BN_free(*(BIGNUM **)(group + 8));
    BN_free(*(BIGNUM **)(group + 0xc));
    CRYPTO_free(*(void **)(group + 0x20));
    CRYPTO_free(group);
    return;
  }
  return;
}

