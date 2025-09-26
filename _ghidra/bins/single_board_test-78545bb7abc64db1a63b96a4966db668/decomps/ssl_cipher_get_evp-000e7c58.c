
undefined4
ssl_cipher_get_evp(int *param_1,int *param_2,int *param_3,int *param_4,undefined4 *param_5,
                  undefined4 *param_6,int param_7)

{
  bool bVar1;
  undefined4 uVar2;
  EVP_CIPHER *pEVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_2c [3];
  
  iVar7 = param_1[0x6e];
  if (iVar7 == 0) {
    return 0;
  }
  if (param_6 == (undefined4 *)0x0) {
    bVar1 = param_2 == (int *)0x0 || param_3 == (int *)0x0;
  }
  else {
    CRYPTO_THREAD_run_once(&ssl_load_builtin_comp_once,0xe6ff5);
    iVar5 = ssl_comp_methods;
    local_2c[0] = param_1[0x6d];
    *param_6 = 0;
    if (iVar5 != 0) {
      uVar2 = OPENSSL_sk_find(iVar5,local_2c);
      uVar2 = OPENSSL_sk_value(ssl_comp_methods,uVar2);
      *param_6 = uVar2;
    }
    if (param_2 == (int *)0x0 && param_3 == (int *)0x0) {
      return 1;
    }
    bVar1 = param_2 == (int *)0x0 || param_3 == (int *)0x0;
  }
  if (bVar1) {
    return 0;
  }
  iVar5 = 0;
  do {
    if (*(int *)(iVar7 + 0x18) == (&ssl_cipher_table_cipher)[iVar5 * 2]) {
      if (iVar5 == 5) {
        pEVar3 = EVP_enc_null();
        *param_2 = (int)pEVar3;
      }
      else {
        *param_2 = *(int *)(ssl_cipher_methods + iVar5 * 4);
      }
      goto LAB_000e7cd6;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x16);
  *param_2 = 0;
LAB_000e7cd6:
  iVar5 = *(int *)(iVar7 + 0x1c);
  if (iVar5 == 1) {
    iVar5 = 0;
LAB_000e7d8e:
    iVar6 = *(int *)(ssl_digest_methods + iVar5 * 4);
    *param_3 = iVar6;
    if (param_4 != (int *)0x0) {
      *param_4 = (&ssl_mac_pkey_id)[iVar5];
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(ssl_mac_secret_size + iVar5 * 4);
    }
    pEVar3 = (EVP_CIPHER *)*param_2;
    if (pEVar3 == (EVP_CIPHER *)0x0) {
      return 0;
    }
    if (iVar6 == 0) goto LAB_000e7dc8;
  }
  else {
    if (iVar5 == 2) {
      iVar5 = 1;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 4) {
      iVar5 = 2;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 8) {
      iVar5 = 3;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0x10) {
      iVar5 = 4;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0x20) {
      iVar5 = 5;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0x80) {
      iVar5 = 6;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0x100) {
      iVar5 = 7;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0x200) {
      iVar5 = 8;
      goto LAB_000e7d8e;
    }
    if (iVar5 == 0) {
      iVar5 = 9;
      goto LAB_000e7d8e;
    }
    *param_3 = 0;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    pEVar3 = (EVP_CIPHER *)*param_2;
    if (*(int *)(iVar7 + 0x1c) == 0x40) {
      param_4 = (int *)0x0;
    }
    if (pEVar3 == (EVP_CIPHER *)0x0) {
      return 0;
    }
LAB_000e7dc8:
    uVar4 = EVP_CIPHER_flags(pEVar3);
    if (-1 < (int)(uVar4 << 10)) {
      return 0;
    }
  }
  if ((param_4 != (int *)0x0) && (*param_4 == 0)) {
    return 0;
  }
  if (param_7 != 0) {
    return 1;
  }
  if (*param_1 >> 8 != 3 || *param_1 == 0x300) {
    return 1;
  }
  iVar5 = *(int *)(iVar7 + 0x18);
  if (iVar5 == 4) {
    if (*(int *)(iVar7 + 0x1c) != 1) {
      return 1;
    }
    pEVar3 = EVP_get_cipherbyname("RC4-HMAC-MD5");
    if (pEVar3 != (EVP_CIPHER *)0x0) {
      *param_2 = (int)pEVar3;
      *param_3 = 0;
      return 1;
    }
    iVar5 = *(int *)(iVar7 + 0x18);
  }
  if (iVar5 == 0x40) {
    iVar5 = *(int *)(iVar7 + 0x1c);
    if (iVar5 == 2) {
      pEVar3 = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA1");
      if (pEVar3 != (EVP_CIPHER *)0x0) goto LAB_000e7e24;
      if (*(int *)(iVar7 + 0x18) == 0x80) goto LAB_000e7e0e;
      if (*(int *)(iVar7 + 0x18) != 0x40) {
        return 1;
      }
LAB_000e7eb2:
      iVar5 = *(int *)(iVar7 + 0x1c);
    }
    if (iVar5 != 0x10) {
      return 1;
    }
    pEVar3 = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA256");
    if (pEVar3 != (EVP_CIPHER *)0x0) goto LAB_000e7e24;
    iVar5 = *(int *)(iVar7 + 0x18);
LAB_000e7e96:
    if (iVar5 != 0x80) {
      return 1;
    }
    iVar5 = *(int *)(iVar7 + 0x1c);
  }
  else {
    if (iVar5 != 0x80) {
      return 1;
    }
LAB_000e7e0e:
    iVar5 = *(int *)(iVar7 + 0x1c);
    if (iVar5 == 2) {
      pEVar3 = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA1");
      if (pEVar3 != (EVP_CIPHER *)0x0) goto LAB_000e7e24;
      iVar5 = *(int *)(iVar7 + 0x18);
      if (iVar5 == 0x40) goto LAB_000e7eb2;
      goto LAB_000e7e96;
    }
  }
  if ((iVar5 != 0x10) ||
     (pEVar3 = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA256"), pEVar3 == (EVP_CIPHER *)0x0)) {
    return 1;
  }
LAB_000e7e24:
  *param_2 = (int)pEVar3;
  *param_3 = 0;
  return 1;
}

