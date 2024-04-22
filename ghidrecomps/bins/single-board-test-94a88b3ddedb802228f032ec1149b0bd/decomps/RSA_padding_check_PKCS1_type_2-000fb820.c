
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  byte *__s;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (-1 < (tlen | fl)) {
    if ((fl <= rsa_len) && (10 < rsa_len)) {
      __s = (byte *)CRYPTO_malloc(rsa_len,DAT_000fb934,0xce);
      if (__s == (byte *)0x0) {
        ERR_put_error(4,0x71,0x41,DAT_000fb934,0xd0);
        return -1;
      }
      memset(__s,0,rsa_len);
      memcpy(__s + (rsa_len - fl),f,fl);
      uVar2 = 2;
      uVar3 = 0;
      uVar5 = 0;
      do {
        uVar4 = (int)(__s[uVar2] - 1 & ~(uint)__s[uVar2]) >> 0x1f;
        uVar1 = uVar4 & ~uVar3;
        uVar3 = uVar3 | uVar4;
        uVar4 = uVar1 & uVar2;
        uVar2 = uVar2 + 1;
        uVar5 = uVar5 & ~uVar1 | uVar4;
      } while (uVar2 != rsa_len);
      uVar2 = uVar2 - (uVar5 + 1);
      if (((int)(*__s - 1 & ~(uint)*__s & (__s[1] ^ 2) - 1 & ~(__s[1] ^ 2)) >> 0x1f &
           ~((int)((uVar5 - 10 ^ 10 | uVar5 ^ 10) ^ uVar5) >> 0x1f) &
          ~((int)(tlen ^ (tlen - uVar2 ^ uVar2 | uVar2 ^ tlen)) >> 0x1f)) == 0) {
        CRYPTO_free(__s);
      }
      else {
        memcpy(to,__s + uVar5 + 1,uVar2);
        CRYPTO_free(__s);
        if (uVar2 != 0xffffffff) {
          return uVar2;
        }
      }
    }
    ERR_put_error(4,0x71,0x9f,DAT_000fb934,0x111);
  }
  return -1;
}

