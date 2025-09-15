
int lex_get_save(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = stream_get(param_1,param_2);
  if ((iVar1 != -1) && (iVar1 != -2)) {
    lex_save(param_1,iVar1);
  }
  return iVar1;
}

