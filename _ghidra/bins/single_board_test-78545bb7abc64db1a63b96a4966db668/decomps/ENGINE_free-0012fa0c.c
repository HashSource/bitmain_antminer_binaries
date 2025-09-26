
int ENGINE_free(ENGINE *e)

{
  int iVar1;
  
  iVar1 = engine_free_util(e,1);
  return iVar1;
}

