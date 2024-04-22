
/* WARNING: Variable defined which should be unmapped: outlen-local */

int blake2b_init(blake2b_state *S,uint8_t outlen)

{
  int iVar1;
  undefined3 uStack_50;
  uint8_t outlen_local;
  blake2b_state *S_local;
  blake2b_param P [1];
  
  _uStack_50 = CONCAT13(outlen,uStack_50);
  if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else {
    P[0].key_length = '\0';
    P[0].fanout = '\x01';
    P[0].depth = '\x01';
    P[0].digest_length = outlen;
    store32(&P[0].leaf_length,0);
    store64(&P[0].node_offset,CONCAT44(S,_uStack_50));
    P[0].node_depth = '\0';
    P[0].inner_length = '\0';
    memset(P[0].reserved,0,0xe);
    memset(P[0].salt,0,0x10);
    memset(P[0].personal,0,0x10);
    iVar1 = blake2b_init_param(S,P);
  }
  return iVar1;
}

