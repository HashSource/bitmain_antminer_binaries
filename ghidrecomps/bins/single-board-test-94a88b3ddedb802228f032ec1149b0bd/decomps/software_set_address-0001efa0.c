
void software_set_address(void)

{
  char cVar1;
  int local_10;
  uint local_c;
  
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) && (testDone[local_c] != '\x01')) {
      cVar1 = '\0';
      chain_inactive(local_c & 0xff);
      usleep(5000);
      for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
        set_address(local_c & 0xff,0,cVar1);
        cVar1 = cVar1 + '\x02';
        usleep(5000);
      }
    }
  }
  return;
}

