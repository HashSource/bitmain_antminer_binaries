
int parse_value(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_18 [3];
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x34);
  if (iVar1 == 0x101) {
    if ((param_2 & 8) == 0) {
      local_c = json_integer(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c));
    }
    else {
      iVar1 = jsonp_strtod(param_1 + 0x28,local_18);
      if (iVar1 != 0) {
        error_set(param_3,param_1,"real number overflow");
        return 0;
      }
      local_c = json_real(local_18[0]);
    }
  }
  else if (iVar1 < 0x102) {
    if (iVar1 == 0x5b) {
      local_c = parse_array(param_1,param_2,param_3);
    }
    else {
      if (iVar1 < 0x5c) {
        if (iVar1 == -1) {
          error_set(param_3,param_1,"invalid token");
          return 0;
        }
LAB_0002547c:
        error_set(param_3,param_1,"unexpected token");
        return 0;
      }
      if (iVar1 == 0x7b) {
        local_c = parse_object(param_1,param_2,param_3);
      }
      else {
        if (iVar1 != 0x100) goto LAB_0002547c;
        local_c = json_string_nocheck(*(undefined4 *)(param_1 + 0x38));
      }
    }
  }
  else if (iVar1 == 0x103) {
    local_c = json_true();
  }
  else if (iVar1 < 0x103) {
    local_c = json_real((int)*(undefined8 *)(param_1 + 0x38));
  }
  else if (iVar1 == 0x104) {
    local_c = json_false();
  }
  else {
    if (iVar1 != 0x105) goto LAB_0002547c;
    local_c = json_null();
  }
  if (local_c == 0) {
    local_c = 0;
  }
  return local_c;
}

