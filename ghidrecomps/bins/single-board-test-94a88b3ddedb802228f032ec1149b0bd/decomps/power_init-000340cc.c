
void power_init(void)

{
  power_type_detect(&power_info);
  DAT_003b0f60 = 0;
  DAT_003b0f4c = 0;
  if ((int)((uint)((double)CONCAT44(DAT_003b0f50._4_4_,(undefined4)DAT_003b0f50) < DAT_00034170) <<
           0x1f) < 0) {
    DAT_003b0f50._0_4_ = DAT_00034178;
    DAT_003b0f50._4_4_ = DAT_0003417c;
  }
  DAT_003b0f64 = 0;
  DAT_003b0f68 = 0;
  DAT_003b0f58._0_4_ = DAT_00034180;
  DAT_003b0f58._4_4_ = DAT_00034184;
  return;
}

