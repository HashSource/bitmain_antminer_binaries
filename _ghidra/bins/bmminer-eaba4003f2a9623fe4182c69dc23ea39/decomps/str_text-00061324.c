
void * str_text(char *ptr)

{
  uchar uVar1;
  char *pcVar2;
  size_t sVar3;
  char *ptr_local;
  char tmp42 [2048];
  char *ret;
  char *txt;
  uchar *uptr;
  
  if ((ptr == (char *)0x0) && (pcVar2 = strdup("(null)"), pcVar2 == (char *)0x0)) {
    snprintf(tmp42,0x800,"Failed to malloc null in %s %s():%d","util.c","str_text",0xca3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  sVar3 = strlen(ptr);
  pcVar2 = (char *)_cgmalloc(sVar3 * 4 + 5,"util.c","str_text",0xca8);
  txt = pcVar2;
  uptr = (uchar *)ptr;
  do {
    if ((*uptr < 0x20) || (0x7e < *uptr)) {
      sprintf(txt,"0x%02x",(uint)*uptr);
      txt = txt + 4;
    }
    else {
      *txt = *uptr;
      txt = txt + 1;
    }
    uVar1 = *uptr;
    uptr = uptr + 1;
  } while (uVar1 != '\0');
  *txt = '\0';
  return pcVar2;
}

