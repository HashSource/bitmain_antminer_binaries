
BIGNUM * bnrand_part_0(int param_1,BIGNUM *param_2,int param_3,int param_4,int param_5)

{
  byte *buf;
  int iVar1;
  int iVar2;
  BIGNUM *pBVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte local_29 [5];
  
  iVar7 = param_3 + 0xe;
  if (-1 < param_3 + 7) {
    iVar7 = param_3 + 7;
  }
  iVar7 = iVar7 >> 3;
  buf = (byte *)CRYPTO_malloc(iVar7,"crypto/bn/bn_rand.c",0x27);
  if (buf == (byte *)0x0) {
    ERR_put_error(3,0x7f,0x41,"crypto/bn/bn_rand.c",0x29);
    pBVar3 = (BIGNUM *)0x0;
    goto LAB_00189cd4;
  }
  if (param_1 == 0) {
    iVar1 = RAND_bytes(buf,iVar7);
    if (iVar1 < 1) goto LAB_00189cd2;
  }
  else {
    iVar1 = RAND_priv_bytes();
    if (iVar1 < 1) {
LAB_00189cd2:
      pBVar3 = (BIGNUM *)0x0;
      goto LAB_00189cd4;
    }
    if ((param_1 == 1) && (0 < iVar7)) {
      iVar1 = 0;
      pbVar8 = buf + -1;
      do {
        iVar2 = RAND_bytes(local_29,1);
        if (iVar2 < 1) goto LAB_00189cd2;
        if ((int)((uint)local_29[0] << 0x18) < 0) {
          if (iVar1 != 0) {
            pbVar8[1] = *pbVar8;
          }
        }
        else if (local_29[0] < 0x2a) {
          pbVar8[1] = 0;
        }
        else if (local_29[0] < 0x54) {
          pbVar8[1] = 0xff;
        }
        iVar1 = iVar1 + 1;
        pbVar8 = pbVar8 + 1;
      } while (iVar7 != iVar1);
    }
  }
  uVar5 = param_3 - 1;
  uVar6 = uVar5 & 7;
  if ((int)uVar5 < 1) {
    uVar6 = -(-uVar5 & 7);
  }
  if (param_4 < 0) {
    bVar4 = *buf;
  }
  else if (param_4 == 0) {
    bVar4 = (byte)(1 << (uVar6 & 0xff)) | *buf;
  }
  else if (uVar6 == 0) {
    bVar4 = 1;
    buf[1] = buf[1] | 0x80;
  }
  else {
    bVar4 = *buf | (byte)(3 << (uVar6 - 1 & 0xff));
  }
  *buf = bVar4 & ~(byte)(0xff << (uVar6 + 1 & 0xff));
  if (param_5 != 0) {
    buf[iVar7 + -1] = buf[iVar7 + -1] | 1;
  }
  pBVar3 = BN_bin2bn(buf,iVar7,param_2);
  if (pBVar3 != (BIGNUM *)0x0) {
    pBVar3 = (BIGNUM *)0x1;
  }
LAB_00189cd4:
  CRYPTO_clear_free(buf,iVar7,"crypto/bn/bn_rand.c",0x58);
  return pBVar3;
}

