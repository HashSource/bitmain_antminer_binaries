
undefined4 delete_c_rb(int **param_1)

{
  int **local_c;
  
  local_c = (int **)*param_1;
  while (param_1 + 1 != local_c) {
    if ((int **)*local_c == param_1 + 1) {
      if ((int **)local_c[1] == param_1 + 1) {
        __delete_c_rb_node(param_1,local_c);
        if (local_c[2] == (int *)0x0) {
          free(local_c);
          local_c = param_1 + 1;
        }
        else {
          local_c = (int **)local_c[2];
          if ((int **)*local_c == param_1 + 1) {
            if ((int **)local_c[1] != param_1 + 1) {
              free(local_c[1]);
              local_c[1] = (int *)(param_1 + 1);
            }
          }
          else {
            free(*local_c);
            *local_c = (int *)(param_1 + 1);
          }
        }
      }
      else {
        local_c = (int **)local_c[1];
      }
    }
    else {
      local_c = (int **)*local_c;
    }
  }
  free(param_1);
  return 0;
}

