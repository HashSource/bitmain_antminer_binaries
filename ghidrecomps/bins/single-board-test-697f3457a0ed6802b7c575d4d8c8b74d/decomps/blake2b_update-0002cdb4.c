
/* WARNING: Variable defined which should be unmapped: inlen-local */

int blake2b_update(blake2b_state *S,uint8_t *in,uint64_t inlen)

{
  uint in_r2;
  uint in_r3;
  size_t sVar1;
  uint __n;
  bool bVar2;
  uint64_t inlen_local;
  uint8_t *in_local;
  blake2b_state *S_local;
  size_t fill;
  size_t left;
  
  inlen_local._0_4_ = in_r2;
  inlen_local._4_4_ = in_r3;
  in_local = in;
  while (((uint)inlen_local | inlen_local._4_4_) != 0) {
    sVar1 = S->buflen;
    __n = 0x100 - sVar1;
    bVar2 = inlen_local._4_4_ == 0;
    if (inlen_local._4_4_ == 0) {
      bVar2 = (uint)inlen_local <= __n;
    }
    if (bVar2) {
      memcpy(S->buf + sVar1,in_local,(uint)inlen_local);
      S->buflen = S->buflen + (uint)inlen_local;
      in_local = in_local + (uint)inlen_local;
      inlen_local._0_4_ = 0;
      inlen_local._4_4_ = 0;
    }
    else {
      memcpy(S->buf + sVar1,in_local,__n);
      S->buflen = S->buflen + __n;
      blake2b_increment_counter(S,CONCAT44(inlen_local._4_4_,(uint)inlen_local));
      blake2b_compress(S,S->buf);
      memcpy(S->buf,S->buf + 0x80,0x80);
      S->buflen = S->buflen - 0x80;
      in_local = in_local + __n;
      bVar2 = (uint)inlen_local < __n;
      inlen_local._0_4_ = (uint)inlen_local - __n;
      inlen_local._4_4_ = inlen_local._4_4_ - bVar2;
    }
  }
  return 0;
}

