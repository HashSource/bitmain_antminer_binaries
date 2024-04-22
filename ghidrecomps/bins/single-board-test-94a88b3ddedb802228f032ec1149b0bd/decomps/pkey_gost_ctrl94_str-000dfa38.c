
undefined4 pkey_gost_ctrl94_str(EVP_PKEY_CTX *param_1,char *param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  __int32_t **pp_Var5;
  int iVar6;
  
  iVar2 = strcmp(param_2,DAT_000dfb08);
  if (iVar2 != 0) {
    return 0xfffffffe;
  }
  if (param_3 != (byte *)0x0) {
    sVar3 = strlen((char *)param_3);
    if (sVar3 == 1) {
      pp_Var5 = __ctype_toupper_loc();
      switch((*pp_Var5)[*param_3]) {
      case 0x41:
        iVar2 = 0x340;
        break;
      case 0x42:
        iVar2 = 0x341;
        break;
      case 0x43:
        iVar2 = 0x342;
        break;
      case 0x44:
        iVar2 = 0x343;
        break;
      default:
        goto switchD_000dfad4_caseD_4;
      }
LAB_000dfa78:
      piVar4 = (int *)EVP_PKEY_CTX_get_data(param_1);
      *piVar4 = iVar2;
      return 1;
    }
    if (sVar3 == 2) {
      pp_Var5 = __ctype_toupper_loc();
      if ((*pp_Var5)[*param_3] == 0x58) {
        iVar2 = (*pp_Var5)[param_3[1]];
        if (iVar2 == 0x42) {
          iVar2 = 0x345;
        }
        else if (iVar2 == 0x43) {
          iVar2 = 0x346;
        }
        else {
          if (iVar2 != 0x41) {
            return 0;
          }
          iVar2 = 0x344;
        }
        goto LAB_000dfa78;
      }
    }
    iVar2 = OBJ_txt2nid((char *)param_3);
    if (iVar2 != 0) {
      iVar6 = *DAT_000dfb0c;
      piVar4 = DAT_000dfb0c;
      while (iVar6 != 0) {
        if (iVar2 == iVar6) goto LAB_000dfa78;
        piVar1 = piVar4 + 4;
        piVar4 = piVar4 + 4;
        iVar6 = *piVar1;
      }
      ERR_GOST_error(0x7f,0x70,DAT_000dfb10,0xb1);
    }
  }
switchD_000dfad4_caseD_4:
  return 0;
}

