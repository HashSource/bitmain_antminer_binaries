
void ENGINE_unregister_pkey_meths(ENGINE *e)

{
  engine_table_unregister(&pkey_meth_table,e);
  return;
}

