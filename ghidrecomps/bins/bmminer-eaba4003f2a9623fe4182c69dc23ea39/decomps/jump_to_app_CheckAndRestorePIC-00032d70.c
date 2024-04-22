
void jump_to_app_CheckAndRestorePIC(int chainIndex)

{
  int chainIndex_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar pic_version;
  int try_count;
  
  try_count = 0;
  jump_to_app_from_loader((uchar)chainIndex);
  get_pic_software_version((uchar)chainIndex,&pic_version);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Check chain[%d] PIC fw version=0x%02x\n",chainIndex,(uint)pic_version);
    _applog(5,tmp42,false);
  }
  return;
}

