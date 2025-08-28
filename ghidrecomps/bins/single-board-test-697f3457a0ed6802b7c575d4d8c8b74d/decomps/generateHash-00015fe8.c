
void generateHash(blake2b_state *S,uint32_t g,uint8_t *hash,size_t hashLen)

{
  size_t hashLen_local;
  uint8_t *hash_local;
  uint32_t g_local;
  blake2b_state *S_local;
  blake2b_state digest;
  uint32_t le_g;
  
  le_g = g;
  memcpy(&digest,S,0x168);
  blake2b_update(&digest,(uint8_t *)&le_g,4);
  blake2b_final(&digest,hash,(uint8_t)hashLen);
  return;
}

