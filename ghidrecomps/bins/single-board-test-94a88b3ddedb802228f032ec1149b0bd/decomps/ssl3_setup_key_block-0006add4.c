
undefined4 ssl3_setup_key_block(int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  EVP_MD *pEVar9;
  uint extraout_r1;
  uint uVar10;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint *puVar11;
  int iVar12;
  uchar *md;
  uint uVar13;
  uint cnt;
  bool bVar14;
  EVP_CIPHER *local_88;
  EVP_MD *local_84;
  undefined4 local_80;
  uint local_7c [4];
  uchar auStack_6c [20];
  EVP_MD_CTX EStack_58;
  EVP_MD_CTX EStack_40;
  
  uVar3 = 1;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) == 0) {
    iVar4 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_88,&local_84,0,0,&local_80);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x9d,0x8a,DAT_0006b03c,0x1a1);
      uVar3 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x58);
      *(EVP_CIPHER **)(iVar4 + 0x37c) = local_88;
      *(undefined4 *)(iVar4 + 0x38c) = local_80;
      *(EVP_MD **)(iVar4 + 0x380) = local_84;
      iVar4 = EVP_MD_size(local_84);
      if (iVar4 < 0) {
        uVar3 = 0;
      }
      else {
        iVar5 = EVP_CIPHER_key_length(local_88);
        iVar6 = EVP_CIPHER_iv_length(local_88);
        iVar12 = *(int *)(param_1 + 0x58);
        iVar4 = (iVar5 + iVar4 + iVar6) * 2;
        if (*(void **)(iVar12 + 0x378) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar12 + 0x378),*(size_t *)(iVar12 + 0x374));
          CRYPTO_free(*(void **)(*(int *)(param_1 + 0x58) + 0x378));
          iVar12 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar12 + 0x378) = 0;
        }
        iVar5 = 0;
        *(undefined4 *)(iVar12 + 0x374) = 0;
        pvVar7 = CRYPTO_malloc(iVar4,DAT_0006b03c,0x1b6);
        if (pvVar7 == (void *)0x0) {
          ERR_put_error(0x14,0x9d,0x41,DAT_0006b03c,0x1d3);
          uVar3 = 0;
        }
        else {
          iVar6 = *(int *)(param_1 + 0x58);
          *(int *)(iVar6 + 0x374) = iVar4;
          *(void **)(iVar6 + 0x378) = pvVar7;
          EVP_MD_CTX_init(&EStack_58);
          EVP_MD_CTX_set_flags(&EStack_58,8);
          EVP_MD_CTX_init(&EStack_40);
          if (iVar4 < 1) {
LAB_0006b008:
            OPENSSL_cleanse(auStack_6c,0x14);
            EVP_MD_CTX_cleanup(&EStack_58);
            EVP_MD_CTX_cleanup(&EStack_40);
            uVar3 = 1;
          }
          else {
            cnt = 1;
            uVar10 = extraout_r1;
            do {
              md = (uchar *)((int)pvVar7 + iVar5);
              bVar14 = cnt >> 2 == 0;
              bVar2 = cnt < 3;
              bVar1 = cnt == 3;
              uVar8 = cnt + 0x40 & 0xff;
              uVar13 = cnt & 0xfffffffc;
              if ((bVar14 || !bVar2) && (!bVar14 && !bVar1)) {
                uVar10 = 0;
              }
              if (!bVar14 && bVar2 || (bVar14 || bVar1)) {
                uVar10 = 1;
              }
              if (!bVar14 && bVar2 || (bVar14 || bVar1)) {
                uVar13 = 0;
LAB_0006aef8:
                do {
                  *(char *)((int)local_7c + uVar13) = (char)(cnt + 0x40);
                  uVar13 = uVar13 + 1;
                } while (uVar13 < cnt);
              }
              else {
                puVar11 = local_7c;
                do {
                  uVar10 = uVar10 + 1;
                  *puVar11 = uVar8 | uVar8 << 8 | uVar8 << 0x10 | uVar8 << 0x18;
                  puVar11 = puVar11 + 1;
                } while (uVar10 < cnt >> 2);
                if (uVar13 != cnt) goto LAB_0006aef8;
              }
              pEVar9 = EVP_sha1();
              iVar5 = iVar5 + 0x10;
              EVP_DigestInit_ex(&EStack_40,pEVar9,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_40,local_7c,cnt);
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
              EVP_DigestFinal_ex(&EStack_40,auStack_6c,(uint *)0x0);
              pEVar9 = EVP_md5();
              EVP_DigestInit_ex(&EStack_58,pEVar9,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_58,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_58,auStack_6c,0x14);
              if (iVar4 < iVar5) {
                EVP_DigestFinal_ex(&EStack_58,auStack_6c,(uint *)0x0);
                memcpy(md,auStack_6c,(iVar4 + 0x10) - iVar5);
                uVar10 = extraout_r1_00;
              }
              else {
                EVP_DigestFinal_ex(&EStack_58,md,(uint *)0x0);
                uVar10 = extraout_r1_01;
              }
              if (iVar4 <= iVar5) goto LAB_0006b008;
              cnt = cnt + 1;
            } while (iVar5 != 0x100);
            ERR_put_error(0x14,0xee,0x44,DAT_0006b03c,0xb6);
            uVar3 = 0;
          }
          if ((*(uint *)(param_1 + 0x100) & 0x800) == 0) {
            iVar4 = *(int *)(param_1 + 0x58);
            iVar5 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar4 + 0xe0) = 1;
            if ((iVar5 != 0) && ((iVar5 = *(int *)(iVar5 + 0x14), iVar5 == 0x20 || (iVar5 == 4)))) {
              *(undefined4 *)(iVar4 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  return uVar3;
}

