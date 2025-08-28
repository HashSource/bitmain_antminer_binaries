
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_cleanup(void)

{
  if (cleanup_stack != (_STACK *)0x0) {
    sk_pop_free(cleanup_stack,(func *)0xa61a9);
    cleanup_stack = (_STACK *)0x0;
  }
  RAND_set_rand_method((RAND_METHOD *)0x0);
  return;
}

