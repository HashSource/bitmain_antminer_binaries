
void set_work_ntime(work *work,int ntime)

{
  char *pcVar1;
  uint __bsx;
  int ntime_local;
  work *work_local;
  uint *work_ntime;
  
  *(uint *)(work->data + 0x44) =
       (uint)ntime >> 0x18 | (ntime & 0xff0000U) >> 8 | (ntime & 0xff00U) << 8 | ntime << 0x18;
  if (work->ntime != (char *)0x0) {
    free(work->ntime);
    pcVar1 = bin2hex(work->data + 0x44,4);
    work->ntime = pcVar1;
  }
  return;
}

