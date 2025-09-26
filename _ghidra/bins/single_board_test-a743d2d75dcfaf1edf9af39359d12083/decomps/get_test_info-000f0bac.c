
void get_test_info(char *log_name,test_info_t *test_info)

{
  char *pcVar1;
  test_info_t *test_info_local;
  char *log_name_local;
  char tmp42 [2048];
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
  snprintf(tmp42,0x800,"test_type:%s\n",test_info->test_type);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"miner_type:%s\n",test_info->miner_type);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"boardname:%s\n",test_info->boardname);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"sn:%s\n",test_info->sn);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"fac:%s\n",test_info->fac);
  _applog(5,tmp42,false);
  return;
}

