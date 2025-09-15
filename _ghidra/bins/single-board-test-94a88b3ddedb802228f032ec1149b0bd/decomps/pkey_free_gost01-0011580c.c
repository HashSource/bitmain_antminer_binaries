
void pkey_free_gost01(int param_1)

{
  if (*(EC_KEY **)(param_1 + 0x14) != (EC_KEY *)0x0) {
    EC_KEY_free(*(EC_KEY **)(param_1 + 0x14));
    return;
  }
  return;
}

