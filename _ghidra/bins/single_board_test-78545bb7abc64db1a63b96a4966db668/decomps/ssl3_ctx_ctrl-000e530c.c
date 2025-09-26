
EC_KEY * ssl3_ctx_ctrl(int param_1,int param_2,uint param_3,EC_KEY *param_4)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 uVar3;
  EC_KEY *pEVar4;
  EC_GROUP *group;
  EVP_PKEY *pkey;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  EC_KEY *local_1c [2];
  
  switch(param_2) {
  case 3:
    if (param_4 != (EC_KEY *)0x0) {
      pkey = (EVP_PKEY *)ssl_dh_to_pkey(param_4);
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0x85,0x41,"ssl/s3_lib.c",0xec7);
        return (EC_KEY *)0x0;
      }
      uVar3 = EVP_PKEY_security_bits();
      iVar9 = ssl_ctx_security(param_1,0x40007,uVar3,0,pkey);
      if (iVar9 != 0) {
        EVP_PKEY_free(*(EVP_PKEY **)(*(int *)(param_1 + 0xc0) + 4));
        *(EVP_PKEY **)(*(int *)(param_1 + 0xc0) + 4) = pkey;
        return (EC_KEY *)0x1;
      }
      ERR_put_error(0x14,0x85,0x18a,"ssl/s3_lib.c",0xecc);
      EVP_PKEY_free(pkey);
      return (EC_KEY *)0x0;
    }
    iVar9 = 0xec2;
    goto LAB_000e584c;
  case 4:
    if (param_4 != (EC_KEY *)0x0) {
      group = EC_KEY_get0_group(param_4);
      if (group == (EC_GROUP *)0x0) {
        ERR_put_error(0x14,0x85,0x7c,"ssl/s3_lib.c",0xee9);
        return (EC_KEY *)0x0;
      }
      local_1c[0] = (EC_KEY *)EC_GROUP_get_curve_name(group);
      if (local_1c[0] != (EC_KEY *)0x0) {
        pEVar4 = (EC_KEY *)tls1_set_groups(param_1 + 0x16c,param_1 + 0x168,local_1c,1);
        return pEVar4;
      }
      return (EC_KEY *)0x0;
    }
    iVar9 = 0xee4;
LAB_000e584c:
    ERR_put_error(0x14,0x85,0x43,"ssl/s3_lib.c",iVar9);
    pEVar4 = param_4;
    break;
  default:
    return (EC_KEY *)0x0;
  case 6:
    ERR_put_error(0x14,0x85,0x42,"ssl/s3_lib.c",0xed6);
    pEVar4 = (EC_KEY *)0x0;
    break;
  case 0xe:
    iVar9 = *(int *)(param_1 + 0x98);
    if (iVar9 == 0) {
      iVar9 = OPENSSL_sk_new_null();
      *(int *)(param_1 + 0x98) = iVar9;
      if (iVar9 == 0) {
        ERR_put_error(0x14,0x85,0x41,"ssl/s3_lib.c",0xf80);
        return (EC_KEY *)0x0;
      }
    }
    iVar9 = OPENSSL_sk_push(iVar9,param_4);
    if (iVar9 == 0) {
      ERR_put_error(0x14,0x85,0x41,"ssl/s3_lib.c",0xf85);
      return (EC_KEY *)0x0;
    }
    goto LAB_000e558a;
  case 0x36:
    *(EC_KEY **)(param_1 + 0x134) = param_4;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x3a:
  case 0x3b:
    pEVar4 = (EC_KEY *)0x50;
    if (param_4 != (EC_KEY *)0x0) {
      if (param_3 == 0x50) {
        if (param_2 == 0x3b) {
          uVar7 = *(undefined4 *)(param_4 + 4);
          uVar6 = *(undefined4 *)(param_4 + 8);
          uVar3 = *(undefined4 *)(param_4 + 0xc);
          *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)param_4;
          *(undefined4 *)(param_1 + 0x13c) = uVar7;
          *(undefined4 *)(param_1 + 0x140) = uVar6;
          *(undefined4 *)(param_1 + 0x144) = uVar3;
          puVar8 = *(undefined4 **)(param_1 + 0x148);
          uVar7 = *(undefined4 *)(param_4 + 0x14);
          uVar6 = *(undefined4 *)(param_4 + 0x18);
          uVar3 = *(undefined4 *)(param_4 + 0x1c);
          *puVar8 = *(undefined4 *)(param_4 + 0x10);
          puVar8[1] = uVar7;
          puVar8[2] = uVar6;
          puVar8[3] = uVar3;
          uVar6 = *(undefined4 *)(param_4 + 0x28);
          uVar3 = *(undefined4 *)(param_4 + 0x2c);
          uVar7 = *(undefined4 *)(param_4 + 0x20);
          puVar8[5] = *(undefined4 *)(param_4 + 0x24);
          puVar8[6] = uVar6;
          puVar8[4] = uVar7;
          puVar8[7] = uVar3;
          iVar9 = *(int *)(param_1 + 0x148);
          uVar3 = *(undefined4 *)(param_4 + 0x3c);
          uVar7 = *(undefined4 *)(param_4 + 0x34);
          uVar6 = *(undefined4 *)(param_4 + 0x38);
          *(undefined4 *)(iVar9 + 0x20) = *(undefined4 *)(param_4 + 0x30);
          *(undefined4 *)(iVar9 + 0x24) = uVar7;
          *(undefined4 *)(iVar9 + 0x28) = uVar6;
          *(undefined4 *)(iVar9 + 0x2c) = uVar3;
          uVar7 = *(undefined4 *)(param_4 + 0x44);
          uVar6 = *(undefined4 *)(param_4 + 0x48);
          uVar3 = *(undefined4 *)(param_4 + 0x4c);
          *(undefined4 *)(iVar9 + 0x30) = *(undefined4 *)(param_4 + 0x40);
          *(undefined4 *)(iVar9 + 0x34) = uVar7;
          *(undefined4 *)(iVar9 + 0x38) = uVar6;
          *(undefined4 *)(iVar9 + 0x3c) = uVar3;
          pEVar4 = (EC_KEY *)0x1;
        }
        else {
          uVar3 = *(undefined4 *)(param_1 + 0x13c);
          uVar7 = *(undefined4 *)(param_1 + 0x144);
          uVar6 = *(undefined4 *)(param_1 + 0x140);
          *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x138);
          *(undefined4 *)(param_4 + 4) = uVar3;
          *(undefined4 *)(param_4 + 8) = uVar6;
          *(undefined4 *)(param_4 + 0xc) = uVar7;
          puVar8 = *(undefined4 **)(param_1 + 0x148);
          uVar7 = puVar8[1];
          uVar6 = puVar8[2];
          uVar3 = puVar8[3];
          *(undefined4 *)(param_4 + 0x10) = *puVar8;
          *(undefined4 *)(param_4 + 0x14) = uVar7;
          *(undefined4 *)(param_4 + 0x18) = uVar6;
          *(undefined4 *)(param_4 + 0x1c) = uVar3;
          uVar6 = puVar8[6];
          uVar3 = puVar8[7];
          uVar7 = puVar8[5];
          *(undefined4 *)(param_4 + 0x20) = puVar8[4];
          *(undefined4 *)(param_4 + 0x28) = uVar6;
          *(undefined4 *)(param_4 + 0x24) = uVar7;
          *(undefined4 *)(param_4 + 0x2c) = uVar3;
          iVar9 = *(int *)(param_1 + 0x148);
          uVar3 = *(undefined4 *)(iVar9 + 0x2c);
          uVar7 = *(undefined4 *)(iVar9 + 0x24);
          uVar6 = *(undefined4 *)(iVar9 + 0x28);
          *(undefined4 *)(param_4 + 0x30) = *(undefined4 *)(iVar9 + 0x20);
          *(undefined4 *)(param_4 + 0x34) = uVar7;
          *(undefined4 *)(param_4 + 0x38) = uVar6;
          *(undefined4 *)(param_4 + 0x3c) = uVar3;
          uVar7 = *(undefined4 *)(iVar9 + 0x34);
          uVar6 = *(undefined4 *)(iVar9 + 0x38);
          uVar3 = *(undefined4 *)(iVar9 + 0x3c);
          *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)(iVar9 + 0x30);
          *(undefined4 *)(param_4 + 0x44) = uVar7;
          *(undefined4 *)(param_4 + 0x48) = uVar6;
          *(undefined4 *)(param_4 + 0x4c) = uVar3;
          pEVar4 = (EC_KEY *)0x1;
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x145,"ssl/s3_lib.c",0xf01);
        pEVar4 = (EC_KEY *)0x0;
      }
    }
    break;
  case 0x40:
    *(EC_KEY **)(param_1 + 0x154) = param_4;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x41:
    *(uint *)(param_1 + 0x158) = param_3;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x4e:
    *(EC_KEY **)(param_1 + 0x1c0) = param_4;
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x20;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x4f:
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x20;
    CRYPTO_free(*(void **)(param_1 + 0x1d0));
    *(undefined4 *)(param_1 + 0x1d0) = 0;
    if (param_4 != (EC_KEY *)0x0) {
      sVar2 = strlen((char *)param_4);
      if ((0xff < sVar2) || (*param_4 == (EC_KEY)0x0)) {
        ERR_put_error(0x14,0x85,0x165,"ssl/s3_lib.c",0xf37);
        return (EC_KEY *)0x0;
      }
      pEVar4 = (EC_KEY *)CRYPTO_strdup((char *)param_4,"ssl/s3_lib.c",0xf3a);
      iVar9 = 0xf3b;
      *(EC_KEY **)(param_1 + 0x1d0) = pEVar4;
      if (pEVar4 == (EC_KEY *)0x0) goto LAB_000e5812;
    }
    goto LAB_000e558a;
  case 0x50:
    *(uint *)(param_1 + 0x1f8) = param_3;
    goto LAB_000e558a;
  case 0x51:
    *(undefined4 *)(param_1 + 0x1cc) = 0xe3b79;
    if (*(void **)(param_1 + 500) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 500));
    }
    pcVar1 = CRYPTO_strdup((char *)param_4,"ssl/s3_lib.c",0xf44);
    *(char **)(param_1 + 500) = pcVar1;
    if (pcVar1 == (char *)0x0) {
      iVar9 = 0xf45;
      pEVar4 = (EC_KEY *)0x0;
LAB_000e5812:
      ERR_put_error(0x14,0x85,0x44,"ssl/s3_lib.c",iVar9);
      return pEVar4;
    }
    goto LAB_000e558a;
  case 0x52:
    if (param_3 != 0 || *(int *)(param_1 + 0x98) != 0) {
      *(int *)param_4 = *(int *)(param_1 + 0x98);
      return (EC_KEY *)0x1;
    }
  case 0x73:
    *(undefined4 *)param_4 = *(undefined4 *)(**(int **)(param_1 + 0xc0) + 8);
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x53:
    OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 0x98),0x178169);
    *(undefined4 *)(param_1 + 0x98) = 0;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x58:
    if (param_3 == 0) {
      pEVar4 = (EC_KEY *)ssl_cert_set0_chain(0,param_1,param_4);
    }
    else {
      pEVar4 = (EC_KEY *)ssl_cert_set1_chain(0);
    }
    break;
  case 0x59:
    if (param_3 == 0) {
      pEVar4 = (EC_KEY *)ssl_cert_add0_chain_cert(0,param_1,param_4);
    }
    else {
      pEVar4 = (EC_KEY *)ssl_cert_add1_chain_cert(0);
    }
    break;
  case 0x5b:
    pEVar4 = (EC_KEY *)tls1_set_groups(param_1 + 0x16c,param_1 + 0x168,param_4,param_3);
    break;
  case 0x5c:
    pEVar4 = (EC_KEY *)tls1_set_groups_list(param_1 + 0x16c,param_1 + 0x168,param_4);
    break;
  case 0x61:
    pEVar4 = (EC_KEY *)tls1_set_sigalgs(*(undefined4 *)(param_1 + 0xc0),param_4,param_3,0);
    break;
  case 0x62:
    pEVar4 = (EC_KEY *)tls1_set_sigalgs_list(*(undefined4 *)(param_1 + 0xc0),param_4,0);
    break;
  case 0x65:
    pEVar4 = (EC_KEY *)tls1_set_sigalgs(*(undefined4 *)(param_1 + 0xc0),param_4,param_3,1);
    break;
  case 0x66:
    pEVar4 = (EC_KEY *)tls1_set_sigalgs_list(*(undefined4 *)(param_1 + 0xc0),param_4,1);
    break;
  case 0x68:
    iVar9 = *(int *)(param_1 + 0xc0);
    CRYPTO_free(*(void **)(iVar9 + 200));
    *(undefined4 *)(iVar9 + 200) = 0;
    *(undefined4 *)(iVar9 + 0xcc) = 0;
    if (param_3 != 0 && param_4 != (EC_KEY *)0x0) {
      if (0xff < param_3) {
        return (EC_KEY *)0x0;
      }
      iVar5 = CRYPTO_memdup(param_4,param_3,"ssl/s3_lib.c",0x112f);
      *(int *)(iVar9 + 200) = iVar5;
      if (iVar5 == 0) {
        return (EC_KEY *)0x0;
      }
      *(uint *)(iVar9 + 0xcc) = param_3;
      return (EC_KEY *)0x1;
    }
LAB_000e558a:
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x69:
    pEVar4 = (EC_KEY *)ssl_build_cert_chain(0,param_1,param_3);
    break;
  case 0x6a:
    pEVar4 = (EC_KEY *)ssl_cert_set_cert_store(*(undefined4 *)(param_1 + 0xc0),param_4,0,param_3);
    break;
  case 0x6b:
    pEVar4 = (EC_KEY *)ssl_cert_set_cert_store(*(undefined4 *)(param_1 + 0xc0),param_4,1,param_3);
    break;
  case 0x74:
    pEVar4 = (EC_KEY *)ssl_cert_select_current(*(undefined4 *)(param_1 + 0xc0),param_4);
    break;
  case 0x75:
    pEVar4 = (EC_KEY *)ssl_cert_set_current(*(undefined4 *)(param_1 + 0xc0),param_3);
    break;
  case 0x76:
    *(uint *)(*(int *)(param_1 + 0xc0) + 0xc) = param_3;
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x7f:
    pEVar4 = *(EC_KEY **)(param_1 + 0x158);
    break;
  case 0x80:
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x150);
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x81:
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x154);
    pEVar4 = (EC_KEY *)0x1;
    break;
  case 0x89:
    pEVar4 = (EC_KEY *)ssl_cert_get_cert_store(*(undefined4 *)(param_1 + 0xc0),param_4,0);
    break;
  case 0x8a:
    pEVar4 = (EC_KEY *)ssl_cert_get_cert_store(*(undefined4 *)(param_1 + 0xc0),param_4,1);
  }
  return pEVar4;
}

