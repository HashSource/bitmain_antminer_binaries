
BIGNUM * bnrand_part_0(int param_1,BIGNUM *param_2,int param_3,int param_4,int param_5)

{
  byte *buf;
  int iVar1;
  BIGNUM *pBVar2;
  byte extraout_r1;
  byte extraout_r1_00;
  byte extraout_r1_01;
  byte bVar3;
  uint uVar4;
  size_t len;
  size_t sVar5;
  byte *pbVar6;
  undefined4 in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  byte local_30 [4];
  time_t atStack_2c [2];
  
  iVar1 = param_3 + 0xe;
  if (-1 < param_3 + 7) {
    iVar1 = param_3 + 7;
  }
  len = iVar1 >> 3;
  buf = (byte *)CRYPTO_malloc(len,DAT_000f23f8,0x8a);
  if (buf == (byte *)0x0) {
    ERR_put_error(3,0x7f,0x41,DAT_000f23f8,0x8c);
    return (BIGNUM *)0x0;
  }
  time(atStack_2c);
  RAND_add(atStack_2c,4,(double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
  if (param_1 == 0) {
    iVar1 = RAND_bytes(buf,len);
    pBVar2 = (BIGNUM *)0x0;
    bVar3 = extraout_r1;
    if (iVar1 < 1) goto LAB_000f2346;
  }
  else {
    iVar1 = RAND_pseudo_bytes(buf,len);
    if (iVar1 == -1) {
LAB_000f23b8:
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_000f2346;
    }
    bVar3 = extraout_r1_00;
    if ((param_1 == 2) && (0 < (int)len)) {
      sVar5 = 0;
      pbVar6 = buf + -1;
      do {
        iVar1 = RAND_pseudo_bytes(local_30,1);
        if (iVar1 < 0) goto LAB_000f23b8;
        if (((int)((uint)local_30[0] << 0x18) < 0) && (sVar5 != 0)) {
          pbVar6[1] = *pbVar6;
        }
        else if (local_30[0] < 0x2a) {
          pbVar6[1] = 0;
        }
        else if (local_30[0] < 0x54) {
          pbVar6[1] = 0xff;
        }
        sVar5 = sVar5 + 1;
        pbVar6 = pbVar6 + 1;
        bVar3 = extraout_r1_01;
      } while (sVar5 != len);
    }
  }
  if (param_4 < 0) {
    bVar3 = *buf;
  }
  uVar4 = (param_3 + -1) % 8;
  if (param_4 >= 0) {
    if (param_4 == 0) {
      bVar3 = (byte)(1 << (uVar4 & 0xff)) | *buf;
    }
    else if (uVar4 == 0) {
      bVar3 = 1;
      buf[1] = buf[1] | 0x80;
    }
    else {
      bVar3 = *buf | (byte)(3 << (uVar4 - 1 & 0xff));
    }
  }
  *buf = bVar3 & ~(byte)(0xff << (uVar4 + 1 & 0xff));
  if (param_5 != 0) {
    buf[len - 1] = buf[len - 1] | 1;
  }
  pBVar2 = BN_bin2bn(buf,len,param_2);
  if (pBVar2 != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)0x1;
  }
LAB_000f2346:
  OPENSSL_cleanse(buf,len);
  CRYPTO_free(buf);
  return pBVar2;
}

