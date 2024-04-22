
undefined4 open_i2c(void)

{
  uint local_20;
  undefined2 local_1c;
  undefined local_1a;
  byte local_19;
  uint local_18;
  undefined2 local_14;
  undefined local_12;
  undefined local_11;
  uint local_10;
  undefined2 local_c;
  undefined local_a;
  byte local_9;
  
  local_10 = (uint)gChain;
  local_c = 0;
  local_a = 4;
  local_9 = gChain;
  printf("--- %s on 7007, slave high = 0x%x, low = 0x%x\n",__FUNCTION___5185,4,(uint)gChain);
  i2c_fd = iic_init(&local_10);
  local_18 = (uint)gChain;
  local_14 = 1;
  local_12 = 2;
  local_11 = 0;
  printf("--- %s on 7007, slave high = 0x%x, low = 0x%x\n",__FUNCTION___5185,2,0);
  power_fd = iic_init(&local_18);
  local_20 = (uint)gChain;
  local_1c = 0;
  local_1a = 10;
  local_19 = gChain;
  printf("--- %s on 7007, slave high = 0x%x, low = 0x%x\n",__FUNCTION___5185,10,(uint)gChain);
  e2prom_fd = iic_init(&local_20);
  return i2c_fd;
}

