
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_default_DSA(void)

{
  ENGINE *pEVar1;
  
  pEVar1 = (ENGINE *)engine_table_select(&dsa_table,1);
  return pEVar1;
}

