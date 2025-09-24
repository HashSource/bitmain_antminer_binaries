
ENGINE * ENGINE_get_pkey_meth_engine(int nid)

{
  ENGINE *pEVar1;
  
  pEVar1 = (ENGINE *)engine_table_select(&pkey_meth_table,nid);
  return pEVar1;
}

