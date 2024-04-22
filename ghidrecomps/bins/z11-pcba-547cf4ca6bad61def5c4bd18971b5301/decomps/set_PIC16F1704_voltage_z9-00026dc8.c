
void set_PIC16F1704_voltage_z9(undefined4 param_1,undefined param_2,undefined2 param_3)

{
  undefined2 local_18;
  undefined local_15;
  undefined4 local_14;
  uint local_c;
  
  local_18 = param_3;
  local_15 = param_2;
  local_14 = param_1;
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    PIC16F1704_i2c_forward_send
              (local_14,local_15,*(undefined *)((int)&isl68127_i2c_dev_addr + local_c),0,0,1,0);
    PIC16F1704_i2c_forward_send
              (local_14,local_15,*(undefined *)((int)&isl68127_i2c_dev_addr + local_c),0,0x21,2,
               &local_18);
  }
  return;
}

