
int UI_get_result_maxsize(UI_STRING *uis)

{
  int iVar1;
  
  if (*(int *)uis - 1U < 2) {
    iVar1 = *(int *)(uis + 0x18);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

