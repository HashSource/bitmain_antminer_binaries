
void store64(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_38;
  
  local_38 = (undefined1)param_3;
  *param_1 = local_38;
  local_38 = (undefined1)((uint)param_3 >> 8);
  param_1[1] = local_38;
  local_38 = (undefined1)((uint)param_3 >> 0x10);
  param_1[2] = local_38;
  local_38 = (undefined1)((uint)param_3 >> 0x18);
  param_1[3] = local_38;
  local_38 = (undefined1)param_4;
  param_1[4] = local_38;
  local_38 = (undefined1)((uint)param_4 >> 8);
  param_1[5] = local_38;
  local_38 = (undefined1)((uint)param_4 >> 0x10);
  param_1[6] = local_38;
  param_1[7] = (char)((uint)param_4 >> 0x18);
  return;
}

