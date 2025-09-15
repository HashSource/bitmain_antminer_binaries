
void json_delete(int *param_1)

{
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
      if ((param_1 == (int *)0x0) || (*param_1 != 2)) {
        if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
          if ((param_1 != (int *)0x0) && (*param_1 == 4)) {
            json_delete_real(param_1);
          }
        }
        else {
          json_delete_integer(param_1);
        }
      }
      else {
        json_delete_string(param_1);
      }
    }
    else {
      json_delete_array(param_1);
    }
  }
  else {
    json_delete_object(param_1);
  }
  return;
}

