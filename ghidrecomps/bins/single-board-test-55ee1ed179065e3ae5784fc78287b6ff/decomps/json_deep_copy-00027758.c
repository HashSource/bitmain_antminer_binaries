
int * json_deep_copy(int *param_1)

{
  if (param_1 == (int *)0x0) {
    param_1 = (int *)0x0;
  }
  else if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
      if ((param_1 == (int *)0x0) || (*param_1 != 2)) {
        if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
          if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
            if ((((param_1 == (int *)0x0) || (*param_1 != 5)) &&
                ((param_1 == (int *)0x0 || (*param_1 != 6)))) &&
               ((param_1 == (int *)0x0 || (*param_1 != 7)))) {
              param_1 = (int *)0x0;
            }
          }
          else {
            param_1 = (int *)json_real_copy(param_1);
          }
        }
        else {
          param_1 = (int *)json_integer_copy(param_1);
        }
      }
      else {
        param_1 = (int *)json_string_copy(param_1);
      }
    }
    else {
      param_1 = (int *)json_array_deep_copy(param_1);
    }
  }
  else {
    param_1 = (int *)json_object_deep_copy(param_1);
  }
  return param_1;
}

