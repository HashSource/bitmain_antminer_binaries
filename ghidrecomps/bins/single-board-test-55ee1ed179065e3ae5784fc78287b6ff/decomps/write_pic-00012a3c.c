
void write_pic(undefined param_1,undefined param_2,undefined param_3)

{
  undefined local_b;
  undefined local_a;
  undefined local_9;
  
  local_b = param_3;
  local_a = param_2;
  local_9 = param_1;
  iic_i2c_write(&local_b,1);
  return;
}

