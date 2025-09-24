
X509_STORE_CTX * ssl_build_cert_chain(int param_1,int param_2,uint param_3)

{
  X509_STORE_CTX *ctx;
  int iVar1;
  X509 *pXVar2;
  undefined4 uVar3;
  int iVar4;
  X509_STORE *pXVar5;
  char *pcVar6;
  stack_st_X509 *psVar7;
  X509_STORE_CTX *reason;
  int *piVar8;
  undefined4 *puVar9;
  X509_STORE *ctx_00;
  
  if (param_1 == 0) {
    puVar9 = *(undefined4 **)(param_2 + 0xc0);
  }
  else {
    puVar9 = *(undefined4 **)(param_1 + 0x404);
  }
  piVar8 = (int *)*puVar9;
  if (*piVar8 == 0) {
    ERR_put_error(0x14,0x14c,0xb3,"ssl/ssl_cert.c",0x300);
    ctx_00 = (X509_STORE *)0x0;
    ctx = (X509_STORE_CTX *)0x0;
  }
  else {
    if ((param_3 & 4) != 0) {
      ctx_00 = X509_STORE_new();
      iVar1 = 0;
      pXVar5 = ctx_00;
      while (pXVar5 != (X509_STORE *)0x0) {
        iVar4 = OPENSSL_sk_num(piVar8[2]);
        if (iVar4 <= iVar1) {
          iVar1 = X509_STORE_add_cert(ctx_00,(X509 *)*piVar8);
          psVar7 = (stack_st_X509 *)0x0;
          if (iVar1 != 0) goto LAB_000dcf52;
          break;
        }
        pXVar2 = (X509 *)OPENSSL_sk_value(piVar8[2],iVar1);
        pXVar5 = (X509_STORE *)X509_STORE_add_cert(ctx_00,pXVar2);
        iVar1 = iVar1 + 1;
      }
      reason = (X509_STORE_CTX *)0x0;
      X509_STORE_free(ctx_00);
      ctx = reason;
      goto LAB_000dd014;
    }
    ctx_00 = (X509_STORE *)puVar9[0x3a];
    if (ctx_00 == (X509_STORE *)0x0) {
      if (param_1 == 0) {
        ctx_00 = *(X509_STORE **)(param_2 + 0x10);
      }
      else {
        ctx_00 = *(X509_STORE **)(*(int *)(param_1 + 0x4d0) + 0x10);
      }
    }
    psVar7 = (stack_st_X509 *)(param_3 & 1);
    if (psVar7 != (stack_st_X509 *)0x0) {
      psVar7 = (stack_st_X509 *)piVar8[2];
    }
LAB_000dcf52:
    ctx = X509_STORE_CTX_new();
    if (ctx == (X509_STORE_CTX *)0x0) {
      ERR_put_error(0x14,0x14c,0x41,"ssl/ssl_cert.c",0x31e);
    }
    else {
      iVar1 = X509_STORE_CTX_init(ctx,ctx_00,(X509 *)*piVar8,psVar7);
      if (iVar1 == 0) {
        ERR_put_error(0x14,0x14c,0xb,"ssl/ssl_cert.c",0x322);
      }
      else {
        X509_STORE_CTX_set_flags(ctx,puVar9[4] & 0x30000);
        iVar1 = X509_verify_cert(ctx);
        if (iVar1 < 1) {
          if ((param_3 & 8) == 0) {
            ERR_put_error(0x14,0x14c,0x86,"ssl/ssl_cert.c",0x333);
            iVar1 = X509_STORE_CTX_get_error(ctx);
            pcVar6 = X509_verify_cert_error_string(iVar1);
            ERR_add_error_data(2,"Verify error:",pcVar6);
            goto LAB_000dcf82;
          }
          if ((int)(param_3 << 0x1b) < 0) {
            ERR_clear_error();
            reason = (X509_STORE_CTX *)0x2;
          }
          else {
            reason = (X509_STORE_CTX *)0x2;
          }
        }
        else {
          reason = (X509_STORE_CTX *)0x0;
        }
        psVar7 = X509_STORE_CTX_get1_chain(ctx);
        pXVar2 = (X509 *)OPENSSL_sk_shift();
        X509_free(pXVar2);
        if (((int)(param_3 << 0x1e) < 0) && (iVar1 = OPENSSL_sk_num(psVar7), 0 < iVar1)) {
          iVar1 = OPENSSL_sk_num(psVar7);
          OPENSSL_sk_value(psVar7,iVar1 + -1);
          iVar1 = X509_get_extension_flags();
          if (iVar1 << 0x12 < 0) {
            pXVar2 = (X509 *)OPENSSL_sk_pop(psVar7);
            X509_free(pXVar2);
          }
        }
        iVar1 = 0;
        do {
          iVar4 = OPENSSL_sk_num(psVar7);
          if (iVar4 <= iVar1) {
            OPENSSL_sk_pop_free(piVar8[2],(undefined *)0x16e591);
            piVar8[2] = (int)psVar7;
            if (reason == (X509_STORE_CTX *)0x0) {
              reason = (X509_STORE_CTX *)0x1;
            }
            goto joined_r0x000dd00c;
          }
          uVar3 = OPENSSL_sk_value(psVar7,iVar1);
          reason = (X509_STORE_CTX *)ssl_security_cert(param_1,param_2,uVar3,0,0);
          iVar1 = iVar1 + 1;
        } while (reason == (X509_STORE_CTX *)0x1);
        ERR_put_error(0x14,0x14c,(int)reason,"ssl/ssl_cert.c",0x34f);
        OPENSSL_sk_pop_free(psVar7,(undefined *)0x16e591);
      }
    }
  }
LAB_000dcf82:
  reason = (X509_STORE_CTX *)0x0;
joined_r0x000dd00c:
  if ((param_3 & 4) == 0) {
    X509_STORE_CTX_free(ctx);
    return reason;
  }
  X509_STORE_free(ctx_00);
LAB_000dd014:
  X509_STORE_CTX_free(ctx);
  return reason;
}

