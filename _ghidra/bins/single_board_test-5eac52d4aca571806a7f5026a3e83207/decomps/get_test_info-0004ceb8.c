
void get_test_info(char *log_name,test_info_t *test_info)

{
  char *pcVar1;
  test_info_t *test_info_local;
  char *log_name_local;
  char split [2];
  char m_log_name [128];
  char *token;
  
  memset(m_log_name,0,0x80);
  strncpy(m_log_name,log_name,0x7f);
  strncpy(test_info->file_path,log_name,0x7f);
  token = strtok(m_log_name,"_");
  while ((token != (char *)0x0 && (pcVar1 = strstr(token,LOG_PREFIX_LOCAL), pcVar1 == (char *)0x0)))
  {
    token = strtok((char *)0x0,"_");
  }
  pcVar1 = strtok((char *)0x0,"_");
  if (pcVar1 != (char *)0x0) {
    strncpy(test_info->test_type,pcVar1,0x7f);
  }
  pcVar1 = strtok((char *)0x0,"_");
  if (pcVar1 != (char *)0x0) {
    strncpy(test_info->miner_type,pcVar1,0x7f);
  }
  pcVar1 = strtok((char *)0x0,"_");
  if (pcVar1 != (char *)0x0) {
    strncpy(test_info->boardname,pcVar1,0x7f);
  }
  pcVar1 = strtok((char *)0x0,"_");
  if (pcVar1 != (char *)0x0) {
    strncpy(test_info->sn,pcVar1,0x7f);
  }
  strncpy(test_info->fac,test_info->sn,4);
  return;
}

