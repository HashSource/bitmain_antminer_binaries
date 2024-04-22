
void BM1722_chain_inactive(undefined param_1)

{
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_c = 0;
  printf("\n--- %s\n","BM1722_chain_inactive");
  local_10 = 0x53;
  local_f = 5;
  local_e = 0;
  local_d = 0;
  local_c = CRC5(&local_10,0x20);
  dcr_uart_send(param_1,&local_10,5);
  usleep(5000);
  return;
}

