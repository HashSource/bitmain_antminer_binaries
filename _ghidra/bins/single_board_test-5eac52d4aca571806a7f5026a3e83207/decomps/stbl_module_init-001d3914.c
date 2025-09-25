
undefined4 stbl_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *pcVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *line;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong local_48;
  char *local_30;
  ulong local_2c [2];
  
  pcVar1 = CONF_imodule_get_value(param_1);
  psVar2 = NCONF_get_section(param_2,pcVar1);
  if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
    ERR_put_error(0xd,0xdf,0xac,"crypto/asn1/asn_mstbl.c",0x1d);
    return 0;
  }
  iVar8 = 0;
  iVar3 = OPENSSL_sk_num(psVar2);
  if (0 < iVar3) {
    do {
      iVar3 = OPENSSL_sk_value(psVar2,iVar8);
      pcVar1 = *(char **)(iVar3 + 4);
      line = *(char **)(iVar3 + 8);
      local_2c[0] = 0;
      iVar3 = OBJ_sn2nid(pcVar1);
      if (((iVar3 == 0) && (iVar3 = OBJ_ln2nid(pcVar1), iVar3 == 0)) ||
         (psVar4 = X509V3_parse_list(line), psVar4 == (stack_st_CONF_VALUE *)0x0)) {
        ERR_put_error(0xd,0xde,0xda,"crypto/asn1/asn_mstbl.c",99);
        psVar4 = (stack_st_CONF_VALUE *)0x0;
        ERR_add_error_data(4,"name=",pcVar1,", value=",line);
LAB_001d3a6a:
        OPENSSL_sk_pop_free(psVar4,0x1752a9);
        ERR_put_error(0xd,0xdf,0xdb,"crypto/asn1/asn_mstbl.c",0x23);
        return 0;
      }
      uVar9 = 0;
      local_48 = 0xffffffff;
      uVar10 = 0xffffffff;
      for (iVar7 = 0; iVar5 = OPENSSL_sk_num(psVar4), iVar7 < iVar5; iVar7 = iVar7 + 1) {
        iVar5 = OPENSSL_sk_value(psVar4,iVar7);
        pcVar1 = *(char **)(iVar5 + 4);
        if (*pcVar1 == 'm') {
          if (pcVar1[1] != 'i') {
            if (((pcVar1[1] != 'a') || (pcVar1[2] != 'x')) || (pcVar1[3] != '\0'))
            goto LAB_001d39e8;
            local_48 = strtoul(*(char **)(iVar5 + 8),&local_30,0);
            if (*local_30 != '\0') goto LAB_001d3a40;
            goto LAB_001d39c8;
          }
          if ((pcVar1[2] != 'n') || (pcVar1[3] != '\0')) goto LAB_001d39e8;
          uVar10 = strtoul(*(char **)(iVar5 + 8),&local_30,0);
          if (*local_30 == '\0') goto LAB_001d39c8;
LAB_001d3a40:
          ERR_put_error(0xd,0xde,0xda,"crypto/asn1/asn_mstbl.c",99);
          ERR_add_error_data(4,"field=",*(undefined4 *)(iVar5 + 4),", value=",
                             *(undefined4 *)(iVar5 + 8));
          goto LAB_001d3a6a;
        }
LAB_001d39e8:
        iVar6 = strcmp(pcVar1,"mask");
        if (iVar6 == 0) {
          iVar6 = ASN1_str2mask(*(undefined4 *)(iVar5 + 8),local_2c);
          if ((iVar6 != 0) && (local_2c[0] != 0)) goto LAB_001d39c8;
          goto LAB_001d3a40;
        }
        iVar6 = strcmp(pcVar1,"flags");
        if (iVar6 != 0) goto LAB_001d3a40;
        pcVar1 = *(char **)(iVar5 + 8);
        iVar6 = strcmp(pcVar1,"nomask");
        if (iVar6 == 0) {
          uVar9 = 2;
        }
        else {
          iVar6 = strcmp(pcVar1,"none");
          if (iVar6 != 0) goto LAB_001d3a40;
          uVar9 = 1;
        }
LAB_001d39c8:
      }
      iVar3 = ASN1_STRING_TABLE_add(iVar3,uVar10,local_48,local_2c[0],uVar9);
      if (iVar3 == 0) {
        ERR_put_error(0xd,0xde,0x41,"crypto/asn1/asn_mstbl.c",0x6d);
        goto LAB_001d3a6a;
      }
      iVar8 = iVar8 + 1;
      OPENSSL_sk_pop_free(psVar4,0x1752a9);
      iVar3 = OPENSSL_sk_num(psVar2);
    } while (iVar8 < iVar3);
  }
  return 1;
}

