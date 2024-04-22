
undefined4 ssleay_rand_bytes(undefined *param_1,size_t param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  EVP_MD *pEVar4;
  undefined4 extraout_r1;
  byte bVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  size_t cnt;
  size_t cnt_00;
  int iVar12;
  bool bVar13;
  double dVar14;
  double dVar15;
  void *local_78;
  __pid_t local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  EVP_MD_CTX EStack_40;
  
  local_64 = getpid();
  if (0 < (int)param_2) {
    EVP_MD_CTX_init(&EStack_40);
    if (param_4 != 0) {
      CRYPTO_lock(9,0x12,DAT_00103838,0x182);
    }
    puVar2 = DAT_00103510;
    CRYPTO_lock(9,0x13,DAT_00103514,0x185);
    CRYPTO_THREADID_current((CRYPTO_THREADID *)(puVar2 + 1));
    CRYPTO_lock(10,0x13,DAT_00103514,0x187);
    *puVar2 = 1;
    if (puVar2[3] == 0) {
      RAND_poll();
      puVar2[3] = 1;
    }
    dVar14 = *(double *)(puVar2 + 4);
    iVar6 = puVar2[0x114];
    bVar1 = dVar14 < DAT_00103500 == (NAN(dVar14) || NAN(DAT_00103500));
    if (!bVar1) {
      dVar15 = dVar14 - (double)(longlong)(int)param_2;
      if ((int)((uint)(dVar14 - (double)(longlong)(int)param_2 < DAT_00103508) << 0x1f) < 0) {
        dVar15 = DAT_00103508;
      }
      *(double *)(DAT_00103510 + 4) = dVar15;
    }
    if (iVar6 == 0) {
      iVar6 = 0x34;
      do {
        ssleay_rand_add_part_0(SUB84(DAT_00103508,0),DAT_00103518,0x14);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (bVar1) {
        puVar2[0x114] = 1;
      }
    }
    puVar3 = DAT_00103510;
    iVar6 = puVar2[0x10c];
    local_58 = DAT_00103510[0x10d];
    local_54 = DAT_00103510[0x10e];
    local_50 = DAT_00103510[0x10f];
    uStack_4c = DAT_00103510[0x110];
    iVar12 = ((int)(param_2 - 1) / 10 + 1) * 10 + iVar6;
    iVar11 = puVar2[0x112];
    local_48 = DAT_00103510[0x111];
    iVar9 = puVar2[0x10b];
    local_5c = puVar2[0x113];
    local_60 = iVar11;
    if (iVar9 < iVar12) {
      __aeabi_idivmod(iVar12,iVar9);
      puVar3[0x10c] = extraout_r1;
    }
    else {
      DAT_00103510[0x10c] = iVar12;
    }
    puVar2[0x112] = iVar11 + 1;
    *puVar2 = 0;
    if (param_4 == 0) {
      local_78 = DAT_0010351c;
    }
    else {
      local_78 = DAT_00103830;
      CRYPTO_lock(10,0x12,DAT_00103838,0x1d2);
    }
    do {
      pEVar4 = EVP_sha1();
      cnt = param_2;
      if (9 < (int)param_2) {
        cnt = 10;
      }
      EVP_DigestInit_ex(&EStack_40,pEVar4,(ENGINE *)0x0);
      param_2 = param_2 - cnt;
      if (local_64 != 0) {
        EVP_DigestUpdate(&EStack_40,&local_64,4);
        local_64 = 0;
      }
      EVP_DigestUpdate(&EStack_40,&local_58,0x14);
      EVP_DigestUpdate(&EStack_40,&local_60,8);
      EVP_DigestUpdate(&EStack_40,param_1,cnt);
      cnt_00 = (iVar6 + 10) - iVar9;
      if ((int)cnt_00 < 1) {
        EVP_DigestUpdate(&EStack_40,(void *)((int)local_78 + iVar6),10);
      }
      else {
        EVP_DigestUpdate(&EStack_40,(void *)((int)local_78 + iVar6),10 - cnt_00);
        EVP_DigestUpdate(&EStack_40,DAT_00103830,cnt_00);
      }
      EVP_DigestFinal_ex(&EStack_40,(uchar *)&local_58,(uint *)0x0);
      iVar11 = iVar6 + 1;
      if (iVar11 < iVar9) {
        iVar10 = iVar6 + 2;
        iVar12 = iVar11;
      }
      else {
        iVar10 = iVar6;
        iVar12 = 0;
      }
      *(byte *)((int)puVar2 + iVar6 + 0x18) = *(byte *)((int)puVar2 + iVar6 + 0x18) ^ (byte)local_58
      ;
      if (iVar9 <= iVar11) {
        iVar10 = 1;
      }
      iVar6 = iVar10;
      if (iVar9 <= iVar10) {
        iVar6 = 0;
      }
      *param_1 = local_50._2_1_;
      bVar5 = *(byte *)((int)puVar2 + iVar12 + 0x18) ^ local_58._1_1_;
      *(byte *)((int)puVar2 + iVar12 + 0x18) = bVar5;
      if (iVar10 < iVar9) {
        iVar11 = iVar6 + 1;
      }
      else {
        iVar11 = 1;
      }
      bVar13 = cnt == 1;
      if (!bVar13) {
        bVar5 = local_50._3_1_;
      }
      iVar6 = iVar6 + (int)puVar2;
      if (bVar13) {
        param_1 = param_1 + 1;
      }
      if (!bVar13) {
        param_1[1] = bVar5;
        param_1 = param_1 + 2;
      }
      iVar12 = iVar11;
      if (iVar9 <= iVar11) {
        iVar12 = 0;
      }
      *(byte *)(iVar6 + 0x18) = *(byte *)(iVar6 + 0x18) ^ local_58._2_1_;
      if (iVar11 < iVar9) {
        iVar11 = iVar12 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar7 = param_1;
      if (2 < (int)cnt) {
        puVar7 = param_1 + 1;
        *param_1 = (undefined)uStack_4c;
      }
      iVar10 = iVar11;
      if (iVar9 <= iVar11) {
        iVar10 = 0;
      }
      *(byte *)((int)puVar2 + iVar12 + 0x18) =
           *(byte *)((int)puVar2 + iVar12 + 0x18) ^ local_58._3_1_;
      if (iVar11 < iVar9) {
        iVar11 = iVar10 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar8 = puVar7;
      if (3 < (int)cnt) {
        puVar8 = puVar7 + 1;
        *puVar7 = uStack_4c._1_1_;
      }
      iVar12 = iVar11;
      if (iVar9 <= iVar11) {
        iVar12 = 0;
      }
      *(byte *)((int)puVar2 + iVar10 + 0x18) =
           *(byte *)((int)puVar2 + iVar10 + 0x18) ^ (byte)local_54;
      if (iVar11 < iVar9) {
        iVar11 = iVar12 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar7 = puVar8;
      if (4 < (int)cnt) {
        puVar7 = puVar8 + 1;
        *puVar8 = uStack_4c._2_1_;
      }
      iVar10 = iVar11;
      if (iVar9 <= iVar11) {
        iVar10 = 0;
      }
      *(byte *)((int)puVar2 + iVar12 + 0x18) =
           *(byte *)((int)puVar2 + iVar12 + 0x18) ^ local_54._1_1_;
      if (iVar11 < iVar9) {
        iVar11 = iVar10 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar8 = puVar7;
      if (5 < (int)cnt) {
        puVar8 = puVar7 + 1;
        *puVar7 = uStack_4c._3_1_;
      }
      iVar12 = iVar11;
      if (iVar9 <= iVar11) {
        iVar12 = 0;
      }
      *(byte *)((int)puVar2 + iVar10 + 0x18) =
           *(byte *)((int)puVar2 + iVar10 + 0x18) ^ local_54._2_1_;
      if (iVar11 < iVar9) {
        iVar11 = iVar12 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar7 = puVar8;
      if (6 < (int)cnt) {
        puVar7 = puVar8 + 1;
        *puVar8 = (undefined)local_48;
      }
      iVar10 = iVar11;
      if (iVar9 <= iVar11) {
        iVar10 = 0;
      }
      *(byte *)((int)puVar2 + iVar12 + 0x18) =
           *(byte *)((int)puVar2 + iVar12 + 0x18) ^ local_54._3_1_;
      if (iVar11 < iVar9) {
        iVar11 = iVar10 + 1;
      }
      else {
        iVar11 = 1;
      }
      puVar8 = puVar7;
      if (7 < (int)cnt) {
        puVar8 = puVar7 + 1;
        *puVar7 = local_48._1_1_;
      }
      if (iVar11 < iVar9) {
        iVar6 = iVar11 + 1;
      }
      if (iVar9 <= iVar11) {
        iVar6 = 1;
        iVar11 = 0;
      }
      *(byte *)((int)puVar2 + iVar10 + 0x18) =
           *(byte *)((int)puVar2 + iVar10 + 0x18) ^ (byte)local_50;
      puVar7 = puVar8;
      if (8 < (int)cnt) {
        puVar7 = puVar8 + 1;
        *puVar8 = local_48._2_1_;
      }
      if (iVar9 <= iVar6) {
        iVar6 = 0;
      }
      *(byte *)((int)puVar2 + iVar11 + 0x18) =
           *(byte *)((int)puVar2 + iVar11 + 0x18) ^ local_50._1_1_;
      param_1 = puVar7;
      if (cnt == 10) {
        param_1 = puVar7 + 1;
        *puVar7 = local_48._3_1_;
      }
    } while (0 < (int)param_2);
    pEVar4 = EVP_sha1();
    EVP_DigestInit_ex(&EStack_40,pEVar4,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_40,&local_60,8);
    EVP_DigestUpdate(&EStack_40,&local_58,0x14);
    if (param_4 == 0) {
      EVP_DigestUpdate(&EStack_40,DAT_00103834,0x14);
      EVP_DigestFinal_ex(&EStack_40,DAT_00103834,(uint *)0x0);
    }
    else {
      CRYPTO_lock(9,0x12,DAT_00103838,0x203);
      EVP_DigestUpdate(&EStack_40,DAT_00103834,0x14);
      EVP_DigestFinal_ex(&EStack_40,DAT_00103834,(uint *)0x0);
      CRYPTO_lock(10,0x12,DAT_00103838,0x207);
    }
    EVP_MD_CTX_cleanup(&EStack_40);
    if (!bVar1) {
      if (param_3 != 0) {
        return 0;
      }
      ERR_put_error(0x24,100,100,DAT_00103838,0x20f);
      ERR_add_error_data(1,DAT_0010383c);
      return 0;
    }
  }
  return 1;
}

