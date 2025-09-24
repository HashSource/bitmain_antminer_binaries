
void * aria_gcm_ctrl(undefined4 *param_1,undefined4 param_2,size_t param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  int iVar2;
  EVP_CIPHER *cipher;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  size_t __n;
  undefined4 uVar7;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  
  iVar2 = EVP_CIPHER_CTX_get_cipher_data();
  switch(param_2) {
  case 0:
    cipher = (EVP_CIPHER *)*param_1;
    *(undefined4 *)(iVar2 + 0x118) = 0;
    *(undefined4 *)(iVar2 + 0x11c) = 0;
    iVar4 = EVP_CIPHER_iv_length(cipher);
    *(int *)(iVar2 + 0x2cc) = iVar4;
    uVar6 = EVP_CIPHER_CTX_iv_noconst(param_1);
    *(undefined4 *)(iVar2 + 0x2d4) = 0;
    *(undefined4 *)(iVar2 + 0x2c8) = uVar6;
    pvVar8 = (void *)0x1;
    *(undefined4 *)(iVar2 + 0x2d0) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x2d8) = 0xffffffff;
    break;
  default:
    pvVar8 = (void *)0xffffffff;
    break;
  case 8:
    iVar4 = EVP_CIPHER_CTX_get_cipher_data(param_4);
    if (*(int *)(iVar2 + 0x294) != 0) {
      if (*(int *)(iVar2 + 0x294) != iVar2) {
        return (void *)0x0;
      }
      *(int *)(iVar4 + 0x294) = iVar4;
    }
    iVar11 = *(int *)(iVar2 + 0x2c8);
    iVar9 = EVP_CIPHER_CTX_iv_noconst(param_1);
    if (iVar11 == iVar9) {
      uVar6 = EVP_CIPHER_CTX_iv_noconst(param_4);
      *(undefined4 *)(iVar4 + 0x2c8) = uVar6;
      return (void *)0x1;
    }
    pvVar8 = CRYPTO_malloc(*(int *)(iVar2 + 0x2cc),"crypto/evp/e_aria.c",0x17a);
    *(void **)(iVar4 + 0x2c8) = pvVar8;
    if (pvVar8 != (void *)0x0) {
      memcpy(pvVar8,*(void **)(iVar2 + 0x2c8),*(size_t *)(iVar2 + 0x2cc));
      return (void *)0x1;
    }
    iVar4 = 0x17b;
    pvVar8 = (void *)0x0;
LAB_0012b736:
    ERR_put_error(6,0xc5,0x41,"crypto/evp/e_aria.c",iVar4);
    break;
  case 9:
    if ((int)param_3 < 1) {
      return (void *)0x0;
    }
    if ((0x10 < (int)param_3) && (*(int *)(iVar2 + 0x2cc) < (int)param_3)) {
      iVar9 = *(int *)(iVar2 + 0x2c8);
      iVar4 = EVP_CIPHER_CTX_iv_noconst(param_1);
      if (iVar9 != iVar4) {
        CRYPTO_free(*(void **)(iVar2 + 0x2c8));
      }
      pvVar8 = CRYPTO_malloc(param_3,"crypto/evp/e_aria.c",0x10d);
      iVar4 = 0x10e;
      *(void **)(iVar2 + 0x2c8) = pvVar8;
      if (pvVar8 == (void *)0x0) goto LAB_0012b736;
    }
    *(size_t *)(iVar2 + 0x2cc) = param_3;
    pvVar8 = (void *)0x1;
    break;
  case 0x10:
    if (0xf < param_3 - 1) {
      return (void *)0x0;
    }
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar2 + 0x2d0) < 0) {
      return (void *)0x0;
    }
    pvVar8 = (void *)EVP_CIPHER_CTX_buf_noconst(param_1);
    memcpy(param_4,pvVar8,param_3);
    pvVar8 = (void *)0x1;
    break;
  case 0x11:
    if (0xf < param_3 - 1) {
      return (void *)0x0;
    }
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 != 0) {
      return (void *)0x0;
    }
    pvVar8 = (void *)EVP_CIPHER_CTX_buf_noconst(param_1);
    memcpy(pvVar8,param_4,param_3);
    *(size_t *)(iVar2 + 0x2d0) = param_3;
    pvVar8 = (void *)0x1;
    break;
  case 0x12:
    if (param_3 != 0xffffffff) {
      if ((int)param_3 < 4) {
        return (void *)0x0;
      }
      if ((int)(*(int *)(iVar2 + 0x2cc) - param_3) < 8) {
        return (void *)0x0;
      }
      memcpy(*(void **)(iVar2 + 0x2c8),param_4,param_3);
      iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
      if ((iVar4 != 0) &&
         (iVar4 = RAND_bytes((uchar *)(*(int *)(iVar2 + 0x2c8) + param_3),
                             *(int *)(iVar2 + 0x2cc) - param_3), iVar4 < 1)) {
        return (void *)0x0;
      }
      *(undefined4 *)(iVar2 + 0x2d4) = 1;
      return (void *)0x1;
    }
    memcpy(*(void **)(iVar2 + 0x2c8),param_4,*(size_t *)(iVar2 + 0x2cc));
    pvVar8 = (void *)0x1;
    *(undefined4 *)(iVar2 + 0x2d4) = 1;
    break;
  case 0x13:
    if (*(int *)(iVar2 + 0x2d4) == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar2 + 0x118) == 0) {
      return (void *)0x0;
    }
    CRYPTO_gcm128_setiv(iVar2 + 0x120,*(undefined4 *)(iVar2 + 0x2c8),*(undefined4 *)(iVar2 + 0x2cc))
    ;
    __n = *(size_t *)(iVar2 + 0x2cc);
    if (((int)param_3 < 1) || ((int)__n < (int)param_3)) {
      iVar4 = 0;
    }
    else {
      iVar4 = __n - param_3;
      __n = param_3;
    }
    memcpy(param_4,(void *)(iVar4 + *(int *)(iVar2 + 0x2c8)),__n);
    iVar4 = *(int *)(iVar2 + 0x2cc);
    iVar9 = *(int *)(iVar2 + 0x2c8);
    cVar5 = *(char *)(iVar9 + iVar4 + -1) + '\x01';
    *(char *)(iVar9 + iVar4 + -1) = cVar5;
    if (((((cVar5 == '\0') &&
          (cVar5 = *(char *)(iVar9 + iVar4 + -2) + '\x01', *(char *)(iVar9 + iVar4 + -2) = cVar5,
          cVar5 == '\0')) &&
         (cVar5 = *(char *)(iVar9 + iVar4 + -3) + '\x01', *(char *)(iVar9 + iVar4 + -3) = cVar5,
         cVar5 == '\0')) &&
        ((cVar5 = *(char *)(iVar9 + iVar4 + -4) + '\x01', *(char *)(iVar9 + iVar4 + -4) = cVar5,
         cVar5 == '\0' &&
         (cVar5 = *(char *)(iVar9 + iVar4 + -5) + '\x01', *(char *)(iVar9 + iVar4 + -5) = cVar5,
         cVar5 == '\0')))) &&
       ((cVar5 = *(char *)(iVar9 + iVar4 + -6) + '\x01', *(char *)(iVar9 + iVar4 + -6) = cVar5,
        cVar5 == '\0' &&
        (cVar5 = *(char *)(iVar9 + iVar4 + -7) + '\x01', *(char *)(iVar9 + iVar4 + -7) = cVar5,
        cVar5 == '\0')))) {
      *(char *)(iVar9 + iVar4 + -8) = *(char *)(iVar9 + iVar4 + -8) + '\x01';
    }
    goto LAB_0012b876;
  case 0x16:
    if (param_3 == 0xd) {
      puVar3 = (undefined4 *)EVP_CIPHER_CTX_buf_noconst(param_1);
      uVar6 = param_4[1];
      uVar7 = param_4[2];
      *puVar3 = *param_4;
      puVar3[1] = uVar6;
      puVar3[2] = uVar7;
      *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(param_4 + 3);
      *(undefined4 *)(iVar2 + 0x2d8) = 0xd;
      iVar2 = EVP_CIPHER_CTX_buf_noconst(param_1);
      uVar1 = *(undefined1 *)(iVar2 + 0xb);
      iVar2 = EVP_CIPHER_CTX_buf_noconst(param_1);
      uVar10 = (uint)CONCAT11(uVar1,*(undefined1 *)(iVar2 + 0xc));
      if (7 < uVar10) {
        uVar12 = uVar10 - 8;
        iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
        if (iVar2 == 0) {
          if (uVar12 < 0x10) {
            return (void *)0x0;
          }
          uVar12 = uVar10 - 0x18;
        }
        iVar2 = EVP_CIPHER_CTX_buf_noconst(param_1);
        *(char *)(iVar2 + 0xb) = (char)(uVar12 >> 8);
        iVar2 = EVP_CIPHER_CTX_buf_noconst(param_1);
        *(char *)(iVar2 + 0xc) = (char)uVar12;
        return (void *)0x10;
      }
    }
    return (void *)0x0;
  case 0x18:
    if (*(int *)(iVar2 + 0x2d4) == 0) {
      return (void *)0x0;
    }
    if (*(int *)(iVar2 + 0x118) == 0) {
      return (void *)0x0;
    }
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 != 0) {
      return (void *)0x0;
    }
    memcpy((void *)(*(int *)(iVar2 + 0x2c8) + (*(int *)(iVar2 + 0x2cc) - param_3)),param_4,param_3);
    CRYPTO_gcm128_setiv(iVar2 + 0x120,*(undefined4 *)(iVar2 + 0x2c8),*(undefined4 *)(iVar2 + 0x2cc))
    ;
LAB_0012b876:
    pvVar8 = (void *)0x1;
    *(undefined4 *)(iVar2 + 0x11c) = 1;
    break;
  case 0x25:
    pvVar8 = (void *)0x1;
    *param_4 = *(undefined4 *)(iVar2 + 0x2cc);
  }
  return pvVar8;
}

