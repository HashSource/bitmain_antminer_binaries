
void debug_verify_property_5_helper(int param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_14;
  
  iVar1 = debug_node_color(param_1,param_2);
  local_14 = param_3;
  if (iVar1 == 0) {
    local_14 = param_3 + 1;
  }
  if ((undefined4 *)(param_1 + 4) == param_2) {
    if (*param_4 == -1) {
      *param_4 = local_14;
    }
    else if (*param_4 != local_14) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("black_count == *path_black_count","3rdparty/cstl/src/c_rb.c",0x205,
                    "debug_verify_property_5_helper");
    }
  }
  else {
    debug_verify_property_5_helper(param_1,*param_2,local_14,param_4);
    debug_verify_property_5_helper(param_1,param_2[1],local_14,param_4);
  }
  return;
}

