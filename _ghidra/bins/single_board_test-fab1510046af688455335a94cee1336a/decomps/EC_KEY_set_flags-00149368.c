
void EC_KEY_set_flags(EC_KEY *key,int flags)

{
  *(uint *)(key + 0x1c) = flags | *(uint *)(key + 0x1c);
  return;
}

