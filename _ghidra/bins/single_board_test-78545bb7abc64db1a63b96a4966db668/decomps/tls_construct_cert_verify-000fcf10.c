
undefined4 tls_construct_cert_verify(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uchar *sigret;
  int iVar4;
  EVP_PKEY *pkey;
  EVP_MD_CTX *ctx;
  bool bVar5;
  EVP_MD *local_d8;
  EVP_PKEY_CTX *local_d4;
  size_t local_d0;
  size_t local_cc;
  void *local_c8;
  undefined1 auStack_c4 [164];
  
  local_d8 = (EVP_MD *)0x0;
  iVar4 = *(int *)(param_1[0x1f] + 0x260);
  local_d4 = (EVP_PKEY_CTX *)0x0;
  local_d0 = 0;
  local_cc = 0;
  if ((iVar4 == 0) || (iVar1 = *(int *)(param_1[0x1f] + 0x264), iVar1 == 0)) {
    uVar2 = 0xf4;
  }
  else {
    pkey = *(EVP_PKEY **)(iVar1 + 4);
    if ((pkey != (EVP_PKEY *)0x0) && (iVar1 = tls1_lookup_md(iVar4,&local_d8), iVar1 != 0)) {
      ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
      if (ctx == (EVP_MD_CTX *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x1f0,0x41,"ssl/statem/statem_lib.c",0x102);
        sigret = (uchar *)0x0;
        goto LAB_000fcf5c;
      }
      iVar1 = get_cert_verify_tbs_data(param_1,auStack_c4,&local_c8,&local_d0);
      if (iVar1 == 0) {
        sigret = (uchar *)0x0;
        goto LAB_000fcf5c;
      }
      if ((*(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1e < 0) &&
         (iVar1 = WPACKET_put_bytes__(param_2,2,*(undefined2 *)(iVar4 + 4),0,2), iVar1 == 0)) {
        uVar2 = 0x10e;
        sigret = (uchar *)0x0;
LAB_000fd036:
        ossl_statem_fatal(param_1,0x50,0x1f0,0x44,"ssl/statem/statem_lib.c",uVar2);
      }
      else {
        local_cc = EVP_PKEY_size(pkey);
        sigret = (uchar *)CRYPTO_malloc(local_cc,"ssl/statem/statem_lib.c",0x112);
        if (sigret == (uchar *)0x0) {
          ossl_statem_fatal(param_1,0x50,0x1f0,0x41,"ssl/statem/statem_lib.c",0x115);
          goto LAB_000fcf5c;
        }
        iVar1 = EVP_DigestSignInit(ctx,&local_d4,local_d8,(ENGINE *)0x0,pkey);
        if (iVar1 < 1) {
          ossl_statem_fatal(param_1,0x50,0x1f0,6,"ssl/statem/statem_lib.c",0x11b);
          goto LAB_000fcf5c;
        }
        if ((*(int *)(iVar4 + 0x10) == 0x390) &&
           ((iVar1 = RSA_pkey_ctx_ctrl(local_d4,0xffffffff,0x1001,6,0), iVar1 < 1 ||
            (iVar1 = RSA_pkey_ctx_ctrl(local_d4,0x18,0x1002,0xffffffff,0), iVar1 < 1)))) {
          uVar2 = 0x124;
        }
        else if (*param_1 == 0x300) {
          iVar1 = EVP_DigestUpdate(ctx,local_c8,local_d0);
          if (((0 < iVar1) &&
              (iVar1 = EVP_MD_CTX_ctrl(ctx,0x1d,*(undefined4 *)(param_1[0x11d] + 4),
                                       param_1[0x11d] + 0x48), iVar1 != 0)) &&
             (iVar1 = EVP_DigestSignFinal(ctx,sigret,&local_cc), 0 < iVar1)) goto LAB_000fd002;
          uVar2 = 0x130;
        }
        else {
          iVar1 = EVP_DigestSign(ctx,sigret,&local_cc,local_c8,local_d0);
          if (0 < iVar1) {
LAB_000fd002:
            uVar3 = *(uint *)(iVar4 + 0x10);
            bVar5 = 0x32a < uVar3;
            if (uVar3 != 0x32b) {
              bVar5 = uVar3 != 0x3d3;
            }
            if (!bVar5 || (uVar3 == 0x32b || uVar3 == 0x3d4)) {
              BUF_reverse(sigret,(uchar *)0x0,local_cc);
            }
            iVar4 = WPACKET_sub_memcpy__(param_2,sigret,local_cc,2);
            if (iVar4 != 0) {
              iVar4 = ssl3_digest_cached_records(param_1,0);
              if (iVar4 != 0) {
                CRYPTO_free(sigret);
                EVP_MD_CTX_free(ctx);
                return 1;
              }
              goto LAB_000fcf5c;
            }
            uVar2 = 0x146;
            goto LAB_000fd036;
          }
          uVar2 = 0x135;
        }
        ossl_statem_fatal(param_1,0x50,0x1f0,6,"ssl/statem/statem_lib.c",uVar2);
      }
      goto LAB_000fcf5c;
    }
    uVar2 = 0xfb;
  }
  sigret = (uchar *)0x0;
  ctx = (EVP_MD_CTX *)0x0;
  ossl_statem_fatal(param_1,0x50,0x1f0,0x44,"ssl/statem/statem_lib.c",uVar2);
LAB_000fcf5c:
  CRYPTO_free(sigret);
  EVP_MD_CTX_free(ctx);
  return 0;
}

