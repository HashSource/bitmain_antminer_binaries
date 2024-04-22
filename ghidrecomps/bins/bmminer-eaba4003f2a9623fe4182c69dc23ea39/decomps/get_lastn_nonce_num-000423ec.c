
void get_lastn_nonce_num(char *dest,int n)

{
  int iVar1;
  size_t sVar2;
  int n_local;
  char *dest_local;
  char xtime [2048];
  char tmp [20];
  int j;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      xtime[0] = '{';
      xtime[1] = '\0';
      xtime[2] = '\0';
      xtime[3] = '\0';
      memset(xtime + 4,0,0x7fc);
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      tmp[4] = '\0';
      tmp[5] = '\0';
      tmp[6] = '\0';
      tmp[7] = '\0';
      tmp[8] = '\0';
      tmp[9] = '\0';
      tmp[10] = '\0';
      tmp[11] = '\0';
      tmp[12] = '\0';
      tmp[13] = '\0';
      tmp[14] = '\0';
      tmp[15] = '\0';
      tmp[16] = '\0';
      tmp[17] = '\0';
      tmp[18] = '\0';
      tmp[19] = '\0';
      sprintf(tmp,"Chain%d:{",i + 1);
      strcat(xtime,tmp);
      iVar1 = get_asic_nonce_num(i,0,n);
      sprintf(tmp,"N%d=%d",0,iVar1);
      strcat(xtime,tmp);
      for (j = 1; j < (int)(uint)dev->max_asic_num_in_one_chain; j = j + 1) {
        iVar1 = get_asic_nonce_num(i,j,n);
        sprintf(tmp,",N%d=%d",j,iVar1);
        strcat(xtime,tmp);
      }
      sVar2 = strlen(xtime);
      *(undefined2 *)(xtime + sVar2) = DAT_00077a80;
      xtime[sVar2 + 2] = DAT_00077a82;
      strcat(dest,xtime);
    }
  }
  sVar2 = strlen(dest);
  dest[sVar2 - 1] = '\0';
  return;
}

