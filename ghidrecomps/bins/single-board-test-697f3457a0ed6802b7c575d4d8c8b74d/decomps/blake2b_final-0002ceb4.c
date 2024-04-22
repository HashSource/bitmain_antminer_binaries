
/* WARNING: Variable defined which should be unmapped: outlen-local */

int blake2b_final(blake2b_state *S,uint8_t *out,uint8_t outlen)

{
  int iVar1;
  undefined7 uStack_68;
  uint8_t outlen_local;
  uint8_t *out_local;
  blake2b_state *S_local;
  uint8_t buffer [64];
  int i;
  
  memset(buffer,0,0x40);
  if (((out == (uint8_t *)0x0) || (outlen == '\0')) || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else {
    iVar1 = blake2b_is_lastblock(S);
    if (iVar1 == 0) {
      if (0x80 < S->buflen) {
        blake2b_increment_counter(S,CONCAT17(outlen,uStack_68));
        blake2b_compress(S,S->buf);
        S->buflen = S->buflen - 0x80;
        memcpy(S->buf,S->buf + 0x80,S->buflen);
      }
      blake2b_increment_counter(S,CONCAT17(outlen,uStack_68));
      blake2b_set_lastblock(S);
      memset(S->buf + S->buflen,0,0x100 - S->buflen);
      blake2b_compress(S,S->buf);
      for (i = 0; i < 8; i = i + 1) {
        store64(buffer + i * 8,CONCAT17(outlen,uStack_68));
      }
      memcpy(out,buffer,(uint)outlen);
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

