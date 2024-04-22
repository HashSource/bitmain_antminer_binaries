
/* WARNING: Unknown calling convention */

void _free_work(work **workptr,char *file,char *func,int line)

{
  work *work;
  work *work_00;
  
  work_00 = *workptr;
  if (work_00 == (work *)0x0) {
    if (((*DAT_0001ed8c != '\0') || (*DAT_0001ed90 != '\0')) || (2 < *DAT_0001ed94)) {
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

