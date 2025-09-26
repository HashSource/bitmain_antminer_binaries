
undefined4 ssl3_setup_key_block(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  EVP_MD *pEVar6;
  int iVar7;
  uchar *md;
  undefined4 uVar8;
  size_t cnt;
  undefined4 uVar9;
  EVP_CIPHER *local_58;
  EVP_MD *local_54;
  undefined4 local_50;
  char local_4c;
  char local_4b;
  char local_4a;
  char local_49;
  char local_48;
  char local_47;
  char local_46;
  char local_45;
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  char local_40;
  char local_3f;
  char local_3e;
  char local_3d;
  uchar auStack_3c [24];
  
  uVar8 = 1;
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x228) == 0) {
    iVar2 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0x474),&local_58,&local_54,0,0,&local_50,0)
    ;
    if (iVar2 == 0) {
      ossl_statem_fatal(param_1,0x50,0x9d,0x8a,"ssl/s3_enc.c",0x103);
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x7c);
    *(EVP_CIPHER **)(iVar2 + 0x230) = local_58;
    *(undefined4 *)(iVar2 + 0x240) = local_50;
    *(EVP_MD **)(iVar2 + 0x234) = local_54;
    iVar2 = EVP_MD_size(local_54);
    uVar8 = 0;
    if (-1 < iVar2) {
      iVar3 = EVP_CIPHER_key_length(local_58);
      iVar4 = EVP_CIPHER_iv_length(local_58);
      iVar4 = iVar4 + iVar2 + iVar3;
      iVar2 = iVar4 * 2;
      ssl3_cleanup_key_block(param_1);
      pvVar5 = CRYPTO_malloc(iVar2,"ssl/s3_enc.c",0x118);
      if (pvVar5 == (void *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x9d,0x41,"ssl/s3_enc.c",0x11a);
        uVar8 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x7c);
        *(int *)(iVar3 + 0x228) = iVar2;
        *(void **)(iVar3 + 0x22c) = pvVar5;
        ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
        ctx_00 = (EVP_MD_CTX *)EVP_MD_CTX_new();
        if (ctx_00 == (EVP_MD_CTX *)0x0 || ctx == (EVP_MD_CTX *)0x0) {
          ossl_statem_fatal(param_1,0x50,0xee,0x41,"ssl/s3_enc.c",0x22);
        }
        else {
          iVar3 = 0;
          EVP_MD_CTX_set_flags(ctx,8);
          if (iVar2 < 1) {
LAB_0010ab04:
            OPENSSL_cleanse(auStack_3c,0x14);
            uVar8 = 1;
          }
          else {
            local_4c = 'A';
            cnt = 1;
            while( true ) {
              cVar1 = (char)cnt + 'A';
              md = (uchar *)((int)pvVar5 + iVar3);
              pEVar6 = EVP_sha1();
              iVar7 = EVP_DigestInit_ex(ctx_00,pEVar6,(ENGINE *)0x0);
              if ((((iVar7 == 0) || (iVar7 = EVP_DigestUpdate(ctx_00,&local_4c,cnt), iVar7 == 0)) ||
                  (iVar7 = EVP_DigestUpdate(ctx_00,(void *)(*(int *)(param_1 + 0x474) + 0x48),
                                            *(size_t *)(*(int *)(param_1 + 0x474) + 4)), iVar7 == 0)
                  ) || ((iVar7 = EVP_DigestUpdate(ctx_00,(void *)(*(int *)(param_1 + 0x7c) + 0x8c),
                                                  0x20), iVar7 == 0 ||
                        (iVar7 = EVP_DigestUpdate(ctx_00,(void *)(*(int *)(param_1 + 0x7c) + 0xac),
                                                  0x20), iVar7 == 0)))) break;
              iVar7 = EVP_DigestFinal_ex(ctx_00,auStack_3c,(uint *)0x0);
              if (iVar7 == 0) break;
              pEVar6 = EVP_md5();
              iVar7 = EVP_DigestInit_ex(ctx,pEVar6,(ENGINE *)0x0);
              if (((iVar7 == 0) ||
                  (iVar7 = EVP_DigestUpdate(ctx,(void *)(*(int *)(param_1 + 0x474) + 0x48),
                                            *(size_t *)(*(int *)(param_1 + 0x474) + 4)), iVar7 == 0)
                  ) || (iVar7 = EVP_DigestUpdate(ctx,auStack_3c,0x14), iVar7 == 0)) break;
              iVar3 = iVar3 + 0x10;
              if (iVar3 == iVar2 || iVar3 + iVar4 * -2 < 0 != SBORROW4(iVar3,iVar2)) {
                iVar7 = EVP_DigestFinal_ex(ctx,md,(uint *)0x0);
                if (iVar7 == 0) {
                  uVar9 = 0x4b;
LAB_0010aa3e:
                  uVar8 = 0;
                  ossl_statem_fatal(param_1,0x50,0xee,0x44,"ssl/s3_enc.c",uVar9);
                  goto LAB_0010aa84;
                }
              }
              else {
                iVar7 = EVP_DigestFinal_ex(ctx,auStack_3c,(uint *)0x0);
                if (iVar7 == 0) {
                  uVar9 = 0x44;
                  goto LAB_0010aa3e;
                }
                memcpy(md,auStack_3c,(iVar2 + 0x10) - iVar3);
              }
              if (iVar3 + iVar4 * -2 < 0 == SBORROW4(iVar3,iVar2)) goto LAB_0010ab04;
              cnt = cnt + 1;
              if (iVar3 == 0x100) {
                uVar8 = 0x2b;
                goto LAB_0010aaca;
              }
              local_4c = cVar1;
              local_4b = cVar1;
              if (((((cnt != 2) && (local_4a = cVar1, cnt != 3)) && (local_49 = cVar1, cnt != 4)) &&
                  ((local_48 = cVar1, cnt != 5 && (local_47 = cVar1, cnt != 6)))) &&
                 ((((local_46 = cVar1, cnt != 7 &&
                    ((local_45 = cVar1, cnt != 8 && (local_44 = cVar1, cnt != 9)))) &&
                   (local_43 = cVar1, cnt != 10)) &&
                  ((((local_42 = cVar1, cnt != 0xb && (local_41 = cVar1, cnt != 0xc)) &&
                    (local_40 = cVar1, cnt != 0xd)) &&
                   ((local_3f = cVar1, cnt != 0xe && (local_3e = cVar1, cnt == 0x10)))))))) {
                local_3d = cVar1;
              }
            }
            uVar8 = 0x3e;
LAB_0010aaca:
            ossl_statem_fatal(param_1,0x50,0xee,0x44,"ssl/s3_enc.c",uVar8);
            uVar8 = 0;
          }
        }
LAB_0010aa84:
        EVP_MD_CTX_free(ctx);
        EVP_MD_CTX_free(ctx_00);
        if ((*(uint *)(param_1 + 0x4ec) & 0x800) == 0) {
          iVar2 = *(int *)(param_1 + 0x7c);
          iVar3 = *(int *)(*(int *)(param_1 + 0x474) + 0x1b8);
          *(undefined4 *)(iVar2 + 0xcc) = 1;
          if ((iVar3 != 0) && ((iVar3 = *(int *)(iVar3 + 0x18), iVar3 == 0x20 || (iVar3 == 4)))) {
            *(undefined4 *)(iVar2 + 0xcc) = 0;
          }
        }
      }
    }
  }
  return uVar8;
}

