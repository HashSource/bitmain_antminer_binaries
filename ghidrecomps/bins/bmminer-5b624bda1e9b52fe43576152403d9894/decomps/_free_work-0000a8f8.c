
void _free_work(work **workptr,char *file,char *func,int line)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,DAT_0000a924,workptr,file,func);
  _applog(3,tmp42,false);
  return;
}

