
int UI_get_result_maxsize(UI_STRING *uis)

{
  if ((uis != (UI_STRING *)0x0) && (*(int *)uis - 1U < 2)) {
    return *(int *)(uis + 0x14);
  }
  return -1;
}

