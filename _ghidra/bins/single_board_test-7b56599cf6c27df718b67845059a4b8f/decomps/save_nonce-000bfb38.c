
void save_nonce(work_format *work,uint32_t which_midstate,uint32_t nonce)

{
  int fd;
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *__ptr_02;
  size_t sVar1;
  uint32_t nonce_local;
  uint32_t which_midstate_local;
  work_format *work_local;
  uint32_t version;
  char type [16];
  uchar data_tmp [32];
  uchar midstate_tmp [32];
  char szmsg [1024];
  char *szversion;
  char *sznonce;
  char *szdata;
  char *szmidstate;
  int j;
  
  nonce_local = nonce;
  which_midstate_local = which_midstate;
  work_local = work;
  memset(szmsg,0,0x400);
  memset(midstate_tmp,0,0x20);
  memset(data_tmp,0,0x20);
  type[0] = '\0';
  type[1] = '\0';
  type[2] = '\0';
  type[3] = '\0';
  type[4] = '\0';
  type[5] = '\0';
  type[6] = '\0';
  type[7] = '\0';
  type[8] = '\0';
  type[9] = '\0';
  type[10] = '\0';
  type[0xb] = '\0';
  type[0xc] = '\0';
  type[0xd] = '\0';
  type[0xe] = '\0';
  type[0xf] = '\0';
  if (fd_log == (FILE *)0x0) {
    fd_log = (FILE *)fopen("/tmp/worklog.txt","ab");
  }
  version = (which_midstate_local << 0x15 | 0x20000000) >> 0x18 |
            ((which_midstate_local & 7) << 0x15) >> 8;
  nonce_local = nonce_local >> 0x18 | (nonce_local & 0xff0000) >> 8 | (nonce_local & 0xff00) << 8 |
                nonce_local << 0x18;
  midstate_tmp._0_4_ = *(undefined4 *)work_local->midstate[which_midstate_local];
  midstate_tmp._4_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 4);
  midstate_tmp._8_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 8);
  midstate_tmp._12_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 0xc);
  midstate_tmp._16_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 0x10);
  midstate_tmp._20_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 0x14);
  midstate_tmp._24_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 0x18);
  midstate_tmp._28_4_ = *(undefined4 *)(work_local->midstate[which_midstate_local] + 0x1c);
  memcpy(data_tmp,work_local->data,0xc);
  __ptr = bin2hex(midstate_tmp,0x20);
  __ptr_00 = bin2hex(data_tmp,0xc);
  __ptr_01 = bin2hex((uchar *)&nonce_local,4);
  __ptr_02 = bin2hex((uchar *)&version,4);
  sprintf(szmsg,"midstate %s data %s nonce %s version %s \r\n",__ptr,__ptr_00,__ptr_01,__ptr_02);
  sVar1 = strlen(szmsg);
  fwrite(szmsg,sVar1,1,(FILE *)fd_log);
  fflush((FILE *)fd_log);
  if (g_sock == 0) {
    g_sock = create_socket();
  }
  if (0 < g_sock) {
    memset(szmsg,0,0x400);
    for (j = 0; j < 0x10; j = j + 1) {
      if (((byte)(Local_Config_Information->Hash_Board).Asic_Type[j] < 0x41) ||
         (0x5a < (byte)(Local_Config_Information->Hash_Board).Asic_Type[j])) {
        type[j] = (Local_Config_Information->Hash_Board).Asic_Type[j];
      }
      else {
        type[j] = (Local_Config_Information->Hash_Board).Asic_Type[j] + ' ';
      }
    }
    sprintf(szmsg,"type %s midstate %s data %s nonce %s version %s\n",type,__ptr,__ptr_00,__ptr_01,
            __ptr_02);
    fd = g_sock;
    sVar1 = strlen(szmsg);
    send_nonce(fd,szmsg,sVar1);
  }
  if (__ptr != (char *)0x0) {
    free(__ptr);
  }
  if (__ptr_00 != (char *)0x0) {
    free(__ptr_00);
  }
  if (__ptr_01 != (char *)0x0) {
    free(__ptr_01);
  }
  if (__ptr_02 != (char *)0x0) {
    free(__ptr_02);
  }
  return;
}

