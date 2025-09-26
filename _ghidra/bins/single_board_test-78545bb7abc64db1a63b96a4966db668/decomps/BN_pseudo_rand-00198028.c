
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  int num;
  byte *buf;
  int iVar1;
  BIGNUM *pBVar2;
  byte bVar3;
  uint uVar4;
  
  if (bits == 0) {
    if (bottom == 0 && top == -1) {
      BN_set_word(rnd,0);
      return 1;
    }
  }
  else if ((-1 < bits) && (top < 1 || bits != 1)) {
    num = bits + 7 >> 3;
    uVar4 = bits - 1U & 7;
    buf = (byte *)CRYPTO_malloc(num,"crypto/bn/bn_rand.c",0x27);
    if (buf == (byte *)0x0) {
      ERR_put_error(3,0x7f,0x41,"crypto/bn/bn_rand.c",0x29);
      pBVar2 = (BIGNUM *)0x0;
    }
    else {
      iVar1 = RAND_bytes(buf,num);
      pBVar2 = (BIGNUM *)0x0;
      if (0 < iVar1) {
        if (top < 0) {
          bVar3 = *buf;
        }
        else if (top == 0) {
          bVar3 = (byte)(1 << uVar4) | *buf;
        }
        else if (uVar4 == 0) {
          bVar3 = 1;
          buf[1] = buf[1] | 0x80;
        }
        else {
          bVar3 = *buf | (byte)(3 << (uVar4 - 1 & 0xff));
        }
        *buf = bVar3 & ~(byte)(0xff << uVar4 + 1);
        if (bottom != 0) {
          buf[num + -1] = buf[num + -1] | 1;
        }
        pBVar2 = BN_bin2bn(buf,num,rnd);
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
      }
    }
    CRYPTO_clear_free(buf,num,"crypto/bn/bn_rand.c",0x58);
    return (int)pBVar2;
  }
  ERR_put_error(3,0x7f,0x76,"crypto/bn/bn_rand.c",0x5d);
  return 0;
}

