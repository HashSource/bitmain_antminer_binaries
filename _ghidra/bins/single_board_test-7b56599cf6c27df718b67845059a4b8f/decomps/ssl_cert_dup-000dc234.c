
int * ssl_cert_dup(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *ptr;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  void *__src;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  
  ptr = (int *)CRYPTO_zalloc(0x110,"ssl/ssl_cert.c",0x4c);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x14,0xdd,0x41,"ssl/ssl_cert.c",0x50);
    return (int *)0x0;
  }
  DataMemoryBarrier(0x1b);
  ptr[0x42] = 1;
  DataMemoryBarrier(0x1b);
  piVar8 = param_1 + 5;
  *ptr = (int)ptr + (*param_1 - (int)piVar8 & 0xfffffffcU) + 0x14;
  iVar3 = CRYPTO_THREAD_lock_new();
  ptr[0x43] = iVar3;
  if (iVar3 == 0) {
    ERR_put_error(0x14,0xdd,0x41,"ssl/ssl_cert.c",0x58);
    CRYPTO_free(ptr);
    return (int *)0x0;
  }
  if (param_1[1] != 0) {
    ptr[1] = param_1[1];
    EVP_PKEY_up_ref();
  }
  iVar3 = param_1[3];
  ptr[2] = param_1[2];
  ptr[3] = iVar3;
  piVar9 = param_1;
  piVar10 = ptr;
  piVar2 = ptr;
  do {
    iVar3 = *piVar8;
    if (iVar3 != 0) {
      piVar2[5] = iVar3;
      X509_up_ref(iVar3);
    }
    if (piVar8[1] != 0) {
      piVar2[6] = piVar8[1];
      EVP_PKEY_up_ref(piVar8[1]);
    }
    piVar1 = piVar8 + 2;
    piVar8 = piVar8 + 5;
    if (*piVar1 != 0) {
      iVar3 = X509_chain_up_ref(*piVar1);
      piVar2[7] = iVar3;
      if (iVar3 != 0) goto LAB_000dc2dc;
      iVar3 = 0x75;
LAB_000dc43a:
      ERR_put_error(0x14,0xdd,0x41,"ssl/ssl_cert.c",iVar3);
      goto LAB_000dc446;
    }
LAB_000dc2dc:
    if (piVar9[8] != 0) {
      pvVar4 = CRYPTO_malloc(piVar9[9],"ssl/ssl_cert.c",0x7c);
      piVar10[8] = (int)pvVar4;
      if (pvVar4 == (void *)0x0) {
        iVar3 = 0x7e;
        goto LAB_000dc43a;
      }
      __src = (void *)piVar9[8];
      piVar10[9] = piVar9[9];
      memcpy(pvVar4,__src,piVar9[9]);
    }
    piVar9 = piVar9 + 5;
    piVar10 = piVar10 + 5;
    piVar2 = piVar2 + 5;
  } while (piVar8 != param_1 + 0x32);
  if (param_1[0x34] == 0) {
    ptr[0x34] = 0;
    iVar3 = param_1[0x36];
    if (iVar3 != 0) goto LAB_000dc352;
LAB_000dc42e:
    ptr[0x36] = iVar3;
  }
  else {
    pvVar4 = CRYPTO_malloc(param_1[0x35] << 1,"ssl/ssl_cert.c",0x8a);
    ptr[0x34] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_000dc446;
    memcpy(pvVar4,(void *)param_1[0x34],param_1[0x35] << 1);
    ptr[0x35] = param_1[0x35];
    iVar3 = param_1[0x36];
    if (iVar3 == 0) goto LAB_000dc42e;
LAB_000dc352:
    pvVar4 = CRYPTO_malloc(param_1[0x37] << 1,"ssl/ssl_cert.c",0x95);
    ptr[0x36] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_000dc446;
    memcpy(pvVar4,(void *)param_1[0x36],param_1[0x37] << 1);
    ptr[0x37] = param_1[0x37];
  }
  if (param_1[0x32] != 0) {
    iVar3 = CRYPTO_memdup(param_1[0x32],param_1[0x33],"ssl/ssl_cert.c",0x9f);
    ptr[0x32] = iVar3;
    if (iVar3 == 0) goto LAB_000dc446;
    ptr[0x33] = param_1[0x33];
  }
  iVar3 = param_1[0x3b];
  iVar6 = param_1[0x38];
  iVar7 = param_1[0x39];
  ptr[4] = param_1[4];
  ptr[0x38] = iVar6;
  ptr[0x39] = iVar7;
  if (iVar3 != 0) {
    X509_STORE_up_ref();
    ptr[0x3b] = param_1[0x3b];
  }
  if (param_1[0x3a] != 0) {
    X509_STORE_up_ref();
    ptr[0x3a] = param_1[0x3a];
  }
  iVar3 = param_1[0x3f];
  iVar6 = param_1[0x40];
  ptr[0x3e] = param_1[0x3e];
  ptr[0x3f] = iVar3;
  ptr[0x40] = iVar6;
  iVar3 = custom_exts_copy(ptr + 0x3c,param_1 + 0x3c);
  if (iVar3 != 0) {
    if ((char *)param_1[0x41] != (char *)0x0) {
      pcVar5 = CRYPTO_strdup((char *)param_1[0x41],"ssl/ssl_cert.c",0xbc);
      ptr[0x41] = (int)pcVar5;
      if (pcVar5 == (char *)0x0) goto LAB_000dc446;
    }
    return ptr;
  }
LAB_000dc446:
  ssl_cert_free(ptr);
  return (int *)0x0;
}

