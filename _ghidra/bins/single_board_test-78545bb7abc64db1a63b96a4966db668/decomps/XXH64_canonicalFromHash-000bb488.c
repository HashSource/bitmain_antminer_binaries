
void XXH64_canonicalFromHash(XXH64_canonical_t *dst,XXH64_hash_t hash)

{
  int iVar1;
  XXH64_hash_t hash_local;
  XXH64_canonical_t *dst_local;
  
  hash_local = hash;
  dst_local = dst;
  iVar1 = XXH_isLittleEndian();
  if (iVar1 != 0) {
    hash_local = CONCAT44((uint)hash_local << 0x18 | ((uint)hash_local >> 8 & 0xff) << 0x10 |
                          ((uint)hash_local >> 0x10 & 0xff) << 8 | (uint)hash_local >> 0x18,
                          hash_local._4_4_ << 0x18 | (hash_local._4_4_ >> 8 & 0xff) << 0x10 |
                          (hash_local._4_4_ >> 0x10 & 0xff) << 8 | hash_local._4_4_ >> 0x18);
  }
  memcpy(dst_local,&hash_local,8);
  return;
}

