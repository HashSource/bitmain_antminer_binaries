
undefined read_pic(void)

{
  undefined local_9;
  
  local_9 = 0;
  iic_i2c_read(&local_9,1);
  return local_9;
}

