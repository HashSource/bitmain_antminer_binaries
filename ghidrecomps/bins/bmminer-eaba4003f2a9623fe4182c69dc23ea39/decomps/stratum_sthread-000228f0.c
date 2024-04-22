
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff54 : 0x00022b0e */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void * stratum_sthread(void *userdata)

{
  work *pwVar1;
  _Bool _Var2;
  pthread_t __th;
  thread_q *ptVar3;
  stratum_share *__ptr;
  time_t tVar4;
  uint uVar5;
  size_t len;
  UT_hash_table *pUVar6;
  UT_hash_bucket *pUVar7;
  undefined4 uVar8;
  bool bVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  UT_hash_handle *pUVar14;
  UT_hash_bucket *pUVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  bool bVar19;
  char *pcVar20;
  char *pcVar21;
  void *userdata_local;
  char s [1024];
  char tmp42 [2048];
  work *work;
  uchar nonce2 [8];
  uint nonce;
  char nonce2hex [20];
  char noncehex [12];
  char threadname [16];
  int ssdiff;
  _Bool sessionid_match;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  uint *hash32;
  stratum_share *sshare;
  uint64_t *nonce2_64;
  pool *pool;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _ha_hashv;
  _Bool submitted;
  uint last_nonce;
  uint64_t last_nonce2;
  
  last_nonce2._0_4_ = 0;
  last_nonce2._4_4_ = 0;
  last_nonce = 0;
  __th = pthread_self();
  pthread_detach(__th);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,"%d/SStratum",*userdata);
  RenameThread(threadname);
  ptVar3 = tq_new();
  *(thread_q **)((int)userdata + 0x2e0) = ptVar3;
  if (*(int *)((int)userdata + 0x2e0) == 0) {
    tmp42[0] = s_Failed_to_create_stratum_q_in_st_000737d8[0];
    tmp42[1] = s_Failed_to_create_stratum_q_in_st_000737d8[1];
    tmp42[2] = s_Failed_to_create_stratum_q_in_st_000737d8[2];
    tmp42[3] = s_Failed_to_create_stratum_q_in_st_000737d8[3];
    tmp42[4] = s_Failed_to_create_stratum_q_in_st_000737d8[4];
    tmp42[5] = s_Failed_to_create_stratum_q_in_st_000737d8[5];
    tmp42[6] = s_Failed_to_create_stratum_q_in_st_000737d8[6];
    tmp42[7] = s_Failed_to_create_stratum_q_in_st_000737d8[7];
    tmp42[8] = s_Failed_to_create_stratum_q_in_st_000737d8[8];
    tmp42[9] = s_Failed_to_create_stratum_q_in_st_000737d8[9];
    tmp42[10] = s_Failed_to_create_stratum_q_in_st_000737d8[10];
    tmp42[11] = s_Failed_to_create_stratum_q_in_st_000737d8[11];
    tmp42[12] = s_Failed_to_create_stratum_q_in_st_000737d8[12];
    tmp42[13] = s_Failed_to_create_stratum_q_in_st_000737d8[13];
    tmp42[14] = s_Failed_to_create_stratum_q_in_st_000737d8[14];
    tmp42[15] = s_Failed_to_create_stratum_q_in_st_000737d8[15];
    tmp42[16] = s_Failed_to_create_stratum_q_in_st_000737d8[16];
    tmp42[17] = s_Failed_to_create_stratum_q_in_st_000737d8[17];
    tmp42[18] = s_Failed_to_create_stratum_q_in_st_000737d8[18];
    tmp42[19] = s_Failed_to_create_stratum_q_in_st_000737d8[19];
    tmp42[20] = s_Failed_to_create_stratum_q_in_st_000737d8[20];
    tmp42[21] = s_Failed_to_create_stratum_q_in_st_000737d8[21];
    tmp42[22] = s_Failed_to_create_stratum_q_in_st_000737d8[22];
    tmp42[23] = s_Failed_to_create_stratum_q_in_st_000737d8[23];
    tmp42[24] = s_Failed_to_create_stratum_q_in_st_000737d8[24];
    tmp42[25] = s_Failed_to_create_stratum_q_in_st_000737d8[25];
    tmp42[26] = s_Failed_to_create_stratum_q_in_st_000737d8[26];
    tmp42[27] = s_Failed_to_create_stratum_q_in_st_000737d8[27];
    tmp42[28] = s_Failed_to_create_stratum_q_in_st_000737d8[28];
    tmp42[29] = s_Failed_to_create_stratum_q_in_st_000737d8[29];
    tmp42[30] = s_Failed_to_create_stratum_q_in_st_000737d8[30];
    tmp42[31] = s_Failed_to_create_stratum_q_in_st_000737d8[31];
    tmp42[32] = s_Failed_to_create_stratum_q_in_st_000737d8[32];
    tmp42[33] = s_Failed_to_create_stratum_q_in_st_000737d8[33];
    tmp42[34] = s_Failed_to_create_stratum_q_in_st_000737d8[34];
    tmp42[35] = s_Failed_to_create_stratum_q_in_st_000737d8[35];
    tmp42[36] = s_Failed_to_create_stratum_q_in_st_000737d8[36];
    tmp42[37] = s_Failed_to_create_stratum_q_in_st_000737d8[37];
    tmp42[38] = s_Failed_to_create_stratum_q_in_st_000737d8[38];
    tmp42[39] = s_Failed_to_create_stratum_q_in_st_000737d8[39];
    tmp42[40] = s_Failed_to_create_stratum_q_in_st_000737d8[40];
    tmp42[41] = s_Failed_to_create_stratum_q_in_st_000737d8[41];
    tmp42[42] = s_Failed_to_create_stratum_q_in_st_000737d8[42];
    tmp42[43] = s_Failed_to_create_stratum_q_in_st_000737d8[43];
    tmp42[44] = (char)(short)ram0x00073804;
    tmp42[45] = (char)((ushort)(short)ram0x00073804 >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  do {
    while( true ) {
      while( true ) {
        if (*(char *)((int)userdata + 0x6d) != '\0') {
          tq_freeze(*(thread_q **)((int)userdata + 0x2e0));
          return (void *)0x0;
        }
        work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2e0),(timespec *)0x0);
        if (work == (work *)0x0) {
          tmp42[0] = s_Stratum_q_returned_empty_work_00073808[0];
          tmp42[1] = s_Stratum_q_returned_empty_work_00073808[1];
          tmp42[2] = s_Stratum_q_returned_empty_work_00073808[2];
          tmp42[3] = s_Stratum_q_returned_empty_work_00073808[3];
          tmp42[4] = s_Stratum_q_returned_empty_work_00073808[4];
          tmp42[5] = s_Stratum_q_returned_empty_work_00073808[5];
          tmp42[6] = s_Stratum_q_returned_empty_work_00073808[6];
          tmp42[7] = s_Stratum_q_returned_empty_work_00073808[7];
          tmp42[8] = s_Stratum_q_returned_empty_work_00073808[8];
          tmp42[9] = s_Stratum_q_returned_empty_work_00073808[9];
          tmp42[10] = s_Stratum_q_returned_empty_work_00073808[10];
          tmp42[11] = s_Stratum_q_returned_empty_work_00073808[11];
          tmp42[12] = s_Stratum_q_returned_empty_work_00073808[12];
          tmp42[13] = s_Stratum_q_returned_empty_work_00073808[13];
          tmp42[14] = s_Stratum_q_returned_empty_work_00073808[14];
          tmp42[15] = s_Stratum_q_returned_empty_work_00073808[15];
          tmp42[16] = s_Stratum_q_returned_empty_work_00073808[16];
          tmp42[17] = s_Stratum_q_returned_empty_work_00073808[17];
          tmp42[18] = s_Stratum_q_returned_empty_work_00073808[18];
          tmp42[19] = s_Stratum_q_returned_empty_work_00073808[19];
          tmp42[20] = s_Stratum_q_returned_empty_work_00073808[20];
          tmp42[21] = s_Stratum_q_returned_empty_work_00073808[21];
          tmp42[22] = s_Stratum_q_returned_empty_work_00073808[22];
          tmp42[23] = s_Stratum_q_returned_empty_work_00073808[23];
          tmp42[24] = s_Stratum_q_returned_empty_work_00073808[24];
          tmp42[25] = s_Stratum_q_returned_empty_work_00073808[25];
          tmp42[26] = s_Stratum_q_returned_empty_work_00073808[26];
          tmp42[27] = s_Stratum_q_returned_empty_work_00073808[27];
          tmp42[28] = (char)(short)ram0x00073824;
          tmp42[29] = (char)((ushort)(short)ram0x00073824 >> 8);
          _applog(3,tmp42,true);
          _quit(1);
        }
        if (work->nonce2_len < 9) break;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d asking for inappropriately long nonce2 length %d",*userdata,
                   work->nonce2_len);
          _applog(3,tmp42,false);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_Not_attempting_to_submit_shares_00073864[0];
          tmp42[1] = s_Not_attempting_to_submit_shares_00073864[1];
          tmp42[2] = s_Not_attempting_to_submit_shares_00073864[2];
          tmp42[3] = s_Not_attempting_to_submit_shares_00073864[3];
          tmp42[4] = s_Not_attempting_to_submit_shares_00073864[4];
          tmp42[5] = s_Not_attempting_to_submit_shares_00073864[5];
          tmp42[6] = s_Not_attempting_to_submit_shares_00073864[6];
          tmp42[7] = s_Not_attempting_to_submit_shares_00073864[7];
          tmp42[8] = s_Not_attempting_to_submit_shares_00073864[8];
          tmp42[9] = s_Not_attempting_to_submit_shares_00073864[9];
          tmp42[10] = s_Not_attempting_to_submit_shares_00073864[10];
          tmp42[11] = s_Not_attempting_to_submit_shares_00073864[11];
          tmp42[12] = s_Not_attempting_to_submit_shares_00073864[12];
          tmp42[13] = s_Not_attempting_to_submit_shares_00073864[13];
          tmp42[14] = s_Not_attempting_to_submit_shares_00073864[14];
          tmp42[15] = s_Not_attempting_to_submit_shares_00073864[15];
          tmp42[16] = s_Not_attempting_to_submit_shares_00073864[16];
          tmp42[17] = s_Not_attempting_to_submit_shares_00073864[17];
          tmp42[18] = s_Not_attempting_to_submit_shares_00073864[18];
          tmp42[19] = s_Not_attempting_to_submit_shares_00073864[19];
          tmp42[20] = s_Not_attempting_to_submit_shares_00073864[20];
          tmp42[21] = s_Not_attempting_to_submit_shares_00073864[21];
          tmp42[22] = s_Not_attempting_to_submit_shares_00073864[22];
          tmp42[23] = s_Not_attempting_to_submit_shares_00073864[23];
          tmp42[24] = s_Not_attempting_to_submit_shares_00073864[24];
          tmp42[25] = s_Not_attempting_to_submit_shares_00073864[25];
          tmp42[26] = s_Not_attempting_to_submit_shares_00073864[26];
          tmp42[27] = s_Not_attempting_to_submit_shares_00073864[27];
          tmp42[28] = s_Not_attempting_to_submit_shares_00073864[28];
          tmp42[29] = s_Not_attempting_to_submit_shares_00073864[29];
          tmp42[30] = s_Not_attempting_to_submit_shares_00073864[30];
          tmp42[31] = s_Not_attempting_to_submit_shares_00073864[31];
          _applog(3,tmp42,false);
        }
        _free_work(&work,"cgminer.c","stratum_sthread",0x1d79);
      }
      uVar10 = *(uint *)(work->data + 0x4c);
      uVar8 = *(undefined4 *)&work->nonce2;
      uVar11 = *(undefined4 *)((int)&work->nonce2 + 4);
      nonce = uVar10;
      if ((uVar10 != last_nonce) ||
         (nonce2._4_4_ != last_nonce2._4_4_ || nonce2._0_4_ != (int)last_nonce2)) break;
      if (((use_syslog != false) || (opt_log_output != false)) ||
         (nonce2._0_4_ = uVar8, nonce2._4_4_ = uVar11, 5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        nonce2._0_4_ = uVar8;
        nonce2._4_4_ = uVar11;
        snprintf(tmp42,0x800,"Filtering duplicate share to pool %d",*userdata);
        _applog(6,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1d85);
    }
    last_nonce2._0_1_ = nonce2[0];
    last_nonce2._1_1_ = nonce2[1];
    last_nonce2._2_1_ = nonce2[2];
    last_nonce2._3_1_ = nonce2[3];
    last_nonce2._4_1_ = nonce2[4];
    last_nonce2._5_1_ = nonce2[5];
    last_nonce2._6_1_ = nonce2[6];
    last_nonce2._7_1_ = nonce2[7];
    nonce2._0_4_ = uVar8;
    nonce2._4_4_ = uVar11;
    __bin2hex(noncehex,(uchar *)&nonce,4);
    __bin2hex(nonce2hex,nonce2,work->nonce2_len);
    __ptr = (stratum_share *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1d8e);
    pwVar1 = work;
    bVar19 = false;
    tVar4 = time((time_t *)0x0);
    __ptr->sshare_time = tVar4;
    __ptr->work = work;
    memset(s,0,0x400);
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1d97);
    __ptr->id = swork_id;
    swork_id = swork_id + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1d9a);
    if (*(char *)((int)userdata + 0x28c) == '\0') {
      pcVar17 = work->ntime;
      uVar5 = __ptr->id;
      pcVar20 = nonce2hex;
      pcVar21 = noncehex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,*(undefined4 *)((int)userdata + 0xb4),work->job_id,pcVar20,pcVar17,pcVar21,uVar5);
    }
    else {
      uVar8 = *(undefined4 *)((int)userdata + 0xb4);
      pcVar18 = work->job_id;
      pcVar17 = work->ntime;
      uVar5 = swab32(work->version);
      pcVar20 = nonce2hex;
      pcVar21 = noncehex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,uVar8,pcVar18,pcVar20,pcVar17,pcVar21,uVar5,__ptr->id);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Submitting share %08lx to pool %d",*(undefined4 *)(pwVar1->hash + 0x18),
               *userdata,pcVar20,pcVar17,pcVar21,uVar5);
      _applog(6,tmp42,false);
    }
    while( true ) {
      tVar4 = time((time_t *)0x0);
      if (__ptr->sshare_time + 0x78 <= tVar4) goto LAB_00023b52;
      len = strlen(s);
      _Var2 = stratum_send((pool *)userdata,s,len);
      if (_Var2) break;
      _Var2 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x62));
      if ((!_Var2) && (_Var2 = cnx_needed((pool *)userdata), _Var2)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d stratum share submission failure",*userdata);
          _applog(4,tmp42,false);
        }
        total_ro = total_ro + 1;
        *(int *)((int)userdata + 0x88) = *(int *)((int)userdata + 0x88) + 1;
      }
      if (opt_lowmem != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Lowmem_option_prevents_resubmitt_00073a08[0];
          tmp42[1] = s_Lowmem_option_prevents_resubmitt_00073a08[1];
          tmp42[2] = s_Lowmem_option_prevents_resubmitt_00073a08[2];
          tmp42[3] = s_Lowmem_option_prevents_resubmitt_00073a08[3];
          tmp42[4] = s_Lowmem_option_prevents_resubmitt_00073a08[4];
          tmp42[5] = s_Lowmem_option_prevents_resubmitt_00073a08[5];
          tmp42[6] = s_Lowmem_option_prevents_resubmitt_00073a08[6];
          tmp42[7] = s_Lowmem_option_prevents_resubmitt_00073a08[7];
          tmp42[8] = s_Lowmem_option_prevents_resubmitt_00073a08[8];
          tmp42[9] = s_Lowmem_option_prevents_resubmitt_00073a08[9];
          tmp42[10] = s_Lowmem_option_prevents_resubmitt_00073a08[10];
          tmp42[11] = s_Lowmem_option_prevents_resubmitt_00073a08[11];
          tmp42[12] = s_Lowmem_option_prevents_resubmitt_00073a08[12];
          tmp42[13] = s_Lowmem_option_prevents_resubmitt_00073a08[13];
          tmp42[14] = s_Lowmem_option_prevents_resubmitt_00073a08[14];
          tmp42[15] = s_Lowmem_option_prevents_resubmitt_00073a08[15];
          tmp42[16] = s_Lowmem_option_prevents_resubmitt_00073a08[16];
          tmp42[17] = s_Lowmem_option_prevents_resubmitt_00073a08[17];
          tmp42[18] = s_Lowmem_option_prevents_resubmitt_00073a08[18];
          tmp42[19] = s_Lowmem_option_prevents_resubmitt_00073a08[19];
          tmp42[20] = s_Lowmem_option_prevents_resubmitt_00073a08[20];
          tmp42[21] = s_Lowmem_option_prevents_resubmitt_00073a08[21];
          tmp42[22] = s_Lowmem_option_prevents_resubmitt_00073a08[22];
          tmp42[23] = s_Lowmem_option_prevents_resubmitt_00073a08[23];
          tmp42[24] = s_Lowmem_option_prevents_resubmitt_00073a08[24];
          tmp42[25] = s_Lowmem_option_prevents_resubmitt_00073a08[25];
          tmp42[26] = s_Lowmem_option_prevents_resubmitt_00073a08[26];
          tmp42[27] = s_Lowmem_option_prevents_resubmitt_00073a08[27];
          tmp42[28] = s_Lowmem_option_prevents_resubmitt_00073a08[28];
          tmp42[29] = s_Lowmem_option_prevents_resubmitt_00073a08[29];
          tmp42[30] = s_Lowmem_option_prevents_resubmitt_00073a08[30];
          tmp42[31] = s_Lowmem_option_prevents_resubmitt_00073a08[31];
          tmp42[32] = s_Lowmem_option_prevents_resubmitt_00073a08[32];
          tmp42[33] = s_Lowmem_option_prevents_resubmitt_00073a08[33];
          tmp42[34] = s_Lowmem_option_prevents_resubmitt_00073a08[34];
          tmp42[35] = s_Lowmem_option_prevents_resubmitt_00073a08[35];
          tmp42[36] = s_Lowmem_option_prevents_resubmitt_00073a08[36];
          tmp42[37] = s_Lowmem_option_prevents_resubmitt_00073a08[37];
          tmp42[38] = s_Lowmem_option_prevents_resubmitt_00073a08[38];
          tmp42[39] = s_Lowmem_option_prevents_resubmitt_00073a08[39];
          tmp42[40] = s_Lowmem_option_prevents_resubmitt_00073a08[40];
          tmp42[41] = s_Lowmem_option_prevents_resubmitt_00073a08[41];
          tmp42[42] = s_Lowmem_option_prevents_resubmitt_00073a08[42];
          tmp42[43] = s_Lowmem_option_prevents_resubmitt_00073a08[43];
          tmp42[44] = s_Lowmem_option_prevents_resubmitt_00073a08[44];
          tmp42[45] = s_Lowmem_option_prevents_resubmitt_00073a08[45];
          tmp42[46] = s_Lowmem_option_prevents_resubmitt_00073a08[46];
          tmp42[47] = s_Lowmem_option_prevents_resubmitt_00073a08[47];
          tmp42[48] = (char)(short)ram0x00073a38;
          tmp42[49] = (char)((ushort)(short)ram0x00073a38 >> 8);
          _applog(7,tmp42,false);
        }
        goto LAB_00023b52;
      }
      _cg_rlock((cglock_t *)((int)userdata + 0xdc),"cgminer.c","stratum_sthread",0x1dd7);
      if ((*(int *)((int)userdata + 0x26c) == 0) ||
         (iVar16 = strcmp(work->nonce1,*(char **)((int)userdata + 0x26c)), iVar16 != 0)) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      _cg_runlock((cglock_t *)((int)userdata + 0xdc),"cgminer.c","stratum_sthread",0x1dd9);
      if (!bVar9) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_No_matching_session_id_for_resub_00073a3c[0];
          tmp42[1] = s_No_matching_session_id_for_resub_00073a3c[1];
          tmp42[2] = s_No_matching_session_id_for_resub_00073a3c[2];
          tmp42[3] = s_No_matching_session_id_for_resub_00073a3c[3];
          tmp42[4] = s_No_matching_session_id_for_resub_00073a3c[4];
          tmp42[5] = s_No_matching_session_id_for_resub_00073a3c[5];
          tmp42[6] = s_No_matching_session_id_for_resub_00073a3c[6];
          tmp42[7] = s_No_matching_session_id_for_resub_00073a3c[7];
          tmp42[8] = s_No_matching_session_id_for_resub_00073a3c[8];
          tmp42[9] = s_No_matching_session_id_for_resub_00073a3c[9];
          tmp42[10] = s_No_matching_session_id_for_resub_00073a3c[10];
          tmp42[11] = s_No_matching_session_id_for_resub_00073a3c[11];
          tmp42[12] = s_No_matching_session_id_for_resub_00073a3c[12];
          tmp42[13] = s_No_matching_session_id_for_resub_00073a3c[13];
          tmp42[14] = s_No_matching_session_id_for_resub_00073a3c[14];
          tmp42[15] = s_No_matching_session_id_for_resub_00073a3c[15];
          tmp42[16] = s_No_matching_session_id_for_resub_00073a3c[16];
          tmp42[17] = s_No_matching_session_id_for_resub_00073a3c[17];
          tmp42[18] = s_No_matching_session_id_for_resub_00073a3c[18];
          tmp42[19] = s_No_matching_session_id_for_resub_00073a3c[19];
          tmp42[20] = s_No_matching_session_id_for_resub_00073a3c[20];
          tmp42[21] = s_No_matching_session_id_for_resub_00073a3c[21];
          tmp42[22] = s_No_matching_session_id_for_resub_00073a3c[22];
          tmp42[23] = s_No_matching_session_id_for_resub_00073a3c[23];
          tmp42[24] = s_No_matching_session_id_for_resub_00073a3c[24];
          tmp42[25] = s_No_matching_session_id_for_resub_00073a3c[25];
          tmp42[26] = s_No_matching_session_id_for_resub_00073a3c[26];
          tmp42[27] = s_No_matching_session_id_for_resub_00073a3c[27];
          tmp42[28] = s_No_matching_session_id_for_resub_00073a3c[28];
          tmp42[29] = s_No_matching_session_id_for_resub_00073a3c[29];
          tmp42[30] = s_No_matching_session_id_for_resub_00073a3c[30];
          tmp42[31] = s_No_matching_session_id_for_resub_00073a3c[31];
          tmp42[32] = s_No_matching_session_id_for_resub_00073a3c[32];
          tmp42[33] = s_No_matching_session_id_for_resub_00073a3c[33];
          tmp42[34] = s_No_matching_session_id_for_resub_00073a3c[34];
          tmp42[35] = s_No_matching_session_id_for_resub_00073a3c[35];
          tmp42[36] = s_No_matching_session_id_for_resub_00073a3c[36];
          tmp42[37] = s_No_matching_session_id_for_resub_00073a3c[37];
          tmp42[38] = s_No_matching_session_id_for_resub_00073a3c[38];
          tmp42[39] = s_No_matching_session_id_for_resub_00073a3c[39];
          tmp42[40] = s_No_matching_session_id_for_resub_00073a3c[40];
          tmp42[41] = s_No_matching_session_id_for_resub_00073a3c[41];
          tmp42[42] = s_No_matching_session_id_for_resub_00073a3c[42];
          tmp42[43] = s_No_matching_session_id_for_resub_00073a3c[43];
          tmp42[44] = s_No_matching_session_id_for_resub_00073a3c[44];
          tmp42[45] = s_No_matching_session_id_for_resub_00073a3c[45];
          tmp42[46] = s_No_matching_session_id_for_resub_00073a3c[46];
          tmp42[47] = s_No_matching_session_id_for_resub_00073a3c[47];
          tmp42[48] = s_No_matching_session_id_for_resub_00073a3c[48];
          tmp42[49] = s_No_matching_session_id_for_resub_00073a3c[49];
          tmp42[50] = s_No_matching_session_id_for_resub_00073a3c[50];
          tmp42[51] = s_No_matching_session_id_for_resub_00073a3c[51];
          tmp42._52_2_ = (undefined2)ram0x00073a70;
          _applog(7,tmp42,false);
        }
        goto LAB_00023b52;
      }
      sleep(2);
    }
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1dbe);
    _hj_key = (uchar *)&__ptr->id;
    _ha_hashv = 0xfeedbeef;
    _hj_j = 0x9e3779b9;
    _hj_i = 0x9e3779b9;
    for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
      iVar16 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                       (uint)_hj_key[7] * 0x1000000;
      uVar5 = _ha_hashv +
              (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
              (uint)_hj_key[0xb] * 0x1000000;
      uVar12 = uVar5 >> 0xd ^
               ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                         (uint)_hj_key[3] * 0x1000000) - iVar16) - uVar5;
      uVar13 = uVar12 << 8 ^ (iVar16 - uVar5) - uVar12;
      uVar5 = uVar13 >> 0xd ^ (uVar5 - uVar12) - uVar13;
      uVar12 = uVar5 >> 0xc ^ (uVar12 - uVar13) - uVar5;
      uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar5) - uVar12;
      uVar5 = uVar13 >> 5 ^ (uVar5 - uVar12) - uVar13;
      _hj_i = uVar5 >> 3 ^ (uVar12 - uVar13) - uVar5;
      _hj_j = _hj_i << 10 ^ (uVar13 - uVar5) - _hj_i;
      _ha_hashv = _hj_j >> 0xf ^ (uVar5 - _hj_i) - _hj_j;
      _hj_key = _hj_key + 0xc;
    }
    uVar5 = _ha_hashv + 4;
    switch(_hj_k) {
    case 8:
      _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000 + (uint)_hj_key[6] * 0x10000 +
              (uint)_hj_key[5] * 0x100 + (uint)_hj_key[4];
    case 4:
      _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000 + (uint)_hj_key[2] * 0x10000 +
              (uint)_hj_key[1] * 0x100 + (uint)*_hj_key;
    }
    uVar12 = uVar5 >> 0xd ^ (_hj_i - _hj_j) - uVar5;
    uVar13 = uVar12 << 8 ^ (_hj_j - uVar5) - uVar12;
    uVar5 = uVar13 >> 0xd ^ (uVar5 - uVar12) - uVar13;
    uVar12 = uVar5 >> 0xc ^ (uVar12 - uVar13) - uVar5;
    uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar5) - uVar12;
    uVar5 = uVar13 >> 5 ^ (uVar5 - uVar12) - uVar13;
    uVar12 = uVar5 >> 3 ^ (uVar12 - uVar13) - uVar5;
    uVar13 = uVar12 << 10 ^ (uVar13 - uVar5) - uVar12;
    uVar5 = uVar13 >> 0xf ^ (uVar5 - uVar12) - uVar13;
    (__ptr->hh).hashv = uVar5;
    (__ptr->hh).key = &__ptr->id;
    (__ptr->hh).keylen = 4;
    if (stratum_shares == (stratum_share *)0x0) {
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev = (void *)0x0;
      stratum_shares = __ptr;
      pUVar6 = (UT_hash_table *)malloc(0x2c);
      (__ptr->hh).tbl = pUVar6;
      if ((stratum_shares->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((stratum_shares->hh).tbl,0,0x2c);
      ((stratum_shares->hh).tbl)->tail = &stratum_shares->hh;
      ((stratum_shares->hh).tbl)->num_buckets = 0x20;
      ((stratum_shares->hh).tbl)->log2_num_buckets = 5;
      ((stratum_shares->hh).tbl)->hho = 0;
      pUVar6 = (stratum_shares->hh).tbl;
      pUVar7 = (UT_hash_bucket *)malloc(0x180);
      pUVar6->buckets = pUVar7;
      if (((stratum_shares->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(((stratum_shares->hh).tbl)->buckets,0,0x180);
      ((stratum_shares->hh).tbl)->signature = 0xa0111fe1;
    }
    else {
      (__ptr->hh).tbl = (stratum_shares->hh).tbl;
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev =
           (void *)((int)((stratum_shares->hh).tbl)->tail - ((stratum_shares->hh).tbl)->hho);
      ((stratum_shares->hh).tbl)->tail->next = __ptr;
      ((stratum_shares->hh).tbl)->tail = (UT_hash_handle *)__ptr;
    }
    pUVar6 = (stratum_shares->hh).tbl;
    pUVar6->num_items = pUVar6->num_items + 1;
    uVar5 = uVar5 & ((stratum_shares->hh).tbl)->num_buckets - 1;
    pUVar7 = ((stratum_shares->hh).tbl)->buckets;
    pUVar7[uVar5].count = pUVar7[uVar5].count + 1;
    (__ptr->hh).hh_next = ((stratum_shares->hh).tbl)->buckets[uVar5].hh_head;
    (__ptr->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((stratum_shares->hh).tbl)->buckets[uVar5].hh_head != (UT_hash_handle *)0x0) {
      (((stratum_shares->hh).tbl)->buckets[uVar5].hh_head)->hh_prev = (UT_hash_handle *)__ptr;
    }
    ((stratum_shares->hh).tbl)->buckets[uVar5].hh_head = (UT_hash_handle *)__ptr;
    if (((((stratum_shares->hh).tbl)->buckets[uVar5].expand_mult + 1) * 10 <=
         ((stratum_shares->hh).tbl)->buckets[uVar5].count) && (((__ptr->hh).tbl)->noexpand != 1)) {
      pUVar7 = (UT_hash_bucket *)malloc(((__ptr->hh).tbl)->num_buckets * 0x18);
      if (pUVar7 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar7,0,((__ptr->hh).tbl)->num_buckets * 0x18);
      ((__ptr->hh).tbl)->ideal_chain_maxlen =
           (((__ptr->hh).tbl)->num_items >> (((__ptr->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((__ptr->hh).tbl)->num_buckets * 2 - 1 & ((__ptr->hh).tbl)->num_items) != 0);
      ((__ptr->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__ptr->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__ptr->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar14 = _he_thh->hh_next;
          pUVar15 = pUVar7 + (((__ptr->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar15->count = pUVar15->count + 1;
          if (((__ptr->hh).tbl)->ideal_chain_maxlen < pUVar15->count) {
            pUVar6 = (__ptr->hh).tbl;
            pUVar6->nonideal_items = pUVar6->nonideal_items + 1;
            uVar5 = __aeabi_uidiv(pUVar15->count,((__ptr->hh).tbl)->ideal_chain_maxlen);
            pUVar15->expand_mult = uVar5;
          }
          _he_thh->hh_prev = (UT_hash_handle *)0x0;
          _he_thh->hh_next = pUVar15->hh_head;
          if (pUVar15->hh_head != (UT_hash_handle *)0x0) {
            pUVar15->hh_head->hh_prev = _he_thh;
          }
          pUVar15->hh_head = _he_thh;
          _he_thh = pUVar14;
        }
      }
      free(((__ptr->hh).tbl)->buckets);
      ((__ptr->hh).tbl)->num_buckets = ((__ptr->hh).tbl)->num_buckets << 1;
      pUVar6 = (__ptr->hh).tbl;
      pUVar6->log2_num_buckets = pUVar6->log2_num_buckets + 1;
      ((__ptr->hh).tbl)->buckets = pUVar7;
      if (((__ptr->hh).tbl)->num_items >> 1 < ((__ptr->hh).tbl)->nonideal_items) {
        uVar5 = ((__ptr->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar5 = 0;
      }
      ((__ptr->hh).tbl)->ineff_expands = uVar5;
      if (1 < ((__ptr->hh).tbl)->ineff_expands) {
        ((__ptr->hh).tbl)->noexpand = 1;
      }
    }
    *(int *)((int)userdata + 0x2e4) = *(int *)((int)userdata + 0x2e4) + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1dc1);
    _Var2 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x62));
    if ((_Var2) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Pool %d communication resumed, submitting work",*userdata);
      _applog(4,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Successfully_submitted__adding_t_000739a8[0];
      tmp42[1] = s_Successfully_submitted__adding_t_000739a8[1];
      tmp42[2] = s_Successfully_submitted__adding_t_000739a8[2];
      tmp42[3] = s_Successfully_submitted__adding_t_000739a8[3];
      tmp42[4] = s_Successfully_submitted__adding_t_000739a8[4];
      tmp42[5] = s_Successfully_submitted__adding_t_000739a8[5];
      tmp42[6] = s_Successfully_submitted__adding_t_000739a8[6];
      tmp42[7] = s_Successfully_submitted__adding_t_000739a8[7];
      tmp42[8] = s_Successfully_submitted__adding_t_000739a8[8];
      tmp42[9] = s_Successfully_submitted__adding_t_000739a8[9];
      tmp42[10] = s_Successfully_submitted__adding_t_000739a8[10];
      tmp42[11] = s_Successfully_submitted__adding_t_000739a8[11];
      tmp42[12] = s_Successfully_submitted__adding_t_000739a8[12];
      tmp42[13] = s_Successfully_submitted__adding_t_000739a8[13];
      tmp42[14] = s_Successfully_submitted__adding_t_000739a8[14];
      tmp42[15] = s_Successfully_submitted__adding_t_000739a8[15];
      tmp42[16] = s_Successfully_submitted__adding_t_000739a8[16];
      tmp42[17] = s_Successfully_submitted__adding_t_000739a8[17];
      tmp42[18] = s_Successfully_submitted__adding_t_000739a8[18];
      tmp42[19] = s_Successfully_submitted__adding_t_000739a8[19];
      tmp42[20] = s_Successfully_submitted__adding_t_000739a8[20];
      tmp42[21] = s_Successfully_submitted__adding_t_000739a8[21];
      tmp42[22] = s_Successfully_submitted__adding_t_000739a8[22];
      tmp42[23] = s_Successfully_submitted__adding_t_000739a8[23];
      tmp42[24] = s_Successfully_submitted__adding_t_000739a8[24];
      tmp42[25] = s_Successfully_submitted__adding_t_000739a8[25];
      tmp42[26] = s_Successfully_submitted__adding_t_000739a8[26];
      tmp42[27] = s_Successfully_submitted__adding_t_000739a8[27];
      tmp42[28] = s_Successfully_submitted__adding_t_000739a8[28];
      tmp42[29] = s_Successfully_submitted__adding_t_000739a8[29];
      tmp42[30] = s_Successfully_submitted__adding_t_000739a8[30];
      tmp42[31] = s_Successfully_submitted__adding_t_000739a8[31];
      tmp42[32] = s_Successfully_submitted__adding_t_000739a8[32];
      tmp42[33] = s_Successfully_submitted__adding_t_000739a8[33];
      tmp42[34] = s_Successfully_submitted__adding_t_000739a8[34];
      tmp42[35] = s_Successfully_submitted__adding_t_000739a8[35];
      tmp42[36] = s_Successfully_submitted__adding_t_000739a8[36];
      tmp42[37] = s_Successfully_submitted__adding_t_000739a8[37];
      tmp42[38] = s_Successfully_submitted__adding_t_000739a8[38];
      tmp42[39] = s_Successfully_submitted__adding_t_000739a8[39];
      tmp42[40] = s_Successfully_submitted__adding_t_000739a8[40];
      tmp42[41] = s_Successfully_submitted__adding_t_000739a8[41];
      tmp42[42] = s_Successfully_submitted__adding_t_000739a8[42];
      tmp42[43] = s_Successfully_submitted__adding_t_000739a8[43];
      tmp42[44] = s_Successfully_submitted__adding_t_000739a8[44];
      tmp42[45] = s_Successfully_submitted__adding_t_000739a8[45];
      tmp42[46] = s_Successfully_submitted__adding_t_000739a8[46];
      tmp42[47] = s_Successfully_submitted__adding_t_000739a8[47];
      tmp42[48] = s_Successfully_submitted__adding_t_000739a8[48];
      tmp42[49] = s_Successfully_submitted__adding_t_000739a8[49];
      tmp42[50] = s_Successfully_submitted__adding_t_000739a8[50];
      tmp42[51] = s_Successfully_submitted__adding_t_000739a8[51];
      _applog(7,tmp42,false);
    }
    bVar19 = true;
LAB_00023b52:
    last_nonce = uVar10;
    if (bVar19) {
      tVar4 = time((time_t *)0x0);
      __ptr->sshare_sent = tVar4;
      iVar16 = __ptr->sshare_sent - __ptr->sshare_time;
      if (((opt_debug != false) || (0 < iVar16)) &&
         ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Pool %d stratum share submission lag time %d seconds",*userdata,iVar16
                );
        _applog(6,tmp42,false);
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_submit_stratum_share__d_00073a74[0];
        tmp42[1] = s_Failed_to_submit_stratum_share__d_00073a74[1];
        tmp42[2] = s_Failed_to_submit_stratum_share__d_00073a74[2];
        tmp42[3] = s_Failed_to_submit_stratum_share__d_00073a74[3];
        tmp42[4] = s_Failed_to_submit_stratum_share__d_00073a74[4];
        tmp42[5] = s_Failed_to_submit_stratum_share__d_00073a74[5];
        tmp42[6] = s_Failed_to_submit_stratum_share__d_00073a74[6];
        tmp42[7] = s_Failed_to_submit_stratum_share__d_00073a74[7];
        tmp42[8] = s_Failed_to_submit_stratum_share__d_00073a74[8];
        tmp42[9] = s_Failed_to_submit_stratum_share__d_00073a74[9];
        tmp42[10] = s_Failed_to_submit_stratum_share__d_00073a74[10];
        tmp42[11] = s_Failed_to_submit_stratum_share__d_00073a74[11];
        tmp42[12] = s_Failed_to_submit_stratum_share__d_00073a74[12];
        tmp42[13] = s_Failed_to_submit_stratum_share__d_00073a74[13];
        tmp42[14] = s_Failed_to_submit_stratum_share__d_00073a74[14];
        tmp42[15] = s_Failed_to_submit_stratum_share__d_00073a74[15];
        tmp42[16] = s_Failed_to_submit_stratum_share__d_00073a74[16];
        tmp42[17] = s_Failed_to_submit_stratum_share__d_00073a74[17];
        tmp42[18] = s_Failed_to_submit_stratum_share__d_00073a74[18];
        tmp42[19] = s_Failed_to_submit_stratum_share__d_00073a74[19];
        tmp42[20] = s_Failed_to_submit_stratum_share__d_00073a74[20];
        tmp42[21] = s_Failed_to_submit_stratum_share__d_00073a74[21];
        tmp42[22] = s_Failed_to_submit_stratum_share__d_00073a74[22];
        tmp42[23] = s_Failed_to_submit_stratum_share__d_00073a74[23];
        tmp42[24] = s_Failed_to_submit_stratum_share__d_00073a74[24];
        tmp42[25] = s_Failed_to_submit_stratum_share__d_00073a74[25];
        tmp42[26] = s_Failed_to_submit_stratum_share__d_00073a74[26];
        tmp42[27] = s_Failed_to_submit_stratum_share__d_00073a74[27];
        tmp42[28] = s_Failed_to_submit_stratum_share__d_00073a74[28];
        tmp42[29] = s_Failed_to_submit_stratum_share__d_00073a74[29];
        tmp42[30] = s_Failed_to_submit_stratum_share__d_00073a74[30];
        tmp42[31] = s_Failed_to_submit_stratum_share__d_00073a74[31];
        tmp42[32] = s_Failed_to_submit_stratum_share__d_00073a74[32];
        tmp42[33] = s_Failed_to_submit_stratum_share__d_00073a74[33];
        tmp42[34] = s_Failed_to_submit_stratum_share__d_00073a74[34];
        tmp42[35] = s_Failed_to_submit_stratum_share__d_00073a74[35];
        tmp42[36] = s_Failed_to_submit_stratum_share__d_00073a74[36];
        tmp42[37] = s_Failed_to_submit_stratum_share__d_00073a74[37];
        tmp42[38] = s_Failed_to_submit_stratum_share__d_00073a74[38];
        tmp42[39] = s_Failed_to_submit_stratum_share__d_00073a74[39];
        tmp42._40_3_ = (undefined3)ram0x00073a9c;
        _applog(7,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1de8);
      free(__ptr);
      *(int *)((int)userdata + 0x7c) = *(int *)((int)userdata + 0x7c) + 1;
      bVar19 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar19;
    }
  } while( true );
}

