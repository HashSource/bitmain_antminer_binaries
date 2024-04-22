
undefined4 bm1740_app_test(void)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  int local_c;
  
  local_c = 10;
  asic_num = 0;
  set_core_timeout(0x100000);
  asic_num_calculate();
  asic_addr_interval();
  set_address();
  asic_num = 0;
  sleep(3);
  asic_num_calculate();
  sleep(1);
  puts("Send Work Test...\n");
  send_work_example();
  nonce_ok = 0;
  memset(&nonce_num_each_asic,0,0x10);
  puts("Tempture Sensor Test...\n");
  sensor_ok = 0;
  do {
    sleep(1);
    printf("waiting %d seconds\n",local_c);
    if ((nonce_ok == 1) && (sensor_ok == 1)) break;
    iVar3 = local_c;
    if (local_c < 1) {
      iVar3 = 0;
    }
    cVar2 = (char)iVar3;
    if (0 < local_c) {
      cVar2 = '\x01';
    }
    local_c = local_c + -1;
  } while (cVar2 != '\0');
  if (nonce_ok == 0) {
    puVar1 = &DAT_0002c194;
  }
  else {
    puVar1 = &DAT_0002c190;
  }
  if (sensor_ok == 0) {
    puVar4 = &DAT_0002c194;
  }
  else {
    puVar4 = &DAT_0002c190;
  }
  printf("nonce sensor [%s %s]\n",puVar1,puVar4);
  return 0;
}

