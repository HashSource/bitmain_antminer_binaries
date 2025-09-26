
EC_KEY * ssl3_ctrl(int param_1,undefined4 param_2,uint param_3,EC_KEY *param_4)

{
  EC_GROUP *group;
  EVP_PKEY *pkey;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  char *pcVar5;
  EC_KEY *pEVar6;
  int iVar7;
  ushort *puVar8;
  EC_KEY *pEVar9;
  EC_KEY *local_1c [2];
  
  switch(param_2) {
  case 3:
    if (param_4 != (EC_KEY *)0x0) {
      pkey = (EVP_PKEY *)ssl_dh_to_pkey(param_4);
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xd5,0x41,"ssl/s3_lib.c",0xd5d);
        return (EC_KEY *)0x0;
      }
      uVar1 = EVP_PKEY_security_bits();
      iVar7 = ssl_security(param_1,0x40007,uVar1,0,pkey);
      if (iVar7 == 0) {
        ERR_put_error(0x14,0xd5,0x18a,"ssl/s3_lib.c",0xd62);
        EVP_PKEY_free(pkey);
        return (EC_KEY *)0x0;
      }
      EVP_PKEY_free(*(EVP_PKEY **)(*(int *)(param_1 + 0x404) + 4));
      *(EVP_PKEY **)(*(int *)(param_1 + 0x404) + 4) = pkey;
      return (EC_KEY *)0x1;
    }
    iVar7 = 0xd58;
    goto LAB_000e5284;
  case 4:
    if (param_4 != (EC_KEY *)0x0) {
      group = EC_KEY_get0_group(param_4);
      if (group == (EC_GROUP *)0x0) {
        ERR_put_error(0x14,0xd5,0x7c,"ssl/s3_lib.c",0xd80);
        return (EC_KEY *)0x0;
      }
      local_1c[0] = (EC_KEY *)EC_GROUP_get_curve_name(group);
      if (local_1c[0] == (EC_KEY *)0x0) {
        return (EC_KEY *)0x0;
      }
      pEVar6 = (EC_KEY *)tls1_set_groups(param_1 + 0x574,param_1 + 0x570,local_1c,1);
      return pEVar6;
    }
    iVar7 = 0xd7b;
LAB_000e5284:
    ERR_put_error(0x14,0xd5,0x43,"ssl/s3_lib.c",iVar7);
    break;
  default:
    goto switchD_000e4d22_caseD_5;
  case 6:
    ERR_put_error(0x14,0xd5,0x42,"ssl/s3_lib.c",0xd6d);
    param_4 = (EC_KEY *)0x0;
    break;
  case 10:
    param_4 = *(EC_KEY **)(*(int *)(param_1 + 0x7c) + 0xf8);
    break;
  case 0xb:
    param_4 = *(EC_KEY **)(*(int *)(param_1 + 0x7c) + 0xf8);
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xf8) = 0;
    break;
  case 0xc:
    param_4 = *(EC_KEY **)(*(int *)(param_1 + 0x7c) + 0xf4);
    break;
  case 0xd:
    param_4 = (EC_KEY *)**(int **)(param_1 + 0x7c);
    break;
  case 0x37:
    if (param_3 != 0) {
      ERR_put_error(0x14,0xd5,0x140,"ssl/s3_lib.c",0xda9);
      return (EC_KEY *)0x0;
    }
    CRYPTO_free(*(void **)(param_1 + 0x538));
    *(undefined4 *)(param_1 + 0x538) = 0;
    if (param_4 != (EC_KEY *)0x0) {
      sVar4 = strlen((char *)param_4);
      if (0xfe < sVar4 - 1) {
        ERR_put_error(0x14,0xd5,0x13f,"ssl/s3_lib.c",0xda1);
        return (EC_KEY *)0x0;
      }
      pcVar5 = CRYPTO_strdup((char *)param_4,"ssl/s3_lib.c",0xda4);
      *(char **)(param_1 + 0x538) = pcVar5;
      if (pcVar5 == (char *)0x0) {
        ERR_put_error(0x14,0xd5,0x44,"ssl/s3_lib.c",0xda5);
        return (EC_KEY *)0x0;
      }
    }
LAB_000e51e8:
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x39:
    *(EC_KEY **)(param_1 + 0x534) = param_4;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x41:
    *(uint *)(param_1 + 0x53c) = param_3;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x42:
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x550);
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x43:
    *(EC_KEY **)(param_1 + 0x550) = param_4;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x44:
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x54c);
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x45:
    *(EC_KEY **)(param_1 + 0x54c) = param_4;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x46:
    pEVar6 = *(EC_KEY **)(param_1 + 0x558);
    if ((int)pEVar6 < 1) {
      pEVar6 = (EC_KEY *)0xffffffff;
    }
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x554);
    param_4 = pEVar6;
    break;
  case 0x47:
    CRYPTO_free(*(void **)(param_1 + 0x554));
    *(EC_KEY **)(param_1 + 0x554) = param_4;
    *(uint *)(param_1 + 0x558) = param_3;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x58:
    if (param_3 == 0) {
      param_4 = (EC_KEY *)ssl_cert_set0_chain(param_1,0,param_4);
    }
    else {
      param_4 = (EC_KEY *)ssl_cert_set1_chain(param_1,0);
    }
    break;
  case 0x59:
    if (param_3 == 0) {
      param_4 = (EC_KEY *)ssl_cert_add0_chain_cert(param_1,0,param_4);
    }
    else {
      param_4 = (EC_KEY *)ssl_cert_add1_chain_cert(param_1,0);
    }
    break;
  case 0x5a:
    if (*(int *)(param_1 + 0x474) != 0) {
      pEVar6 = *(EC_KEY **)(param_1 + 0x578);
      if (param_4 == (EC_KEY *)0x0) {
        return pEVar6;
      }
      if (pEVar6 == (EC_KEY *)0x0) {
        return (EC_KEY *)0x0;
      }
      puVar8 = *(ushort **)(param_1 + 0x57c);
      pEVar9 = (EC_KEY *)0x0;
      do {
        puVar3 = (undefined4 *)tls1_group_id_lookup(*puVar8);
        if (puVar3 == (undefined4 *)0x0) {
          *(uint *)param_4 = *puVar8 | 0x1000000;
        }
        else {
          *(undefined4 *)param_4 = *puVar3;
        }
        pEVar9 = pEVar9 + 1;
        puVar8 = puVar8 + 1;
        param_4 = param_4 + 4;
      } while (pEVar6 != pEVar9);
      return pEVar6;
    }
    goto switchD_000e4d22_caseD_5;
  case 0x5b:
    param_4 = (EC_KEY *)tls1_set_groups(param_1 + 0x574,param_1 + 0x570,param_4,param_3);
    break;
  case 0x5c:
    param_4 = (EC_KEY *)tls1_set_groups_list(param_1 + 0x574,param_1 + 0x570,param_4);
    break;
  case 0x5d:
    pEVar6 = (EC_KEY *)tls1_shared_group(param_1,param_3);
    if (param_3 == 0xffffffff) {
      return pEVar6;
    }
    puVar3 = (undefined4 *)tls1_group_id_lookup();
    if (puVar3 != (undefined4 *)0x0) {
      return (EC_KEY *)*puVar3;
    }
    goto switchD_000e4d22_caseD_5;
  case 0x61:
    param_4 = (EC_KEY *)tls1_set_sigalgs(*(undefined4 *)(param_1 + 0x404),param_4,param_3,0);
    break;
  case 0x62:
    param_4 = (EC_KEY *)tls1_set_sigalgs_list(*(undefined4 *)(param_1 + 0x404),param_4,0);
    break;
  case 0x65:
    param_4 = (EC_KEY *)tls1_set_sigalgs(*(undefined4 *)(param_1 + 0x404),param_4,param_3,1);
    break;
  case 0x66:
    param_4 = (EC_KEY *)tls1_set_sigalgs_list(*(undefined4 *)(param_1 + 0x404),param_4,1);
    break;
  case 0x67:
    if ((*(int *)(param_1 + 0x1c) == 0) &&
       (iVar7 = *(int *)(param_1 + 0x7c), *(int *)(iVar7 + 0x218) != 0)) {
      if (param_4 != (EC_KEY *)0x0) {
        *(undefined4 *)param_4 = *(undefined4 *)(iVar7 + 0x21c);
        iVar7 = *(int *)(param_1 + 0x7c);
      }
      return *(EC_KEY **)(iVar7 + 0x220);
    }
    goto switchD_000e4d22_caseD_5;
  case 0x68:
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar7 = *(int *)(param_1 + 0x404);
      CRYPTO_free(*(void **)(iVar7 + 200));
      *(undefined4 *)(iVar7 + 200) = 0;
      *(undefined4 *)(iVar7 + 0xcc) = 0;
      if (param_3 == 0 || param_4 == (EC_KEY *)0x0) goto LAB_000e51e8;
      if (param_3 < 0x100) {
        iVar2 = CRYPTO_memdup(param_4,param_3,"ssl/s3_lib.c",0x112f);
        *(int *)(iVar7 + 200) = iVar2;
        if (iVar2 != 0) {
          *(uint *)(iVar7 + 0xcc) = param_3;
          return (EC_KEY *)0x1;
        }
      }
    }
    goto switchD_000e4d22_caseD_5;
  case 0x69:
    param_4 = (EC_KEY *)ssl_build_cert_chain(param_1,0,param_3);
    break;
  case 0x6a:
    param_4 = (EC_KEY *)ssl_cert_set_cert_store(*(undefined4 *)(param_1 + 0x404),param_4,0,param_3);
    break;
  case 0x6b:
    param_4 = (EC_KEY *)ssl_cert_set_cert_store(*(undefined4 *)(param_1 + 0x404),param_4,1,param_3);
    break;
  case 0x6c:
    iVar7 = *(int *)(*(int *)(param_1 + 0x7c) + 0x278);
    goto joined_r0x000e4ef4;
  case 0x6d:
    if ((*(int *)(param_1 + 0x474) != 0) && (*(int *)(*(int *)(param_1 + 0x7c) + 0x358) != 0)) {
      EVP_PKEY_up_ref();
      *(undefined4 *)param_4 = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x358);
      return (EC_KEY *)0x1;
    }
    goto switchD_000e4d22_caseD_5;
  case 0x6f:
    if (*(int *)(param_1 + 0x56c) != 0) {
      *(int *)param_4 = *(int *)(param_1 + 0x56c);
      return *(EC_KEY **)(param_1 + 0x568);
    }
    goto switchD_000e4d22_caseD_5;
  case 0x73:
    *(undefined4 *)param_4 = *(undefined4 *)(**(int **)(param_1 + 0x404) + 8);
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x74:
    param_4 = (EC_KEY *)ssl_cert_select_current(*(undefined4 *)(param_1 + 0x404),param_4);
    break;
  case 0x75:
    if (param_3 != 3) {
      pEVar6 = (EC_KEY *)ssl_cert_set_current(*(undefined4 *)(param_1 + 0x404),param_3);
      return pEVar6;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar7 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
      if (iVar7 != 0) {
        if ((*(uint *)(iVar7 + 0x14) & 0x44) != 0) {
          return (EC_KEY *)0x2;
        }
        iVar7 = *(int *)(*(int *)(param_1 + 0x7c) + 0x264);
        if (iVar7 != 0) {
          **(int **)(param_1 + 0x404) = iVar7;
          return (EC_KEY *)0x1;
        }
      }
    }
    goto switchD_000e4d22_caseD_5;
  case 0x76:
    *(uint *)(*(int *)(param_1 + 0x404) + 0xc) = param_3;
    param_4 = (EC_KEY *)0x1;
    break;
  case 0x7f:
    param_4 = *(EC_KEY **)(param_1 + 0x53c);
    break;
  case 0x84:
    iVar7 = *(int *)(*(int *)(param_1 + 0x7c) + 0x260);
joined_r0x000e4ef4:
    if (iVar7 != 0) {
      *(undefined4 *)param_4 = *(undefined4 *)(iVar7 + 8);
      return (EC_KEY *)0x1;
    }
    goto switchD_000e4d22_caseD_5;
  case 0x85:
    if ((*(int *)(param_1 + 0x474) != 0) && (*(int *)(*(int *)(param_1 + 0x7c) + 0x214) != 0)) {
      EVP_PKEY_up_ref();
      *(undefined4 *)param_4 = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x214);
      return (EC_KEY *)0x1;
    }
switchD_000e4d22_caseD_5:
    param_4 = (EC_KEY *)0x0;
    break;
  case 0x89:
    param_4 = (EC_KEY *)ssl_cert_get_cert_store(*(undefined4 *)(param_1 + 0x404),param_4,0);
    break;
  case 0x8a:
    param_4 = (EC_KEY *)ssl_cert_get_cert_store(*(undefined4 *)(param_1 + 0x404),param_4,1);
  }
  return param_4;
}

