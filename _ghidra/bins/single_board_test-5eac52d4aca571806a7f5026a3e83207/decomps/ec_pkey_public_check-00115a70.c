
void ec_pkey_public_check(int param_1)

{
  EC_KEY_check_key(*(EC_KEY **)(param_1 + 0x18));
  return;
}

