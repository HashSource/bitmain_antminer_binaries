
/* WARNING: Unknown calling convention */

void _recalloc(void **ptr,size_t old,size_t news,char *file,char *func,int line)

{
  void *pvVar1;
  
  if (news != old) {
    pvVar1 = _cgrealloc(*ptr,news,file,func,line);
    *ptr = pvVar1;
    if (old < news) {
                    /* WARNING: Could not recover jumptable at 0x0000a1c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_LAB_0005f1d8)((int)pvVar1 + old,0,news - old);
      return;
    }
  }
  return;
}

