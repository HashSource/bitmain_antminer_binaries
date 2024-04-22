
_Bool conf_process(int chain,uint16_t (*freq_data) [9],char *str)

{
  size_t sVar1;
  char *pcVar2;
  int flag;
  int freq;
  char *str_local;
  uint16_t (*freq_data_local) [9];
  int chain_local;
  char chain_stamp [16];
  char temp_index [16];
  char temp_freq [16];
  char temp_str [16];
  int stamp_flag [110];
  int line_flag [110];
  int str_len;
  int i_2;
  int i_1;
  int i;
  int stamp_num;
  int line_num;
  _Bool ret;
  
  line_num = 0;
  stamp_num = 0;
  sVar1 = strlen(str);
  str_len = sVar1 + 1;
  sprintf(chain_stamp,"chain %d",chain + 1);
  pcVar2 = strstr(str,chain_stamp);
  if (pcVar2 == (char *)0x0) {
    puts("conf file format is incorrect, please check!");
    ret = false;
  }
  else {
    printf("now set: %s freq array ...\n",chain_stamp);
    for (i = 0; i < str_len; i = i + 1) {
      if ((str[i] == '\n') || (str[i] == '\0')) {
        line_flag[line_num] = i;
        line_num = line_num + 1;
      }
    }
    for (i_1 = 0; i_1 < str_len; i_1 = i_1 + 1) {
      if (str[i_1] == ':') {
        stamp_flag[stamp_num] = i_1;
        stamp_num = stamp_num + 1;
      }
    }
    for (i_2 = 0; i_2 < stamp_num; i_2 = i_2 + 1) {
      memset(temp_freq,0,0x10);
      strncpy(temp_freq,str + stamp_flag[i_2] + 1,(line_flag[i_2 + 1] - stamp_flag[i_2]) - 1);
      temp_freq[line_flag[i_2 + 1] - stamp_flag[i_2]] = '\0';
      memset(temp_index,0,0x10);
      strncpy(temp_index,str + line_flag[i_2] + 1,(stamp_flag[i_2] - line_flag[i_2]) - 1);
      temp_index[line_flag[i_2 + 1] - stamp_flag[i_2]] = '\0';
      flag = atoi(temp_index);
      freq = atoi(temp_freq);
      ret = set_freq_array(flag,freq_data,freq);
    }
  }
  return ret;
}

