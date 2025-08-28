
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void opt_free_table(void)

{
  free(opt_table);
  opt_table = (opt_table *)0x0;
  return;
}

