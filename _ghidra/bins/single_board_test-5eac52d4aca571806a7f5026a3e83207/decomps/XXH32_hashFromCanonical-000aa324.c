
XXH32_hash_t XXH32_hashFromCanonical(XXH32_canonical_t *src)

{
  U32 UVar1;
  XXH32_canonical_t *src_local;
  
  UVar1 = XXH_readBE32(src);
  return UVar1;
}

