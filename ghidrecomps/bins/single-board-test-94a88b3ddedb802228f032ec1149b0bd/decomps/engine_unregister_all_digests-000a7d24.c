
void engine_unregister_all_digests(void)

{
  engine_table_cleanup(&digest_table);
  return;
}

