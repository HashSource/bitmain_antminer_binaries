
code * print_error(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  pcVar2 = *(code **)(*param_3 + 8);
  local_28 = 5;
  if (pcVar2 != (code *)0x0) {
    local_24 = param_1;
    iVar1 = (*pcVar2)(param_3,&local_28);
    if (iVar1 == 0) {
      pcVar2 = (code *)0xffffffff;
    }
    else {
      pcVar2 = (code *)0x0;
    }
  }
  return pcVar2;
}

