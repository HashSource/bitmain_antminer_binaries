
undefined4 pkey_gost_ctrl01_str(EVP_PKEY_CTX *param_1,char *param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  __int32_t **pp_Var5;
  int iVar6;
  
  iVar2 = strcmp(param_2,DAT_000dfc24);
  if (iVar2 != 0) {
    return 0xfffffffe;
  }
  if (param_3 != (byte *)0x0) {
    sVar3 = strlen((char *)param_3);
    if (sVar3 == 1) {
      pp_Var5 = __ctype_toupper_loc();
      switch((*pp_Var5)[*param_3]) {
      case 0x30:
        iVar2 = 0x347;
        break;
      default:
        goto switchD_000dfbac_caseD_31;
      case 0x41:
        iVar2 = 0x348;
        break;
      case 0x42:
        iVar2 = 0x349;
        break;
      case 0x43:
        iVar2 = 0x34a;
      }
LAB_000dfb54:
      piVar4 = (int *)EVP_PKEY_CTX_get_data(param_1);
      *piVar4 = iVar2;
      return 1;
    }
    if (sVar3 == 2) {
      pp_Var5 = __ctype_toupper_loc();
      if ((*pp_Var5)[*param_3] == 0x58) {
        iVar2 = (*pp_Var5)[param_3[1]];
        if (iVar2 == 0x41) {
          iVar2 = 0x34b;
        }
        else {
          if (iVar2 != 0x42) {
            return 0;
          }
          iVar2 = 0x34c;
        }
        goto LAB_000dfb54;
      }
    }
    iVar2 = OBJ_txt2nid((char *)param_3);
    if (iVar2 != 0) {
      iVar6 = *DAT_000dfc28;
      piVar4 = DAT_000dfc28;
      while (iVar6 != 0) {
        if (iVar2 == iVar6) goto LAB_000dfb54;
        piVar1 = piVar4 + 7;
        piVar4 = piVar4 + 7;
        iVar6 = *piVar1;
      }
      ERR_GOST_error(0x7e,0x70,DAT_000dfc2c,0xee);
    }
  }
switchD_000dfbac_caseD_31:
  return 0;
}

