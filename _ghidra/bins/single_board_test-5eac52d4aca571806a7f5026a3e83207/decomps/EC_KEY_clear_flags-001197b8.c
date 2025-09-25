
void EC_KEY_clear_flags(EC_KEY *key,int flags)

{
  *(uint *)(key + 0x24) = *(uint *)(key + 0x24) & ~flags;
  return;
}

