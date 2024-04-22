
void __rb_insert_fixup(int *param_1,int param_2)

{
  int iVar1;
  int local_18;
  
  local_18 = param_2;
  while ((*param_1 != local_18 && (*(int *)(*(int *)(local_18 + 8) + 0xc) == 1))) {
    if (*(int *)(local_18 + 8) == **(int **)(*(int *)(local_18 + 8) + 8)) {
      iVar1 = *(int *)(*(int *)(*(int *)(local_18 + 8) + 8) + 4);
      if (*(int *)(iVar1 + 0xc) == 1) {
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(local_18 + 8) + 8) + 0xc) = 1;
        local_18 = *(int *)(*(int *)(local_18 + 8) + 8);
      }
      else {
        if (*(int *)(*(int *)(local_18 + 8) + 4) == local_18) {
          local_18 = *(int *)(local_18 + 8);
          __left_rotate(param_1,local_18);
        }
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(local_18 + 8) + 8) + 0xc) = 1;
        __right_rotate(param_1,*(undefined4 *)(*(int *)(local_18 + 8) + 8));
      }
    }
    else {
      iVar1 = **(int **)(*(int *)(local_18 + 8) + 8);
      if (*(int *)(iVar1 + 0xc) == 1) {
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(local_18 + 8) + 8) + 0xc) = 1;
        local_18 = *(int *)(*(int *)(local_18 + 8) + 8);
      }
      else {
        if (**(int **)(local_18 + 8) == local_18) {
          local_18 = *(int *)(local_18 + 8);
          __right_rotate(param_1,local_18);
        }
        *(undefined4 *)(*(int *)(local_18 + 8) + 0xc) = 0;
        *(undefined4 *)(*(int *)(*(int *)(local_18 + 8) + 8) + 0xc) = 1;
        __left_rotate(param_1,*(undefined4 *)(*(int *)(local_18 + 8) + 8));
      }
    }
  }
  *(undefined4 *)(*param_1 + 0xc) = 0;
  return;
}

