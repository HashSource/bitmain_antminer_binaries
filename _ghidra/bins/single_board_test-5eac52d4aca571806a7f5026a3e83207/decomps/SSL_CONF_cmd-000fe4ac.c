
undefined4 SSL_CONF_cmd(uint *param_1,char *param_2,int param_3)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_2 == (char *)0x0) {
    ERR_put_error(0x14,0x14e,0x181,"ssl/ssl_conf.c",0x323);
    return 0;
  }
  pcVar6 = (char *)param_1[1];
  if (pcVar6 == (char *)0x0) {
    uVar8 = *param_1;
    if ((uVar8 & 1) != 0) {
      if (*param_2 != '-') {
        return 0xfffffffe;
      }
      pcVar6 = param_2 + 1;
      param_2 = param_2 + 1;
      if (*pcVar6 == '\0') {
        return 0xfffffffe;
      }
    }
  }
  else {
    sVar2 = strlen(param_2);
    uVar7 = param_1[2];
    if (sVar2 <= uVar7) {
      return 0xfffffffe;
    }
    uVar8 = *param_1;
    if (((uVar8 & 1) != 0) && (iVar3 = strncmp(param_2,pcVar6,uVar7), iVar3 != 0)) {
      return 0xfffffffe;
    }
    if (((uVar8 & 2) != 0) && (iVar3 = strncasecmp(param_2,pcVar6,uVar7), iVar3 != 0)) {
      return 0xfffffffe;
    }
    param_2 = param_2 + uVar7;
  }
  puVar4 = (undefined4 *)ssl_conf_cmd_lookup(param_1,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    if ((uVar8 & 0x10) != 0) {
      ERR_put_error(0x14,0x14e,0x182,"ssl/ssl_conf.c",0x340);
      ERR_add_error_data(2,&DAT_001feb80,param_2);
    }
    return 0xfffffffe;
  }
  if (*(short *)((int)puVar4 + 0xe) != 4) {
    if (param_3 == 0) {
      return 0xfffffffd;
    }
    iVar3 = (*(code *)*puVar4)(param_1,param_3);
    if (0 < iVar3) {
      return 2;
    }
    if (iVar3 == -2) {
      return 0xfffffffe;
    }
    if ((int)(*param_1 << 0x1b) < 0) {
      ERR_put_error(0x14,0x14e,0x180,"ssl/ssl_conf.c",0x339);
      ERR_add_error_data(4,&DAT_001feb80,param_2,", value=",param_3);
      return 0;
    }
    return 0;
  }
  uVar8 = (int)(puVar4 + -0x95dac) >> 4;
  if (0x15 < uVar8) {
    return 0;
  }
  puVar5 = (uint *)param_1[5];
  uVar7 = *(uint *)(&DAT_001fea98 + uVar8 * 8);
  if (puVar5 == (uint *)0x0) {
    return 1;
  }
  if ((int)(uVar7 << 0x1f) < 0) {
    uVar7 = uVar7 & 0xf00;
    if (uVar7 == 0x100) {
      bVar1 = false;
LAB_000fe640:
      puVar5 = (uint *)param_1[0xf];
      if (bVar1) goto LAB_000fe61a;
      goto LAB_000fe632;
    }
    if (uVar7 != 0x200) {
      if (uVar7 != 0) {
        return 1;
      }
      goto LAB_000fe632;
    }
    bVar1 = false;
  }
  else {
    uVar7 = uVar7 & 0xf00;
    if (uVar7 == 0x100) {
      bVar1 = true;
      goto LAB_000fe640;
    }
    if (uVar7 != 0x200) {
      if (uVar7 != 0) {
        return 1;
      }
      goto LAB_000fe61a;
    }
    bVar1 = true;
  }
  puVar5 = (uint *)param_1[0x10];
  if (bVar1) {
LAB_000fe61a:
    *puVar5 = *(uint *)(&ssl_cmd_switches + uVar8 * 8) | *puVar5;
    return 1;
  }
LAB_000fe632:
  *puVar5 = *puVar5 & ~*(uint *)(&ssl_cmd_switches + uVar8 * 8);
  return 1;
}

