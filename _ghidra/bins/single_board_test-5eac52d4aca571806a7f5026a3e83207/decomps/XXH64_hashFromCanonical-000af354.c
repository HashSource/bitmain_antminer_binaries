
XXH64_hash_t XXH64_hashFromCanonical(XXH64_canonical_t *src)

{
  U64 UVar1;
  XXH64_canonical_t *src_local;
  
  UVar1 = XXH_readBE64(src);
  return UVar1;
}

