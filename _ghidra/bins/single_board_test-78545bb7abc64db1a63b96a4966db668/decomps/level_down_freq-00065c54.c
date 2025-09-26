
int level_down_freq(int infreq,int *outfreq)

{
  int iVar1;
  int *outfreq_local;
  int infreq_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : level down freq %d\n","level_down_freq",infreq);
  snprintf(tmp1,0x100,"level down freq %d",infreq);
  log_to_file(tmp1,time_stamp);
  if (infreq == 0x1ae) {
    *outfreq = 0x1ae;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : no need to level down freq %d->%d\n","level_down_freq",0x1ae,*outfreq);
    snprintf(tmp1,0x100,"no need to level down freq %d->%d",0x1ae,*outfreq);
    log_to_file(tmp1,time_stamp);
    iVar1 = 1;
  }
  else {
    if (infreq == 0x1dd) {
      *outfreq = 0x1cc;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : level down freq %d->%d\n","level_down_freq",0x1dd,*outfreq);
      snprintf(tmp1,0x100,"level down freq %d->%d",0x1dd,*outfreq);
      log_to_file(tmp1,time_stamp);
    }
    else if (infreq == 0x1ea) {
      *outfreq = 0x1dd;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : level down freq %d->%d\n","level_down_freq",0x1ea,*outfreq);
      snprintf(tmp1,0x100,"level down freq %d->%d",0x1ea,*outfreq);
      log_to_file(tmp1,time_stamp);
    }
    else if (infreq == 0x1cc) {
      *outfreq = 0x1ae;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : level down freq %d->%d\n","level_down_freq",0x1cc,*outfreq);
      snprintf(tmp1,0x100,"level down freq %d->%d",0x1cc,*outfreq);
      log_to_file(tmp1,time_stamp);
    }
    iVar1 = 0;
  }
  return iVar1;
}

