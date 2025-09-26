
undefined4 tls12_check_peer_sigalg(undefined4 *param_1,int param_2,char *param_3,int *param_4)

{
  uint uVar1;
  EC_GROUP *group;
  EC_METHOD *meth;
  int iVar2;
  EC_POINT *pEVar3;
  point_conversion_form_t pVar4;
  EVP_MD *pEVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  EC_KEY *key;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 local_30 [8];
  char local_28;
  char local_27;
  
  iVar9 = *param_4;
  if (iVar9 == tls12_sig._0_4_) {
    puVar10 = tls12_sig;
  }
  else if (iVar9 == tls12_sig._8_4_) {
    puVar10 = (undefined1 *)0x24d318;
  }
  else {
    if (iVar9 != tls12_sig._16_4_) {
      return 0xffffffff;
    }
    puVar10 = (undefined1 *)0x24d320;
  }
  if (*(uint *)(puVar10 + 4) == 0xffffffff) {
    return 0xffffffff;
  }
  if ((uint)(byte)param_3[1] != *(uint *)(puVar10 + 4)) {
    iVar9 = 0x43c;
    goto LAB_00111206;
  }
  if (iVar9 != 0x198) {
    iVar9 = *(int *)(param_2 + 0x98);
    uVar1 = *(uint *)(iVar9 + 0x38);
    if ((uVar1 & 0x30000) != 0) {
      return 0;
    }
LAB_001110ee:
    cVar7 = *param_3;
LAB_001110f2:
    if ((*(int *)(param_2 + 0x24) == 0) ||
       (puVar10 = *(undefined1 **)(iVar9 + 0x134), (undefined4 *)puVar10 == (undefined4 *)0x0)) {
      puVar10 = *(undefined1 **)(iVar9 + 300);
      if ((undefined4 *)puVar10 == (undefined4 *)0x0) {
        puVar10 = tls12_sigalgs;
        uVar11 = 0x1e;
        goto LAB_00111108;
      }
      uVar11 = *(uint *)(iVar9 + 0x130);
    }
    else {
      uVar11 = *(uint *)(iVar9 + 0x138);
    }
    if (uVar11 != 0) goto LAB_00111108;
LAB_001111f4:
    if ((cVar7 != '\x02') || ((uVar1 & 0x30001) != 0)) {
      iVar9 = 0x46a;
LAB_00111206:
      ERR_put_error(0x14,0x14d,0x172,"t1_lib.c",iVar9);
      return 0;
    }
switchD_00111130_caseD_2:
    pEVar5 = EVP_sha1();
    goto LAB_00111222;
  }
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
  iVar9 = EC_METHOD_get_field_type(meth);
  EC_GROUP_get_curve_name(group);
  iVar2 = tls1_ec_nid2curve_id();
  if (iVar2 == 0) {
    local_28 = -1;
    if (iVar9 != 0x196) {
      local_27 = '\x02';
    }
    else {
      local_27 = '\x01';
    }
  }
  else {
    local_27 = (char)iVar2;
    local_28 = '\0';
  }
  pEVar3 = EC_KEY_get0_public_key(key);
  if (pEVar3 == (EC_POINT *)0x0) {
    return 0;
  }
  pVar4 = EC_KEY_get_conv_form(key);
  if (pVar4 == POINT_CONVERSION_COMPRESSED) {
    if (iVar9 != 0x196) {
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
     (iVar9 = tls1_check_ec_key(param_2,&local_28,local_30), iVar9 == 0)) {
    ERR_put_error(0x14,0x14d,0x17a,"t1_lib.c",0x446);
    return 0;
  }
  iVar9 = *(int *)(param_2 + 0x98);
  uVar1 = *(uint *)(iVar9 + 0x38);
  uVar11 = uVar1 & 0x30000;
  if (uVar11 == 0) goto LAB_001110ee;
  if (local_28 != '\0') {
    return 0;
  }
  if (local_27 == '\x17') {
    cVar7 = *param_3;
    if (cVar7 != '\x04') {
      iVar9 = 0x450;
      goto LAB_001111de;
    }
  }
  else {
    if (local_27 != '\x18') {
      return 0;
    }
    cVar7 = *param_3;
    if (cVar7 != '\x05') {
      iVar9 = 0x456;
LAB_001111de:
      ERR_put_error(0x14,0x14d,0x17c,"t1_lib.c",iVar9);
      return 0;
    }
  }
  if (uVar11 != 0x20000) {
    if (uVar11 == 0x30000) {
      puVar10 = (undefined1 *)&suiteb_sigalgs;
      uVar11 = 4;
      goto LAB_00111108;
    }
    if (uVar11 == 0x10000) {
      puVar10 = (undefined1 *)&suiteb_sigalgs;
      uVar11 = 2;
      goto LAB_00111108;
    }
    goto LAB_001110f2;
  }
  puVar10 = (undefined1 *)0x24d32a;
  uVar11 = 2;
LAB_00111108:
  uVar8 = 0;
  do {
    if ((*(char *)((int)puVar10 + uVar8) == cVar7) &&
       (param_3[1] == *(char *)((int)puVar10 + uVar8 + 1))) break;
    uVar8 = uVar8 + 2;
  } while (uVar8 < uVar11);
  if (uVar11 == uVar8) goto LAB_001111f4;
  switch(cVar7) {
  case '\x01':
    pEVar5 = EVP_md5();
    break;
  case '\x02':
    goto switchD_00111130_caseD_2;
  case '\x03':
    pEVar5 = EVP_sha224();
    break;
  case '\x04':
    pEVar5 = EVP_sha256();
    break;
  case '\x05':
    pEVar5 = EVP_sha384();
    break;
  case '\x06':
    pEVar5 = EVP_sha512();
    break;
  default:
    *param_1 = 0;
    goto LAB_0011126a;
  }
LAB_00111222:
  *param_1 = pEVar5;
  if (pEVar5 == (EVP_MD *)0x0) {
LAB_0011126a:
    ERR_put_error(0x14,0x14d,0x170,"t1_lib.c",0x46f);
    uVar6 = 0;
  }
  else if ((*(int *)(param_2 + 0xc0) == 0) ||
          (iVar9 = *(int *)(*(int *)(param_2 + 0xc0) + 0x98), iVar9 == 0)) {
    uVar6 = 1;
  }
  else {
    uVar6 = 1;
    *(EVP_MD **)(*(int *)(iVar9 + 8) + 8) = pEVar5;
  }
  return uVar6;
}

