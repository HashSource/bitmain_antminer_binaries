
void debug_verify_property_4(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = debug_node_color(param_1,param_2);
  if (iVar1 == 1) {
    iVar1 = debug_node_color(param_1,*param_2);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("debug_node_color(pTree,n->left) == 0","3rdparty/cstl/src/c_rb.c",0x1ef,
                    "debug_verify_property_4");
    }
    iVar1 = debug_node_color(param_1,param_2[1]);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("debug_node_color(pTree,n->right) == 0","3rdparty/cstl/src/c_rb.c",0x1f0,
                    "debug_verify_property_4");
    }
    iVar1 = debug_node_color(param_1,param_2[2]);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("debug_node_color(pTree,n->parent) == 0","3rdparty/cstl/src/c_rb.c",0x1f1,
                    "debug_verify_property_4");
    }
  }
  if ((undefined4 *)(param_1 + 4) != param_2) {
    debug_verify_property_4(param_1,*param_2);
    debug_verify_property_4(param_1,param_2[1]);
  }
  return;
}

