
void hexdump(char *name,void *p,int size)

{
  byte *pbVar1;
  uint uVar2;
  void *pvVar3;
  char *pcVar4;
  char *pcVar5;
  char tmp42 [2048];
  
  pcVar4 = "read return data";
  pcVar5 = name;
  snprintf(tmp42,0x800,"Dumping %u %s bytes from %p:\n",p,"read return data",name);
  _applog(2,tmp42,false);
  if ((int)p < 1) {
    return;
  }
  do {
    pvVar3 = (void *)0x0;
    do {
      while (p <= pvVar3) {
        pvVar3 = (void *)((int)pvVar3 + 1);
        tmp42._0_4_ = (int)"TLS_ECDHE_PSK_WITH_CHACHA20_POLY1305_SHA256" + 0x24;
        _applog(2,tmp42,false);
        if (pvVar3 == (void *)0x10) goto LAB_000ca08c;
      }
      pbVar1 = (byte *)(name + (int)pvVar3);
      pvVar3 = (void *)((int)pvVar3 + 1);
      snprintf(tmp42,0x800,"%02x ",(uint)*pbVar1,pcVar4,pcVar5);
      _applog(2,tmp42,false);
    } while (pvVar3 != (void *)0x10);
LAB_000ca08c:
    pvVar3 = (void *)0x0;
    do {
      while (p <= pvVar3) {
        pvVar3 = (void *)((int)pvVar3 + 1);
        tmp42[0] = ' ';
        tmp42[1] = '\0';
        _applog(2,tmp42,false);
        if (pvVar3 == (void *)0x10) goto LAB_000ca0dc;
      }
      uVar2 = (uint)(byte)name[(int)pvVar3];
      pvVar3 = (void *)((int)pvVar3 + 1);
      if (0x5e < uVar2 - 0x20) {
        uVar2 = 0x2e;
      }
      snprintf(tmp42,0x800,"%c",uVar2);
      _applog(2,tmp42,false);
    } while (pvVar3 != (void *)0x10);
LAB_000ca0dc:
    tmp42[0] = '\n';
    tmp42[1] = '\0';
    name = name + 0x10;
    _applog(2,tmp42,false);
    if ((int)p < 0x11) {
      return;
    }
    p = (void *)((int)p + -0x10);
  } while( true );
}

