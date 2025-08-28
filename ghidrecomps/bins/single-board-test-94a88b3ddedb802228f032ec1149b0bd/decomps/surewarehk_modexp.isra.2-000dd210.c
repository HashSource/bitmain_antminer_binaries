
int surewarehk_modexp_isra_2
              (BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  ulong *puVar2;
  char local_60 [12];
  undefined2 local_54;
  undefined1 auStack_52 [50];
  
  builtin_strncpy(local_60,"ENGINE_modex",0xc);
  local_54 = 0x70;
  memset(auStack_52,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x435);
  }
  else if (param_1 != (BIGNUM *)0x0) {
    bn_expand2(param_1,param_4[1]);
    if (param_1->dmax == param_4[1]) {
      iVar1 = (*p_surewarehk_Mod_Exp)
                        (local_60,param_1->dmax << 2,*param_4,param_3[1] << 2,*param_3,
                         param_2[1] << 2,*param_2,param_1->d);
      surewarehk_error_handling(local_60,0x6b,iVar1);
      if (iVar1 != 1) {
        return iVar1;
      }
      iVar1 = param_4[1];
      param_1->top = iVar1;
      if (iVar1 < 1) {
        return 1;
      }
      puVar2 = param_1->d + iVar1 + -1;
      do {
        if (*puVar2 != 0) break;
        iVar1 = iVar1 + -1;
        puVar2 = puVar2 + -1;
      } while (iVar1 != 0);
      param_1->top = iVar1;
      return 1;
    }
  }
  return 0;
}

