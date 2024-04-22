
undefined4
tls1_PRF_constprop_0
          (uint param_1,void *param_2,size_t param_3,void *param_4,size_t param_5,void *param_6,
          size_t param_7,void *param_8,size_t param_9,uchar *param_10,uint param_11,
          uint *param_12_00,uint *param_13,uint param_12)

{
  uint *puVar1;
  uint *puVar2;
  EVP_MD *type;
  int iVar3;
  EVP_PKEY *pkey;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  size_t __n;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  bool bVar15;
  uchar *local_104;
  int local_c0;
  EVP_MD *local_bc;
  size_t local_b8;
  size_t local_b4;
  EVP_MD_CTX EStack_b0;
  EVP_MD_CTX EStack_98;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  iVar10 = 0;
  iVar3 = 0;
  while( true ) {
    iVar12 = iVar3 + 1;
    iVar3 = ssl_get_handshake_digest(iVar3,&local_c0,&local_bc);
    if (iVar3 == 0) break;
    iVar3 = iVar12;
    if ((param_1 & local_c0 << 10) != 0) {
      iVar10 = iVar10 + 1;
    }
  }
  if (iVar10 == 0) {
    ERR_put_error(0x14,0x11c,0x44,DAT_000741e0,0x109);
    uVar5 = 0;
  }
  else {
    iVar3 = __aeabi_idiv(param_11,iVar10);
    memset(param_12_00,0,param_12);
    uVar13 = param_12 >> 2;
    if (iVar10 == 1) {
      param_11 = 0;
    }
    bVar15 = (((uint)param_13 | (uint)param_12_00) & 3) != 0;
    uVar8 = param_12 & 0xfffffffc;
    if (uVar13 == 0 ||
        (bVar15 || (param_12 < 4 || param_13 < param_12_00 + 1 && param_12_00 < param_13 + 1))) {
      uVar8 = 0;
    }
    iVar10 = 0;
    while (iVar12 = ssl_get_handshake_digest(iVar10,&local_c0,&local_bc), type = local_bc,
          iVar12 != 0) {
      if ((param_1 & local_c0 << 10) == 0) goto LAB_0007405c;
      if (local_bc == (EVP_MD *)0x0) {
        ERR_put_error(0x14,0x11c,0x146,DAT_000741e0,0x114);
        return 0;
      }
      iVar12 = EVP_MD_size(local_bc);
      if (iVar12 < 0) {
        OpenSSLDie(DAT_000741e0,0xaa,DAT_000741e4);
      }
      EVP_MD_CTX_init(&EStack_b0);
      EVP_MD_CTX_init(&EStack_98);
      EVP_MD_CTX_init(&EStack_80);
      EVP_MD_CTX_set_flags(&EStack_80,8);
      pkey = EVP_PKEY_new_mac_key(0x357,(ENGINE *)0x0,param_10,iVar3 + (param_11 & 1));
      if ((((((pkey == (EVP_PKEY *)0x0) ||
             (iVar4 = EVP_DigestSignInit(&EStack_80,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey),
             iVar4 == 0)) || (iVar4 = EVP_MD_CTX_copy_ex(&EStack_b0,&EStack_80), iVar4 == 0)) ||
           ((param_2 != (void *)0x0 &&
            (iVar4 = EVP_DigestUpdate(&EStack_b0,param_2,param_3), iVar4 == 0)))) ||
          (((param_4 != (void *)0x0 &&
            (iVar4 = EVP_DigestUpdate(&EStack_b0,param_4,param_5), iVar4 == 0)) ||
           ((param_6 != (void *)0x0 &&
            (iVar4 = EVP_DigestUpdate(&EStack_b0,param_6,param_7), iVar4 == 0)))))) ||
         ((param_8 != (void *)0x0 &&
          (iVar4 = EVP_DigestUpdate(&EStack_b0,param_8,param_9), iVar4 == 0)))) {
LAB_00073ee4:
        local_104 = auStack_68;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_cleanup(&EStack_b0);
        EVP_MD_CTX_cleanup(&EStack_98);
        EVP_MD_CTX_cleanup(&EStack_80);
        OPENSSL_cleanse(local_104,0x40);
        return 0;
      }
      iVar4 = EVP_DigestSignFinal(&EStack_b0,auStack_68,&local_b4);
      puVar9 = param_13;
      __n = param_12;
      while( true ) {
        if (((((iVar4 == 0) || (iVar4 = EVP_MD_CTX_copy_ex(&EStack_b0,&EStack_80), iVar4 == 0)) ||
             (iVar4 = EVP_DigestUpdate(&EStack_b0,auStack_68,local_b4), iVar4 == 0)) ||
            (((iVar12 < (int)__n && (iVar4 = EVP_MD_CTX_copy_ex(&EStack_98,&EStack_b0), iVar4 == 0))
             || ((param_2 != (void *)0x0 &&
                 (iVar4 = EVP_DigestUpdate(&EStack_b0,param_2,param_3), iVar4 == 0)))))) ||
           ((((param_4 != (void *)0x0 &&
              (iVar4 = EVP_DigestUpdate(&EStack_b0,param_4,param_5), iVar4 == 0)) ||
             ((param_6 != (void *)0x0 &&
              (iVar4 = EVP_DigestUpdate(&EStack_b0,param_6,param_7), iVar4 == 0)))) ||
            ((param_8 != (void *)0x0 &&
             (iVar4 = EVP_DigestUpdate(&EStack_b0,param_8,param_9), iVar4 == 0))))))
        goto LAB_00073ee4;
        if ((int)__n <= iVar12) break;
        iVar4 = EVP_DigestSignFinal(&EStack_b0,(uchar *)puVar9,&local_b8);
        if (iVar4 == 0) goto LAB_00073ee4;
        puVar9 = (uint *)((int)puVar9 + local_b8);
        __n = __n - local_b8;
        iVar4 = EVP_DigestSignFinal(&EStack_98,auStack_68,&local_b4);
      }
      iVar12 = EVP_DigestSignFinal(&EStack_b0,auStack_68,&local_b4);
      if (iVar12 == 0) goto LAB_00073ee4;
      param_10 = param_10 + iVar3;
      memcpy(puVar9,auStack_68,__n);
      EVP_PKEY_free(pkey);
      EVP_MD_CTX_cleanup(&EStack_b0);
      EVP_MD_CTX_cleanup(&EStack_98);
      EVP_MD_CTX_cleanup(&EStack_80);
      OPENSSL_cleanse(auStack_68,0x40);
      if (0 < (int)param_12) {
        uVar7 = uVar8;
        if (uVar13 != 0 &&
            (!bVar15 &&
            (param_12 >= 4 && (param_13 >= param_12_00 + 1 || param_12_00 >= param_13 + 1)))) {
          if (uVar13 < 9) {
            uVar6 = 0;
            puVar9 = param_12_00;
            puVar14 = param_13;
          }
          else {
            uVar6 = 0;
            puVar1 = param_13;
            puVar2 = param_12_00;
            do {
              puVar9 = puVar2 + 8;
              puVar14 = puVar1 + 8;
              uVar11 = uVar6 + 9;
              uVar6 = uVar6 + 8;
              HintPreloadData(puVar2 + 0x14);
              *puVar2 = *puVar1 ^ *puVar2;
              puVar2[1] = puVar1[1] ^ puVar2[1];
              puVar2[2] = puVar1[2] ^ puVar2[2];
              puVar2[3] = puVar1[3] ^ puVar2[3];
              puVar2[4] = puVar1[4] ^ puVar2[4];
              puVar2[5] = puVar1[5] ^ puVar2[5];
              puVar2[6] = puVar1[6] ^ puVar2[6];
              puVar2[7] = puVar1[7] ^ puVar2[7];
              puVar1 = puVar14;
              puVar2 = puVar9;
            } while (uVar11 < uVar13 - 7);
          }
          iVar12 = 0;
          do {
            uVar6 = uVar6 + 1;
            *(uint *)((int)puVar9 + iVar12) =
                 *(uint *)((int)puVar14 + iVar12) ^ *(uint *)((int)puVar9 + iVar12);
            iVar12 = iVar12 + 4;
          } while (uVar6 < uVar13);
          if (param_12 == (param_12 & 0xfffffffc)) goto LAB_0007405c;
        }
        do {
          *(byte *)((int)param_12_00 + uVar7) =
               *(byte *)((int)param_12_00 + uVar7) ^ *(byte *)((int)param_13 + uVar7);
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < (int)param_12);
      }
LAB_0007405c:
      iVar10 = iVar10 + 1;
    }
    uVar5 = 1;
  }
  return uVar5;
}

