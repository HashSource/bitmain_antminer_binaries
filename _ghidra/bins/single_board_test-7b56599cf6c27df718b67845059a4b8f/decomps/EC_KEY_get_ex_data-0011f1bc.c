
void EC_KEY_get_ex_data(int param_1,int param_2)

{
  CRYPTO_get_ex_data((CRYPTO_EX_DATA *)(param_1 + 0x28),param_2);
  return;
}

