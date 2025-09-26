
int RAND_query_egd_bytes(char *path,uchar *buf,int bytes)

{
  size_t sVar1;
  int __fd;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  uint *puVar5;
  uint extraout_r3;
  uint num;
  uint extraout_r3_00;
  int iVar6;
  uint uVar7;
  uchar *puVar8;
  byte local_198 [8];
  sockaddr local_190 [7];
  uchar auStack_120 [256];
  
  memset(local_190,0,0x6e);
  local_190[0].sa_family = 1;
  sVar1 = strlen(path);
  if (sVar1 < 0x6c) {
    BUF_strlcpy(local_190[0].sa_data,path,0x6c);
    sVar1 = strlen(path);
    __fd = socket(1,1,0);
    if (__fd != -1) {
LAB_001bf9ba:
      do {
        iVar2 = connect(__fd,local_190,sVar1 + 2);
        num = extraout_r3;
        if (iVar2 == 0) {
LAB_001bf9c8:
          iVar2 = 0;
          if (bytes < 1) goto LAB_001bfa14;
          goto LAB_001bf9d4;
        }
        puVar5 = (uint *)__errno_location();
        num = *puVar5;
        if (num == 0x6a) goto LAB_001bf9c8;
        if (0x6a < (int)num) {
          if (1 < num - 0x72) {
            iVar2 = 0;
            goto LAB_001bfa14;
          }
          goto LAB_001bf9ba;
        }
      } while ((num == 4) || (num == 0xb));
      iVar2 = 0;
      goto LAB_001bfa14;
    }
  }
  return -1;
LAB_001bfa10:
  iVar2 = -1;
  goto LAB_001bfa14;
  while( true ) {
    puVar8 = buf + iVar2;
    if (buf == (uchar *)0x0) {
      puVar8 = auStack_120;
    }
    uVar7 = 0;
    while( true ) {
      if (num == uVar7) break;
      sVar3 = read(__fd,puVar8 + uVar7,num - uVar7);
      if (sVar3 == 0) goto LAB_001bfa14;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_001bfa10;
      }
      else {
        uVar7 = uVar7 + sVar3;
      }
      num = (uint)local_198[0];
    }
    iVar2 = iVar2 + num;
    bytes = bytes - num;
    if (buf == (uchar *)0x0) {
      RAND_seed(auStack_120,num);
      num = extraout_r3_00;
    }
    if (bytes < 1) break;
LAB_001bf9d4:
    if (bytes < 0xff) {
      num = bytes;
    }
    local_198[1] = (byte)num;
    if (0xfe < bytes) {
      local_198[1] = 0xff;
    }
    iVar6 = 0;
    local_198[0] = 1;
    do {
      sVar3 = write(__fd,local_198 + iVar6,2 - iVar6);
      if (sVar3 < 0) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_001bfa10;
      }
      else {
        iVar6 = iVar6 + sVar3;
      }
    } while (iVar6 != 2);
    iVar6 = 0;
    do {
      sVar3 = read(__fd,local_198,1);
      if (sVar3 == 0) goto LAB_001bfa14;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_001bfa10;
      }
      else {
        iVar6 = iVar6 + sVar3;
      }
    } while (iVar6 != 1);
    num = (uint)local_198[0];
    if (num == 0) break;
  }
LAB_001bfa14:
  close(__fd);
  return iVar2;
}

