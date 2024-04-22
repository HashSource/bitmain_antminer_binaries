
void set_curblock(char *hexstr,uchar *bedata)

{
  uchar *bedata_local;
  char *hexstr_local;
  char tmp42 [2048];
  int ofs;
  
  _cg_wlock(&ch_lock,"cgminer.c","set_curblock",0x152f);
  cgtime(&block_timeval);
  strcpy(current_hash,hexstr);
  _cg_memcpy(current_block,bedata,0x20,"cgminer.c","set_curblock",0x1532);
  get_timestamp(blocktime,0x20,&block_timeval);
  _cg_wunlock(&ch_lock,"cgminer.c","set_curblock",0x1534);
  for (ofs = 0; (ofs < 0x39 && (current_hash[ofs] == (char)DAT_0007313c)); ofs = ofs + 1) {
  }
  strncpy(prev_block,current_hash + ofs,8);
  prev_block[8] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"New block: %s... diff %s",current_hash,block_diff);
    _applog(6,tmp42,false);
  }
  return;
}

