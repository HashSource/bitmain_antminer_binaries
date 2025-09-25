
void ec_bits(int param_1)

{
  EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x18));
  EC_GROUP_order_bits();
  return;
}

