
int * ssl_cert_dup(int *param_1)

{
  int *__s;
  RSA *r;
  DH *pDVar1;
  BIGNUM *pBVar2;
  EC_KEY *pEVar3;
  void *pvVar4;
  EVP_MD *pEVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  __s = (int *)CRYPTO_malloc(0x170,DAT_0007cc6c,0xde);
  if (__s == (int *)0x0) {
    ERR_put_error(0x14,0xdd,0x41,DAT_0007d2fc,0xe0);
    return (int *)0x0;
  }
  memset(__s,0,0x170);
  iVar9 = *param_1;
  iVar10 = param_1[1];
  iVar6 = param_1[3];
  iVar8 = param_1[4];
  r = (RSA *)param_1[7];
  __s[2] = param_1[2];
  *__s = (int)__s + (iVar9 - (int)(param_1 + 0xf) & 0xfffffffcU) + 0x3c;
  __s[1] = iVar10;
  iVar9 = param_1[5];
  __s[3] = iVar6;
  __s[4] = iVar8;
  __s[5] = iVar9;
  if (r != (RSA *)0x0) {
    RSA_up_ref(r);
    __s[7] = param_1[7];
  }
  pDVar1 = (DH *)param_1[9];
  __s[8] = param_1[8];
  if (pDVar1 == (DH *)0x0) goto LAB_0007ca56;
  pDVar1 = DHparams_dup(pDVar1);
  __s[9] = (int)pDVar1;
  if (pDVar1 == (DH *)0x0) {
    ERR_put_error(0x14,0xdd,5,DAT_0007d2fc,0xfe);
    goto LAB_0007cff4;
  }
  iVar6 = param_1[9];
  if (*(BIGNUM **)(iVar6 + 0x18) != (BIGNUM *)0x0) {
    pBVar2 = BN_dup(*(BIGNUM **)(iVar6 + 0x18));
    iVar6 = 0x104;
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar6 = param_1[9];
      *(BIGNUM **)(__s[9] + 0x18) = pBVar2;
      goto LAB_0007ca44;
    }
LAB_0007d27c:
    ERR_put_error(0x14,0xdd,3,DAT_0007d2ac,iVar6);
    goto LAB_0007cff4;
  }
LAB_0007ca44:
  if (*(BIGNUM **)(iVar6 + 0x14) != (BIGNUM *)0x0) {
    pBVar2 = BN_dup(*(BIGNUM **)(iVar6 + 0x14));
    if (pBVar2 == (BIGNUM *)0x0) {
      iVar6 = 0x10c;
      goto LAB_0007d27c;
    }
    *(BIGNUM **)(__s[9] + 0x14) = pBVar2;
  }
LAB_0007ca56:
  pEVar3 = (EC_KEY *)param_1[0xb];
  __s[10] = param_1[10];
  if (pEVar3 != (EC_KEY *)0x0) {
    pEVar3 = EC_KEY_dup(pEVar3);
    __s[0xb] = (int)pEVar3;
    if (pEVar3 == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0xdd,0x10,DAT_0007d2fc,0x119);
      goto LAB_0007cff4;
    }
  }
  iVar6 = param_1[0xf];
  iVar8 = param_1[0xd];
  __s[0xc] = param_1[0xc];
  __s[0xd] = iVar8;
  if (iVar6 != 0) {
    __s[0xf] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cc6c,0x126);
  }
  if (param_1[0x10] != 0) {
    __s[0x10] = param_1[0x10];
    CRYPTO_add_lock((int *)(param_1[0x10] + 8),1,10,DAT_0007cc6c,299);
  }
  if (param_1[0x12] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x12] = iVar6;
    if (iVar6 != 0) goto LAB_0007cab4;
LAB_0007cfda:
    ERR_put_error(0x14,0xdd,0x41,DAT_0007d2ac,0x131);
    goto LAB_0007cff4;
  }
LAB_0007cab4:
  iVar6 = param_1[0x13];
  __s[0x15] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x14],DAT_0007cc6c,0x13a);
    __s[0x13] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x13];
    __s[0x14] = param_1[0x14];
    memcpy(pvVar4,pvVar7,param_1[0x14]);
  }
  iVar6 = param_1[0x16];
  if (iVar6 != 0) {
    __s[0x16] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cc6c,0x126);
  }
  if (param_1[0x17] != 0) {
    __s[0x17] = param_1[0x17];
    CRYPTO_add_lock((int *)(param_1[0x17] + 8),1,10,DAT_0007cc6c,299);
  }
  if (param_1[0x19] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x19] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x1a];
  __s[0x1c] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x1b],DAT_0007cc6c,0x13a);
    __s[0x1a] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x1a];
    __s[0x1b] = param_1[0x1b];
    memcpy(pvVar4,pvVar7,param_1[0x1b]);
  }
  iVar6 = param_1[0x1d];
  if (iVar6 != 0) {
    __s[0x1d] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cc6c,0x126);
  }
  if (param_1[0x1e] != 0) {
    __s[0x1e] = param_1[0x1e];
    CRYPTO_add_lock((int *)(param_1[0x1e] + 8),1,10,DAT_0007cc6c,299);
  }
  if (param_1[0x20] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x20] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x21];
  __s[0x23] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x22],DAT_0007cc6c,0x13a);
    __s[0x21] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x21];
    __s[0x22] = param_1[0x22];
    memcpy(pvVar4,pvVar7,param_1[0x22]);
  }
  iVar6 = param_1[0x24];
  if (iVar6 != 0) {
    __s[0x24] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cc6c,0x126);
  }
  if (param_1[0x25] != 0) {
    __s[0x25] = param_1[0x25];
    CRYPTO_add_lock((int *)(param_1[0x25] + 8),1,10,DAT_0007cc6c,299);
  }
  if (param_1[0x27] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x27] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x28];
  __s[0x2a] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x29],DAT_0007cc6c,0x13a);
    __s[0x28] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x28];
    __s[0x29] = param_1[0x29];
    memcpy(pvVar4,pvVar7,param_1[0x29]);
  }
  iVar6 = param_1[0x2b];
  if (iVar6 != 0) {
    __s[0x2b] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cc6c,0x126);
  }
  if (param_1[0x2c] != 0) {
    __s[0x2c] = param_1[0x2c];
    CRYPTO_add_lock((int *)(param_1[0x2c] + 8),1,10,DAT_0007cf98,299);
  }
  if (param_1[0x2e] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x2e] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x2f];
  __s[0x31] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x30],DAT_0007cf98,0x13a);
    __s[0x2f] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x2f];
    __s[0x30] = param_1[0x30];
    memcpy(pvVar4,pvVar7,param_1[0x30]);
  }
  iVar6 = param_1[0x32];
  if (iVar6 != 0) {
    __s[0x32] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cf98,0x126);
  }
  if (param_1[0x33] != 0) {
    __s[0x33] = param_1[0x33];
    CRYPTO_add_lock((int *)(param_1[0x33] + 8),1,10,DAT_0007cf98,299);
  }
  if (param_1[0x35] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x35] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x36];
  __s[0x38] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x37],DAT_0007cf98,0x13a);
    __s[0x36] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x36];
    __s[0x37] = param_1[0x37];
    memcpy(pvVar4,pvVar7,param_1[0x37]);
  }
  iVar6 = param_1[0x39];
  if (iVar6 != 0) {
    __s[0x39] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cf98,0x126);
  }
  if (param_1[0x3a] != 0) {
    __s[0x3a] = param_1[0x3a];
    CRYPTO_add_lock((int *)(param_1[0x3a] + 8),1,10,DAT_0007cf98,299);
  }
  if (param_1[0x3c] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x3c] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x3d];
  __s[0x3f] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x3e],DAT_0007cf98,0x13a);
    __s[0x3d] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007d294;
    pvVar7 = (void *)param_1[0x3d];
    __s[0x3e] = param_1[0x3e];
    memcpy(pvVar4,pvVar7,param_1[0x3e]);
  }
  iVar6 = param_1[0x40];
  if (iVar6 != 0) {
    __s[0x40] = iVar6;
    CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,DAT_0007cf98,0x126);
  }
  if (param_1[0x41] != 0) {
    __s[0x41] = param_1[0x41];
    CRYPTO_add_lock((int *)(param_1[0x41] + 8),1,10,DAT_0007cf98,299);
  }
  if (param_1[0x43] != 0) {
    iVar6 = X509_chain_up_ref();
    __s[0x43] = iVar6;
    if (iVar6 == 0) goto LAB_0007cfda;
  }
  iVar6 = param_1[0x44];
  __s[0x46] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x45],DAT_0007cf98,0x13a);
    __s[0x44] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
LAB_0007d294:
      ERR_put_error(0x14,0xdd,0x41,DAT_0007d2ac,0x13c);
      return (int *)0x0;
    }
    pvVar7 = (void *)param_1[0x44];
    __s[0x45] = param_1[0x45];
    memcpy(pvVar4,pvVar7,param_1[0x45]);
  }
  __s[0x5b] = 1;
  pEVar5 = EVP_sha1();
  __s[0x1f] = (int)pEVar5;
  pEVar5 = EVP_sha1();
  __s[0x18] = (int)pEVar5;
  pEVar5 = EVP_sha1();
  __s[0x11] = (int)pEVar5;
  pEVar5 = EVP_sha1();
  iVar6 = param_1[0x4b];
  __s[0x34] = (int)pEVar5;
  __s[0x49] = 0;
  __s[0x4a] = 0;
  if (iVar6 == 0) {
    iVar6 = param_1[0x4d];
    __s[0x4b] = 0;
    if (iVar6 != 0) goto LAB_0007cedc;
LAB_0007cfd4:
    __s[0x4d] = iVar6;
  }
  else {
    pvVar4 = CRYPTO_malloc(param_1[0x4c],DAT_0007cf98,0x154);
    __s[0x4b] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007cff4;
    memcpy(pvVar4,(void *)param_1[0x4b],param_1[0x4c]);
    __s[0x4c] = param_1[0x4c];
    iVar6 = param_1[0x4d];
    if (iVar6 == 0) goto LAB_0007cfd4;
LAB_0007cedc:
    pvVar4 = CRYPTO_malloc(param_1[0x4e],DAT_0007cf98,0x15d);
    __s[0x4d] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007cff4;
    memcpy(pvVar4,(void *)param_1[0x4d],param_1[0x4e]);
    __s[0x4e] = param_1[0x4e];
  }
  iVar6 = param_1[0x47];
  __s[0x4f] = 0;
  if (iVar6 != 0) {
    pvVar4 = CRYPTO_malloc(param_1[0x48],DAT_0007cf98,0x169);
    __s[0x47] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_0007cff4;
    memcpy(pvVar4,(void *)param_1[0x47],param_1[0x48]);
    __s[0x48] = param_1[0x48];
  }
  iVar8 = param_1[0x51];
  iVar9 = param_1[0x52];
  iVar6 = param_1[0x54];
  __s[0xe] = param_1[0xe];
  __s[0x51] = iVar8;
  __s[0x52] = iVar9;
  if (iVar6 != 0) {
    CRYPTO_add_lock((int *)(iVar6 + 0x44),1,0xb,DAT_0007cf98,0x177);
    __s[0x54] = param_1[0x54];
  }
  if (param_1[0x53] != 0) {
    CRYPTO_add_lock((int *)(param_1[0x53] + 0x44),1,0xb,DAT_0007cf98,0x17c);
    __s[0x53] = param_1[0x53];
  }
  __s[0x55] = 0;
  iVar6 = custom_exts_copy(__s + 0x57,param_1 + 0x57);
  if ((iVar6 != 0) && (iVar6 = custom_exts_copy(__s + 0x59,param_1 + 0x59), iVar6 != 0)) {
    return __s;
  }
LAB_0007cff4:
  if ((RSA *)__s[7] != (RSA *)0x0) {
    RSA_free((RSA *)__s[7]);
  }
  if ((DH *)__s[9] != (DH *)0x0) {
    DH_free((DH *)__s[9]);
  }
  if ((EC_KEY *)__s[0xb] != (EC_KEY *)0x0) {
    EC_KEY_free((EC_KEY *)__s[0xb]);
  }
  custom_exts_free(__s + 0x57);
  custom_exts_free(__s + 0x59);
  if ((X509 *)__s[0xf] != (X509 *)0x0) {
    X509_free((X509 *)__s[0xf]);
    __s[0xf] = 0;
  }
  if ((EVP_PKEY *)__s[0x10] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x10]);
    __s[0x10] = 0;
  }
  if ((_STACK *)__s[0x12] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x12],DAT_0007d2b0);
    __s[0x12] = 0;
  }
  if ((void *)__s[0x13] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x13]);
    __s[0x13] = 0;
    __s[0x14] = 0;
  }
  __s[0x15] = __s[0x15] & 0x100;
  if ((X509 *)__s[0x16] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x16]);
    __s[0x16] = 0;
  }
  if ((EVP_PKEY *)__s[0x17] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x17]);
    __s[0x17] = 0;
  }
  if ((_STACK *)__s[0x19] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x19],DAT_0007d2b0);
    __s[0x19] = 0;
  }
  if ((void *)__s[0x1a] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x1a]);
    __s[0x1a] = 0;
    __s[0x1b] = 0;
  }
  __s[0x1c] = __s[0x1c] & 0x100;
  if ((X509 *)__s[0x1d] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x1d]);
    __s[0x1d] = 0;
  }
  if ((EVP_PKEY *)__s[0x1e] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x1e]);
    __s[0x1e] = 0;
  }
  if ((_STACK *)__s[0x20] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x20],DAT_0007d2b0);
    __s[0x20] = 0;
  }
  if ((void *)__s[0x21] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x21]);
    __s[0x21] = 0;
    __s[0x22] = 0;
  }
  __s[0x23] = __s[0x23] & 0x100;
  if ((X509 *)__s[0x24] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x24]);
    __s[0x24] = 0;
  }
  if ((EVP_PKEY *)__s[0x25] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x25]);
    __s[0x25] = 0;
  }
  if ((_STACK *)__s[0x27] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x27],DAT_0007d2b0);
    __s[0x27] = 0;
  }
  if ((void *)__s[0x28] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x28]);
    __s[0x28] = 0;
    __s[0x29] = 0;
  }
  __s[0x2a] = __s[0x2a] & 0x100;
  if ((X509 *)__s[0x2b] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x2b]);
    __s[0x2b] = 0;
  }
  if ((EVP_PKEY *)__s[0x2c] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x2c]);
    __s[0x2c] = 0;
  }
  if ((_STACK *)__s[0x2e] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x2e],DAT_0007d2b0);
    __s[0x2e] = 0;
  }
  if ((void *)__s[0x2f] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x2f]);
    __s[0x2f] = 0;
    __s[0x30] = 0;
  }
  __s[0x31] = __s[0x31] & 0x100;
  if ((X509 *)__s[0x32] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x32]);
    __s[0x32] = 0;
  }
  if ((EVP_PKEY *)__s[0x33] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x33]);
    __s[0x33] = 0;
  }
  if ((_STACK *)__s[0x35] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x35],DAT_0007d2b0);
    __s[0x35] = 0;
  }
  if ((void *)__s[0x36] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x36]);
    __s[0x36] = 0;
    __s[0x37] = 0;
  }
  __s[0x38] = __s[0x38] & 0x100;
  if ((X509 *)__s[0x39] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x39]);
    __s[0x39] = 0;
  }
  if ((EVP_PKEY *)__s[0x3a] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x3a]);
    __s[0x3a] = 0;
  }
  if ((_STACK *)__s[0x3c] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x3c],DAT_0007d2b0);
    __s[0x3c] = 0;
  }
  if ((void *)__s[0x3d] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x3d]);
    __s[0x3d] = 0;
    __s[0x3e] = 0;
  }
  __s[0x3f] = __s[0x3f] & 0x100;
  if ((X509 *)__s[0x40] != (X509 *)0x0) {
    X509_free((X509 *)__s[0x40]);
    __s[0x40] = 0;
  }
  if ((EVP_PKEY *)__s[0x41] != (EVP_PKEY *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)__s[0x41]);
    __s[0x41] = 0;
  }
  if ((_STACK *)__s[0x43] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)__s[0x43],DAT_0007d2b0);
    __s[0x43] = 0;
  }
  if ((void *)__s[0x44] != (void *)0x0) {
    CRYPTO_free((void *)__s[0x44]);
    __s[0x44] = 0;
    __s[0x45] = 0;
  }
  __s[0x46] = __s[0x46] & 0x100;
  return (int *)0x0;
}

