
/* WARNING: Unknown calling convention */

void debug_verify_property_1(clib_rb *pTree,clib_rb_node *n)

{
  while( true ) {
    if (n == &pTree->sentinel) {
      return;
    }
    if (1 < (uint)n->color) break;
    debug_verify_property_1(pTree,n->left);
    n = n->right;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("debug_node_color(pTree,n) == 1 || debug_node_color(pTree,n) == 0",
                "3rdparty/cstl/src/c_rb.c",0x1df,"debug_verify_property_1");
}

