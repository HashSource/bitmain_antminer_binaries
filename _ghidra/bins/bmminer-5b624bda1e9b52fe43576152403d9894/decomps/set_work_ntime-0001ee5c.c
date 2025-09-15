
/* WARNING: Unknown calling convention */

void set_work_ntime(work *work,int ntime)

{
  char *pcVar1;
  uint *work_ntime;
  
  pcVar1 = work->ntime;
  *(uint *)(work->data + 0x44) =
       ntime << 0x18 | ((uint)ntime >> 8 & 0xff) << 0x10 | ((uint)ntime >> 0x10 & 0xff) << 8 |
       (uint)ntime >> 0x18;
  if (pcVar1 != (char *)0x0) {
    free(pcVar1);
    pcVar1 = bin2hex(work->data + 0x44,4);
    work->ntime = pcVar1;
  }
  return;
}

