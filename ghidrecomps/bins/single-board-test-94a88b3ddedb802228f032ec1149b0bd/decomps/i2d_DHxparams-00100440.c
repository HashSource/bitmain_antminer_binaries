
void i2d_DHxparams(int param_1,uchar **param_2)

{
  int *local_3c;
  int local_38;
  int local_34 [2];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int **local_14;
  
  local_24 = *(undefined4 *)(param_1 + 8);
  local_1c = *(undefined4 *)(param_1 + 0xc);
  local_20 = *(undefined4 *)(param_1 + 0x24);
  local_18 = *(undefined4 *)(param_1 + 0x28);
  if (((*(int *)(param_1 + 0x34) == 0) || (*(int *)(param_1 + 0x2c) == 0)) ||
     (*(int *)(param_1 + 0x30) < 1)) {
    local_14 = (int **)0x0;
  }
  else {
    local_3c = local_34;
    local_14 = &local_3c;
    local_28 = 8;
    local_38 = *(int *)(param_1 + 0x34);
    local_34[0] = *(int *)(param_1 + 0x30);
    local_2c = *(int *)(param_1 + 0x2c);
  }
  ASN1_item_i2d((ASN1_VALUE *)&local_24,param_2,DAT_00100488);
  return;
}

