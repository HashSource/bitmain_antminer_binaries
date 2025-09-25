
undefined4
tls_psk_do_binder(int param_1,EVP_MD *param_2,void *param_3,size_t param_4,void *param_5,
                 void **param_6,int param_7,int param_8,int param_9)

{
  size_t cnt;
  int iVar1;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  uint cnt_00;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  size_t local_12c;
  uchar auStack_128 [64];
  undefined1 auStack_e8 [64];
  undefined1 auStack_a8 [64];
  void *local_68 [17];
  
  cnt = EVP_MD_size(param_2);
  if ((int)cnt < 0) {
    ctx = (EVP_MD_CTX *)0x0;
    uVar3 = 0xffffffff;
    pkey = (EVP_PKEY *)0x0;
    ossl_statem_fatal(param_1,0x50,0x1fa,0x44,"ssl/statem/extensions.c",0x5d7);
    goto LAB_000e3614;
  }
  if (param_9 == 0) {
    pcVar4 = "res binder";
LAB_000e34e2:
    iVar5 = param_1 + 0xcc;
  }
  else {
    if ((*(int *)(param_1 + 0x68) == 2) && (*(int *)(*(int *)(param_1 + 0x474) + 0x1e0) == 0)) {
      if (*(int *)(param_1 + 0x1c) == 0) {
        if (*(int *)(param_7 + 0x1e0) == 0) goto LAB_000e364e;
        pcVar4 = "ext binder";
      }
      else {
        pcVar4 = "ext binder";
      }
      goto LAB_000e34e2;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      pcVar4 = "ext binder";
      goto LAB_000e34e2;
    }
LAB_000e364e:
    iVar5 = param_7 + 8;
    pcVar4 = "ext binder";
  }
  iVar1 = tls13_generate_secret(param_1,param_2,0,param_7 + 0x48,*(undefined4 *)(param_7 + 4),iVar5)
  ;
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    ctx = (EVP_MD_CTX *)0x0;
    pkey = (EVP_PKEY *)0x0;
    goto LAB_000e3614;
  }
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if ((ctx != (EVP_MD_CTX *)0x0) &&
     (iVar1 = EVP_DigestInit_ex(ctx,param_2,(ENGINE *)0x0), 0 < iVar1)) {
    iVar1 = EVP_DigestFinal_ex(ctx,auStack_128,(uint *)0x0);
    if (0 < iVar1) {
      iVar5 = tls13_hkdf_expand(param_1,param_2,iVar5,pcVar4,10,auStack_128,cnt,auStack_e8,cnt,1);
      if (iVar5 == 0) {
        uVar3 = 0xffffffff;
        pkey = (EVP_PKEY *)0x0;
        goto LAB_000e3614;
      }
      iVar5 = tls13_derive_finishedkey(param_1,param_2,auStack_e8,auStack_a8,cnt);
      if (iVar5 == 0) {
        uVar3 = 0xffffffff;
        pkey = (EVP_PKEY *)0x0;
        goto LAB_000e3614;
      }
      iVar5 = EVP_DigestInit_ex(ctx,param_2,(ENGINE *)0x0);
      if (iVar5 < 1) {
        uVar3 = 0x619;
LAB_000e36b8:
        ossl_statem_fatal(param_1,0x50,0x1fa,0x44,"ssl/statem/extensions.c",uVar3);
      }
      else {
        if (*(int *)(param_1 + 0x44c) != 1) {
LAB_000e358e:
          iVar5 = EVP_DigestUpdate(ctx,param_3,param_4);
          if ((0 < iVar5) && (iVar5 = EVP_DigestFinal_ex(ctx,auStack_128,(uint *)0x0), 0 < iVar5)) {
            pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,auStack_a8,cnt);
            if (pkey == (EVP_PKEY *)0x0) {
              uVar3 = 0x655;
            }
            else {
              if (param_8 == 0) {
                param_6 = local_68;
              }
              local_12c = cnt;
              iVar5 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,param_2,(ENGINE *)0x0,pkey);
              if ((((0 < iVar5) && (iVar5 = EVP_DigestUpdate(ctx,auStack_128,cnt), 0 < iVar5)) &&
                  (iVar5 = EVP_DigestSignFinal(ctx,(uchar *)param_6,&local_12c), 0 < iVar5)) &&
                 (cnt == local_12c)) {
                if (param_8 == 0) {
                  iVar5 = CRYPTO_memcmp(param_5,param_6,cnt);
                  if (iVar5 == 0) {
                    uVar3 = 1;
                  }
                  else {
                    uVar3 = 0;
                    ossl_statem_fatal(param_1,0x2f,0x1fa,0xfd,"ssl/statem/extensions.c",0x66d);
                  }
                }
                else {
                  uVar3 = 1;
                }
                goto LAB_000e3614;
              }
              uVar3 = 0x662;
            }
            ossl_statem_fatal(param_1,0x50,0x1fa,0x44,"ssl/statem/extensions.c",uVar3);
            uVar3 = 0xffffffff;
            goto LAB_000e3614;
          }
          uVar3 = 0x64d;
          goto LAB_000e36b8;
        }
        cnt_00 = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4),3,0,local_68);
        if (0 < (int)cnt_00) {
          if (*(int *)(param_1 + 0x1c) == 0) {
LAB_000e3748:
            iVar5 = EVP_DigestUpdate(ctx,local_68[0],cnt_00);
            if (0 < iVar5) goto LAB_000e358e;
            uVar3 = 0x645;
          }
          else {
            if (3 < cnt_00) {
              uVar2 = (uint)*(byte *)((int)local_68[0] + 3) |
                      (uint)*(byte *)((int)local_68[0] + 2) << 8 |
                      (uint)*(byte *)((int)local_68[0] + 1) << 0x10;
              if ((uVar2 <= cnt_00 - 4) && (uVar6 = (cnt_00 - 4) - uVar2, 3 < uVar6)) {
                uVar6 = uVar6 - 4;
                uVar2 = (uint)*(byte *)((int)local_68[0] + uVar2 + 6) << 8 |
                        (uint)*(byte *)((int)local_68[0] + uVar2 + 5) << 0x10 |
                        (uint)*(byte *)((int)local_68[0] + uVar2 + 7);
                if (uVar2 <= uVar6) {
                  cnt_00 = cnt_00 - (uVar6 - uVar2);
                  goto LAB_000e3748;
                }
              }
            }
            uVar3 = 0x63d;
          }
          goto LAB_000e36b8;
        }
        ossl_statem_fatal(param_1,0x50,0x1fa,0x14c,"ssl/statem/extensions.c",0x62b);
      }
      uVar3 = 0xffffffff;
      pkey = (EVP_PKEY *)0x0;
      goto LAB_000e3614;
    }
  }
  uVar3 = 0xffffffff;
  ossl_statem_fatal(param_1,0x50,0x1fa,0x44,"ssl/statem/extensions.c",0x606);
  pkey = (EVP_PKEY *)0x0;
LAB_000e3614:
  OPENSSL_cleanse(auStack_e8,0x40);
  OPENSSL_cleanse(auStack_a8,0x40);
  EVP_PKEY_free(pkey);
  EVP_MD_CTX_free(ctx);
  return uVar3;
}

