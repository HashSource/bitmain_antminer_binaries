
/* WARNING: Unknown calling convention */

void opt_free_table(void)

{
  free(opt_table);
  opt_table = (opt_table *)0x0;
  return;
}

