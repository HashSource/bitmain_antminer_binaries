
/* WARNING: Unknown calling convention */

void _cg_memcpy(void *dest,void *src,uint n,char *file,char *func,int line)

{
  char *__format;
  int iVar1;
  char tmp42 [2048];
  
  if ((int)(n - 1) < 0) {
    __format = DAT_00012738;
    if ((*DAT_0001272c != '\0') || (*DAT_00012730 != '\0')) goto LAB_000126ca;
    iVar1 = *DAT_00012734;
  }
  else if (dest == (void *)0x0) {
    __format = DAT_00012740;
    if ((*DAT_0001272c != '\0') || (*DAT_00012730 != '\0')) goto LAB_000126ca;
    iVar1 = *DAT_00012734;
  }
  else {
    if (src != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000a384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_LAB_0005f264)();
      return;
    }
    __format = DAT_0001273c;
    if ((*DAT_0001272c != '\0') || (*DAT_00012730 != '\0')) goto LAB_000126ca;
    iVar1 = *DAT_00012734;
  }
  if (iVar1 < 3) {
    return;
  }
LAB_000126ca:
  snprintf(tmp42,0x800,__format,n,file,func,line);
  _applog(3,tmp42,false);
  return;
}

