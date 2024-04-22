
int EC_KEY_get_flags(EC_KEY *key)

{
  return *(int *)(key + 0x1c);
}

