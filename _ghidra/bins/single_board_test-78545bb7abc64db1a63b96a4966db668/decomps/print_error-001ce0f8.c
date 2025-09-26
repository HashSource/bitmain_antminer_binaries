
code * print_error(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_34;
  undefined4 local_30;
  
  memset(&local_34,0,0x24);
  local_34 = 5;
  pcVar2 = *(code **)(*param_3 + 8);
  if (pcVar2 != (code *)0x0) {
    local_30 = param_1;
    iVar1 = (*pcVar2)(param_3,&local_34);
    pcVar2 = (code *)0xffffffff;
    if (0 < iVar1) {
      pcVar2 = (code *)0x0;
    }
  }
  return pcVar2;
}

