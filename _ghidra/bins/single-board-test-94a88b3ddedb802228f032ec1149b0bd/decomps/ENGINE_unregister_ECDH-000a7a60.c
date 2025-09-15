
void ENGINE_unregister_ECDH(ENGINE *e)

{
  engine_table_unregister(&ecdh_table,e);
  return;
}

