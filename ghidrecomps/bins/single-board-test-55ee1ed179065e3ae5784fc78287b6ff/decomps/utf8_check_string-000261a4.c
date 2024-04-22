
undefined4 utf8_check_string(char *param_1,size_t param_2)

{
  int iVar1;
  int iVar2;
  size_t local_18;
  int local_c;
  
  local_18 = param_2;
  if (param_2 == 0xffffffff) {
    local_18 = strlen(param_1);
  }
  local_c = 0;
  do {
    if ((int)local_18 <= local_c) {
      return 1;
    }
    iVar1 = utf8_check_first(param_1[local_c]);
    if (iVar1 == 0) {
      return 0;
    }
    if (1 < iVar1) {
      if ((int)local_18 < local_c + iVar1) {
        return 0;
      }
      iVar2 = utf8_check_full(param_1 + local_c,iVar1,0);
      if (iVar2 == 0) {
        return 0;
      }
      local_c = local_c + iVar1 + -1;
    }
    local_c = local_c + 1;
  } while( true );
}

