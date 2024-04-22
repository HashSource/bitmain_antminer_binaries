
void * http_download(char *param_1,char *param_2)

{
  void *local_434 [2];
  char acStack_42c [1024];
  FILE *local_2c;
  void *local_28;
  FILE *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  void **local_c;
  
  local_c = local_434;
  local_10 = 0;
  strcpy(acStack_42c,param_1);
  local_14 = curl_easy_init();
  if (local_14 == 0) {
    local_28 = (void *)0xffffffff;
  }
  else {
    local_10 = curl_slist_append(local_10,"Accept: application/zip");
    local_10 = curl_slist_append(local_10,"Content-Type: application/zip");
    local_18 = 0x2734;
    curl_easy_setopt(local_14,0x2734,&DAT_001301e4);
    local_1c = 0x2727;
    curl_easy_setopt(local_14,0x2727,local_10);
    local_20 = curl_fetch_url(local_14,acStack_42c,local_c,0,0);
    curl_easy_cleanup(local_14);
    curl_slist_free_all(local_10);
    if ((local_20 == 0) && (local_c[1] != (void *)0x0)) {
      if (*local_c == (void *)0x0) {
        local_28 = (void *)0xffffffff;
      }
      else {
        local_24 = fopen(param_2,"wb");
        if (local_24 == (FILE *)0x0) {
          if (3 < log_level) {
            local_2c = fopen(log_file,"a+");
            if (local_2c != (FILE *)0x0) {
              fprintf(local_2c,"%s:%d: Fatal Error: can not open %s \n","http.c",0x130,param_2);
            }
            fclose(local_2c);
          }
          do {
            sleep(1);
          } while( true );
        }
        fwrite(*local_c,1,(size_t)local_c[1],local_24);
        fclose(local_24);
        local_28 = local_c[1];
        free(*local_c);
      }
    }
    else {
      local_28 = (void *)0xffffffff;
    }
  }
  return local_28;
}

