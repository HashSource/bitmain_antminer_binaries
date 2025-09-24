
undefined4 SSL_CONF_CTX_finish(int *param_1)

{
  SSL_CTX *ctx;
  int iVar1;
  SSL *pSVar2;
  int iVar3;
  char *pcVar4;
  
  ctx = (SSL_CTX *)param_1[3];
  if (ctx == (SSL_CTX *)0x0) {
    if (param_1[4] != 0) {
      iVar3 = *(int *)(param_1[4] + 0x404);
      goto LAB_001029ee;
    }
    iVar3 = param_1[0x15];
    if (iVar3 == 0) {
      return 1;
    }
  }
  else {
    iVar3 = ctx->verify_mode;
LAB_001029ee:
    if ((iVar3 != 0) && (*param_1 << 0x19 < 0)) {
      pcVar4 = (char *)param_1[6];
      if ((pcVar4 != (char *)0x0) && ((*(int *)(iVar3 + 0x18) == 0 && (*param_1 << 0x1a < 0)))) {
        if (ctx == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102ae6;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file(ctx,pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102ae6:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[7];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x2c) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102b3c;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102b3c:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[8];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x40) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102b6a;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102b6a:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[9];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x54) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102b96;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102b96:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[10];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x68) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102bc2;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102bc2:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[0xb];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x7c) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102bec;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102bec:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[0xc];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0x90) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102c16;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102c16:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[0xd];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0xa4) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102b10;
        }
        else {
          iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102b10:
            iVar1 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
      }
      pcVar4 = (char *)param_1[0xe];
      if (((pcVar4 != (char *)0x0) && (*(int *)(iVar3 + 0xb8) == 0)) && (*param_1 << 0x1a < 0)) {
        if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) goto LAB_00102ab2;
        }
        else {
          iVar3 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],pcVar4,1);
          pSVar2 = (SSL *)param_1[4];
          if (pSVar2 != (SSL *)0x0) {
LAB_00102ab2:
            iVar3 = SSL_use_PrivateKey_file(pSVar2,pcVar4,1);
          }
          if (iVar3 < 1) {
            return 0;
          }
        }
      }
    }
    iVar3 = param_1[0x15];
    if (iVar3 == 0) {
      return 1;
    }
    if (param_1[4] != 0) {
      SSL_set0_CA_list();
      goto LAB_00102a6e;
    }
    if (param_1[3] != 0) {
      SSL_CTX_set0_CA_list();
      param_1[0x15] = 0;
      return 1;
    }
  }
  OPENSSL_sk_pop_free(iVar3,0x16da91);
LAB_00102a6e:
  param_1[0x15] = 0;
  return 1;
}

