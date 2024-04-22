
void engine_unregister_all_RAND(void)

{
  engine_table_cleanup(&rand_table);
  return;
}

