
/* WARNING: Variable defined which should be unmapped: key-local */

int blake2b_init_key(blake2b_state *S,uint8_t outlen,void *key,uint8_t keylen)

{
  int iVar1;
  undefined4 uStack_d8;
  void *key_local;
  uint8_t keylen_local;
  uint8_t outlen_local;
  blake2b_state *S_local;
  uint8_t block [128];
  blake2b_param P [1];
  
  if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else if ((key == (void *)0x0) || ((keylen == '\0' || (0x40 < keylen)))) {
    iVar1 = -1;
  }
  else {
    P[0].fanout = '\x01';
    P[0].depth = '\x01';
    P[0].digest_length = outlen;
    P[0].key_length = keylen;
    store32(&P[0].leaf_length,0);
    store64(&P[0].node_offset,CONCAT44(key,uStack_d8));
    P[0].node_depth = '\0';
    P[0].inner_length = '\0';
    memset(P[0].reserved,0,0xe);
    memset(P[0].salt,0,0x10);
    memset(P[0].personal,0,0x10);
    iVar1 = blake2b_init_param(S,P);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      memset(block,0,0x80);
      memcpy(block,key,(uint)keylen);
      blake2b_update(S,block,CONCAT44(key,uStack_d8));
      secure_zero_memory(block,0x80);
      iVar1 = 0;
    }
  }
  return iVar1;
}

