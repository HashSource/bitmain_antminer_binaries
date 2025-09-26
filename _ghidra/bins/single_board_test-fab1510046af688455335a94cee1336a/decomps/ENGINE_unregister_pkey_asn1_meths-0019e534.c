
void ENGINE_unregister_pkey_asn1_meths(ENGINE *e)

{
  engine_table_unregister(&pkey_asn1_meth_table,e);
  return;
}

