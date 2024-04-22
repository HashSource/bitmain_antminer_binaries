
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_default_DH(void)

{
  ENGINE *pEVar1;
  
  pEVar1 = (ENGINE *)engine_table_select(&dh_table,1);
  return pEVar1;
}

