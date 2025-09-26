
undefined4 tls12_check_peer_sigalg(int param_1,uint param_2,EVP_PKEY *param_3)

{
  int iVar1;
  EVP_MD *pEVar2;
  EC_KEY *pEVar3;
  EC_GROUP *pEVar4;
  point_conversion_form_t pVar5;
  EC_METHOD *meth;
  char cVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined1 local_34;
  undefined1 local_33;
  ushort *local_30;
  EVP_MD *local_2c;
  int local_28;
  EVP_MD *local_24 [2];
  
  local_2c = (EVP_MD *)0x0;
  iVar1 = EVP_PKEY_id(param_3);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  piVar7 = *(int **)(param_1 + 4);
  uVar14 = *(uint *)(piVar7[0x19] + 0x30) & 8;
  if ((uVar14 == 0) && (*piVar7 != 0x10000 && 0x303 < *piVar7)) {
    if (iVar1 == 0x74) {
      ossl_statem_fatal(param_1,0x2f,0x14d,0x172,"ssl/t1_lib.c",0x411);
      return 0;
    }
    if (iVar1 == 6) {
      iVar1 = 0x390;
    }
  }
  puVar13 = &sigalg_lookup_tbl;
  do {
    if (*(ushort *)(puVar13 + 4) == param_2) {
      if (uVar14 == 0) {
        iVar8 = *piVar7 + -0x10000;
        if (iVar8 != 0) {
          iVar8 = 1;
        }
        if (*piVar7 < 0x304) {
          iVar8 = 0;
        }
        if ((iVar8 != 0) && (*(int *)(puVar13 + 8) == 0x2a3 || *(int *)(puVar13 + 8) == 0x40))
        break;
      }
      if ((iVar1 == *(int *)(puVar13 + 0x10)) || (*(int *)(puVar13 + 0x10) == 0x390 && iVar1 == 6))
      {
        iVar8 = EVP_PKEY_id(param_3);
        iVar8 = ssl_cert_lookup_by_nid(iVar8,&local_28);
        if ((iVar8 == 0) || (*(int *)(puVar13 + 0x14) != local_28)) {
          uVar10 = 0x429;
          goto LAB_00104a14;
        }
        if (iVar1 != 0x198) {
          if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) == 0) goto LAB_00104a92;
          uVar10 = 0x457;
          goto LAB_00104b6a;
        }
        iVar1 = EVP_PKEY_id(param_3);
        if (iVar1 != 0x198) goto LAB_00104bc6;
        pEVar3 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(param_3);
        pEVar4 = EC_KEY_get0_group(pEVar3);
        pVar5 = EC_KEY_get_conv_form(pEVar3);
        if (pVar5 == POINT_CONVERSION_UNCOMPRESSED) {
          cVar6 = '\0';
        }
        else {
          if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
             (iVar1 = **(int **)(param_1 + 4), iVar1 != 0x10000 && 0x303 < iVar1))
          goto LAB_00104bdc;
          meth = EC_GROUP_method_of(pEVar4);
          iVar1 = EC_METHOD_get_field_type(meth);
          if (iVar1 == 0x196) {
            cVar6 = '\x01';
          }
          else {
            if (iVar1 != 0x197) goto LAB_00104d0c;
            cVar6 = '\x02';
          }
        }
        pcVar12 = *(char **)(param_1 + 0x56c);
        if (pcVar12 == (char *)0x0) goto LAB_00104bc6;
        if (*(int *)(param_1 + 0x568) == 0) goto LAB_00104d0c;
        if (*pcVar12 == cVar6) goto LAB_00104bc6;
        pcVar9 = pcVar12 + *(int *)(param_1 + 0x568);
        goto LAB_00104d48;
      }
      break;
    }
    puVar13 = puVar13 + 0x20;
  } while (puVar13 != legacy_rsa_sigalg);
  uVar10 = 0x422;
LAB_00104a14:
  uVar11 = 0x172;
LAB_00104a1c:
  ossl_statem_fatal(param_1,0x2f,0x14d,uVar11,"ssl/t1_lib.c",uVar10);
  return 0;
LAB_00104d0c:
  uVar10 = 0x434;
  uVar11 = 0xa2;
  goto LAB_00104a1c;
  while (*pcVar12 != cVar6) {
LAB_00104d48:
    pcVar12 = pcVar12 + 1;
    if (pcVar12 == pcVar9) goto LAB_00104d0c;
  }
LAB_00104bc6:
  piVar7 = *(int **)(param_1 + 4);
  if (*(int *)(piVar7[0x19] + 0x30) << 0x1c < 0) {
LAB_00104bd0:
    if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) != 0) goto LAB_00104bdc;
  }
  else {
    iVar1 = *piVar7 + -0x10000;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (*piVar7 < 0x304) {
      iVar1 = 0;
    }
    if (iVar1 == 0) goto LAB_00104bd0;
LAB_00104bdc:
    pEVar3 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(param_3);
    pEVar4 = EC_KEY_get0_group(pEVar3);
    iVar1 = EC_GROUP_get_curve_name(pEVar4);
    if (*(int *)(puVar13 + 0x1c) != 0 && iVar1 != *(int *)(puVar13 + 0x1c)) {
      uVar10 = 0x43f;
      uVar11 = 0x17a;
      goto LAB_00104a1c;
    }
    piVar7 = *(int **)(param_1 + 4);
  }
  if ((*(int *)(piVar7[0x19] + 0x30) << 0x1c < 0) || (*piVar7 < 0x304 || *piVar7 == 0x10000)) {
    pEVar3 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(param_3);
    if (pEVar3 != (EC_KEY *)0x0) {
      pEVar4 = EC_KEY_get0_group(pEVar3);
      iVar1 = EC_GROUP_get_curve_name(pEVar4);
      iVar8 = 0;
      uVar14 = 0;
      do {
        piVar7 = (int *)((int)&nid_list + iVar8);
        uVar14 = uVar14 + 1;
        iVar8 = iVar8 + 0xc;
        if (iVar1 == *piVar7) {
          uVar14 = uVar14 & 0xffff;
          goto LAB_00104c46;
        }
      } while (uVar14 != 0x1e);
    }
    uVar14 = 0;
LAB_00104c46:
    iVar1 = tls1_check_group_id(param_1,uVar14,1);
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x2f,0x14d,0x17a,"ssl/t1_lib.c",0x447);
      return 0;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) != 0) &&
       ((param_2 & 0xfeff) != 0x403)) {
      uVar10 = 0x450;
      goto LAB_00104b6a;
    }
  }
LAB_00104a92:
  iVar1 = tls12_get_psigalgs(param_1,1,&local_30);
  if (iVar1 == 0) {
LAB_00104ac0:
    if ((*(int *)(puVar13 + 8) != 0x40) ||
       ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30001) != 0)) {
      uVar10 = 0x466;
      goto LAB_00104b6a;
    }
  }
  else if (*local_30 != param_2) {
    iVar8 = 0;
    do {
      local_30 = local_30 + 1;
      iVar8 = iVar8 + 1;
      if (iVar1 == iVar8) goto LAB_00104ac0;
    } while (*local_30 != param_2);
  }
  iVar1 = tls1_lookup_md(puVar13,&local_2c);
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x28,0x14d,0x170,"ssl/t1_lib.c",0x46b);
    return 0;
  }
  local_33 = (undefined1)param_2;
  local_24[0] = (EVP_MD *)0x0;
  local_34 = (undefined1)(param_2 >> 8);
  iVar1 = tls1_lookup_md(puVar13,local_24);
  if (iVar1 != 0) {
    if (local_24[0] == (EVP_MD *)0x0) {
      if (*(short *)(puVar13 + 4) == 0x807) {
        iVar1 = 0x80;
      }
      else {
        if (*(short *)(puVar13 + 4) != 0x808) goto LAB_00104bb0;
        iVar1 = 0xe0;
      }
    }
    else {
      iVar1 = EVP_MD_size(local_24[0]);
      iVar1 = iVar1 << 2;
      if (iVar1 == 0) goto LAB_00104bb0;
    }
    pEVar2 = local_2c;
    if (local_2c != (EVP_MD *)0x0) {
      pEVar2 = (EVP_MD *)EVP_MD_type(local_2c);
    }
    iVar1 = ssl_security(param_1,0x5000d,iVar1,pEVar2,&local_34);
    if (iVar1 != 0) {
      *(undefined1 **)(*(int *)(param_1 + 0x7c) + 0x278) = puVar13;
      return 1;
    }
  }
LAB_00104bb0:
  uVar10 = 0x47a;
LAB_00104b6a:
  ossl_statem_fatal(param_1,0x28,0x14d,0x172,"ssl/t1_lib.c",uVar10);
  return 0;
}

