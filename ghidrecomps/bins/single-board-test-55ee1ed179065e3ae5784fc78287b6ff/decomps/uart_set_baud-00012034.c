
void uart_set_baud(undefined param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined local_9;
  
  local_10 = param_2;
  local_9 = param_1;
  printf("uart_set_config %d \n",param_2);
  uart_set_config(local_9,0,&local_10,4);
  return;
}

