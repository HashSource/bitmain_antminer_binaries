
void sph_enc64be(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined local_50;
  undefined local_48;
  undefined local_40;
  undefined local_38;
  undefined local_30;
  
  local_38 = (undefined)((uint)param_4 >> 0x18);
  *param_1 = local_38;
  local_40 = (undefined)((uint)param_4 >> 0x10);
  param_1[1] = local_40;
  local_48 = (undefined)((uint)param_4 >> 8);
  param_1[2] = local_48;
  local_50 = (undefined)param_4;
  param_1[3] = local_50;
  param_1[4] = (char)((uint)param_3 >> 0x18);
  param_1[5] = (char)((uint)param_3 >> 0x10);
  param_1[6] = (char)((uint)param_3 >> 8);
  local_30 = (undefined)param_3;
  param_1[7] = local_30;
  return;
}

