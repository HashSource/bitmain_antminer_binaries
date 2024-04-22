
undefined4 lex_scan(int param_1,undefined4 param_2)

{
  char *__s1;
  int iVar1;
  int local_c;
  
  strbuffer_clear(param_1 + 0x28);
  if (*(int *)(param_1 + 0x34) == 0x100) {
    jsonp_free(*(undefined4 *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  local_c = lex_get(param_1,param_2);
  while ((((local_c == 0x20 || (local_c == 9)) || (local_c == 10)) || (local_c == 0xd))) {
    local_c = lex_get(param_1,param_2);
  }
  if (local_c == -1) {
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  else if (local_c == -2) {
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  }
  else {
    lex_save(param_1,local_c);
    if ((((local_c == 0x7b) || (local_c == 0x7d)) ||
        ((local_c == 0x5b || ((local_c == 0x5d || (local_c == 0x3a)))))) || (local_c == 0x2c)) {
      *(int *)(param_1 + 0x34) = local_c;
    }
    else if (local_c == 0x22) {
      lex_scan_string(param_1,param_2);
    }
    else if (((local_c < 0x30) || (0x39 < local_c)) && (local_c != 0x2d)) {
      if (((local_c < 0x41) || (0x5a < local_c)) && ((local_c < 0x61 || (0x7a < local_c)))) {
        lex_save_cached(param_1);
        *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
      }
      else {
        local_c = lex_get_save(param_1,param_2);
        while (((0x40 < local_c && (local_c < 0x5b)) || ((0x60 < local_c && (local_c < 0x7b))))) {
          local_c = lex_get_save(param_1,param_2);
        }
        lex_unget_unsave(param_1,local_c);
        __s1 = (char *)strbuffer_value(param_1 + 0x28);
        iVar1 = strcmp(__s1,"true");
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x34) = 0x103;
        }
        else {
          iVar1 = strcmp(__s1,"false");
          if (iVar1 == 0) {
            *(undefined4 *)(param_1 + 0x34) = 0x104;
          }
          else {
            iVar1 = strcmp(__s1,"null");
            if (iVar1 == 0) {
              *(undefined4 *)(param_1 + 0x34) = 0x105;
            }
            else {
              *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
            }
          }
        }
      }
    }
    else {
      lex_scan_number(param_1,local_c,param_2);
    }
  }
  return *(undefined4 *)(param_1 + 0x34);
}

