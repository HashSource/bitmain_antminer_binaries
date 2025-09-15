
void write_pic(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_b = param_3;
  local_a = param_2;
  local_9 = param_1;
  iic_i2c_write(&local_b,1);
  return;
}

