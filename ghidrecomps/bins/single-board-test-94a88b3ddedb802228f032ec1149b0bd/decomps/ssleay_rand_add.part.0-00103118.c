
void ssleay_rand_add_part_0(void *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  EVP_MD *type;
  size_t cnt;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  size_t cnt_00;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  double in_d0;
  int local_64;
  undefined4 local_60;
  CRYPTO_THREADID local_5c;
  uint local_54;
  uint local_50;
  uint local_4c;
  EVP_MD_CTX EStack_48;
  
  piVar3 = DAT_00103390;
  if (*DAT_00103390 != 0) {
    CRYPTO_THREADID_current(&local_5c);
    CRYPTO_lock(5,0x13,DAT_00103394,0xdf);
    iVar6 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(piVar3 + 1),&local_5c);
    CRYPTO_lock(6,0x13,DAT_00103394,0xe1);
    if (iVar6 == 0) {
      bVar2 = true;
      goto LAB_00103148;
    }
  }
  CRYPTO_lock(9,0x12,DAT_00103394,0xe6);
  bVar2 = false;
LAB_00103148:
  piVar4 = DAT_00103390;
  iVar6 = piVar3[0x10c];
  local_5c.ptr = (void *)DAT_00103390[0x10d];
  local_5c.val = DAT_00103390[0x10e];
  local_54 = DAT_00103390[0x10f];
  local_50 = DAT_00103390[0x110];
  puVar10 = (uint *)(DAT_00103390 + 0x111);
  iVar8 = iVar6 + param_2;
  piVar3[0x10c] = iVar8;
  local_4c = *puVar10;
  local_64 = piVar3[0x112];
  local_60 = piVar3[0x113];
  if (iVar8 < 0x3ff) {
    if ((piVar4[0x10b] < 0x3ff) && (piVar4[0x10b] < iVar8)) {
      piVar4[0x10b] = iVar8;
    }
  }
  else {
    piVar4[0x10b] = 0x3ff;
    piVar4[0x10c] = iVar8 % 0x3ff;
  }
  iVar8 = param_2 / 0x14;
  if (0 < param_2 % 0x14) {
    iVar8 = iVar8 + 1;
  }
  piVar3[0x113] = local_60 + iVar8;
  if (!bVar2) {
    CRYPTO_lock(10,0x12,DAT_00103394,0x106);
  }
  EVP_MD_CTX_init(&EStack_48);
  if (0 < param_2) {
    iVar8 = 0;
    do {
      type = EVP_sha1();
      cnt_00 = param_2 - iVar8;
      EVP_DigestInit_ex(&EStack_48,type,(ENGINE *)0x0);
      if (0x13 < (int)cnt_00) {
        cnt_00 = 0x14;
      }
      EVP_DigestUpdate(&EStack_48,&local_5c,0x14);
      cnt = (cnt_00 + iVar6) - 0x3ff;
      if ((int)cnt < 1) {
        EVP_DigestUpdate(&EStack_48,(void *)((int)DAT_00103398 + iVar6),cnt_00);
      }
      else {
        EVP_DigestUpdate(&EStack_48,(void *)((int)DAT_00103398 + iVar6),cnt_00 - cnt);
        EVP_DigestUpdate(&EStack_48,DAT_00103398,cnt);
      }
      EVP_DigestUpdate(&EStack_48,param_1,cnt_00);
      EVP_DigestUpdate(&EStack_48,&local_64,8);
      EVP_DigestFinal_ex(&EStack_48,(uchar *)&local_5c,(uint *)0x0);
      local_60 = local_60 + 1;
      if (0 < (int)cnt_00) {
        pbVar5 = (byte *)((int)&local_60 + 3);
        pbVar9 = pbVar5 + cnt_00;
        iVar7 = iVar6;
        do {
          pbVar5 = pbVar5 + 1;
          iVar6 = iVar7 + 1;
          if (0x3fe < iVar6) {
            iVar6 = 0;
          }
          *(byte *)((int)piVar3 + iVar7 + 0x18) = *(byte *)((int)piVar3 + iVar7 + 0x18) ^ *pbVar5;
          iVar7 = iVar6;
        } while (pbVar5 != pbVar9);
      }
      iVar8 = iVar8 + 0x14;
      param_1 = (void *)((int)param_1 + cnt_00);
    } while (iVar8 < param_2);
  }
  EVP_MD_CTX_cleanup(&EStack_48);
  if (!bVar2) {
    CRYPTO_lock(9,0x12,DAT_00103394,0x137);
  }
  bVar1 = *(double *)(piVar3 + 4) < DAT_00103388;
  piVar3[0x10d] = (uint)local_5c.ptr ^ piVar3[0x10d];
  piVar3[0x10e] = local_5c.val ^ piVar3[0x10e];
  piVar3[0x10f] = piVar3[0x10f] ^ local_54;
  piVar3[0x110] = piVar3[0x110] ^ local_50;
  piVar3[0x111] = piVar3[0x111] ^ local_4c;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    *(double *)(DAT_00103390 + 4) = *(double *)(piVar3 + 4) + in_d0;
  }
  if (!bVar2) {
    CRYPTO_lock(10,0x12,DAT_00103394,0x144);
  }
  return;
}

