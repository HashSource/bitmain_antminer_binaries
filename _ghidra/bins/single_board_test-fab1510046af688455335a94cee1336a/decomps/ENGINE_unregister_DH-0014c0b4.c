
void ENGINE_unregister_DH(ENGINE *e)

{
  engine_table_unregister(&dh_table,e);
  return;
}

