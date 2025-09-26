
int UI_get_result_minsize(UI_STRING *uis)

{
  int iVar1;
  
  if (*(int *)uis - 1U < 2) {
    iVar1 = *(int *)(uis + 0x14);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

