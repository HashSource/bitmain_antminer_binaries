
void V9_set_baud(byte param_1,byte param_2)

{
  printf("\n--- %s: Chain : %d, baud = %d\n","V9_set_baud",(uint)param_1,(uint)param_2);
  BM1385_set_baud(param_1,0,param_2,1);
  usleep(50000);
  set_fpga_baud(param_2);
  return;
}

