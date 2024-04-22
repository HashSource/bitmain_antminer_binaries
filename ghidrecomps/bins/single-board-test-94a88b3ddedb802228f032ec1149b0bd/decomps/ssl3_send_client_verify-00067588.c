
undefined4 ssl3_send_client_verify(int param_1)

{
  undefined4 uVar1;
  EVP_MD *pEVar2;
  int iVar3;
  size_t cnt;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  EVP_PKEY_CTX *ctx;
  int iVar7;
  int iVar8;
  EVP_PKEY *pkey;
  uint local_ac;
  uint local_a8;
  void *local_a4;
  size_t local_a0;
  EVP_MD_CTX EStack_9c;
  uchar auStack_84 [16];
  uchar auStack_74 [20];
  uchar auStack_60 [64];
  
  local_ac = 0;
  EVP_MD_CTX_init(&EStack_9c);
  if (*(int *)(param_1 + 0x34) != 0x1190) {
    ctx = (EVP_PKEY_CTX *)0x0;
    goto LAB_000675aa;
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  pkey = *(EVP_PKEY **)(**(int **)(param_1 + 0x98) + 4);
  iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c);
  ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
  EVP_PKEY_sign_init(ctx);
  pEVar2 = EVP_sha1();
  iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,pEVar2);
  iVar6 = iVar8 + iVar7;
  if (iVar3 < 1) {
    ERR_clear_error();
LAB_000676ba:
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 100);
    if ((*(uint *)(iVar3 + 0x38) & 2) != 0) goto LAB_0006761c;
    iVar5 = pkey->type;
    if (iVar5 != 6) {
      if (iVar5 == 0x74) {
        iVar3 = DSA_sign(pkey->save_type,auStack_74,0x14,(uchar *)(iVar6 + 2),&local_a8,
                         (DSA *)(pkey->pkey).rsa);
        if (iVar3 == 0) {
          ERR_put_error(0x14,0x99,10,DAT_00067834,0xcb1);
          goto LAB_0006776a;
        }
LAB_0006772c:
        *(char *)(iVar8 + iVar7) = (char)(local_a8 >> 8);
        *(char *)(iVar6 + 1) = (char)local_a8;
        iVar6 = local_a8 + 2;
        goto LAB_00067696;
      }
      if (iVar5 == 0x198) {
        iVar3 = ECDSA_sign(pkey->save_type,auStack_74,0x14,(uchar *)(iVar6 + 2),&local_a8,
                           (EC_KEY *)(pkey->pkey).rsa);
        if (iVar3 == 0) {
          ERR_put_error(0x14,0x99,0x2a,DAT_00067834,0xcbe);
          goto LAB_0006776a;
        }
        goto LAB_0006772c;
      }
      if (iVar5 - 0x32bU < 2) {
        local_a0 = 0x40;
        (**(code **)(iVar3 + 0x1c))(param_1,0x329,auStack_84);
        iVar3 = EVP_PKEY_sign(ctx,auStack_60,&local_a0,auStack_84,0x20);
        if (0 < iVar3) {
          puVar4 = &stack0xffffffe0;
          local_a8 = 0;
          do {
            puVar4 = puVar4 + -1;
            *(uchar *)(iVar6 + local_a8 + 2) = *puVar4;
            local_a8 = local_a8 + 1;
          } while (puVar4 != auStack_60);
          goto LAB_0006772c;
        }
        iVar3 = 0xccd;
      }
      else {
        iVar3 = 0xcd6;
      }
      goto LAB_0006778c;
    }
    (**(code **)(iVar3 + 0x1c))(param_1,4,auStack_84);
    iVar3 = RSA_sign(0x72,auStack_84,0x24,(uchar *)(iVar6 + 2),&local_ac,(pkey->pkey).rsa);
    if (iVar3 < 1) {
      ERR_put_error(0x14,0x99,4,DAT_00067834,0xca4);
      goto LAB_0006776a;
    }
    *(char *)(iVar8 + iVar7) = (char)(local_ac >> 8);
    *(char *)(iVar6 + 1) = (char)local_ac;
    iVar6 = local_ac + 2;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 100);
    if (-1 < *(int *)(iVar3 + 0x38) << 0x1e) {
      (**(code **)(iVar3 + 0x1c))(param_1,0x40,auStack_74);
      goto LAB_000676ba;
    }
LAB_0006761c:
    pEVar2 = *(EVP_MD **)(**(int **)(param_1 + 0x98) + 8);
    cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),3,0,&local_a4);
    if (((int)cnt < 1) || (iVar3 = tls12_get_sigandhash(iVar6,pkey,pEVar2), iVar3 == 0)) {
      iVar3 = 0xc8b;
LAB_0006778c:
      ERR_put_error(0x14,0x99,0x44,DAT_00067834,iVar3);
LAB_0006776a:
      EVP_MD_CTX_cleanup(&EStack_9c);
      EVP_PKEY_CTX_free(ctx);
      *(undefined4 *)(param_1 + 0x34) = 5;
      return 0xffffffff;
    }
    iVar3 = EVP_DigestInit_ex(&EStack_9c,pEVar2,(ENGINE *)0x0);
    if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_9c,local_a4,cnt), iVar3 == 0)) ||
       (iVar3 = EVP_SignFinal(&EStack_9c,(uchar *)(iVar6 + 4),&local_ac,pkey), iVar3 == 0)) {
      ERR_put_error(0x14,0x99,6,DAT_00067834,0xc96);
      goto LAB_0006776a;
    }
    *(char *)(iVar6 + 2) = (char)(local_ac >> 8);
    *(char *)(iVar6 + 3) = (char)local_ac;
    iVar6 = local_ac + 4;
    iVar3 = ssl3_digest_cached_records(param_1);
    if (iVar3 == 0) goto LAB_0006776a;
  }
LAB_00067696:
  (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,0xf,iVar6);
  *(undefined4 *)(param_1 + 0x34) = 0x1191;
LAB_000675aa:
  EVP_MD_CTX_cleanup(&EStack_9c);
  EVP_PKEY_CTX_free(ctx);
  uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  return uVar1;
}

