
undefined4 ssl3_output_cert_chain(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  X509_STORE_CTX *ctx;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  X509 *pXVar6;
  int iVar7;
  X509_STORE *store;
  uchar *apuStack_2c [2];
  
  iVar1 = WPACKET_start_sub_packet_len__(param_2,3);
  if (iVar1 == 0) {
    uVar4 = 0x3f3;
    goto LAB_000efc3a;
  }
  if ((param_3 != (undefined4 *)0x0) && (pXVar6 = (X509 *)*param_3, pXVar6 != (X509 *)0x0)) {
    iVar7 = param_3[2];
    iVar1 = iVar7;
    if (iVar7 == 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x4d0) + 0x98);
      uVar5 = (uint)(*(int *)(param_1 + 0x4f0) << 0x1c) >> 0x1f;
      if (iVar1 != 0) {
        uVar5 = 1;
      }
      if ((uVar5 == 0) &&
         ((store = *(X509_STORE **)(*(int *)(param_1 + 0x404) + 0xe8), store != (X509_STORE *)0x0 ||
          (store = *(X509_STORE **)(*(int *)(param_1 + 0x4d0) + 0x10), iVar1 = iVar7,
          store != (X509_STORE *)0x0)))) {
        ctx = X509_STORE_CTX_new();
        if (ctx == (X509_STORE_CTX *)0x0) {
          ossl_statem_fatal(param_1,0x50,0x13c,0x41,"ssl/statem/statem_lib.c",0x3b0);
          return 0;
        }
        iVar1 = X509_STORE_CTX_init(ctx,store,pXVar6,(stack_st_X509 *)0x0);
        if (iVar1 == 0) {
          X509_STORE_CTX_free(ctx);
          ossl_statem_fatal(param_1,0x50,0x13c,0xb,"ssl/statem/statem_lib.c",0x3b6);
          return 0;
        }
        X509_verify_cert(ctx);
        ERR_clear_error();
        uVar4 = X509_STORE_CTX_get0_chain(ctx);
        iVar7 = ssl_security_cert_chain(param_1,uVar4,0);
        if (iVar7 != 1) {
          X509_STORE_CTX_free(ctx);
          uVar4 = 0x3cc;
          goto LAB_000efcd6;
        }
        iVar1 = OPENSSL_sk_num(uVar4);
        if (0 < iVar1) {
          iVar7 = 0;
          do {
            pXVar6 = (X509 *)OPENSSL_sk_value(uVar4,iVar7);
            iVar3 = i2d_X509(pXVar6,(uchar **)0x0);
            if (iVar3 < 0) {
              ossl_statem_fatal(param_1,0x50,0x1ed,7,"ssl/statem/statem_lib.c",0x37a);
LAB_000efd70:
              X509_STORE_CTX_free(ctx);
              return 0;
            }
            iVar2 = WPACKET_sub_allocate_bytes__(param_2,iVar3,apuStack_2c,3);
            if ((iVar2 == 0) || (iVar2 = i2d_X509(pXVar6,apuStack_2c), iVar3 != iVar2)) {
              ossl_statem_fatal(param_1,0x50,0x1ed,0x44,"ssl/statem/statem_lib.c",0x380);
              goto LAB_000efd70;
            }
            if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
              iVar3 = **(int **)(param_1 + 4);
              iVar2 = iVar3 + -0x10000;
              if (iVar2 != 0) {
                iVar2 = 1;
              }
              if (iVar3 < 0x304) {
                iVar2 = 0;
              }
              if ((iVar2 != 0) &&
                 (iVar3 = tls_construct_extensions(param_1,param_2,0x1000,pXVar6,iVar7), iVar3 == 0)
                 ) goto LAB_000efd70;
            }
            iVar7 = iVar7 + 1;
          } while (iVar1 != iVar7);
        }
        X509_STORE_CTX_free(ctx);
        goto LAB_000efc1e;
      }
    }
    iVar7 = ssl_security_cert_chain(param_1,iVar1,pXVar6,0);
    if (iVar7 != 1) {
      uVar4 = 0x3dd;
LAB_000efcd6:
      ossl_statem_fatal(param_1,0x50,0x13c,iVar7,"ssl/statem/statem_lib.c",uVar4);
      return 0;
    }
    iVar3 = ssl_add_cert_to_wpacket(param_1,param_2,pXVar6,0);
    iVar7 = 0;
    while( true ) {
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = OPENSSL_sk_num(iVar1);
      if (iVar3 <= iVar7) break;
      uVar4 = OPENSSL_sk_value(iVar1,iVar7);
      iVar3 = ssl_add_cert_to_wpacket(param_1,param_2,uVar4,iVar7 + 1);
      iVar7 = iVar7 + 1;
    }
  }
LAB_000efc1e:
  iVar1 = WPACKET_close(param_2);
  if (iVar1 != 0) {
    return 1;
  }
  uVar4 = 0x3fc;
LAB_000efc3a:
  ossl_statem_fatal(param_1,0x50,0x93,0x44,"ssl/statem/statem_lib.c",uVar4);
  return 0;
}

