
int ssl_create_cipher_list
              (int param_1,undefined4 param_2,int *param_3,int *param_4,char *param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *ptr;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined1 *puVar13;
  int iVar14;
  int *local_30;
  int *local_2c [2];
  
  local_30 = (int *)0x0;
  local_2c[0] = (int *)0x0;
  if (param_3 == (int *)0x0 || (param_4 == (int *)0x0 || param_5 == (char *)0x0)) {
    return 0;
  }
  iVar5 = strncmp(param_5,"SUITEB128ONLY",0xd);
  if (iVar5 == 0) {
    uVar10 = 0x10000;
    bVar1 = false;
LAB_000e806c:
    *(uint *)(param_6 + 0x10) = *(uint *)(param_6 + 0x10) & 0xfffcffff | uVar10;
LAB_000e807a:
    if ((*(uint *)(*(int *)(param_1 + 100) + 0x30) & 0x10) == 0) {
      ERR_put_error(0x14,0x14b,0x9e,"ssl/ssl_ciph.c",0x4e0);
      return 0;
    }
    if (uVar10 == 0x20000) {
      param_5 = "ECDHE-ECDSA-AES256-GCM-SHA384";
    }
    else if (uVar10 == 0x30000) {
      if (bVar1) {
        param_5 = "ECDHE-ECDSA-AES256-GCM-SHA384";
      }
      else {
        param_5 = "ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384";
      }
    }
    else if (uVar10 == 0x10000) {
      param_5 = "ECDHE-ECDSA-AES128-GCM-SHA256";
    }
  }
  else {
    iVar5 = strncmp(param_5,"SUITEB128C2",0xb);
    if (iVar5 == 0) {
      bVar1 = true;
      uVar10 = 0x30000;
      goto LAB_000e806c;
    }
    iVar5 = strncmp(param_5,"SUITEB128",9);
    if (iVar5 == 0) {
      uVar10 = 0x30000;
      bVar1 = false;
      goto LAB_000e806c;
    }
    iVar5 = strncmp(param_5,"SUITEB192",9);
    if (iVar5 == 0) {
      uVar10 = 0x20000;
      bVar1 = false;
      goto LAB_000e806c;
    }
    uVar10 = *(uint *)(param_6 + 0x10) & 0x30000;
    if (uVar10 != 0) {
      bVar1 = false;
      goto LAB_000e807a;
    }
  }
  uVar4 = disabled_auth_mask;
  uVar3 = disabled_mkey_mask;
  uVar2 = disabled_mac_mask;
  uVar10 = disabled_enc_mask;
  iVar5 = (**(code **)(param_1 + 0x58))();
  ptr = (int *)CRYPTO_malloc(iVar5 * 0x14,"ssl/ssl_ciph.c",0x5a2);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x14,0xa6,0x41,"ssl/ssl_ciph.c",0x5a4);
    return 0;
  }
  if (0 < iVar5) {
    iVar14 = 0;
    iVar7 = 0;
    do {
      while (((((piVar6 = (int *)(**(code **)(param_1 + 0x5c))(iVar14), piVar6 == (int *)0x0 ||
                (*piVar6 == 0)) || ((uVar3 & piVar6[4]) != 0)) ||
              (((uVar4 & piVar6[5]) != 0 || ((uVar10 & piVar6[6]) != 0)))) ||
             ((uVar2 & piVar6[7]) != 0))) {
LAB_000e8130:
        iVar14 = iVar14 + 1;
        iVar11 = iVar7;
        if (iVar5 == iVar14) goto LAB_000e8138;
      }
      if (*(int *)(*(int *)(param_1 + 100) + 0x30) << 0x1c < 0) {
        iVar11 = piVar6[10];
      }
      else {
        iVar11 = piVar6[8];
      }
      if (iVar11 == 0) goto LAB_000e8130;
      iVar14 = iVar14 + 1;
      iVar11 = iVar7 + 1;
      ptr[iVar7 * 5] = (int)piVar6;
      ptr[iVar7 * 5 + 3] = 0;
      ptr[iVar7 * 5 + 4] = 0;
      ptr[iVar7 * 5 + 1] = 0;
      iVar7 = iVar11;
    } while (iVar5 != iVar14);
LAB_000e8138:
    if (iVar11 != 0) {
      ptr[4] = 0;
      local_2c[0] = ptr;
      if (iVar11 != 1) {
        ptr[3] = (int)(ptr + 5);
        if (iVar11 == 2) {
          iVar7 = 8;
        }
        else {
          iVar7 = iVar11 * 4;
          piVar6 = ptr + 10;
          do {
            piVar6[-2] = (int)piVar6;
            piVar6[-1] = (int)(piVar6 + -10);
            piVar6 = piVar6 + 5;
          } while (piVar6 != ptr + iVar11 * 5);
        }
        (ptr + iVar7 + iVar11 + -5)[4] = (int)(ptr + iVar7 + iVar11 + -10);
        local_2c[0] = ptr + iVar7 + iVar11 + -5;
      }
      local_2c[0][3] = 0;
      local_30 = ptr;
    }
  }
  ssl_cipher_apply_rule_constprop_5(4,8,0,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(4,0,0,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(4,0,0,0,0,3,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0x3000,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0x80000,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0x3c0c0,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0,0,0,1,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0,1,0,4,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,4,0,0,0,4,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(1,0,0,0,0,4,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(8,0,0,0,0,4,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,4,0,0,4,0xffffffff,&local_30,local_2c);
  iVar7 = ssl_cipher_strength_sort(&local_30,local_2c);
  if (iVar7 == 0) {
    CRYPTO_free(ptr);
    return 0;
  }
  ssl_cipher_apply_rule_constprop_5(0,0,0,0,0x303,6,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0,0x40,0,6,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(6,0,0,0,0,6,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(6,0,0,0x40,0,6,0xffffffff,&local_30,local_2c);
  ssl_cipher_apply_rule_constprop_5(0,0,0,0,0,3,0xffffffff,&local_30,local_2c);
  piVar6 = (int *)CRYPTO_malloc((iVar5 + 0x4d) * 4,"ssl/ssl_ciph.c",0x613);
  if (piVar6 == (int *)0x0) {
    CRYPTO_free(ptr);
    ERR_put_error(0x14,0xa6,0x41,"ssl/ssl_ciph.c",0x616);
    return 0;
  }
  piVar8 = piVar6;
  for (piVar12 = local_30; piVar12 != (int *)0x0; piVar12 = (int *)piVar12[3]) {
    *piVar8 = *piVar12;
    piVar8 = piVar8 + 1;
  }
  puVar13 = &cipher_aliases;
  do {
    HintPreloadData(puVar13 + 0x1d0);
    piVar12 = piVar8;
    if ((((*(uint *)(puVar13 + 0x10) == 0) || ((~uVar3 & *(uint *)(puVar13 + 0x10)) != 0)) &&
        ((*(uint *)(puVar13 + 0x14) == 0 || ((~uVar4 & *(uint *)(puVar13 + 0x14)) != 0)))) &&
       (((*(uint *)(puVar13 + 0x18) == 0 || ((~uVar10 & *(uint *)(puVar13 + 0x18)) != 0)) &&
        ((*(uint *)(puVar13 + 0x1c) == 0 || ((~uVar2 & *(uint *)(puVar13 + 0x1c)) != 0)))))) {
      piVar12 = piVar8 + 1;
      *piVar8 = (int)puVar13;
    }
    puVar13 = puVar13 + 0x40;
    piVar8 = piVar12;
  } while (puVar13 != &GOST_KX_MESSAGE_it);
  *piVar12 = 0;
  iVar5 = strncmp(param_5,"DEFAULT",7);
  if (iVar5 == 0) {
    iVar5 = ssl_cipher_process_rulestr_isra_3
                      ("ALL:!COMPLEMENTOFDEFAULT:!eNULL",&local_30,local_2c,piVar6,param_6 + 0xfc);
    if (param_5[7] == ':') {
      param_5 = param_5 + 8;
    }
    else {
      param_5 = param_5 + 7;
    }
    if (iVar5 != 0) goto LAB_000e8424;
    CRYPTO_free(piVar6);
LAB_000e85d8:
    CRYPTO_free(ptr);
  }
  else {
LAB_000e8424:
    if (*param_5 == '\0') {
      CRYPTO_free(piVar6);
    }
    else {
      iVar5 = ssl_cipher_process_rulestr_isra_3(param_5,&local_30,local_2c,piVar6,param_6 + 0xfc);
      CRYPTO_free(piVar6);
      if (iVar5 == 0) goto LAB_000e85d8;
    }
    iVar5 = OPENSSL_sk_new_null();
    if (iVar5 == 0) {
      CRYPTO_free(ptr);
    }
    else {
      iVar7 = 0;
      while( true ) {
        iVar14 = OPENSSL_sk_num(param_2);
        piVar6 = local_30;
        if (iVar14 <= iVar7) break;
        uVar9 = OPENSSL_sk_value(param_2,iVar7);
        iVar14 = OPENSSL_sk_push(iVar5,uVar9);
        iVar7 = iVar7 + 1;
        if (iVar14 == 0) {
          CRYPTO_free(ptr);
          OPENSSL_sk_free(iVar5);
          return 0;
        }
      }
      for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
        if ((piVar6[1] != 0) && (iVar7 = OPENSSL_sk_push(iVar5,*piVar6), iVar7 == 0)) {
          CRYPTO_free(ptr);
          OPENSSL_sk_free(iVar5);
          return 0;
        }
      }
      CRYPTO_free(ptr);
      iVar7 = OPENSSL_sk_dup(iVar5);
      if (iVar7 != 0) {
        OPENSSL_sk_free(*param_4);
        *param_4 = iVar7;
        OPENSSL_sk_set_cmp_func(iVar7,0xeb2f5);
        OPENSSL_sk_sort(*param_4);
        OPENSSL_sk_free(*param_3);
        *param_3 = iVar5;
        return iVar5;
      }
      OPENSSL_sk_free(iVar5);
    }
  }
  return 0;
}

