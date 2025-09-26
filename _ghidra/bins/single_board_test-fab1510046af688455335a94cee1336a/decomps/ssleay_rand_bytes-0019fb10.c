
undefined4 ssleay_rand_bytes(undefined1 *param_1,size_t param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  EVP_MD *pEVar3;
  int extraout_r1;
  byte bVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  size_t cnt;
  size_t cnt_00;
  int iVar10;
  bool bVar11;
  __pid_t local_64;
  int local_60;
  undefined4 local_5c;
  byte local_58;
  byte bStack_57;
  byte bStack_56;
  byte bStack_55;
  byte local_54;
  byte local_53;
  byte local_52;
  byte local_51;
  byte local_50;
  byte local_4f;
  undefined1 local_4e;
  byte local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  EVP_MD_CTX EStack_40;
  
  local_64 = getpid();
  if (0 < (int)param_2) {
    EVP_MD_CTX_init(&EStack_40);
    if (param_4 != 0) {
      CRYPTO_lock(9,0x12,"md_rand.c",0x182);
    }
    CRYPTO_lock(9,0x13,"md_rand.c",0x185);
    CRYPTO_THREADID_current((CRYPTO_THREADID *)&locking_threadid);
    CRYPTO_lock(10,0x13,"md_rand.c",0x187);
    crypto_lock_rand = 1;
    if (initialized == 0) {
      RAND_poll();
      initialized = 1;
    }
    bVar1 = 32.0 <= entropy;
    if (!bVar1) {
      entropy = entropy - (double)(longlong)(int)param_2;
      if ((int)((uint)(entropy < 0.0) << 0x1f) < 0) {
        entropy = 0.0;
      }
    }
    if (stirred_pool_10802 == 0) {
      iVar8 = 0x34;
      do {
        ssleay_rand_add_part_0(0,"....................",0x14);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      if (bVar1) {
        stirred_pool_10802 = 1;
      }
    }
    iVar5 = (int)md_count;
    iVar8 = state_index;
    iVar2 = state_num;
    iVar10 = ((int)(param_2 - 1) / 10 + 1) * 10 + state_index;
    _local_58 = md._0_4_;
    _local_54 = md._4_4_;
    _local_50 = md._8_4_;
    _local_4c = md._12_4_;
    _local_48 = md._16_4_;
    local_60 = (int)md_count;
    local_5c = md_count._4_4_;
    if (state_num < iVar10) {
      __aeabi_idivmod(iVar10,state_num);
      iVar10 = extraout_r1;
    }
    state_index = iVar10;
    md_count._0_4_ = iVar5 + 1;
    crypto_lock_rand = 0;
    if (param_4 != 0) {
      CRYPTO_lock(10,0x12,"md_rand.c",0x1d2);
    }
    do {
      pEVar3 = EVP_sha1();
      cnt = param_2;
      if (9 < (int)param_2) {
        cnt = 10;
      }
      EVP_DigestInit_ex(&EStack_40,pEVar3,(ENGINE *)0x0);
      param_2 = param_2 - cnt;
      if (local_64 != 0) {
        EVP_DigestUpdate(&EStack_40,&local_64,4);
        local_64 = 0;
      }
      EVP_DigestUpdate(&EStack_40,&local_58,0x14);
      EVP_DigestUpdate(&EStack_40,&local_60,8);
      EVP_DigestUpdate(&EStack_40,param_1,cnt);
      cnt_00 = (iVar8 + 10) - iVar2;
      if ((int)cnt_00 < 1) {
        EVP_DigestUpdate(&EStack_40,state + iVar8,10);
      }
      else {
        EVP_DigestUpdate(&EStack_40,state + iVar8,10 - cnt_00);
        EVP_DigestUpdate(&EStack_40,state,cnt_00);
      }
      EVP_DigestFinal_ex(&EStack_40,&local_58,(uint *)0x0);
      iVar5 = iVar8 + 1;
      if (iVar5 < iVar2) {
        iVar9 = iVar8 + 2;
        iVar10 = iVar5;
      }
      else {
        iVar9 = iVar8;
        iVar10 = 0;
      }
      state[iVar8] = state[iVar8] ^ local_58;
      if (iVar2 <= iVar5) {
        iVar9 = 1;
      }
      iVar5 = iVar9;
      if (iVar2 <= iVar9) {
        iVar5 = 0;
      }
      *param_1 = local_4e;
      bVar4 = state[iVar10];
      state[iVar10] = bVar4 ^ bStack_57;
      if (iVar9 < iVar2) {
        iVar10 = iVar5 + 1;
      }
      else {
        iVar10 = 1;
      }
      bVar11 = cnt == 1;
      bVar4 = bVar4 ^ bStack_57;
      if (!bVar11) {
        bVar4 = local_4d;
      }
      iVar8 = (int)&crypto_lock_rand + iVar5;
      if (bVar11) {
        param_1 = param_1 + 1;
      }
      if (!bVar11) {
        param_1[1] = bVar4;
        param_1 = param_1 + 2;
      }
      iVar9 = iVar10;
      if (iVar2 <= iVar10) {
        iVar9 = 0;
      }
      state[iVar5] = state[iVar5] ^ bStack_56;
      if (iVar10 < iVar2) {
        iVar5 = iVar9 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar6 = param_1;
      if (2 < (int)cnt) {
        puVar6 = param_1 + 1;
        *param_1 = local_4c;
      }
      iVar10 = iVar5;
      if (iVar2 <= iVar5) {
        iVar10 = 0;
      }
      state[iVar9] = state[iVar9] ^ bStack_55;
      if (iVar5 < iVar2) {
        iVar5 = iVar10 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar7 = puVar6;
      if (3 < (int)cnt) {
        puVar7 = puVar6 + 1;
        *puVar6 = local_4b;
      }
      iVar9 = iVar5;
      if (iVar2 <= iVar5) {
        iVar9 = 0;
      }
      state[iVar10] = state[iVar10] ^ local_54;
      if (iVar5 < iVar2) {
        iVar5 = iVar9 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar6 = puVar7;
      if (4 < (int)cnt) {
        puVar6 = puVar7 + 1;
        *puVar7 = local_4a;
      }
      iVar10 = iVar5;
      if (iVar2 <= iVar5) {
        iVar10 = 0;
      }
      state[iVar9] = state[iVar9] ^ local_53;
      if (iVar5 < iVar2) {
        iVar5 = iVar10 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar7 = puVar6;
      if (5 < (int)cnt) {
        puVar7 = puVar6 + 1;
        *puVar6 = local_49;
      }
      iVar9 = iVar5;
      if (iVar2 <= iVar5) {
        iVar9 = 0;
      }
      state[iVar10] = state[iVar10] ^ local_52;
      if (iVar5 < iVar2) {
        iVar5 = iVar9 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar6 = puVar7;
      if (6 < (int)cnt) {
        puVar6 = puVar7 + 1;
        *puVar7 = local_48;
      }
      iVar10 = iVar5;
      if (iVar2 <= iVar5) {
        iVar10 = 0;
      }
      state[iVar9] = state[iVar9] ^ local_51;
      if (iVar5 < iVar2) {
        iVar5 = iVar10 + 1;
      }
      else {
        iVar5 = 1;
      }
      puVar7 = puVar6;
      if (7 < (int)cnt) {
        puVar7 = puVar6 + 1;
        *puVar6 = uStack_47;
      }
      if (iVar5 < iVar2) {
        iVar8 = iVar5 + 1;
      }
      if (iVar2 <= iVar5) {
        iVar8 = 1;
        iVar5 = 0;
      }
      state[iVar10] = state[iVar10] ^ local_50;
      puVar6 = puVar7;
      if (8 < (int)cnt) {
        puVar6 = puVar7 + 1;
        *puVar7 = uStack_46;
      }
      if (iVar2 <= iVar8) {
        iVar8 = 0;
      }
      state[iVar5] = state[iVar5] ^ local_4f;
      param_1 = puVar6;
      if (cnt == 10) {
        param_1 = puVar6 + 1;
        *puVar6 = uStack_45;
      }
    } while (0 < (int)param_2);
    pEVar3 = EVP_sha1();
    EVP_DigestInit_ex(&EStack_40,pEVar3,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_40,&local_60,8);
    EVP_DigestUpdate(&EStack_40,&local_58,0x14);
    if (param_4 == 0) {
      EVP_DigestUpdate(&EStack_40,md,0x14);
      EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0);
    }
    else {
      CRYPTO_lock(9,0x12,"md_rand.c",0x203);
      EVP_DigestUpdate(&EStack_40,md,0x14);
      EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0);
      CRYPTO_lock(10,0x12,"md_rand.c",0x207);
    }
    EVP_MD_CTX_cleanup(&EStack_40);
    if (!bVar1) {
      if (param_3 != 0) {
        return 0;
      }
      ERR_put_error(0x24,100,100,"md_rand.c",0x20f);
      ERR_add_error_data(1,
                         "You need to read the OpenSSL FAQ, http://www.openssl.org/support/faq.html"
                        );
      return 0;
    }
  }
  return 1;
}

