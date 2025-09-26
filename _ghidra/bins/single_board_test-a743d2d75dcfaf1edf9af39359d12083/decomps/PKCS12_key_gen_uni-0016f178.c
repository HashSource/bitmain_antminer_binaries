
int PKCS12_key_gen_uni(uchar *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  undefined1 uVar1;
  uint *puVar2;
  uint cnt;
  size_t cnt_00;
  void *d;
  uchar *md;
  uchar *s;
  int iVar3;
  void *d_00;
  BIGNUM *ret;
  BIGNUM *ret_00;
  uint *puVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  uint uVar7;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  void *pvVar8;
  int iVar9;
  size_t __n;
  size_t cnt_01;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uchar *s_00;
  uint uVar13;
  int local_5c;
  EVP_MD_CTX EStack_40;
  
  EVP_MD_CTX_init(&EStack_40);
  cnt = EVP_MD_block_size(md_type);
  cnt_00 = EVP_MD_size(md_type);
  if ((int)cnt_00 < 0) {
    return 0;
  }
  d = CRYPTO_malloc(cnt,"p12_key.c",0x8d);
  md = (uchar *)CRYPTO_malloc(cnt_00,"p12_key.c",0x8e);
  s = (uchar *)CRYPTO_malloc(cnt + 1,"p12_key.c",0x8f);
  iVar3 = __aeabi_idiv(saltlen + cnt + -1,cnt);
  iVar3 = cnt * iVar3;
  if (passlen == 0) {
    local_5c = 0;
  }
  else {
    local_5c = __aeabi_idiv(passlen + cnt + -1,cnt);
    local_5c = cnt * local_5c;
  }
  cnt_01 = iVar3 + local_5c;
  d_00 = CRYPTO_malloc(cnt_01,"p12_key.c",0x96);
  ret = BN_new();
  ret_00 = BN_new();
  if (((d == (void *)0x0 || md == (uchar *)0x0) || (s == (uchar *)0x0 || d_00 == (void *)0x0)) ||
     (ret == (BIGNUM *)0x0 || ret_00 == (BIGNUM *)0x0)) goto LAB_0016f4b4;
  uVar11 = 0;
  if (0 < (int)cnt) {
    uVar7 = -(int)d & 3U;
    if (cnt <= (-(int)d & 3U)) {
      uVar7 = cnt;
    }
    if (cnt < 4) {
      uVar7 = cnt;
    }
    uVar10 = id & 0xff;
    uVar1 = (undefined1)id;
    if (uVar7 == 0) {
      uVar11 = 0;
    }
    else {
      pvVar8 = d;
      uVar13 = uVar11;
      if (0x20 < uVar7) {
        do {
          *(undefined1 *)((int)d + uVar13) = uVar1;
          HintPreloadData((int)d + uVar13 + 0x22);
          uVar11 = uVar13 + 0x20;
          *(undefined1 *)((int)pvVar8 + 1) = uVar1;
          uVar6 = uVar13 + 0x21;
          *(undefined1 *)((int)pvVar8 + 2) = uVar1;
          *(undefined1 *)((int)pvVar8 + 3) = uVar1;
          *(undefined1 *)((int)pvVar8 + 4) = uVar1;
          *(undefined1 *)((int)pvVar8 + 5) = uVar1;
          *(undefined1 *)((int)pvVar8 + 6) = uVar1;
          *(undefined1 *)((int)pvVar8 + 7) = uVar1;
          *(undefined1 *)((int)pvVar8 + 8) = uVar1;
          *(undefined1 *)((int)pvVar8 + 9) = uVar1;
          *(undefined1 *)((int)pvVar8 + 10) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0xb) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0xc) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0xd) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0xe) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0xf) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x10) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x11) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x12) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x13) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x14) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x15) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x16) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x17) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x18) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x19) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1a) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1b) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1c) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1d) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1e) = uVar1;
          *(undefined1 *)((int)pvVar8 + 0x1f) = uVar1;
          pvVar8 = (void *)((int)pvVar8 + 0x20);
          uVar13 = uVar11;
        } while (uVar6 < uVar7 - 0x1f);
      }
      do {
        *(undefined1 *)((int)d + uVar11) = uVar1;
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar7);
      if (cnt == uVar7) goto LAB_0016f3d6;
    }
    uVar13 = cnt - uVar7 >> 2;
    if (uVar13 != 0) {
      puVar4 = (uint *)(uVar7 + (int)d);
      uVar10 = uVar10 | uVar10 << 8 | uVar10 << 0x10 | uVar10 << 0x18;
      if (uVar13 < 9) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0;
        puVar2 = puVar4;
        do {
          puVar4 = puVar2 + 8;
          uVar12 = uVar6 + 9;
          uVar6 = uVar6 + 8;
          HintPreloadData(puVar2 + 0x28);
          *puVar2 = uVar10;
          puVar2[1] = uVar10;
          puVar2[2] = uVar10;
          puVar2[3] = uVar10;
          puVar2[4] = uVar10;
          puVar2[5] = uVar10;
          puVar2[6] = uVar10;
          puVar2[7] = uVar10;
          puVar2 = puVar4;
        } while (uVar12 < uVar13 - 7);
      }
      do {
        uVar6 = uVar6 + 1;
        *puVar4 = uVar10;
        puVar4 = puVar4 + 1;
      } while (uVar6 < uVar13);
      uVar11 = uVar11 + uVar13 * 4;
      if (cnt - uVar7 == uVar13 * 4) goto LAB_0016f3d6;
    }
    uVar7 = uVar11 + 1;
    if ((int)(uVar11 + 1) < (int)(cnt - 0x1f) && (int)uVar11 < (int)cnt) {
      iVar9 = (int)d + uVar11;
      uVar10 = uVar11;
      do {
        *(undefined1 *)((int)d + uVar10) = uVar1;
        HintPreloadData((int)d + uVar10 + 0x28);
        *(undefined1 *)(iVar9 + 1) = uVar1;
        uVar7 = uVar10 + 0x21;
        *(undefined1 *)(iVar9 + 2) = uVar1;
        *(undefined1 *)(iVar9 + 3) = uVar1;
        *(undefined1 *)(iVar9 + 4) = uVar1;
        *(undefined1 *)(iVar9 + 5) = uVar1;
        *(undefined1 *)(iVar9 + 6) = uVar1;
        *(undefined1 *)(iVar9 + 7) = uVar1;
        *(undefined1 *)(iVar9 + 8) = uVar1;
        *(undefined1 *)(iVar9 + 9) = uVar1;
        *(undefined1 *)(iVar9 + 10) = uVar1;
        *(undefined1 *)(iVar9 + 0xb) = uVar1;
        *(undefined1 *)(iVar9 + 0xc) = uVar1;
        *(undefined1 *)(iVar9 + 0xd) = uVar1;
        *(undefined1 *)(iVar9 + 0xe) = uVar1;
        *(undefined1 *)(iVar9 + 0xf) = uVar1;
        *(undefined1 *)(iVar9 + 0x10) = uVar1;
        *(undefined1 *)(iVar9 + 0x11) = uVar1;
        *(undefined1 *)(iVar9 + 0x12) = uVar1;
        *(undefined1 *)(iVar9 + 0x13) = uVar1;
        *(undefined1 *)(iVar9 + 0x14) = uVar1;
        *(undefined1 *)(iVar9 + 0x15) = uVar1;
        *(undefined1 *)(iVar9 + 0x16) = uVar1;
        *(undefined1 *)(iVar9 + 0x17) = uVar1;
        *(undefined1 *)(iVar9 + 0x18) = uVar1;
        *(undefined1 *)(iVar9 + 0x19) = uVar1;
        *(undefined1 *)(iVar9 + 0x1a) = uVar1;
        *(undefined1 *)(iVar9 + 0x1b) = uVar1;
        *(undefined1 *)(iVar9 + 0x1c) = uVar1;
        *(undefined1 *)(iVar9 + 0x1d) = uVar1;
        *(undefined1 *)(iVar9 + 0x1e) = uVar1;
        *(undefined1 *)(iVar9 + 0x1f) = uVar1;
        iVar9 = iVar9 + 0x20;
        uVar11 = uVar10 + 0x20;
        uVar10 = uVar10 + 0x20;
      } while ((int)uVar7 < (int)(cnt - 0x1f));
    }
    do {
      uVar10 = uVar7;
      *(undefined1 *)((int)d + uVar11) = uVar1;
      uVar7 = uVar10 + 1;
      uVar11 = uVar10;
    } while ((int)uVar10 < (int)cnt);
  }
LAB_0016f3d6:
  pvVar8 = d_00;
  if (0 < iVar3) {
    iVar9 = 0;
    do {
      __aeabi_idivmod(iVar9,saltlen);
      *(uchar *)((int)d_00 + iVar9) = salt[extraout_r1];
      iVar9 = iVar9 + 1;
    } while (iVar9 != iVar3);
    pvVar8 = (void *)(iVar9 + (int)d_00);
  }
  if (0 < local_5c) {
    iVar3 = 0;
    do {
      __aeabi_idivmod(iVar3,passlen);
      *(uchar *)((int)pvVar8 + iVar3) = pass[extraout_r1_00];
      iVar3 = iVar3 + 1;
    } while (iVar3 != local_5c);
  }
  while (((iVar3 = EVP_DigestInit_ex(&EStack_40,md_type,(ENGINE *)0x0), iVar3 != 0 &&
          (iVar3 = EVP_DigestUpdate(&EStack_40,d,cnt), iVar3 != 0)) &&
         ((iVar3 = EVP_DigestUpdate(&EStack_40,d_00,cnt_01), iVar3 != 0 &&
          (iVar3 = EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0), iVar3 != 0))))) {
    if (1 < iter) {
      iVar3 = 1;
      do {
        iVar3 = iVar3 + 1;
        iVar9 = EVP_DigestInit_ex(&EStack_40,md_type,(ENGINE *)0x0);
        if (((iVar9 == 0) || (iVar9 = EVP_DigestUpdate(&EStack_40,md,cnt_00), iVar9 == 0)) ||
           (iVar9 = EVP_DigestFinal_ex(&EStack_40,md,(uint *)0x0), iVar9 == 0)) goto LAB_0016f4b4;
      } while (iVar3 != iter);
    }
    __n = n;
    if ((int)cnt_00 <= n) {
      __n = cnt_00;
    }
    memcpy(out,md,__n);
    if (n <= (int)cnt_00) {
      iVar3 = 1;
      goto LAB_0016f4c6;
    }
    n = n - cnt_00;
    out = out + cnt_00;
    if (0 < (int)cnt) {
      uVar11 = 0;
      do {
        __aeabi_idivmod(uVar11,cnt_00);
        s[uVar11] = md[extraout_r1_01];
        uVar11 = uVar11 + 1;
      } while (uVar11 != cnt);
    }
    pBVar5 = BN_bin2bn(s,cnt,ret_00);
    if ((pBVar5 == (BIGNUM *)0x0) || (iVar3 = BN_add_word(ret_00,1), iVar3 == 0)) break;
    uVar11 = cnt;
    if (0 < (int)cnt_01) {
      do {
        s_00 = (uchar *)((int)d_00 + (uVar11 - cnt));
        pBVar5 = BN_bin2bn(s_00,cnt,ret);
        if (((pBVar5 == (BIGNUM *)0x0) || (iVar3 = BN_add(ret,ret,ret_00), iVar3 == 0)) ||
           (iVar3 = BN_bn2bin(ret,s), iVar3 == 0)) goto LAB_0016f4b4;
        iVar9 = BN_num_bits(ret);
        iVar3 = iVar9 + 0xe;
        if (-1 < iVar9 + 7) {
          iVar3 = iVar9 + 7;
        }
        iVar3 = iVar3 >> 3;
        if ((int)cnt < iVar3) {
          iVar3 = BN_bn2bin(ret,s);
          if (iVar3 == 0) goto LAB_0016f4b4;
          memcpy(s_00,s + 1,cnt);
        }
        else {
          if (iVar3 < (int)cnt) {
            memset(s_00,0,cnt - iVar3);
            iVar3 = BN_bn2bin(ret,(uchar *)((uVar11 - iVar3) + (int)d_00));
          }
          else {
            iVar3 = BN_bn2bin(ret,s_00);
          }
          if (iVar3 == 0) goto LAB_0016f4b4;
        }
        uVar11 = uVar11 + cnt;
      } while ((int)(uVar11 - cnt) < (int)cnt_01);
    }
  }
LAB_0016f4b4:
  iVar3 = 0;
  ERR_put_error(0x23,0x6f,0x41,"p12_key.c",0xda);
LAB_0016f4c6:
  CRYPTO_free(md);
  CRYPTO_free(s);
  CRYPTO_free(d);
  CRYPTO_free(d_00);
  BN_free(ret);
  BN_free(ret_00);
  EVP_MD_CTX_cleanup(&EStack_40);
  return iVar3;
}

