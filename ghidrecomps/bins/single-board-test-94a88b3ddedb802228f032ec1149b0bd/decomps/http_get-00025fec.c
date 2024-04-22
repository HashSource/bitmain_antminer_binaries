
int http_get(char *param_1,void **param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  void *local_438 [2];
  char acStack_430 [1024];
  FILE *local_30;
  FILE *local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  FILE *local_1c;
  int local_18;
  undefined4 local_14;
  void **local_10;
  int local_c;
  
  local_c = 0xffffffff;
  local_10 = local_438;
  local_14 = 0;
  strcpy(acStack_430,param_1);
  local_18 = curl_easy_init();
  if (local_18 == 0) {
    if (3 < log_level) {
      local_1c = fopen(log_file,"a+");
      if (local_1c != (FILE *)0x0) {
        fprintf(local_1c,"%s:%d: ERROR: Failed to create curl handle in fetch_session\n","http.c",
                0x15e);
      }
      fclose(local_1c);
    }
    local_c = -1;
  }
  else {
    local_14 = curl_slist_append(local_14,"Accept: application/json");
    local_14 = curl_slist_append(local_14,"Content-Type: application/json");
    local_20 = 0x2734;
    curl_easy_setopt(local_18,0x2734,&DAT_001301e4);
    local_24 = 0x2727;
    curl_easy_setopt(local_18,0x2727,local_14);
    local_28 = curl_fetch_url(local_18,acStack_430,local_10,0,0);
    curl_easy_cleanup(local_18);
    curl_slist_free_all(local_14);
    if ((local_28 == 0) && (local_10[1] != (void *)0x0)) {
      if (*local_10 == (void *)0x0) {
        if (3 < log_level) {
          local_2c = fopen(log_file,"a+");
          if (local_2c != (FILE *)0x0) {
            fprintf(local_2c,"%s:%d: ERROR: Failed to post msg to server\n","http.c",0x18b);
          }
          fclose(local_2c);
        }
        local_c = -1;
      }
      else {
        pvVar2 = malloc((int)local_10[1] + 1);
        *param_2 = pvVar2;
        memcpy(*param_2,*local_10,(size_t)local_10[1]);
        *(undefined *)((int)local_10[1] + (int)*param_2) = 0;
        local_c = (int)local_10[1] + 1;
        free(*local_10);
      }
    }
    else {
      if (3 < log_level) {
        local_30 = fopen(log_file,"a+");
        if (local_30 != (FILE *)0x0) {
          uVar1 = curl_easy_strerror(local_28);
          fprintf(local_30,"%s:%d: ERROR: Failed to fetch url (%s) - curl said: %s \n","http.c",
                  0x179,acStack_430,uVar1);
        }
        fclose(local_30);
      }
      local_c = -1;
    }
  }
  return local_c;
}

