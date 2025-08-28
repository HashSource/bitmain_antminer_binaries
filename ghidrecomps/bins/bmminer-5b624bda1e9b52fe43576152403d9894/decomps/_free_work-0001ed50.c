
/* WARNING: Unknown calling convention */

void _free_work(work **workptr,char *file,char *func,int line)

{
  work *work;
  work *work_00;
  
  work_00 = *workptr;
  if (work_00 == (work *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      _free_work((work **)file,func,(char *)line,line);
      return;
    }
  }
  else {
    clean_work(work_00);
    free(work_00);
    *workptr = (work *)0x0;
  }
  return;
}

