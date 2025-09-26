
/* WARNING: Unknown calling convention */

int32_t read_reset_key_val(void)

{
  int iVar1;
  uint32_t port;
  uint uVar2;
  uint8_t val;
  char cStack_80f;
  char cStack_80e;
  char cStack_80d;
  char acStack_80c [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    port = hal_key_reset_addr();
    gpio_read(port,&val);
    uVar2 = _val & 0xff;
    if (uVar2 != 0) {
      uVar2 = 1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    val = 'f';
    cStack_80f = 'a';
    cStack_80e = 'i';
    cStack_80d = 'l';
    builtin_strncpy(acStack_80c,"ed to api lock\n",0x10);
    _applog(0,(char *)&val,false);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

