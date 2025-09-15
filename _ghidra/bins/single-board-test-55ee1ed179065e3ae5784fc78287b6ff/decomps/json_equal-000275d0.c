
undefined4 json_equal(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else if (*param_1 == *param_2) {
    if (param_1 == param_2) {
      uVar1 = 1;
    }
    else if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
      if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
        if ((param_1 == (int *)0x0) || (*param_1 != 2)) {
          if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
            if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
              uVar1 = 0;
            }
            else {
              uVar1 = json_real_equal(param_1,param_2);
            }
          }
          else {
            uVar1 = json_integer_equal(param_1,param_2);
          }
        }
        else {
          uVar1 = json_string_equal(param_1,param_2);
        }
      }
      else {
        uVar1 = json_array_equal(param_1,param_2);
      }
    }
    else {
      uVar1 = json_object_equal(param_1,param_2);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

