
undefined4 tls12_check_peer_sigalg(EVP_MD **param_1,int param_2,char *param_3,int *param_4)

{
  uint uVar1;
  EC_GROUP *group;
  EC_METHOD *meth;
  EC_POINT *pEVar2;
  point_conversion_form_t pVar3;
  EVP_MD *pEVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  EC_KEY *key;
  int iVar8;
  uint uVar9;
  undefined local_30 [8];
  char local_28;
  char local_27;
  
  iVar7 = *param_4;
  if (iVar7 == *(int *)(DAT_00070f8c + 0x30)) {
    iVar8 = DAT_00070f8c + 0x30;
  }
  else if (iVar7 == *(int *)(DAT_00070f8c + 0x38)) {
    iVar8 = DAT_00070f8c + 0x38;
  }
  else {
    if (iVar7 != *(int *)(DAT_00070f8c + 0x40)) {
      return 0xffffffff;
    }
    iVar8 = DAT_00070f8c + 0x40;
  }
  if (*(uint *)(iVar8 + 4) == 0xffffffff) {
    return 0xffffffff;
  }
  if ((uint)(byte)param_3[1] != *(uint *)(iVar8 + 4)) {
    iVar7 = 0x43c;
    goto LAB_00070e76;
  }
  if (iVar7 == 0x198) {
    key = (EC_KEY *)param_4[5];
    if (key == (EC_KEY *)0x0) {
      return 0;
    }
    group = EC_KEY_get0_group(key);
    if (group == (EC_GROUP *)0x0) {
      return 0;
    }
    meth = EC_GROUP_method_of(group);
    if (meth == (EC_METHOD *)0x0) {
      return 0;
    }
    iVar7 = EC_METHOD_get_field_type(meth);
    EC_GROUP_get_curve_name(group);
    iVar8 = tls1_ec_nid2curve_id();
    if (iVar8 == 0) {
      local_28 = -1;
      if (iVar7 != 0x196) {
        local_27 = '\x02';
      }
      else {
        local_27 = '\x01';
      }
    }
    else {
      local_27 = (char)iVar8;
      local_28 = '\0';
    }
    pEVar2 = EC_KEY_get0_public_key(key);
    if (pEVar2 == (EC_POINT *)0x0) {
      return 0;
    }
    pVar3 = EC_KEY_get_conv_form(key);
    if (pVar3 == POINT_CONVERSION_COMPRESSED) {
      if (iVar7 != 0x196) {
        local_30[0] = 2;
      }
      else {
        local_30[0] = 1;
      }
    }
    else {
      local_30[0] = 0;
    }
    if ((*(int *)(param_2 + 0x24) == 0) &&
       (iVar7 = tls1_check_ec_key(param_2,&local_28,local_30), iVar7 == 0)) {
      ERR_put_error(0x14,0x14d,0x17a,DAT_00070f90,0x446);
      return 0;
    }
    iVar7 = *(int *)(param_2 + 0x98);
    uVar1 = *(uint *)(iVar7 + 0x38);
    uVar9 = uVar1 & 0x30000;
    if (uVar9 == 0) goto LAB_00070d5e;
    if (local_28 != '\0') {
      return 0;
    }
    if (local_27 == '\x17') {
      cVar5 = *param_3;
      if (cVar5 != '\x04') {
        iVar7 = 0x450;
        goto LAB_00070e4e;
      }
    }
    else {
      if (local_27 != '\x18') {
        return 0;
      }
      cVar5 = *param_3;
      if (cVar5 != '\x05') {
        iVar7 = 0x456;
LAB_00070e4e:
        ERR_put_error(0x14,0x14d,0x17c,DAT_00070f90,iVar7);
        return 0;
      }
    }
    if (uVar9 != 0x20000) {
      iVar8 = DAT_00070f98;
      if (uVar9 == 0x30000) {
        uVar9 = 4;
        goto LAB_00070d78;
      }
      if (uVar9 == 0x10000) {
        uVar9 = 2;
        goto LAB_00070d78;
      }
      goto LAB_00070d62;
    }
    uVar9 = 2;
    iVar8 = DAT_00070f9c;
LAB_00070d78:
    uVar6 = 0;
    do {
      if ((*(char *)(iVar8 + uVar6) == cVar5) && (param_3[1] == *(char *)(iVar8 + uVar6 + 1)))
      break;
      uVar6 = uVar6 + 2;
    } while (uVar6 < uVar9);
    if (uVar9 == uVar6) goto LAB_00070e64;
    switch(cVar5) {
    case '\x01':
      pEVar4 = EVP_md5();
      break;
    case '\x02':
      goto switchD_00070da0_caseD_2;
    case '\x03':
      pEVar4 = EVP_sha224();
      break;
    case '\x04':
      pEVar4 = EVP_sha256();
      break;
    case '\x05':
      pEVar4 = EVP_sha384();
      break;
    case '\x06':
      pEVar4 = EVP_sha512();
      break;
    default:
      *param_1 = (EVP_MD *)0x0;
      goto LAB_00070eda;
    }
  }
  else {
    iVar7 = *(int *)(param_2 + 0x98);
    uVar1 = *(uint *)(iVar7 + 0x38);
    if ((uVar1 & 0x30000) != 0) {
      return 0;
    }
LAB_00070d5e:
    cVar5 = *param_3;
LAB_00070d62:
    if ((*(int *)(param_2 + 0x24) == 0) || (iVar8 = *(int *)(iVar7 + 0x134), iVar8 == 0)) {
      iVar8 = *(int *)(iVar7 + 300);
      if (iVar8 == 0) {
        uVar9 = 0x1e;
        iVar8 = DAT_00070f94;
        goto LAB_00070d78;
      }
      uVar9 = *(uint *)(iVar7 + 0x130);
    }
    else {
      uVar9 = *(uint *)(iVar7 + 0x138);
    }
    if (uVar9 != 0) goto LAB_00070d78;
LAB_00070e64:
    if ((cVar5 != '\x02') || ((uVar1 & 0x30001) != 0)) {
      iVar7 = 0x46a;
LAB_00070e76:
      ERR_put_error(0x14,0x14d,0x172,DAT_00070f90,iVar7);
      return 0;
    }
switchD_00070da0_caseD_2:
    pEVar4 = EVP_sha1();
  }
  *param_1 = pEVar4;
  if (pEVar4 != (EVP_MD *)0x0) {
    if ((*(int *)(param_2 + 0xc0) != 0) &&
       (iVar7 = *(int *)(*(int *)(param_2 + 0xc0) + 0x98), iVar7 != 0)) {
      *(EVP_MD **)(*(int *)(iVar7 + 8) + 8) = pEVar4;
      return 1;
    }
    return 1;
  }
LAB_00070eda:
  ERR_put_error(0x14,0x14d,0x170,DAT_00070f90,0x46f);
  return 0;
}

