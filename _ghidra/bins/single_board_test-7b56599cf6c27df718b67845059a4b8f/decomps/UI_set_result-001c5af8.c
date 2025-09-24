
int UI_set_result(UI *ui,UI_STRING *uis,char *result)

{
  size_t sVar1;
  int iVar2;
  
  sVar1 = strlen(result);
  iVar2 = UI_set_result_ex(ui,uis,result,sVar1);
  return iVar2;
}

