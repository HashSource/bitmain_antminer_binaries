
void ec_key_simple_generate_public_key(int param_1)

{
  EC_POINT_mul(*(EC_GROUP **)(param_1 + 0xc),*(EC_POINT **)(param_1 + 0x10),
               *(BIGNUM **)(param_1 + 0x14),(EC_POINT *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
  return;
}

