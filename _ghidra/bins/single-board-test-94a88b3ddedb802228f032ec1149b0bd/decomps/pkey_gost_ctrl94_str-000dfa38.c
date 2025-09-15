
undefined4 pkey_gost_ctrl94_str(EVP_PKEY_CTX *param_1,char *param_2,byte *param_3)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  __int32_t **pp_Var4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar1 = strcmp(param_2,"paramset");
  if (iVar1 != 0) {
    return 0xfffffffe;
  }
  if (param_3 != (byte *)0x0) {
    sVar2 = strlen((char *)param_3);
    if (sVar2 == 1) {
      pp_Var4 = __ctype_toupper_loc();
      switch((*pp_Var4)[*param_3]) {
      case 0x41:
        iVar1 = 0x340;
        break;
      case 0x42:
        iVar1 = 0x341;
        break;
      case 0x43:
        iVar1 = 0x342;
        break;
      case 0x44:
        iVar1 = 0x343;
        break;
      default:
        goto switchD_000dfad4_default;
      }
LAB_000dfa78:
      piVar3 = (int *)EVP_PKEY_CTX_get_data(param_1);
      *piVar3 = iVar1;
      return 1;
    }
    if (sVar2 == 2) {
      pp_Var4 = __ctype_toupper_loc();
      if ((*pp_Var4)[*param_3] == 0x58) {
        iVar1 = (*pp_Var4)[param_3[1]];
        if (iVar1 == 0x42) {
          iVar1 = 0x345;
        }
        else if (iVar1 == 0x43) {
          iVar1 = 0x346;
        }
        else {
          if (iVar1 != 0x41) {
            return 0;
          }
          iVar1 = 0x344;
        }
        goto LAB_000dfa78;
      }
    }
    iVar1 = OBJ_txt2nid((char *)param_3);
    if (iVar1 != 0) {
      puVar6 = R3410_paramset;
      iVar5 = R3410_paramset._0_4_;
      while (iVar5 != 0) {
        if (iVar1 == iVar5) goto LAB_000dfa78;
        piVar3 = (int *)(puVar6 + 0x10);
        puVar6 = puVar6 + 0x10;
        iVar5 = *piVar3;
      }
      ERR_GOST_error(0x7f,0x70,"gost_pmeth.c",0xb1);
    }
  }
switchD_000dfad4_default:
  return 0;
}

