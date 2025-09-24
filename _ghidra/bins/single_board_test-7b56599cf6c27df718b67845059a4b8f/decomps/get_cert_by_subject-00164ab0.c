
undefined4
get_cert_by_subject(X509_LOOKUP *param_1,int param_2,X509_NAME *param_3,undefined4 *param_4)

{
  BUF_MEM *a;
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  ulong *ptr;
  char *pcVar8;
  X509_STORE *pXVar9;
  ulong uVar10;
  char *pcVar11;
  int local_18c;
  int local_188;
  int local_160;
  undefined1 *local_15c;
  ulong local_158 [2];
  stat sStack_150;
  undefined1 auStack_f8 [12];
  X509_NAME *local_ec;
  X509_NAME *local_d0;
  
  if (param_3 == (X509_NAME *)0x0) {
    return 0;
  }
  local_160 = param_2;
  if (param_2 == 1) {
    local_15c = auStack_f8;
    pcVar11 = "";
    local_d0 = param_3;
    a = BUF_MEM_new();
  }
  else {
    if (param_2 != 2) {
      ERR_put_error(0xb,0x67,0x70,"crypto/x509/by_dir.c",0xef);
      BUF_MEM_free((BUF_MEM *)0x0);
      return 0;
    }
    local_15c = auStack_f8;
    pcVar11 = "r";
    local_ec = param_3;
    a = BUF_MEM_new();
  }
  if (a == (BUF_MEM *)0x0) {
    ERR_put_error(0xb,0x67,7,"crypto/x509/by_dir.c",0xf4);
    BUF_MEM_free((BUF_MEM *)0x0);
    return 0;
  }
  pcVar8 = param_1->method_data;
  local_18c = 0;
  uVar1 = X509_NAME_hash(param_3);
  do {
    iVar2 = OPENSSL_sk_num(*(undefined4 *)(pcVar8 + 4));
    if (iVar2 <= local_18c) {
      BUF_MEM_free(a);
      return 0;
    }
    puVar3 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(pcVar8 + 4),local_18c);
    sVar4 = strlen((char *)*puVar3);
    iVar2 = BUF_MEM_grow(a,sVar4 + 0x11);
    if (iVar2 == 0) {
      iVar2 = 0x103;
      goto LAB_00164de2;
    }
    if (param_2 == 2) {
      if (puVar3[2] == 0) {
        uVar10 = 0;
        local_188 = 0;
      }
      else {
        local_158[0] = uVar1;
        CRYPTO_THREAD_read_lock(*(undefined4 *)(pcVar8 + 8));
        iVar2 = OPENSSL_sk_find(puVar3[2],local_158);
        if (iVar2 < 0) {
          uVar10 = 0;
          local_188 = 0;
        }
        else {
          local_188 = OPENSSL_sk_value(puVar3[2]);
          uVar10 = *(ulong *)(local_188 + 4);
        }
        CRYPTO_THREAD_unlock(*(undefined4 *)(pcVar8 + 8));
      }
      while( true ) {
        BIO_snprintf(a->data,a->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar11,uVar10);
        iVar2 = __xstat(3,a->data,&sStack_150);
        if (iVar2 < 0) break;
        iVar2 = X509_load_crl_file(param_1,a->data,puVar3[1]);
        if (iVar2 == 0) {
          X509_STORE_lock(param_1->store_ctx);
          pXVar9 = param_1->store_ctx;
          goto LAB_00164c78;
        }
        uVar10 = uVar10 + 1;
      }
      X509_STORE_lock(param_1->store_ctx);
      pXVar9 = param_1->store_ctx;
LAB_00164c78:
      uVar6 = OPENSSL_sk_find(pXVar9->objs,&local_160);
      puVar7 = (undefined4 *)OPENSSL_sk_value(param_1->store_ctx->objs,uVar6);
      X509_STORE_unlock(param_1->store_ctx);
      CRYPTO_THREAD_write_lock(*(undefined4 *)(pcVar8 + 8));
      if (local_188 == 0) {
        local_158[0] = uVar1;
        uVar6 = OPENSSL_sk_find(puVar3[2],local_158);
        local_188 = OPENSSL_sk_value(puVar3[2],uVar6);
        if (local_188 != 0) goto LAB_00164ca6;
        ptr = (ulong *)CRYPTO_malloc(8,"crypto/x509/by_dir.c",0x15d);
        if (ptr == (ulong *)0x0) {
          CRYPTO_THREAD_unlock(*(undefined4 *)(pcVar8 + 8));
          iVar2 = 0x160;
LAB_00164de2:
          ERR_put_error(0xb,0x67,0x41,"crypto/x509/by_dir.c",iVar2);
          BUF_MEM_free(a);
          return 0;
        }
        *ptr = uVar1;
        ptr[1] = uVar10;
        iVar2 = OPENSSL_sk_push(puVar3[2],ptr);
        if (iVar2 == 0) {
          CRYPTO_THREAD_unlock(*(undefined4 *)(pcVar8 + 8));
          CRYPTO_free(ptr);
          iVar2 = 0x169;
          goto LAB_00164de2;
        }
      }
      else {
LAB_00164ca6:
        iVar5 = *(int *)(local_188 + 4);
        iVar2 = iVar5;
        if (iVar5 < (int)uVar10) {
          iVar2 = local_188;
        }
        if (iVar5 < (int)uVar10) {
          *(ulong *)(iVar2 + 4) = uVar10;
        }
      }
      CRYPTO_THREAD_unlock(*(undefined4 *)(pcVar8 + 8));
    }
    else {
      iVar2 = 0;
      if (param_2 == 1) {
        do {
          BIO_snprintf(a->data,a->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar11,iVar2);
          iVar5 = __xstat(3,a->data,&sStack_150);
          if (iVar5 < 0) goto LAB_00164bb4;
          iVar5 = X509_load_cert_file(param_1,a->data,puVar3[1]);
          iVar2 = iVar2 + 1;
        } while (iVar5 != 0);
        X509_STORE_lock(param_1->store_ctx);
        uVar6 = OPENSSL_sk_find(param_1->store_ctx->objs,&local_160);
        puVar7 = (undefined4 *)OPENSSL_sk_value(param_1->store_ctx->objs,uVar6);
        X509_STORE_unlock(param_1->store_ctx);
      }
      else {
        do {
          BIO_snprintf(a->data,a->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar11,iVar2);
          iVar5 = __xstat(3,a->data,&sStack_150);
          iVar2 = iVar2 + 1;
        } while (-1 < iVar5);
LAB_00164bb4:
        X509_STORE_lock(param_1->store_ctx);
        uVar6 = OPENSSL_sk_find(param_1->store_ctx->objs,&local_160);
        puVar7 = (undefined4 *)OPENSSL_sk_value(param_1->store_ctx->objs,uVar6);
        X509_STORE_unlock(param_1->store_ctx);
      }
    }
    if (puVar7 != (undefined4 *)0x0) {
      *param_4 = *puVar7;
      param_4[1] = puVar7[1];
      ERR_clear_error();
      BUF_MEM_free(a);
      return 1;
    }
    local_18c = local_18c + 1;
  } while( true );
}

