
void copy_time(timeval *dest,timeval *src)

{
  timeval *src_local;
  timeval *dest_local;
  
  _cg_memcpy(dest,src,8,"util.c","copy_time",0x4d4);
  return;
}

