
void ENGINE_unregister_ECDSA(ENGINE *e)

{
  engine_table_unregister(&ecdsa_table,e);
  return;
}

