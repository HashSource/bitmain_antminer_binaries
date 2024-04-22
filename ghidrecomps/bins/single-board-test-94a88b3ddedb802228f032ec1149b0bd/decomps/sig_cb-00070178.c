
undefined4 sig_cb(void *param_1,size_t param_2,uint *param_3)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  char local_28 [24];
  
  if (param_1 == (void *)0x0) {
    return 0;
  }
  if (*param_3 == 0x38) {
    return 0;
  }
  if (0x13 < (int)param_2) {
    return 0;
  }
  memcpy(local_28,param_1,param_2);
  local_28[param_2] = '\0';
  pcVar1 = strchr(local_28,0x2b);
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  *pcVar1 = '\0';
  if (pcVar1[1] == '\0') {
    return 0;
  }
  if (local_28[0] == 'R') {
    if (((local_28[1] == 'S') && (local_28[2] == 'A')) && (local_28[3] == '\0')) {
      uVar7 = 6;
      goto LAB_0007020e;
    }
  }
  else if (((local_28[0] == 'D') && (local_28[1] == 'S')) &&
          ((local_28[2] == 'A' && (local_28[3] == '\0')))) {
    uVar7 = 0x74;
    goto LAB_0007020e;
  }
  iVar2 = strcmp(local_28,DAT_00070258);
  if (iVar2 != 0) {
    return 0;
  }
  uVar7 = 0x198;
LAB_0007020e:
  uVar3 = OBJ_sn2nid(pcVar1 + 1);
  if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcVar1 + 1), uVar3 == 0)) {
    return 0;
  }
  uVar5 = *param_3;
  if (uVar5 != 0) {
    puVar6 = param_3 + 1;
    uVar4 = 0;
    do {
      uVar4 = uVar4 + 2;
      if ((*puVar6 == uVar7) && (uVar3 == puVar6[1])) {
        return 0;
      }
      puVar6 = puVar6 + 2;
    } while (uVar4 < uVar5);
  }
  *param_3 = uVar5 + 2;
  param_3[uVar5 + 1] = uVar3;
  param_3[uVar5 + 2] = uVar7;
  return 1;
}

