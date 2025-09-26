
/* WARNING: Unknown calling convention */

void debug_verify_property_4(clib_rb *pTree,clib_rb_node *n)

{
  clib_rb_node *n_00;
  clib_rb_node *pcVar1;
  clib_rb_node *pcVar2;
  
  pcVar2 = &pTree->sentinel;
  do {
    if (n == pcVar2) {
      return;
    }
    n_00 = n->left;
    if (n->color == 1) {
      if ((n_00 != pcVar2) && (n_00->color != 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("debug_node_color(pTree,n->left) == 0","3rdparty/cstl/src/c_rb.c",0x1ef,
                      "debug_verify_property_4");
      }
      pcVar1 = n->right;
      if ((pcVar1 != pcVar2) && (pcVar1->color != 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("debug_node_color(pTree,n->right) == 0","3rdparty/cstl/src/c_rb.c",0x1f0,
                      "debug_verify_property_4");
      }
      if ((n->parent != pcVar2) && (n->parent->color != 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("debug_node_color(pTree,n->parent) == 0","3rdparty/cstl/src/c_rb.c",0x1f1,
                      "debug_verify_property_4");
      }
    }
    else {
      pcVar1 = n->right;
    }
    debug_verify_property_4(pTree,n_00);
    n = pcVar1;
  } while( true );
}

