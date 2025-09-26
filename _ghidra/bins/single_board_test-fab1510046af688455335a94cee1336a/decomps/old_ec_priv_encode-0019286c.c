
void old_ec_priv_encode(int param_1,uchar **param_2)

{
  i2d_ECPrivateKey(*(EC_KEY **)(param_1 + 0x14),param_2);
  return;
}

