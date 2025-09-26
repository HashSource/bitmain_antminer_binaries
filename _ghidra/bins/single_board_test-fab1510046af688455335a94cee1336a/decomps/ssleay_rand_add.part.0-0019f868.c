
void ssleay_rand_add_part_0(void *param_1,int param_2)

{
  bool bVar1;
  EVP_MD *type;
  int iVar2;
  size_t cnt;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  size_t cnt_00;
  byte *pbVar6;
  double in_d0;
  undefined4 local_64;
  undefined4 local_60;
  CRYPTO_THREADID local_5c;
  uint local_54;
  uint local_50;
  uint local_4c;
  EVP_MD_CTX EStack_48;
  
  if (crypto_lock_rand != 0) {
    CRYPTO_THREADID_current(&local_5c);
    CRYPTO_lock(5,0x13,"md_rand.c",0xdf);
    iVar5 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,&local_5c);
    CRYPTO_lock(6,0x13,"md_rand.c",0xe1);
    if (iVar5 == 0) {
      bVar1 = true;
      goto LAB_0019f898;
    }
  }
  CRYPTO_lock(9,0x12,"md_rand.c",0xe6);
  bVar1 = false;
LAB_0019f898:
  iVar5 = state_index;
  state_index = state_index + param_2;
  local_5c.ptr = (void *)md._0_4_;
  local_5c.val = md._4_4_;
  local_54 = md._8_4_;
  local_50 = md._12_4_;
  local_4c = md._16_4_;
  local_64 = (undefined4)md_count;
  local_60 = md_count._4_4_;
  if (state_index < 0x3ff) {
    if ((state_num < 0x3ff) && (state_num < state_index)) {
      state_num = state_index;
    }
  }
  else {
    state_num = 0x3ff;
    state_index = state_index % 0x3ff;
  }
  iVar2 = param_2 / 0x14;
  if (0 < param_2 % 0x14) {
    iVar2 = iVar2 + 1;
  }
  md_count._4_4_ = md_count._4_4_ + iVar2;
  if (!bVar1) {
    CRYPTO_lock(10,0x12,"md_rand.c",0x106);
  }
  EVP_MD_CTX_init(&EStack_48);
  if (0 < param_2) {
    iVar2 = 0;
    do {
      type = EVP_sha1();
      cnt_00 = param_2 - iVar2;
      EVP_DigestInit_ex(&EStack_48,type,(ENGINE *)0x0);
      if (0x13 < (int)cnt_00) {
        cnt_00 = 0x14;
      }
      EVP_DigestUpdate(&EStack_48,&local_5c,0x14);
      cnt = (cnt_00 + iVar5) - 0x3ff;
      if ((int)cnt < 1) {
        EVP_DigestUpdate(&EStack_48,state + iVar5,cnt_00);
      }
      else {
        EVP_DigestUpdate(&EStack_48,state + iVar5,cnt_00 - cnt);
        EVP_DigestUpdate(&EStack_48,state,cnt);
      }
      EVP_DigestUpdate(&EStack_48,param_1,cnt_00);
      EVP_DigestUpdate(&EStack_48,&local_64,8);
      EVP_DigestFinal_ex(&EStack_48,(uchar *)&local_5c,(uint *)0x0);
      local_60 = local_60 + 1;
      if (0 < (int)cnt_00) {
        pbVar3 = (byte *)((int)&local_60 + 3);
        pbVar6 = pbVar3 + cnt_00;
        iVar4 = iVar5;
        do {
          pbVar3 = pbVar3 + 1;
          iVar5 = iVar4 + 1;
          if (0x3fe < iVar5) {
            iVar5 = 0;
          }
          state[iVar4] = state[iVar4] ^ *pbVar3;
          iVar4 = iVar5;
        } while (pbVar3 != pbVar6);
      }
      iVar2 = iVar2 + 0x14;
      param_1 = (void *)((int)param_1 + cnt_00);
    } while (iVar2 < param_2);
  }
  EVP_MD_CTX_cleanup(&EStack_48);
  if (!bVar1) {
    CRYPTO_lock(9,0x12,"md_rand.c",0x137);
  }
  md._0_4_ = (uint)local_5c.ptr ^ md._0_4_;
  md._4_4_ = local_5c.val ^ md._4_4_;
  md._8_4_ = md._8_4_ ^ local_54;
  md._16_4_ = md._16_4_ ^ local_4c;
  md._12_4_ = md._12_4_ ^ local_50;
  if ((int)((uint)(entropy < 32.0) << 0x1f) < 0) {
    entropy = entropy + in_d0;
  }
  if (!bVar1) {
    CRYPTO_lock(10,0x12,"md_rand.c",0x144);
  }
  return;
}

