
/* WARNING: Unknown calling convention */

char * recv_line(pool *pool)

{
  uint64_t *puVar1;
  uint64_t *puVar2;
  uint64_t *puVar3;
  double dVar4;
  _Bool _Var5;
  char *pcVar6;
  size_t sVar7;
  ssize_t buflen;
  char *tok;
  size_t sVar8;
  ssize_t len;
  uint uVar9;
  size_t slen;
  size_t old;
  size_t news;
  ssize_t sVar10;
  int *piVar11;
  int iVar12;
  char *__s;
  uint uVar13;
  ssize_t n;
  int iVar14;
  uint uVar15;
  int iVar16;
  size_t size;
  timeval rstart;
  timeval now;
  char tmp42_2 [2048];
  char tmp42 [2048];
  
  __s = pool->sockbuf;
  pcVar6 = strchr(__s,10);
  if (pcVar6 == (char *)0x0) {
    cgtime(&rstart);
    _Var5 = socket_full(pool,0x3c);
    dVar4 = DAT_00011f70;
    if (!_Var5) {
      if ((*DAT_00012028 != '\0') &&
         (((*DAT_0001202c != '\0' || (*DAT_00012030 != '\0')) || (6 < *DAT_00012034)))) {
        tmp42._0_4_ = *DAT_00012038;
        tmp42._4_4_ = DAT_00012038[1];
        tmp42._8_4_ = DAT_00012038[2];
        tmp42._12_4_ = DAT_00012038[3];
        tmp42._16_4_ = DAT_00012038[4];
        tmp42._20_4_ = DAT_00012038[5];
        tmp42._24_4_ = DAT_00012038[6];
        tmp42._28_4_ = DAT_00012038[7];
        tmp42._32_4_ = DAT_00012038[8];
        tmp42._36_4_ = DAT_00012038[9];
        tmp42[40] = (char)(short)DAT_00012038[10];
        tmp42[41] = (char)((ushort)(short)DAT_00012038[10] >> 8);
        _applog(7,tmp42,false);
      }
      goto LAB_00011e0c;
    }
    while( true ) {
      memset(tmp42,0,0x2000);
      sVar10 = recv(pool->sock,tmp42,0x1ffc,0);
      if (sVar10 == 0) break;
      cgtime(&now);
      iVar12 = (int)(longlong)
                    ((double)(longlong)(now.tv_sec - rstart.tv_sec) +
                    (double)(longlong)(now.tv_usec - rstart.tv_usec) / dVar4);
      if (sVar10 < 0) {
        piVar11 = __errno_location();
        if ((*piVar11 != 0xb) || (_Var5 = socket_full(pool,0x3c - iVar12), !_Var5)) {
          if ((*DAT_00011f80 != '\0') &&
             (((*DAT_00011f84 != '\0' || (*DAT_00011f88 != '\0')) || (6 < *DAT_00011f90)))) {
            tmp42_2._0_4_ = *DAT_00011fa0;
            tmp42_2._4_4_ = DAT_00011fa0[1];
            tmp42_2._8_4_ = DAT_00011fa0[2];
            tmp42_2._12_4_ = DAT_00011fa0[3];
            tmp42_2._16_4_ = DAT_00011fa0[4];
            tmp42_2._20_4_ = DAT_00011fa0[5];
            tmp42_2._24_4_ = DAT_00011fa0[6];
            tmp42_2._28_4_ = DAT_00011fa0[7];
            tmp42_2[32] = (char)DAT_00011fa0[8];
            _applog(7,tmp42_2,false);
          }
          goto LAB_00011f64;
        }
      }
      else {
        sVar7 = strlen(tmp42);
        pcVar6 = pool->sockbuf;
        sVar8 = strlen(pcVar6);
        old = sVar7 + sVar8;
        if (pool->sockbuf_size <= old + 1) {
          size = (old + 1 & 0xffffe000) + 0x2000;
          pcVar6 = (char *)_cgrealloc(pcVar6,size,DAT_00011f98,DAT_00011f9c,0x70b);
          pool->sockbuf = pcVar6;
          memset(pcVar6 + sVar8,0,size - sVar8);
          pcVar6 = pool->sockbuf;
          pool->sockbuf_size = size;
        }
        strcat(pcVar6,tmp42);
      }
      __s = pool->sockbuf;
      if ((0x3b < iVar12) || (pcVar6 = strchr(__s,10), pcVar6 != (char *)0x0)) goto LAB_00011d12;
    }
    if ((*DAT_00012028 != '\0') &&
       (((*DAT_0001202c != '\0' || (*DAT_00012030 != '\0')) || (6 < *DAT_00012034)))) {
      tmp42_2._0_4_ = *DAT_0001203c;
      tmp42_2._4_4_ = DAT_0001203c[1];
      tmp42_2._8_4_ = DAT_0001203c[2];
      tmp42_2._12_4_ = DAT_0001203c[3];
      tmp42_2._16_4_ = DAT_0001203c[4];
      tmp42_2._20_4_ = DAT_0001203c[5];
      tmp42_2._24_4_ = DAT_0001203c[6];
      tmp42_2._28_4_ = DAT_0001203c[7];
      tmp42_2._32_2_ = (undefined2)DAT_0001203c[8];
      tmp42_2[34] = (char)((uint)DAT_0001203c[8] >> 0x10);
      _applog(7,tmp42_2,false);
    }
LAB_00011f64:
    suspend_stratum(pool);
    __s = pool->sockbuf;
  }
LAB_00011d12:
  sVar7 = strlen(__s);
  pcVar6 = strtok(__s,DAT_00011f78);
  if (pcVar6 == (char *)0x0) {
    if ((*DAT_00011f80 != '\0') &&
       (((*DAT_00011f84 != '\0' || (*DAT_00011f88 != '\0')) || (6 < *DAT_00011f90)))) {
      tmp42._0_4_ = *DAT_00011f94;
      tmp42._4_4_ = DAT_00011f94[1];
      tmp42._8_4_ = DAT_00011f94[2];
      tmp42._12_4_ = DAT_00011f94[3];
      tmp42._16_4_ = DAT_00011f94[4];
      tmp42._20_4_ = DAT_00011f94[5];
      tmp42._24_4_ = DAT_00011f94[6];
      tmp42._28_4_ = DAT_00011f94[7];
      tmp42._32_4_ = DAT_00011f94[8];
      tmp42._36_4_ = DAT_00011f94[9];
      tmp42._40_4_ = DAT_00011f94[10];
      tmp42._44_4_ = DAT_00011f94[0xb];
      tmp42._48_4_ = DAT_00011f94[0xc];
      _applog(7,tmp42,false);
    }
  }
  else {
    pcVar6 = (char *)__strdup();
    sVar8 = strlen(pcVar6);
    if ((int)(sVar8 + 1) < (int)sVar7) {
      memmove(pool->sockbuf,pool->sockbuf + sVar8 + 1,(sVar7 - sVar8) + 1);
    }
    else {
      *pool->sockbuf = '\0';
    }
    puVar1 = &(pool->cgminer_pool_stats).bytes_received;
    uVar15 = *(uint *)puVar1;
    iVar16 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_received + 4);
    puVar2 = &(pool->cgminer_pool_stats).net_bytes_received;
    uVar13 = *(uint *)puVar2;
    iVar14 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4);
    puVar3 = &(pool->cgminer_pool_stats).times_received;
    uVar9 = *(uint *)puVar3;
    iVar12 = *(int *)((int)&(pool->cgminer_pool_stats).times_received + 4);
    *(uint *)puVar1 = uVar15 + sVar8;
    *(uint *)((int)&(pool->cgminer_pool_stats).bytes_received + 4) =
         iVar16 + ((int)sVar8 >> 0x1f) + (uint)CARRY4(uVar15,sVar8);
    *(size_t *)puVar2 = sVar8 + uVar13;
    *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4) =
         ((int)sVar8 >> 0x1f) + iVar14 + (uint)CARRY4(sVar8,uVar13);
    *(uint *)puVar3 = uVar9 + 1;
    *(uint *)((int)&(pool->cgminer_pool_stats).times_received + 4) =
         iVar12 + (uint)(0xfffffffe < uVar9);
    if (pcVar6 != (char *)0x0) {
      if (*DAT_00011f7c == '\0') {
        return pcVar6;
      }
      if (*DAT_00011f80 == '\0') {
        return pcVar6;
      }
      if (((*DAT_00011f84 == '\0') && (*DAT_00011f88 == '\0')) && (*DAT_00011f90 < 7)) {
        return pcVar6;
      }
      snprintf(tmp42,0x800,DAT_00011f8c,pcVar6);
      _applog(7,tmp42,false);
      return pcVar6;
    }
  }
LAB_00011e0c:
  clear_sock(pool);
  return (char *)0x0;
}

