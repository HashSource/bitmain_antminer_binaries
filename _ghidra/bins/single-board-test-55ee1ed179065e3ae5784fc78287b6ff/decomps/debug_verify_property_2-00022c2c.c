
void debug_verify_property_2(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = debug_node_color(param_1,param_2);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("debug_node_color(pTree,root) == 0","3rdparty/cstl/src/c_rb.c",0x1e6,
                  "debug_verify_property_2");
  }
  return;
}

