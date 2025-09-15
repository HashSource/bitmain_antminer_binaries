
int freq_tuning_get_work_for_one_core(FILE **fp,int asic,int core,int count)

{
  uint32_t uVar1;
  char *pcVar2;
  freq_tuning_work *pfVar3;
  int count_local;
  int core_local;
  int asic_local;
  FILE **fp_local;
  char str [1024];
  freq_tuning_work *new_work;
  char *temp;
  uint32_t subid;
  
  memset(str,0,0x400);
  subid = 0;
  do {
    pcVar2 = fgets(str,0x3ff,(FILE *)*fp);
    if (pcVar2 == (char *)0x0) {
      return subid;
    }
    if (subid < (uint)count) {
      pfVar3 = g_works[asic] + count * core + subid;
      pcVar2 = strstr(str,"nonce");
      if (pcVar2 == (char *)0x0) {
        return subid;
      }
      for (temp = pcVar2 + 5; *temp == ' '; temp = temp + 1) {
      }
      s2hex((uchar *)&pfVar3->nonce,(uchar *)temp,8);
      uVar1 = htonl(pfVar3->nonce);
      pfVar3->nonce = uVar1;
      pcVar2 = strstr(str,"midstate");
      if (pcVar2 == (char *)0x0) {
        return subid;
      }
      for (temp = pcVar2 + 8; *temp == ' '; temp = temp + 1) {
      }
      s2hex(pfVar3->midstate,(uchar *)temp,0x40);
      pcVar2 = strstr(str,"data");
      if (pcVar2 == (char *)0x0) {
        return subid;
      }
      for (temp = pcVar2 + 4; *temp == ' '; temp = temp + 1) {
      }
      s2hex(pfVar3->data,(uchar *)temp,0x18);
      pfVar3->id = subid;
      subid = subid + 1;
    }
    if ((uint)count <= subid) {
      return subid;
    }
  } while( true );
}

