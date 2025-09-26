
void ssl3_get_cipher_by_char(byte *param_1)

{
  ssl3_get_cipher_by_id(param_1[1] | 0x3000000 | (uint)*param_1 << 8);
  return;
}

