
void * aes_gcm_ctrl(undefined4 *param_1,undefined4 param_2,size_t param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  EVP_CIPHER *cipher;
  undefined4 uVar3;
  void *pvVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  size_t __n;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  switch(param_2) {
  case 0:
    cipher = (EVP_CIPHER *)*param_1;
    *(undefined4 *)(iVar1 + 0xf8) = 0;
    *(undefined4 *)(iVar1 + 0xfc) = 0;
    iVar6 = EVP_CIPHER_iv_length(cipher);
    *(int *)(iVar1 + 0x2ac) = iVar6;
    *(undefined4 **)(iVar1 + 0x2a8) = param_1 + 8;
    pvVar2 = (void *)0x1;
    *(undefined4 *)(iVar1 + 0x2b4) = 0;
    *(undefined4 *)(iVar1 + 0x2b0) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x2b8) = 0xffffffff;
    break;
  default:
    pvVar2 = (void *)0xffffffff;
    break;
  case 8:
    pvVar2 = (void *)EVP_CIPHER_CTX_get_cipher_data(param_4);
    if (*(int *)(iVar1 + 0x274) != 0) {
      if (*(int *)(iVar1 + 0x274) != iVar1) {
        return (void *)0x0;
      }
      *(void **)((int)pvVar2 + 0x274) = pvVar2;
    }
    puVar11 = *(undefined4 **)(iVar1 + 0x2a8);
    bVar12 = puVar11 == param_1 + 8;
    pvVar4 = pvVar2;
    if (bVar12) {
      puVar11 = param_4 + 8;
      pvVar4 = (void *)0x1;
    }
    if (bVar12) {
      *(undefined4 **)((int)pvVar2 + 0x2a8) = puVar11;
      return pvVar4;
    }
    pvVar4 = CRYPTO_malloc(*(int *)(iVar1 + 0x2ac),"crypto/evp/e_aes.c",0xb9b);
    *(void **)((int)pvVar2 + 0x2a8) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      memcpy(pvVar4,*(void **)(iVar1 + 0x2a8),*(size_t *)(iVar1 + 0x2ac));
      return (void *)0x1;
    }
    iVar6 = 0xb9c;
    pvVar2 = (void *)0x0;
LAB_0013390a:
    ERR_put_error(6,0xc4,0x41,"crypto/evp/e_aes.c",iVar6);
    break;
  case 9:
    if ((int)param_3 < 1) {
      return (void *)0x0;
    }
    if ((0x10 < (int)param_3) && (*(int *)(iVar1 + 0x2ac) < (int)param_3)) {
      if (*(undefined4 **)(iVar1 + 0x2a8) != param_1 + 8) {
        CRYPTO_free(*(undefined4 **)(iVar1 + 0x2a8));
      }
      pvVar2 = CRYPTO_malloc(param_3,"crypto/evp/e_aes.c",0xb36);
      iVar6 = 0xb37;
      *(void **)(iVar1 + 0x2a8) = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_0013390a;
    }
    *(size_t *)(iVar1 + 0x2ac) = param_3;
    pvVar2 = (void *)0x1;
    break;
  case 0x10:
    if (0xf < param_3 - 1) {
      return (void *)0x0;
    }
    if (param_1[2] == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar1 + 0x2b0) < 0) {
      return (void *)0x0;
    }
    memcpy(param_4,param_1 + 0xc,param_3);
    pvVar2 = (void *)0x1;
    break;
  case 0x11:
    if (0xf < param_3 - 1) {
      return (void *)0x0;
    }
    if (param_1[2] != 0) {
      return (void *)0x0;
    }
    memcpy(param_1 + 0xc,param_4,param_3);
    *(size_t *)(iVar1 + 0x2b0) = param_3;
    pvVar2 = (void *)0x1;
    break;
  case 0x12:
    if (param_3 == 0xffffffff) {
      memcpy(*(void **)(iVar1 + 0x2a8),param_4,*(size_t *)(iVar1 + 0x2ac));
      pvVar2 = (void *)0x1;
      *(undefined4 *)(iVar1 + 0x2b4) = 1;
    }
    else {
      if ((int)param_3 < 4) {
        return (void *)0x0;
      }
      if ((int)(*(int *)(iVar1 + 0x2ac) - param_3) < 8) {
        return (void *)0x0;
      }
      memcpy(*(void **)(iVar1 + 0x2a8),param_4,param_3);
      if ((param_1[2] != 0) &&
         (iVar6 = RAND_bytes((uchar *)(*(int *)(iVar1 + 0x2a8) + param_3),
                             *(int *)(iVar1 + 0x2ac) - param_3), iVar6 < 1)) {
        return (void *)0x0;
      }
      pvVar2 = (void *)0x1;
      *(undefined4 *)(iVar1 + 0x2b4) = 1;
    }
    break;
  case 0x13:
    if (*(int *)(iVar1 + 0x2b4) == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar1 + 0xf8) == 0) {
      return (void *)0x0;
    }
    CRYPTO_gcm128_setiv(iVar1 + 0x100,*(undefined4 *)(iVar1 + 0x2a8),*(undefined4 *)(iVar1 + 0x2ac))
    ;
    __n = *(size_t *)(iVar1 + 0x2ac);
    if (((int)param_3 < 1) || ((int)__n < (int)param_3)) {
      iVar6 = 0;
    }
    else {
      iVar6 = __n - param_3;
      __n = param_3;
    }
    memcpy(param_4,(void *)(iVar6 + *(int *)(iVar1 + 0x2a8)),__n);
    iVar6 = *(int *)(iVar1 + 0x2ac);
    iVar9 = *(int *)(iVar1 + 0x2a8);
    cVar5 = *(char *)(iVar9 + iVar6 + -1) + '\x01';
    *(char *)(iVar9 + iVar6 + -1) = cVar5;
    if (((((cVar5 == '\0') &&
          (cVar5 = *(char *)(iVar9 + iVar6 + -2) + '\x01', *(char *)(iVar9 + iVar6 + -2) = cVar5,
          cVar5 == '\0')) &&
         (cVar5 = *(char *)(iVar9 + iVar6 + -3) + '\x01', *(char *)(iVar9 + iVar6 + -3) = cVar5,
         cVar5 == '\0')) &&
        ((cVar5 = *(char *)(iVar9 + iVar6 + -4) + '\x01', *(char *)(iVar9 + iVar6 + -4) = cVar5,
         cVar5 == '\0' &&
         (cVar5 = *(char *)(iVar9 + iVar6 + -5) + '\x01', *(char *)(iVar9 + iVar6 + -5) = cVar5,
         cVar5 == '\0')))) &&
       ((cVar5 = *(char *)(iVar9 + iVar6 + -6) + '\x01', *(char *)(iVar9 + iVar6 + -6) = cVar5,
        cVar5 == '\0' &&
        (cVar5 = *(char *)(iVar9 + iVar6 + -7) + '\x01', *(char *)(iVar9 + iVar6 + -7) = cVar5,
        cVar5 == '\0')))) {
      *(char *)(iVar9 + iVar6 + -8) = *(char *)(iVar9 + iVar6 + -8) + '\x01';
    }
    goto LAB_00133ad4;
  case 0x16:
    if (param_3 == 0xd) {
      uVar3 = *param_4;
      uVar7 = param_4[1];
      param_1[0xe] = param_4[2];
      param_1[0xc] = uVar3;
      param_1[0xd] = uVar7;
      *(undefined1 *)(param_1 + 0xf) = *(undefined1 *)(param_4 + 3);
      *(undefined4 *)(iVar1 + 0x2b8) = 0xd;
      uVar10 = (uint)CONCAT11(*(undefined1 *)((int)param_1 + 0x3b),*(undefined1 *)(param_1 + 0xf));
      if (7 < uVar10) {
        uVar8 = uVar10 - 8;
        if (param_1[2] == 0) {
          if (uVar8 < 0x10) {
            return (void *)0x0;
          }
          uVar8 = uVar10 - 0x18;
        }
        *(char *)(param_1 + 0xf) = (char)uVar8;
        *(char *)((int)param_1 + 0x3b) = (char)(uVar8 >> 8);
        return (void *)0x10;
      }
    }
    return (void *)0x0;
  case 0x18:
    if (*(int *)(iVar1 + 0x2b4) == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar1 + 0xf8) == 0) {
      return (void *)0x0;
    }
    if (param_1[2] != 0) {
      return (void *)0x0;
    }
    memcpy((void *)(*(int *)(iVar1 + 0x2a8) + (*(int *)(iVar1 + 0x2ac) - param_3)),param_4,param_3);
    CRYPTO_gcm128_setiv(iVar1 + 0x100,*(undefined4 *)(iVar1 + 0x2a8),*(undefined4 *)(iVar1 + 0x2ac))
    ;
LAB_00133ad4:
    pvVar2 = (void *)0x1;
    *(undefined4 *)(iVar1 + 0xfc) = 1;
    break;
  case 0x25:
    pvVar2 = (void *)0x1;
    *param_4 = *(undefined4 *)(iVar1 + 0x2ac);
  }
  return pvVar2;
}

