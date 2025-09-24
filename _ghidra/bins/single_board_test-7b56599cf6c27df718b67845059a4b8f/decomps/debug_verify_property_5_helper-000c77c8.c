
/* WARNING: Unknown calling convention */

void debug_verify_property_5_helper
               (clib_rb *pTree,clib_rb_node *n,int black_count,int *path_black_count)

{
  for (; n != &pTree->sentinel; n = n->right) {
    if (n->color == 0) {
      black_count = black_count + 1;
    }
    debug_verify_property_5_helper(pTree,n->left,black_count,path_black_count);
  }
  if (*path_black_count != -1) {
    if (*path_black_count == black_count + 1) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __assert_fail("black_count == *path_black_count","../../hal/3rdparty/cstl/src/c_rb.c",0x205,
                  "debug_verify_property_5_helper");
  }
  *path_black_count = black_count + 1;
  return;
}

