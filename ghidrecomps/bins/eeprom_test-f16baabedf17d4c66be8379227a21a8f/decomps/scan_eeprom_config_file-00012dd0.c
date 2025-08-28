
_Bool scan_eeprom_config_file(char *conf_file_path,uint16_t (*freq_data) [12] [9])

{
  FILE *__stream;
  size_t sVar1;
  char *__s;
  char *pcVar2;
  uint16_t (*freq_data_local) [12] [9];
  char *conf_file_path_local;
  char msg [1024];
  char *chain_msg_ptr [16];
  int chain_msg_len [17];
  char *file_buf;
  int file_length;
  FILE *fp;
  int i_5;
  int i_4;
  int i_3;
  int j;
  int i_2;
  int i_1;
  int i;
  int freq_set_num;
  _Bool ret;
  
  __stream = fopen(conf_file_path,"r");
  if (__stream == (FILE *)0x0) {
    printf("%s : dose not exist, will use default freq configure\n",conf_file_path);
    for (i = 0; i < 0x10; i = i + 1) {
      if (chain_list[i] != 0) {
        printf("now set: chain %d freq array ...\n",i);
        memcpy(freq_data + i,def_freq_data,0xd8);
        travel_array(freq_data[i]);
      }
    }
    ret = true;
  }
  else {
    fseek(__stream,0,2);
    sVar1 = ftell(__stream);
    fseek(__stream,0,0);
    __s = (char *)malloc(sVar1);
    if (__s == (char *)0x0) {
      perror("failed to allocate memory for file_buf!\n");
      ret = false;
    }
    else {
      memset(__s,0,sVar1);
      for (i_1 = 0; i_1 < 0x10; i_1 = i_1 + 1) {
        pcVar2 = (char *)malloc(0x400);
        chain_msg_ptr[i_1] = pcVar2;
        if (chain_msg_ptr[i_1] == (char *)0x0) {
          perror("failed to allocate memory for chain_msg_ptr!\n");
          return false;
        }
        memset(chain_msg_ptr[i_1],0,0x400);
      }
      fread(__s,sVar1,1,__stream);
      j = 1;
      for (i_2 = 0; i_2 < (int)sVar1; i_2 = i_2 + 1) {
        if ((__s[i_2] == '\n') && (__s[i_2 + 1] == '\n')) {
          chain_msg_len[j] = i_2;
          j = j + 1;
          freq_set_num = j;
          if (0x10 < j) break;
        }
      }
      chain_msg_len[0] = 0;
      sVar1 = strlen(__s);
      chain_msg_len[freq_set_num] = sVar1;
      for (i_3 = 0; i_3 < freq_set_num; i_3 = i_3 + 1) {
        strncpy(chain_msg_ptr[i_3],__s + chain_msg_len[i_3],
                chain_msg_len[i_3 + 1] - chain_msg_len[i_3]);
        pcVar2 = strstr(chain_msg_ptr[i_3],"\n\n");
        if (pcVar2 != (char *)0x0) {
          strncpy(chain_msg_ptr[i_3],chain_msg_ptr[i_3] + 2,
                  chain_msg_len[i_3 + 1] - chain_msg_len[i_3]);
        }
      }
      for (i_4 = 0; i_4 < 0x10; i_4 = i_4 + 1) {
        if (chain_list[i_4] != 0) {
          ret = conf_process(i_4,freq_data[i_4],chain_msg_ptr[i_4]);
          if (!ret) {
            return false;
          }
          travel_array(freq_data[i_4]);
        }
      }
      if (__s != (char *)0x0) {
        free(__s);
      }
      for (i_5 = 0; i_5 < 0x10; i_5 = i_5 + 1) {
        if (chain_msg_ptr[i_5] != (char *)0x0) {
          free(chain_msg_ptr[i_5]);
          chain_msg_ptr[i_5] = (char *)0x0;
        }
      }
      fclose(__stream);
    }
  }
  return ret;
}

