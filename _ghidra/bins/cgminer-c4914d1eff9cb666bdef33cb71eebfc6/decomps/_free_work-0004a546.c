
void _free_work(work **workptr,char *file,char *func,int line)

{
  work *work_00;
  int line_local;
  char *func_local;
  char *file_local;
  work **workptr_local;
  char tmp42 [2048];
  work *work;
  
  work_00 = *workptr;
  if (work_00 == (work *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Free work called with NULL work from %s %s:%d",file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else {
    clean_work(work_00);
    free(work_00);
    *workptr = (work *)0x0;
  }
  return;
}

