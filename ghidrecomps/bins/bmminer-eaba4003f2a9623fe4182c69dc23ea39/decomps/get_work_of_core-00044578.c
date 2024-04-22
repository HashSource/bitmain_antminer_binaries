
int get_work_of_core(int which_asic,int which_core,FILE *stream,int count)

{
  uint32_t uVar1;
  char *pcVar2;
  SCAN_FREQ_WORK *__ptr;
  int count_local;
  FILE *stream_local;
  int which_core_local;
  int which_asic_local;
  char str [1024];
  SCAN_FREQ_WORK *new_work;
  int m;
  int core_num;
  uint subid;
  char *temp;
  
  memset(str,0,0x400);
  subid = 0;
  while( true ) {
    pcVar2 = fgets(str,0x3ff,(FILE *)stream);
    if (pcVar2 == (char *)0x0) {
      return subid;
    }
    if ((uint)count <= subid) {
      return subid;
    }
    __ptr = scanfreq_info.works[which_asic] + count * which_core + subid;
    pcVar2 = strstr(str,"nonce");
    if (pcVar2 == (char *)0x0) break;
    for (temp = pcVar2 + 5; *temp == ' '; temp = temp + 1) {
    }
    s2hex((uchar *)&__ptr->nonce,(uchar *)temp,8);
    uVar1 = htonl(__ptr->nonce);
    __ptr->nonce = uVar1;
    pcVar2 = strstr(str,"midstate");
    if (pcVar2 == (char *)0x0) break;
    for (temp = pcVar2 + 8; *temp == ' '; temp = temp + 1) {
    }
    s2hex(__ptr->midstate,(uchar *)temp,0x40);
    pcVar2 = strstr(str,"data");
    if (pcVar2 == (char *)0x0) break;
    for (temp = pcVar2 + 4; *temp == ' '; temp = temp + 1) {
    }
    s2hex(__ptr->data,(uchar *)temp,0x18);
    memset(__ptr->is_nonce_return_back,0,0x40);
    __ptr->id = subid;
    subid = subid + 1;
  }
  free(__ptr);
  puts("get work err");
  return subid;
}

