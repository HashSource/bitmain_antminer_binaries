
void XXH32_canonicalFromHash(XXH32_canonical_t *dst,XXH32_hash_t hash)

{
  int iVar1;
  XXH32_hash_t hash_local;
  XXH32_canonical_t *dst_local;
  
  hash_local = hash;
  dst_local = dst;
  iVar1 = XXH_isLittleEndian();
  if (iVar1 != 0) {
    hash_local = hash_local << 0x18 | (hash_local >> 8 & 0xff) << 0x10 |
                 (hash_local >> 0x10 & 0xff) << 8 | hash_local >> 0x18;
  }
  memcpy(dst_local,&hash_local,4);
  return;
}

