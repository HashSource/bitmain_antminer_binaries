
void __bin2hex(undefined *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined *local_14;
  int local_c;
  
  local_14 = param_1;
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    puVar1 = local_14 + 1;
    *local_14 = hex_6139[*(byte *)(local_c + param_2) >> 4];
    local_14 = local_14 + 2;
    *puVar1 = hex_6139[*(byte *)(local_c + param_2) & 0xf];
  }
  *local_14 = 0;
  return;
}

