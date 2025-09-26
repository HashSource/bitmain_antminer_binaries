
uint EC_KEY_get_enc_flags(EC_KEY *key)

{
  return *(uint *)(key + 0x10);
}

