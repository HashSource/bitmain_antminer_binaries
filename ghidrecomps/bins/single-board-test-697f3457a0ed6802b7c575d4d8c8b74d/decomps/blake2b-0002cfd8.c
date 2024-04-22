
/* WARNING: Variable defined which should be unmapped: outlen-local */

int blake2b(uint8_t *out,void *in,void *key,uint8_t outlen,uint64_t inlen,uint8_t keylen)

{
  int iVar1;
  undefined3 uStack_188;
  uint8_t outlen_local;
  void *key_local;
  void *in_local;
  uint8_t *out_local;
  blake2b_state S [1];
  
  _uStack_188 = CONCAT13(outlen,uStack_188);
  if ((in == (void *)0x0) && (inlen != 0)) {
    iVar1 = -1;
  }
  else if (out == (uint8_t *)0x0) {
    iVar1 = -1;
  }
  else if ((key == (void *)0x0) && (keylen != '\0')) {
    iVar1 = -1;
  }
  else if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else if (keylen < 0x41) {
    if (keylen == '\0') {
      iVar1 = blake2b_init(S,outlen);
      if (iVar1 < 0) {
        return -1;
      }
    }
    else {
      iVar1 = blake2b_init_key(S,outlen,key,keylen);
      if (iVar1 < 0) {
        return -1;
      }
    }
    blake2b_update(S,(uint8_t *)in,CONCAT44(key,_uStack_188));
    blake2b_final(S,out,outlen);
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

