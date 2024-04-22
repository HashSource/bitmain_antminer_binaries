
void read_BM1385_asic_register(undefined param_1,byte param_2,byte param_3,char param_4)

{
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  
  local_9 = 0;
  local_c = 4;
  if (param_4 != '\0') {
    local_c = 0x84;
  }
  local_b = param_2;
  local_a = param_3;
  local_9 = CRC5(&local_c,0x1b);
  printf("%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","read_BM1385_asic_register",
         (uint)local_c,(uint)local_b,(uint)local_a,(uint)local_9);
  uart_send(param_1,&local_c,4);
  return;
}

