
void EC_KEY_clear_flags(EC_KEY *key,int flags)

{
  *(uint *)(key + 0x1c) = *(uint *)(key + 0x1c) & ~flags;
  return;
}

