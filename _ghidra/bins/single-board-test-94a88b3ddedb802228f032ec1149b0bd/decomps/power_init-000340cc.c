
void power_init(void)

{
  power_type_detect(&power_info);
  DAT_003b0f60 = 0;
  DAT_003b0f4c = 0;
  if ((int)((uint)((double)CONCAT44(DAT_003b0f50._4_4_,(undefined4)DAT_003b0f50) < 9.7) << 0x1f) < 0
     ) {
    DAT_003b0f50._0_4_ = 0x66666666;
    DAT_003b0f50._4_4_ = 0x4024e666;
  }
  DAT_003b0f58._4_4_ = 0x4025cccc;
  DAT_003b0f58._0_4_ = 0xcccccccd;
  DAT_003b0f64 = 0;
  DAT_003b0f68 = 0;
  return;
}

