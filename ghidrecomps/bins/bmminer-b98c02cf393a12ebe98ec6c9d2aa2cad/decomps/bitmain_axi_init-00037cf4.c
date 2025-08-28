
int bitmain_axi_init(void)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  undefined4 local_814;
  char local_810 [24];
  undefined2 local_7f8;
  
  iVar2 = znyq7010_axi_init(&local_814);
  if (iVar2 == 0) {
    dev = (undefined4 *)calloc(0x5470,1);
    cVar1 = opt_debug;
    if (dev != (undefined4 *)0x0) {
      *dev = local_814;
      if (cVar1 == '\0') {
        return 0;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
        return 0;
      }
      builtin_strncpy(local_810,"kmalloc for dev success.",0x18);
      local_7f8 = 10;
      _applog(7,local_810,0);
      return 0;
    }
    if ((opt_debug == '\0') ||
       (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
      iVar2 = -1;
    }
    else {
      builtin_strncpy(local_810,"kmalloc for dev failed.\n",0x18);
      local_7f8 = (ushort)local_7f8._1_1_ << 8;
      _applog(7,local_810,0);
      iVar2 = -1;
    }
  }
  else {
    if (log_level < 2) {
      return iVar2;
    }
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: znyq7010_axi_init failed.\n","driver-btm-c5.c",0x2ecc,
              "bitmain_axi_init");
    }
    fclose(__stream);
  }
  return iVar2;
}

