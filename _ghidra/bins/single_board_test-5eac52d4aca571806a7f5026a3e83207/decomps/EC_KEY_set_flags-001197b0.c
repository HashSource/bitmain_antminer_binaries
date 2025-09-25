
void EC_KEY_set_flags(EC_KEY *key,int flags)

{
  *(uint *)(key + 0x24) = flags | *(uint *)(key + 0x24);
  return;
}

