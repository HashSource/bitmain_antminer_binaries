
/* WARNING: Unknown calling convention */

void debug_verify_properties(clib_rb *t)

{
  clib_rb_node *n;
  int black_count_path;
  
  n = t->root;
  debug_verify_property_1(t,n);
  if ((n != &t->sentinel) && (n->color != 0)) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("debug_node_color(pTree,root) == 0","3rdparty/cstl/src/c_rb.c",0x1e6,
                  "debug_verify_property_2");
  }
  debug_verify_property_4(t,n);
  black_count_path = -1;
  debug_verify_property_5_helper(t,n,0,&black_count_path);
  return;
}

