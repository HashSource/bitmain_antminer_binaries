
int cnt_of_proc(char *app_name)

{
  FILE *pFVar1;
  FILE *pFVar2;
  char *pcVar3;
  ushort **ppuVar4;
  int iVar5;
  size_t sVar6;
  char *app_name_local;
  char sub_pid [32];
  char cmd_stream [64];
  char buf [256];
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  int id;
  int cur_str_size;
  FILE *pFile_3;
  FILE *p_fd;
  int i;
  int last_space_pos;
  int inst_cnt;
  
  memset(buf,0,0x100);
  inst_cnt = 0;
  memset(cmd_stream,0,0x40);
  snprintf(cmd_stream,0x40,"pidof %s",app_name);
  pFVar1 = popen(cmd_stream,"r");
  if (pFVar1 == (FILE *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,(char *)&DAT_0008e568);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s:  app-service:%s Not Found!!!","cgminer.c",0x2ceb,"cnt_of_proc",
                app_name);
      }
      fclose(pFVar1);
    }
  }
  else {
    while (pcVar3 = fgets(buf,0x100,pFVar1), pcVar3 != (char *)0x0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,(char *)&DAT_0008e568);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: pidof %s command result is:%s\n","cgminer.c",0x2cce,
                  "cnt_of_proc",app_name,buf);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,(char *)&DAT_0008e568);
        if (pFVar2 != (FILE *)0x0) {
          sVar6 = strlen(buf);
          fprintf(pFVar2,"%s:%d:%s: strlen is: %d\n","cgminer.c",0x2ccf,"cnt_of_proc",sVar6);
        }
        fclose(pFVar2);
      }
    }
    pclose(pFVar1);
    last_space_pos = 0;
    for (i = 1; sVar6 = strlen(buf), (uint)i <= sVar6; i = i + 1) {
      memset(sub_pid,0,0x20);
      ppuVar4 = __ctype_b_loc();
      if (((*ppuVar4)[(byte)cmd_stream[i + 0x3f]] & 0x2000) != 0) {
        printf("[%d] is a white-space character:%d\n",i,(uint)(byte)cmd_stream[i + 0x3f]);
        strncpy(sub_pid,buf + last_space_pos,(i - last_space_pos) - 1);
        last_space_pos = i;
        iVar5 = atoi(sub_pid);
        if ((0 < iVar5) && (inst_cnt = inst_cnt + 1, 3 < log_level)) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,(char *)&DAT_0008e568);
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Parsed proc id is: %d\n","cgminer.c",0x2ce4,"cnt_of_proc",
                    iVar5);
          }
          fclose(pFVar1);
        }
      }
    }
  }
  if ((0 < inst_cnt) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,(char *)&DAT_0008e568);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s:  %d instance of %s is  already Running on this machine\n",
              "cgminer.c",0x2cf0,"cnt_of_proc",inst_cnt,app_name);
    }
    fclose(pFVar1);
  }
  return inst_cnt;
}

