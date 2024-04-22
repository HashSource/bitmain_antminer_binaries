
void ENGINE_unregister_RSA(ENGINE *e)

{
  engine_table_unregister(&rsa_table,e);
  return;
}

