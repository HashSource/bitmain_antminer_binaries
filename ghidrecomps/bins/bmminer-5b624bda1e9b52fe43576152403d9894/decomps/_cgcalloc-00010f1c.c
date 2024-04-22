
/* WARNING: Unknown calling convention */

void * _cgcalloc(int memb,size_t size,char *file,char *func,int line)

{
  void *pvVar1;
  void *ret;
  char tmp42 [2048];
  
  if ((size & 3) != 0) {
    size = (size & 0xfffffffc) + 4;
  }
  pvVar1 = calloc(memb,size);
  if (pvVar1 == (void *)0x0) {
    snprintf(tmp42,0x800,DAT_00010f78,memb,size,file,func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return pvVar1;
}

