
void _free_work(work **workptr,char *file,char *func,int line)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"Free work called with NULL work from %s %s:%d",workptr,file,func);
  _applog(3,tmp42,false);
  return;
}

