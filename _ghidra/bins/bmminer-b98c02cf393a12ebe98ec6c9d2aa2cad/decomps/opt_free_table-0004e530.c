
void opt_free_table(void)

{
  free(opt_table);
  opt_table = (void *)0x0;
  return;
}

