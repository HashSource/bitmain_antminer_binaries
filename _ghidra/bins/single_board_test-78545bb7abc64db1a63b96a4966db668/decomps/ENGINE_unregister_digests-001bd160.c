
void ENGINE_unregister_digests(ENGINE *e)

{
  engine_table_unregister(&digest_table,e);
  return;
}

