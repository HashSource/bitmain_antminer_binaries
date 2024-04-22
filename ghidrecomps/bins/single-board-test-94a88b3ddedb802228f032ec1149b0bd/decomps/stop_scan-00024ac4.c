
void stop_scan(char *param_1)

{
  strncpy(search_failed_info,param_1,0x40);
  saveSearchFailedFlagInfo();
  searchStatus = 2;
  do {
    processTEST();
    sleep(1);
  } while( true );
}

