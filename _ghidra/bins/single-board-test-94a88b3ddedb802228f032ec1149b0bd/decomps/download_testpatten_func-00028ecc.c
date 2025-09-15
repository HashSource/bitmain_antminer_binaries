
undefined4 download_testpatten_func(void)

{
  int iVar1;
  char acStack_814 [256];
  char acStack_714 [256];
  char acStack_614 [256];
  char acStack_514 [256];
  char acStack_414 [1024];
  FILE *local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  sprintf(acStack_414,"/bin/mkdir %s -p","/etc/config/32xPatten");
  system(acStack_414);
  for (local_c = 0; local_c < 0x40; local_c = local_c + 1) {
    sprintf(acStack_414,"/bin/rm %s/md5.txt -f","/etc/config/32xPatten");
    system(acStack_414);
    sprintf(acStack_414,"/usr/bin/md5sum %s/minertest64_%02d.bin > %s/md5.txt",
            "/etc/config/32xPatten",local_c + 1,"/etc/config/32xPatten");
    system(acStack_414);
    sprintf(acStack_714,"%s/md5.txt","/etc/config/32xPatten");
    sprintf(acStack_814,"%s/minertest64_%02d.txt","/etc/config/32xPatten",local_c + 1);
    iVar1 = isMD5fileSame(acStack_714,acStack_814);
    if (iVar1 == 0) {
      local_10 = 0;
      do {
        sprintf(acStack_414,"/bin/rm %s/minertest64_%02d.bin -f","/etc/config/32xPatten",local_c + 1
               );
        system(acStack_414);
        sprintf(acStack_414,"/bin/rm %s/minertest64_%02d.txt -f","/etc/config/32xPatten",local_c + 1
               );
        system(acStack_414);
        sprintf(acStack_514,"%s%02d.bin","http://192.168.60.30/download/minertest/minertest64_",
                local_c + 1);
        sprintf(acStack_614,"%s/minertest64_%02d.bin","/etc/config/32xPatten",local_c + 1);
        http_download(acStack_514,acStack_614);
        sprintf(acStack_514,"%s%02d.txt","http://192.168.60.30/download/minertest/minertest64_",
                local_c + 1);
        sprintf(acStack_614,"%s/minertest64_%02d.txt","/etc/config/32xPatten",local_c + 1);
        http_download(acStack_514,acStack_614);
        sprintf(acStack_414,"/bin/rm %s/md5.txt -f","/etc/config/32xPatten");
        system(acStack_414);
        sprintf(acStack_414,"/usr/bin/md5sum %s/minertest64_%02d.bin > %s/md5.txt",
                "/etc/config/32xPatten",local_c + 1,"/etc/config/32xPatten");
        system(acStack_414);
        sprintf(acStack_714,"%s/md5.txt","/etc/config/32xPatten");
        sprintf(acStack_814,"%s/minertest64_%02d.txt","/etc/config/32xPatten",local_c + 1);
        iVar1 = isMD5fileSame(acStack_714,acStack_814);
        if (iVar1 == 0) {
          local_10 = 0x17;
          sleep(10);
        }
        else {
          local_10 = 0;
        }
      } while (0 < local_10);
    }
  }
  if (3 < log_level) {
    local_14 = fopen(log_file,"a+");
    if (local_14 != (FILE *)0x0) {
      fprintf(local_14,"%s:%d: 32xPatten download and ready!\n","main.c",0xc4d);
    }
    fclose(local_14);
  }
  is32xPattenReady = 1;
  return 0;
}

