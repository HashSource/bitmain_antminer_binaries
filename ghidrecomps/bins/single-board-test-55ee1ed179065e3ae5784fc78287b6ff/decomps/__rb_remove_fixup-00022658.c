
void __rb_remove_fixup(int *param_1,int param_2)

{
  int local_18;
  int *local_10;
  int *local_c;
  
  local_18 = param_2;
  while ((*param_1 != local_18 && (*(int *)(local_18 + 0xc) == 0))) {
    if (**(int **)(local_18 + 8) == local_18) {
      local_c = *(int **)(*(int *)(local_18 + 8) + 4);
      if (local_c[3] == 1) {
        local_c[3] = 0;
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 1;
        __left_rotate(param_1,*(undefined4 *)(local_18 + 8));
        local_c = *(int **)(*(int *)(local_18 + 8) + 4);
      }
      if ((*(int *)(*local_c + 0xc) == 0) && (*(int *)(local_c[1] + 0xc) == 0)) {
        local_c[3] = 1;
        local_18 = *(int *)(local_18 + 8);
      }
      else {
        if (*(int *)(local_c[1] + 0xc) == 0) {
          *(undefined4 *)(*local_c + 0xc) = 0;
          local_c[3] = 1;
          __right_rotate(param_1,local_c);
          local_c = *(int **)(*(int *)(local_18 + 8) + 4);
        }
        local_c[3] = *(int *)(*(int *)(local_18 + 8) + 0xc);
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(local_c[1] + 0xc) = 0;
        __left_rotate(param_1,*(undefined4 *)(local_18 + 8));
        local_18 = *param_1;
      }
    }
    else {
      local_10 = **(int ***)(local_18 + 8);
      if (local_10[3] == 1) {
        local_10[3] = 0;
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 1;
        __right_rotate(param_1,*(undefined4 *)(local_18 + 8));
        local_10 = **(int ***)(local_18 + 8);
      }
      if ((*(int *)(local_10[1] + 0xc) == 0) && (*(int *)(*local_10 + 0xc) == 0)) {
        local_10[3] = 1;
        local_18 = *(int *)(local_18 + 8);
      }
      else {
        if (*(int *)(*local_10 + 0xc) == 0) {
          *(undefined4 *)(local_10[1] + 0xc) = 0;
          local_10[3] = 1;
          __left_rotate(param_1,local_10);
          local_10 = **(int ***)(local_18 + 8);
        }
        local_10[3] = *(int *)(*(int *)(local_18 + 8) + 0xc);
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(*local_10 + 0xc) = 0;
        __right_rotate(param_1,*(undefined4 *)(local_18 + 8));
        local_18 = *param_1;
      }
    }
  }
  *(undefined4 *)(local_18 + 0xc) = 0;
  return;
}

