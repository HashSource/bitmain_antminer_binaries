
void ENGINE_unregister_RAND(ENGINE *e)

{
  engine_table_unregister(&rand_table,e);
  return;
}

