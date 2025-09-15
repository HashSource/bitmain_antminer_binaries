
undefined4 lex_scan_number(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  char *local_1c;
  undefined8 local_18;
  char *local_c;
  
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  local_30 = param_2;
  if (param_2 == 0x2d) {
    local_30 = lex_get_save(param_1,param_3);
  }
  if (local_30 == 0x30) {
    local_30 = lex_get_save(param_1,param_3);
    if ((0x2f < local_30) && (local_30 < 0x3a)) {
      lex_unget_unsave(param_1,local_30);
      return 0xffffffff;
    }
  }
  else {
    if ((local_30 < 0x30) || (0x39 < local_30)) {
      lex_unget_unsave(param_1,local_30);
      return 0xffffffff;
    }
    local_30 = lex_get_save(param_1,param_3);
    while ((0x2f < local_30 && (local_30 < 0x3a))) {
      local_30 = lex_get_save(param_1,param_3);
    }
  }
  if (((local_30 == 0x2e) || (local_30 == 0x45)) || (local_30 == 0x65)) {
    if (local_30 == 0x2e) {
      iVar2 = lex_get(param_1,param_3);
      if ((iVar2 < 0x30) || (0x39 < iVar2)) {
        lex_unget(param_1,iVar2);
        return 0xffffffff;
      }
      lex_save(param_1,iVar2);
      local_30 = lex_get_save(param_1,param_3);
      while ((0x2f < local_30 && (local_30 < 0x3a))) {
        local_30 = lex_get_save(param_1,param_3);
      }
    }
    if ((local_30 == 0x45) || (local_30 == 0x65)) {
      local_30 = lex_get_save(param_1,param_3);
      if ((local_30 == 0x2b) || (local_30 == 0x2d)) {
        local_30 = lex_get_save(param_1,param_3);
      }
      if ((local_30 < 0x30) || (0x39 < local_30)) {
        lex_unget_unsave(param_1,local_30);
        return 0xffffffff;
      }
      local_30 = lex_get_save(param_1,param_3);
      while ((0x2f < local_30 && (local_30 < 0x3a))) {
        local_30 = lex_get_save(param_1,param_3);
      }
    }
    lex_unget_unsave(param_1,local_30);
    iVar2 = jsonp_strtod(param_1 + 0x28,&local_28);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 0x102;
      *(undefined4 *)(param_1 + 0x38) = local_28;
      *(undefined4 *)(param_1 + 0x3c) = uStack_24;
      return 0;
    }
    error_set(param_3,param_1,"real number overflow");
  }
  else {
    lex_unget_unsave(param_1,local_30);
    local_c = (char *)strbuffer_value(param_1 + 0x28);
    piVar1 = __errno_location();
    *piVar1 = 0;
    local_18 = strtoll(local_c,&local_1c,10);
    piVar1 = __errno_location();
    if (*piVar1 != 0x22) {
      if (local_c + *(int *)(param_1 + 0x2c) != local_1c) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("end == saved_text + lex->saved_text.length","3rdparty/jansson-2.6/src/load.c"
                      ,0x206,"lex_scan_number");
      }
      *(undefined4 *)(param_1 + 0x34) = 0x101;
      *(undefined4 *)(param_1 + 0x38) = (undefined4)local_18;
      *(undefined4 *)(param_1 + 0x3c) = local_18._4_4_;
      return 0;
    }
    if (local_18 < 0) {
      error_set(param_3,param_1,"too big negative integer");
    }
    else {
      error_set(param_3,param_1,"too big integer");
    }
  }
  return 0xffffffff;
}

