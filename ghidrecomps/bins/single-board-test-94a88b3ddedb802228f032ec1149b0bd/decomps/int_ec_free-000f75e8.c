
void int_ec_free(int param_1)

{
  EC_KEY_free(*(EC_KEY **)(param_1 + 0x14));
  return;
}

