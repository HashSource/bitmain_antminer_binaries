
undefined4
ssl_cipher_get_evp(int *param_1,undefined4 *param_2,int *param_3,int *param_4,undefined4 *param_5,
                  undefined4 *param_6)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  ulong uVar3;
  EVP_CIPHER *pEVar4;
  uint uVar5;
  int iVar6;
  int local_34 [4];
  
  iVar6 = param_1[0x2d];
  if (iVar6 == 0) {
    return 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    load_builtin_compressions();
    st = ssl_comp_methods;
    local_34[0] = param_1[0x2c];
    *param_6 = 0;
    if (st != (_STACK *)0x0) {
      iVar1 = sk_find(st,local_34);
      if (iVar1 < 0) {
        *param_6 = 0;
      }
      else {
        pvVar2 = sk_value(ssl_comp_methods,iVar1);
        *param_6 = pvVar2;
      }
    }
  }
  if (param_2 == (undefined4 *)0x0 || param_3 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0;
  uVar5 = *(uint *)(iVar6 + 0x14);
  if (uVar5 == 0x40) {
    iVar1 = 6;
LAB_00119a9e:
    *param_2 = *(undefined4 *)(ssl_cipher_methods + iVar1 * 4);
  }
  else {
    if (0x40 < uVar5) {
      if (uVar5 == 0x400) {
        iVar1 = 10;
      }
      else if (uVar5 < 0x401) {
        if (uVar5 == 0x100) {
          iVar1 = 8;
        }
        else if (uVar5 == 0x200) {
          iVar1 = 9;
        }
        else {
          if (uVar5 != 0x80) goto LAB_00119a88;
          iVar1 = 7;
        }
      }
      else if (uVar5 == 0x1000) {
        iVar1 = 0xc;
      }
      else if (uVar5 == 0x2000) {
        iVar1 = 0xd;
      }
      else {
        if (uVar5 != 0x800) goto LAB_00119a88;
        iVar1 = 0xb;
      }
      goto LAB_00119a9e;
    }
    if (uVar5 == 4) {
      iVar1 = 2;
      goto LAB_00119a9e;
    }
    if (4 < uVar5) {
      if (uVar5 == 0x10) {
        iVar1 = 4;
      }
      else {
        if (uVar5 == 0x20) {
          pEVar4 = EVP_enc_null();
          *param_2 = pEVar4;
          goto LAB_00119aa8;
        }
        if (uVar5 != 8) goto LAB_00119a88;
        iVar1 = 3;
      }
      goto LAB_00119a9e;
    }
    if (uVar5 == 1) goto LAB_00119a9e;
    if (uVar5 == 2) {
      iVar1 = 1;
      goto LAB_00119a9e;
    }
LAB_00119a88:
    *param_2 = 0;
  }
LAB_00119aa8:
  iVar1 = *(int *)(iVar6 + 0x18);
  if ((iVar1 - 1U < 0x20) && (uVar5 = (uint)(char)(&DAT_001f0b2b)[iVar1], uVar5 < 6)) {
    *param_3 = *(int *)(ssl_digest_methods + uVar5 * 4);
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(&ssl_mac_pkey_id + uVar5 * 4);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(ssl_mac_secret_size + uVar5 * 4);
    }
  }
  else {
    *param_3 = 0;
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (iVar1 == 0x40) {
      param_4 = (int *)0x0;
    }
  }
  if ((((EVP_CIPHER *)*param_2 == (EVP_CIPHER *)0x0) ||
      ((*param_3 == 0 && (uVar3 = EVP_CIPHER_flags((EVP_CIPHER *)*param_2), -1 < (int)(uVar3 << 10))
       ))) || ((param_4 != (int *)0x0 && (*param_4 == 0)))) {
    return 0;
  }
  if (*param_1 >> 8 != 3) {
    return 1;
  }
  if (*param_1 < 0x301) {
    return 1;
  }
  iVar1 = *(int *)(iVar6 + 0x14);
  if (iVar1 == 4) {
    if (*(int *)(iVar6 + 0x18) != 1) {
      return 1;
    }
    pEVar4 = EVP_get_cipherbyname("RC4-HMAC-MD5");
    if (pEVar4 != (EVP_CIPHER *)0x0) goto LAB_00119b58;
    iVar1 = *(int *)(iVar6 + 0x14);
  }
  if (iVar1 == 0x40) {
    iVar1 = *(int *)(iVar6 + 0x18);
    if (iVar1 == 2) {
      pEVar4 = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA1");
      if (pEVar4 != (EVP_CIPHER *)0x0) goto LAB_00119b58;
      iVar1 = *(int *)(iVar6 + 0x14);
      goto LAB_00119b40;
    }
LAB_00119b8e:
    if (iVar1 != 0x10) {
      return 1;
    }
    pEVar4 = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA256");
    if (pEVar4 != (EVP_CIPHER *)0x0) goto LAB_00119b58;
    iVar1 = *(int *)(iVar6 + 0x14);
LAB_00119b9e:
    if (iVar1 != 0x80) {
      return 1;
    }
    iVar1 = *(int *)(iVar6 + 0x18);
  }
  else {
LAB_00119b40:
    if (iVar1 != 0x80) {
LAB_00119be2:
      if (iVar1 == 0x40) {
        iVar1 = *(int *)(iVar6 + 0x18);
        goto LAB_00119b8e;
      }
      goto LAB_00119b9e;
    }
    iVar1 = *(int *)(iVar6 + 0x18);
    if (iVar1 == 2) {
      pEVar4 = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA1");
      if (pEVar4 != (EVP_CIPHER *)0x0) goto LAB_00119b58;
      iVar1 = *(int *)(iVar6 + 0x14);
      goto LAB_00119be2;
    }
  }
  if ((iVar1 != 0x10) ||
     (pEVar4 = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA256"), pEVar4 == (EVP_CIPHER *)0x0)) {
    return 1;
  }
LAB_00119b58:
  *param_2 = pEVar4;
  *param_3 = 0;
  return 1;
}

