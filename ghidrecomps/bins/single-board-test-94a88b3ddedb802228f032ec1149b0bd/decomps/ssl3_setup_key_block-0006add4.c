
undefined4 ssl3_setup_key_block(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  EVP_MD *pEVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uchar *md;
  uint uVar11;
  uint cnt;
  uint uVar12;
  EVP_CIPHER *local_88;
  EVP_MD *local_84;
  undefined4 local_80;
  uint local_7c [4];
  uchar auStack_6c [20];
  EVP_MD_CTX EStack_58;
  EVP_MD_CTX EStack_40;
  
  uVar1 = 1;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) == 0) {
    iVar2 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_88,&local_84,0,0,&local_80);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x9d,0x8a,"s3_enc.c",0x1a1);
      uVar1 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x58);
      *(EVP_CIPHER **)(iVar2 + 0x37c) = local_88;
      *(undefined4 *)(iVar2 + 0x38c) = local_80;
      *(EVP_MD **)(iVar2 + 0x380) = local_84;
      iVar2 = EVP_MD_size(local_84);
      if (iVar2 < 0) {
        uVar1 = 0;
      }
      else {
        iVar3 = EVP_CIPHER_key_length(local_88);
        iVar4 = EVP_CIPHER_iv_length(local_88);
        iVar10 = *(int *)(param_1 + 0x58);
        iVar2 = (iVar3 + iVar2 + iVar4) * 2;
        if (*(void **)(iVar10 + 0x378) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar10 + 0x378),*(size_t *)(iVar10 + 0x374));
          CRYPTO_free(*(void **)(*(int *)(param_1 + 0x58) + 0x378));
          iVar10 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar10 + 0x378) = 0;
        }
        iVar3 = 0;
        *(undefined4 *)(iVar10 + 0x374) = 0;
        pvVar5 = CRYPTO_malloc(iVar2,"s3_enc.c",0x1b6);
        if (pvVar5 == (void *)0x0) {
          ERR_put_error(0x14,0x9d,0x41,"s3_enc.c",0x1d3);
          uVar1 = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x58);
          *(int *)(iVar4 + 0x374) = iVar2;
          *(void **)(iVar4 + 0x378) = pvVar5;
          EVP_MD_CTX_init(&EStack_58);
          EVP_MD_CTX_set_flags(&EStack_58,8);
          EVP_MD_CTX_init(&EStack_40);
          if (iVar2 < 1) {
LAB_0006b008:
            OPENSSL_cleanse(auStack_6c,0x14);
            EVP_MD_CTX_cleanup(&EStack_58);
            EVP_MD_CTX_cleanup(&EStack_40);
            uVar1 = 1;
          }
          else {
            cnt = 1;
            do {
              uVar12 = cnt >> 2;
              md = (uchar *)((int)pvVar5 + iVar3);
              uVar6 = cnt + 0x40 & 0xff;
              uVar11 = uVar12 * 4;
              if (uVar12 == 0 || cnt < 4) {
                uVar11 = 0;
LAB_0006aef8:
                do {
                  *(char *)((int)local_7c + uVar11) = (char)(cnt + 0x40);
                  uVar11 = uVar11 + 1;
                } while (uVar11 < cnt);
              }
              else {
                uVar8 = 0;
                puVar9 = local_7c;
                do {
                  uVar8 = uVar8 + 1;
                  *puVar9 = uVar6 | uVar6 << 8 | uVar6 << 0x10 | uVar6 << 0x18;
                  puVar9 = puVar9 + 1;
                } while (uVar8 < uVar12);
                if (uVar11 != cnt) goto LAB_0006aef8;
              }
              pEVar7 = EVP_sha1();
              iVar3 = iVar3 + 0x10;
              EVP_DigestInit_ex(&EStack_40,pEVar7,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_40,local_7c,cnt);
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
              EVP_DigestUpdate(&EStack_40,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
              EVP_DigestFinal_ex(&EStack_40,auStack_6c,(uint *)0x0);
              pEVar7 = EVP_md5();
              EVP_DigestInit_ex(&EStack_58,pEVar7,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_58,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_58,auStack_6c,0x14);
              if (iVar2 < iVar3) {
                EVP_DigestFinal_ex(&EStack_58,auStack_6c,(uint *)0x0);
                memcpy(md,auStack_6c,(iVar2 + 0x10) - iVar3);
              }
              else {
                EVP_DigestFinal_ex(&EStack_58,md,(uint *)0x0);
              }
              if (iVar2 <= iVar3) goto LAB_0006b008;
              cnt = cnt + 1;
            } while (iVar3 != 0x100);
            ERR_put_error(0x14,0xee,0x44,"s3_enc.c",0xb6);
            uVar1 = 0;
          }
          if ((*(uint *)(param_1 + 0x100) & 0x800) == 0) {
            iVar2 = *(int *)(param_1 + 0x58);
            iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar2 + 0xe0) = 1;
            if ((iVar3 != 0) && ((iVar3 = *(int *)(iVar3 + 0x14), iVar3 == 0x20 || (iVar3 == 4)))) {
              *(undefined4 *)(iVar2 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  return uVar1;
}

