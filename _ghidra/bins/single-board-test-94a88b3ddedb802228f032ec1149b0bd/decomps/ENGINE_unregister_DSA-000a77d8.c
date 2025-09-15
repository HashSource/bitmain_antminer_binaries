
void ENGINE_unregister_DSA(ENGINE *e)

{
  engine_table_unregister(&dsa_table,e);
  return;
}

