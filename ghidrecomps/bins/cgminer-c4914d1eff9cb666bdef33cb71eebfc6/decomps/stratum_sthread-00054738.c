
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff4c : 0x000549c0 */
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
  uint32_t uVar5;
  uint32_t uVar6;
  __uint32_t _Var7;
  size_t len;
  UT_hash_table *pUVar8;
  UT_hash_bucket *pUVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  UT_hash_handle *pUVar15;
  UT_hash_bucket *pUVar16;
  char *pcVar17;
  char *pcVar18;
  undefined4 uVar19;
  bool bVar20;
  uchar auVar21 [8];
  char *in_stack_fffff320;
  char *in_stack_fffff324;
  void *userdata_local;
  char s [1024];
  char tmp42 [2048];
  uint32_t pool_version;
  work *work;
  uchar nonce2 [8];
  uint32_t nonce;
  char nonce2hex [20];
  char noncehex [12];
  char threadname [16];
  int ssdiff;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  _Bool sessionid_match;
  uint32_t *hash32;
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
  uint32_t last_nonce;
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
  *(thread_q **)((int)userdata + 0x2d8) = ptVar3;
  if (*(int *)((int)userdata + 0x2d8) == 0) {
    tmp42[0] = s_Failed_to_create_stratum_q_in_st_0008d054[0];
    tmp42[1] = s_Failed_to_create_stratum_q_in_st_0008d054[1];
    tmp42[2] = s_Failed_to_create_stratum_q_in_st_0008d054[2];
    tmp42[3] = s_Failed_to_create_stratum_q_in_st_0008d054[3];
    tmp42[4] = s_Failed_to_create_stratum_q_in_st_0008d054[4];
    tmp42[5] = s_Failed_to_create_stratum_q_in_st_0008d054[5];
    tmp42[6] = s_Failed_to_create_stratum_q_in_st_0008d054[6];
    tmp42[7] = s_Failed_to_create_stratum_q_in_st_0008d054[7];
    tmp42[8] = s_Failed_to_create_stratum_q_in_st_0008d054[8];
    tmp42[9] = s_Failed_to_create_stratum_q_in_st_0008d054[9];
    tmp42[10] = s_Failed_to_create_stratum_q_in_st_0008d054[10];
    tmp42[11] = s_Failed_to_create_stratum_q_in_st_0008d054[11];
    tmp42[12] = s_Failed_to_create_stratum_q_in_st_0008d054[12];
    tmp42[13] = s_Failed_to_create_stratum_q_in_st_0008d054[13];
    tmp42[14] = s_Failed_to_create_stratum_q_in_st_0008d054[14];
    tmp42[15] = s_Failed_to_create_stratum_q_in_st_0008d054[15];
    tmp42[16] = s_Failed_to_create_stratum_q_in_st_0008d054[16];
    tmp42[17] = s_Failed_to_create_stratum_q_in_st_0008d054[17];
    tmp42[18] = s_Failed_to_create_stratum_q_in_st_0008d054[18];
    tmp42[19] = s_Failed_to_create_stratum_q_in_st_0008d054[19];
    tmp42[20] = s_Failed_to_create_stratum_q_in_st_0008d054[20];
    tmp42[21] = s_Failed_to_create_stratum_q_in_st_0008d054[21];
    tmp42[22] = s_Failed_to_create_stratum_q_in_st_0008d054[22];
    tmp42[23] = s_Failed_to_create_stratum_q_in_st_0008d054[23];
    tmp42[24] = s_Failed_to_create_stratum_q_in_st_0008d054[24];
    tmp42[25] = s_Failed_to_create_stratum_q_in_st_0008d054[25];
    tmp42[26] = s_Failed_to_create_stratum_q_in_st_0008d054[26];
    tmp42[27] = s_Failed_to_create_stratum_q_in_st_0008d054[27];
    tmp42[28] = s_Failed_to_create_stratum_q_in_st_0008d054[28];
    tmp42[29] = s_Failed_to_create_stratum_q_in_st_0008d054[29];
    tmp42[30] = s_Failed_to_create_stratum_q_in_st_0008d054[30];
    tmp42[31] = s_Failed_to_create_stratum_q_in_st_0008d054[31];
    tmp42[32] = s_Failed_to_create_stratum_q_in_st_0008d054[32];
    tmp42[33] = s_Failed_to_create_stratum_q_in_st_0008d054[33];
    tmp42[34] = s_Failed_to_create_stratum_q_in_st_0008d054[34];
    tmp42[35] = s_Failed_to_create_stratum_q_in_st_0008d054[35];
    tmp42[36] = s_Failed_to_create_stratum_q_in_st_0008d054[36];
    tmp42[37] = s_Failed_to_create_stratum_q_in_st_0008d054[37];
    tmp42[38] = s_Failed_to_create_stratum_q_in_st_0008d054[38];
    tmp42[39] = s_Failed_to_create_stratum_q_in_st_0008d054[39];
    tmp42[40] = s_Failed_to_create_stratum_q_in_st_0008d054[40];
    tmp42[41] = s_Failed_to_create_stratum_q_in_st_0008d054[41];
    tmp42[42] = s_Failed_to_create_stratum_q_in_st_0008d054[42];
    tmp42[43] = s_Failed_to_create_stratum_q_in_st_0008d054[43];
    tmp42[44] = (char)(short)ram0x0008d080;
    tmp42[45] = (char)((ushort)(short)ram0x0008d080 >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"in %s ","stratum_sthread");
    _applog(5,tmp42,false);
  }
  do {
    while( true ) {
      while( true ) {
        if (*(char *)((int)userdata + 0x69) != '\0') {
          tq_freeze(*(thread_q **)((int)userdata + 0x2d8));
          return (void *)0x0;
        }
        work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2d8),(timespec *)0x0);
        if (work == (work *)0x0) {
          tmp42[0] = s_Stratum_q_returned_empty_work_0008d08c[0];
          tmp42[1] = s_Stratum_q_returned_empty_work_0008d08c[1];
          tmp42[2] = s_Stratum_q_returned_empty_work_0008d08c[2];
          tmp42[3] = s_Stratum_q_returned_empty_work_0008d08c[3];
          tmp42[4] = s_Stratum_q_returned_empty_work_0008d08c[4];
          tmp42[5] = s_Stratum_q_returned_empty_work_0008d08c[5];
          tmp42[6] = s_Stratum_q_returned_empty_work_0008d08c[6];
          tmp42[7] = s_Stratum_q_returned_empty_work_0008d08c[7];
          tmp42[8] = s_Stratum_q_returned_empty_work_0008d08c[8];
          tmp42[9] = s_Stratum_q_returned_empty_work_0008d08c[9];
          tmp42[10] = s_Stratum_q_returned_empty_work_0008d08c[10];
          tmp42[11] = s_Stratum_q_returned_empty_work_0008d08c[11];
          tmp42[12] = s_Stratum_q_returned_empty_work_0008d08c[12];
          tmp42[13] = s_Stratum_q_returned_empty_work_0008d08c[13];
          tmp42[14] = s_Stratum_q_returned_empty_work_0008d08c[14];
          tmp42[15] = s_Stratum_q_returned_empty_work_0008d08c[15];
          tmp42[16] = s_Stratum_q_returned_empty_work_0008d08c[16];
          tmp42[17] = s_Stratum_q_returned_empty_work_0008d08c[17];
          tmp42[18] = s_Stratum_q_returned_empty_work_0008d08c[18];
          tmp42[19] = s_Stratum_q_returned_empty_work_0008d08c[19];
          tmp42[20] = s_Stratum_q_returned_empty_work_0008d08c[20];
          tmp42[21] = s_Stratum_q_returned_empty_work_0008d08c[21];
          tmp42[22] = s_Stratum_q_returned_empty_work_0008d08c[22];
          tmp42[23] = s_Stratum_q_returned_empty_work_0008d08c[23];
          tmp42[24] = s_Stratum_q_returned_empty_work_0008d08c[24];
          tmp42[25] = s_Stratum_q_returned_empty_work_0008d08c[25];
          tmp42[26] = s_Stratum_q_returned_empty_work_0008d08c[26];
          tmp42[27] = s_Stratum_q_returned_empty_work_0008d08c[27];
          tmp42[28] = (char)(short)ram0x0008d0a8;
          tmp42[29] = (char)((ushort)(short)ram0x0008d0a8 >> 8);
          _applog(3,tmp42,true);
          _quit(1);
        }
        if (work->nonce2_len < 9) break;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
          in_stack_fffff320 = (char *)work->nonce2_len;
          snprintf(tmp42,0x800,"Pool %d asking for inappropriately long nonce2 length %d",*userdata)
          ;
          _applog(3,tmp42,false);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_Not_attempting_to_submit_shares_0008d0e8[0];
          tmp42[1] = s_Not_attempting_to_submit_shares_0008d0e8[1];
          tmp42[2] = s_Not_attempting_to_submit_shares_0008d0e8[2];
          tmp42[3] = s_Not_attempting_to_submit_shares_0008d0e8[3];
          tmp42[4] = s_Not_attempting_to_submit_shares_0008d0e8[4];
          tmp42[5] = s_Not_attempting_to_submit_shares_0008d0e8[5];
          tmp42[6] = s_Not_attempting_to_submit_shares_0008d0e8[6];
          tmp42[7] = s_Not_attempting_to_submit_shares_0008d0e8[7];
          tmp42[8] = s_Not_attempting_to_submit_shares_0008d0e8[8];
          tmp42[9] = s_Not_attempting_to_submit_shares_0008d0e8[9];
          tmp42[10] = s_Not_attempting_to_submit_shares_0008d0e8[10];
          tmp42[11] = s_Not_attempting_to_submit_shares_0008d0e8[11];
          tmp42[12] = s_Not_attempting_to_submit_shares_0008d0e8[12];
          tmp42[13] = s_Not_attempting_to_submit_shares_0008d0e8[13];
          tmp42[14] = s_Not_attempting_to_submit_shares_0008d0e8[14];
          tmp42[15] = s_Not_attempting_to_submit_shares_0008d0e8[15];
          tmp42[16] = s_Not_attempting_to_submit_shares_0008d0e8[16];
          tmp42[17] = s_Not_attempting_to_submit_shares_0008d0e8[17];
          tmp42[18] = s_Not_attempting_to_submit_shares_0008d0e8[18];
          tmp42[19] = s_Not_attempting_to_submit_shares_0008d0e8[19];
          tmp42[20] = s_Not_attempting_to_submit_shares_0008d0e8[20];
          tmp42[21] = s_Not_attempting_to_submit_shares_0008d0e8[21];
          tmp42[22] = s_Not_attempting_to_submit_shares_0008d0e8[22];
          tmp42[23] = s_Not_attempting_to_submit_shares_0008d0e8[23];
          tmp42[24] = s_Not_attempting_to_submit_shares_0008d0e8[24];
          tmp42[25] = s_Not_attempting_to_submit_shares_0008d0e8[25];
          tmp42[26] = s_Not_attempting_to_submit_shares_0008d0e8[26];
          tmp42[27] = s_Not_attempting_to_submit_shares_0008d0e8[27];
          tmp42[28] = s_Not_attempting_to_submit_shares_0008d0e8[28];
          tmp42[29] = s_Not_attempting_to_submit_shares_0008d0e8[29];
          tmp42[30] = s_Not_attempting_to_submit_shares_0008d0e8[30];
          tmp42[31] = s_Not_attempting_to_submit_shares_0008d0e8[31];
          _applog(3,tmp42,false);
        }
        _free_work(&work,"cgminer.c","stratum_sthread",0x1dc8);
      }
      nonce = *(uint32_t *)(work->data + 0x4c);
      auVar21 = (uchar  [8])__uint64_identity(CONCAT44(in_stack_fffff324,in_stack_fffff320));
      nonce2 = auVar21;
      if ((last_nonce != nonce) ||
         (last_nonce2._4_4_ != nonce2._4_4_ || (int)last_nonce2 != nonce2._0_4_)) break;
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Filtering duplicate share to pool %d",*userdata);
        _applog(6,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1dd4);
    }
    last_nonce = nonce;
    last_nonce2._0_1_ = nonce2[0];
    last_nonce2._1_1_ = nonce2[1];
    last_nonce2._2_1_ = nonce2[2];
    last_nonce2._3_1_ = nonce2[3];
    last_nonce2._4_1_ = nonce2[4];
    last_nonce2._5_1_ = nonce2[5];
    last_nonce2._6_1_ = nonce2[6];
    last_nonce2._7_1_ = nonce2[7];
    __bin2hex(noncehex,(uchar *)&nonce,4);
    __bin2hex(nonce2hex,nonce2,work->nonce2_len);
    __ptr = (stratum_share *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1ddd);
    pwVar1 = work;
    bVar20 = false;
    tVar4 = time((time_t *)0x0);
    __ptr->sshare_time = tVar4;
    __ptr->work = work;
    memset(s,0,0x400);
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1de6);
    iVar12 = swork_id + 1;
    __ptr->id = swork_id;
    swork_id = iVar12;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1de9);
    pool_version = 0;
    hex2bin((uchar *)&pool_version,(char *)((int)userdata + 0x6f4),4);
    if (*(char *)((int)userdata + 0x284) == '\0') {
      in_stack_fffff320 = work->job_id;
      pcVar18 = work->ntime;
      uVar11 = __ptr->id;
      pcVar17 = noncehex;
      in_stack_fffff324 = nonce2hex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,*(undefined4 *)((int)userdata + 0xac),in_stack_fffff320,in_stack_fffff324,pcVar18,
               pcVar17,uVar11);
    }
    else {
      uVar19 = *(undefined4 *)((int)userdata + 0xac);
      in_stack_fffff320 = work->job_id;
      pcVar18 = work->ntime;
      uVar5 = swab32(work->version);
      uVar6 = swab32(pool_version);
      uVar11 = uVar5 & ~uVar6;
      pcVar17 = noncehex;
      in_stack_fffff324 = nonce2hex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,uVar19,in_stack_fffff320,in_stack_fffff324,pcVar18,pcVar17,uVar11,__ptr->id);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      _Var7 = __uint32_identity(*(__uint32_t *)(pwVar1->hash + 0x18));
                    /* WARNING: Load size is inaccurate */
      in_stack_fffff320 = *userdata;
      snprintf(tmp42,0x800,"Submitting share %08lx to pool %d",_Var7,in_stack_fffff320,
               in_stack_fffff324,pcVar18,pcVar17,uVar11);
      _applog(6,tmp42,false);
    }
    while( true ) {
      tVar4 = time((time_t *)0x0);
      if (__ptr->sshare_time + 0x78 <= tVar4) goto LAB_00055a2c;
      len = strlen(s);
      _Var2 = stratum_send((pool *)userdata,s,len);
      if (_Var2) break;
      _Var2 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x60));
      if ((!_Var2) && (_Var2 = cnx_needed((pool *)userdata), _Var2)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d stratum share submission failure",*userdata);
          _applog(4,tmp42,false);
        }
        total_ro = total_ro + 1;
        *(int *)((int)userdata + 0x84) = *(int *)((int)userdata + 0x84) + 1;
      }
      if (opt_lowmem != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Lowmem_option_prevents_resubmitt_0008d28c[0];
          tmp42[1] = s_Lowmem_option_prevents_resubmitt_0008d28c[1];
          tmp42[2] = s_Lowmem_option_prevents_resubmitt_0008d28c[2];
          tmp42[3] = s_Lowmem_option_prevents_resubmitt_0008d28c[3];
          tmp42[4] = s_Lowmem_option_prevents_resubmitt_0008d28c[4];
          tmp42[5] = s_Lowmem_option_prevents_resubmitt_0008d28c[5];
          tmp42[6] = s_Lowmem_option_prevents_resubmitt_0008d28c[6];
          tmp42[7] = s_Lowmem_option_prevents_resubmitt_0008d28c[7];
          tmp42[8] = s_Lowmem_option_prevents_resubmitt_0008d28c[8];
          tmp42[9] = s_Lowmem_option_prevents_resubmitt_0008d28c[9];
          tmp42[10] = s_Lowmem_option_prevents_resubmitt_0008d28c[10];
          tmp42[11] = s_Lowmem_option_prevents_resubmitt_0008d28c[11];
          tmp42[12] = s_Lowmem_option_prevents_resubmitt_0008d28c[12];
          tmp42[13] = s_Lowmem_option_prevents_resubmitt_0008d28c[13];
          tmp42[14] = s_Lowmem_option_prevents_resubmitt_0008d28c[14];
          tmp42[15] = s_Lowmem_option_prevents_resubmitt_0008d28c[15];
          tmp42[16] = s_Lowmem_option_prevents_resubmitt_0008d28c[16];
          tmp42[17] = s_Lowmem_option_prevents_resubmitt_0008d28c[17];
          tmp42[18] = s_Lowmem_option_prevents_resubmitt_0008d28c[18];
          tmp42[19] = s_Lowmem_option_prevents_resubmitt_0008d28c[19];
          tmp42[20] = s_Lowmem_option_prevents_resubmitt_0008d28c[20];
          tmp42[21] = s_Lowmem_option_prevents_resubmitt_0008d28c[21];
          tmp42[22] = s_Lowmem_option_prevents_resubmitt_0008d28c[22];
          tmp42[23] = s_Lowmem_option_prevents_resubmitt_0008d28c[23];
          tmp42[24] = s_Lowmem_option_prevents_resubmitt_0008d28c[24];
          tmp42[25] = s_Lowmem_option_prevents_resubmitt_0008d28c[25];
          tmp42[26] = s_Lowmem_option_prevents_resubmitt_0008d28c[26];
          tmp42[27] = s_Lowmem_option_prevents_resubmitt_0008d28c[27];
          tmp42[28] = s_Lowmem_option_prevents_resubmitt_0008d28c[28];
          tmp42[29] = s_Lowmem_option_prevents_resubmitt_0008d28c[29];
          tmp42[30] = s_Lowmem_option_prevents_resubmitt_0008d28c[30];
          tmp42[31] = s_Lowmem_option_prevents_resubmitt_0008d28c[31];
          tmp42[32] = s_Lowmem_option_prevents_resubmitt_0008d28c[32];
          tmp42[33] = s_Lowmem_option_prevents_resubmitt_0008d28c[33];
          tmp42[34] = s_Lowmem_option_prevents_resubmitt_0008d28c[34];
          tmp42[35] = s_Lowmem_option_prevents_resubmitt_0008d28c[35];
          tmp42[36] = s_Lowmem_option_prevents_resubmitt_0008d28c[36];
          tmp42[37] = s_Lowmem_option_prevents_resubmitt_0008d28c[37];
          tmp42[38] = s_Lowmem_option_prevents_resubmitt_0008d28c[38];
          tmp42[39] = s_Lowmem_option_prevents_resubmitt_0008d28c[39];
          tmp42[40] = s_Lowmem_option_prevents_resubmitt_0008d28c[40];
          tmp42[41] = s_Lowmem_option_prevents_resubmitt_0008d28c[41];
          tmp42[42] = s_Lowmem_option_prevents_resubmitt_0008d28c[42];
          tmp42[43] = s_Lowmem_option_prevents_resubmitt_0008d28c[43];
          tmp42[44] = s_Lowmem_option_prevents_resubmitt_0008d28c[44];
          tmp42[45] = s_Lowmem_option_prevents_resubmitt_0008d28c[45];
          tmp42[46] = s_Lowmem_option_prevents_resubmitt_0008d28c[46];
          tmp42[47] = s_Lowmem_option_prevents_resubmitt_0008d28c[47];
          tmp42[48] = (char)(short)ram0x0008d2bc;
          tmp42[49] = (char)((ushort)(short)ram0x0008d2bc >> 8);
          _applog(7,tmp42,false);
        }
        goto LAB_00055a2c;
      }
      _cg_rlock((cglock_t *)((int)userdata + 0xd4),"cgminer.c","stratum_sthread",0x1e29);
      if ((*(int *)((int)userdata + 0x264) == 0) ||
         (iVar12 = strcmp(work->nonce1,*(char **)((int)userdata + 0x264)), iVar12 != 0)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      _cg_runlock((cglock_t *)((int)userdata + 0xd4),"cgminer.c","stratum_sthread",0x1e2b);
      if (!bVar10) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_No_matching_session_id_for_resub_0008d2c0[0];
          tmp42[1] = s_No_matching_session_id_for_resub_0008d2c0[1];
          tmp42[2] = s_No_matching_session_id_for_resub_0008d2c0[2];
          tmp42[3] = s_No_matching_session_id_for_resub_0008d2c0[3];
          tmp42[4] = s_No_matching_session_id_for_resub_0008d2c0[4];
          tmp42[5] = s_No_matching_session_id_for_resub_0008d2c0[5];
          tmp42[6] = s_No_matching_session_id_for_resub_0008d2c0[6];
          tmp42[7] = s_No_matching_session_id_for_resub_0008d2c0[7];
          tmp42[8] = s_No_matching_session_id_for_resub_0008d2c0[8];
          tmp42[9] = s_No_matching_session_id_for_resub_0008d2c0[9];
          tmp42[10] = s_No_matching_session_id_for_resub_0008d2c0[10];
          tmp42[11] = s_No_matching_session_id_for_resub_0008d2c0[11];
          tmp42[12] = s_No_matching_session_id_for_resub_0008d2c0[12];
          tmp42[13] = s_No_matching_session_id_for_resub_0008d2c0[13];
          tmp42[14] = s_No_matching_session_id_for_resub_0008d2c0[14];
          tmp42[15] = s_No_matching_session_id_for_resub_0008d2c0[15];
          tmp42[16] = s_No_matching_session_id_for_resub_0008d2c0[16];
          tmp42[17] = s_No_matching_session_id_for_resub_0008d2c0[17];
          tmp42[18] = s_No_matching_session_id_for_resub_0008d2c0[18];
          tmp42[19] = s_No_matching_session_id_for_resub_0008d2c0[19];
          tmp42[20] = s_No_matching_session_id_for_resub_0008d2c0[20];
          tmp42[21] = s_No_matching_session_id_for_resub_0008d2c0[21];
          tmp42[22] = s_No_matching_session_id_for_resub_0008d2c0[22];
          tmp42[23] = s_No_matching_session_id_for_resub_0008d2c0[23];
          tmp42[24] = s_No_matching_session_id_for_resub_0008d2c0[24];
          tmp42[25] = s_No_matching_session_id_for_resub_0008d2c0[25];
          tmp42[26] = s_No_matching_session_id_for_resub_0008d2c0[26];
          tmp42[27] = s_No_matching_session_id_for_resub_0008d2c0[27];
          tmp42[28] = s_No_matching_session_id_for_resub_0008d2c0[28];
          tmp42[29] = s_No_matching_session_id_for_resub_0008d2c0[29];
          tmp42[30] = s_No_matching_session_id_for_resub_0008d2c0[30];
          tmp42[31] = s_No_matching_session_id_for_resub_0008d2c0[31];
          tmp42[32] = s_No_matching_session_id_for_resub_0008d2c0[32];
          tmp42[33] = s_No_matching_session_id_for_resub_0008d2c0[33];
          tmp42[34] = s_No_matching_session_id_for_resub_0008d2c0[34];
          tmp42[35] = s_No_matching_session_id_for_resub_0008d2c0[35];
          tmp42[36] = s_No_matching_session_id_for_resub_0008d2c0[36];
          tmp42[37] = s_No_matching_session_id_for_resub_0008d2c0[37];
          tmp42[38] = s_No_matching_session_id_for_resub_0008d2c0[38];
          tmp42[39] = s_No_matching_session_id_for_resub_0008d2c0[39];
          tmp42[40] = s_No_matching_session_id_for_resub_0008d2c0[40];
          tmp42[41] = s_No_matching_session_id_for_resub_0008d2c0[41];
          tmp42[42] = s_No_matching_session_id_for_resub_0008d2c0[42];
          tmp42[43] = s_No_matching_session_id_for_resub_0008d2c0[43];
          tmp42[44] = s_No_matching_session_id_for_resub_0008d2c0[44];
          tmp42[45] = s_No_matching_session_id_for_resub_0008d2c0[45];
          tmp42[46] = s_No_matching_session_id_for_resub_0008d2c0[46];
          tmp42[47] = s_No_matching_session_id_for_resub_0008d2c0[47];
          tmp42[48] = s_No_matching_session_id_for_resub_0008d2c0[48];
          tmp42[49] = s_No_matching_session_id_for_resub_0008d2c0[49];
          tmp42[50] = s_No_matching_session_id_for_resub_0008d2c0[50];
          tmp42[51] = s_No_matching_session_id_for_resub_0008d2c0[51];
          tmp42._52_2_ = (undefined2)ram0x0008d2f4;
          _applog(7,tmp42,false);
        }
        goto LAB_00055a2c;
      }
      sleep(2);
    }
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1e10);
    _hj_key = (uchar *)&__ptr->id;
    _ha_hashv = 0xfeedbeef;
    _hj_j = 0x9e3779b9;
    _hj_i = 0x9e3779b9;
    for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
      iVar12 = (uint)_hj_key[7] * 0x1000000 +
               (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 + _hj_j;
      uVar11 = (uint)_hj_key[0xb] * 0x1000000 +
               (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 + _ha_hashv
      ;
      uVar13 = uVar11 >> 0xd ^
               (((uint)_hj_key[3] * 0x1000000 +
                 (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 + _hj_i) -
               iVar12) - uVar11;
      uVar14 = uVar13 << 8 ^ (iVar12 - uVar11) - uVar13;
      uVar11 = uVar14 >> 0xd ^ (uVar11 - uVar13) - uVar14;
      uVar13 = uVar11 >> 0xc ^ (uVar13 - uVar14) - uVar11;
      uVar14 = uVar13 << 0x10 ^ (uVar14 - uVar11) - uVar13;
      uVar11 = uVar14 >> 5 ^ (uVar11 - uVar13) - uVar14;
      _hj_i = uVar11 >> 3 ^ (uVar13 - uVar14) - uVar11;
      _hj_j = _hj_i << 10 ^ (uVar14 - uVar11) - _hj_i;
      _ha_hashv = _hj_j >> 0xf ^ (uVar11 - _hj_i) - _hj_j;
      _hj_key = _hj_key + 0xc;
    }
    uVar11 = _ha_hashv + 4;
    switch(_hj_k) {
    case 8:
      _hj_j = (uint)_hj_key[5] * 0x100 +
              (uint)_hj_key[6] * 0x10000 + (uint)_hj_key[7] * 0x1000000 + _hj_j + (uint)_hj_key[4];
    case 4:
      _hj_i = (uint)_hj_key[1] * 0x100 +
              (uint)_hj_key[2] * 0x10000 + (uint)_hj_key[3] * 0x1000000 + _hj_i + (uint)*_hj_key;
    }
    uVar13 = uVar11 >> 0xd ^ (_hj_i - _hj_j) - uVar11;
    uVar14 = uVar13 << 8 ^ (_hj_j - uVar11) - uVar13;
    uVar11 = uVar14 >> 0xd ^ (uVar11 - uVar13) - uVar14;
    uVar13 = uVar11 >> 0xc ^ (uVar13 - uVar14) - uVar11;
    uVar14 = uVar13 << 0x10 ^ (uVar14 - uVar11) - uVar13;
    uVar11 = uVar14 >> 5 ^ (uVar11 - uVar13) - uVar14;
    uVar13 = uVar11 >> 3 ^ (uVar13 - uVar14) - uVar11;
    uVar14 = uVar13 << 10 ^ (uVar14 - uVar11) - uVar13;
    uVar11 = uVar14 >> 0xf ^ (uVar11 - uVar13) - uVar14;
    (__ptr->hh).hashv = uVar11;
    (__ptr->hh).key = &__ptr->id;
    (__ptr->hh).keylen = 4;
    if (stratum_shares == (stratum_share *)0x0) {
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev = (void *)0x0;
      stratum_shares = __ptr;
      pUVar8 = (UT_hash_table *)malloc(0x2c);
      (__ptr->hh).tbl = pUVar8;
      if ((stratum_shares->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((stratum_shares->hh).tbl,0,0x2c);
      ((stratum_shares->hh).tbl)->tail = &stratum_shares->hh;
      ((stratum_shares->hh).tbl)->num_buckets = 0x20;
      ((stratum_shares->hh).tbl)->log2_num_buckets = 5;
      ((stratum_shares->hh).tbl)->hho = 0;
      pUVar8 = (stratum_shares->hh).tbl;
      pUVar9 = (UT_hash_bucket *)malloc(0x180);
      pUVar8->buckets = pUVar9;
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
    pUVar8 = (stratum_shares->hh).tbl;
    pUVar8->num_items = pUVar8->num_items + 1;
    uVar11 = ((stratum_shares->hh).tbl)->num_buckets - 1 & uVar11;
    pUVar9 = ((stratum_shares->hh).tbl)->buckets;
    pUVar9[uVar11].count = pUVar9[uVar11].count + 1;
    (__ptr->hh).hh_next = ((stratum_shares->hh).tbl)->buckets[uVar11].hh_head;
    (__ptr->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((stratum_shares->hh).tbl)->buckets[uVar11].hh_head != (UT_hash_handle *)0x0) {
      (((stratum_shares->hh).tbl)->buckets[uVar11].hh_head)->hh_prev = (UT_hash_handle *)__ptr;
    }
    ((stratum_shares->hh).tbl)->buckets[uVar11].hh_head = (UT_hash_handle *)__ptr;
    if (((((stratum_shares->hh).tbl)->buckets[uVar11].expand_mult + 1) * 10 <=
         ((stratum_shares->hh).tbl)->buckets[uVar11].count) && (((__ptr->hh).tbl)->noexpand != 1)) {
      pUVar9 = (UT_hash_bucket *)malloc(((__ptr->hh).tbl)->num_buckets * 0x18);
      if (pUVar9 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar9,0,((__ptr->hh).tbl)->num_buckets * 0x18);
      ((__ptr->hh).tbl)->ideal_chain_maxlen =
           (((__ptr->hh).tbl)->num_items >> (((__ptr->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((__ptr->hh).tbl)->num_buckets * 2 - 1 & ((__ptr->hh).tbl)->num_items) != 0);
      ((__ptr->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__ptr->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__ptr->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar15 = _he_thh->hh_next;
          pUVar16 = pUVar9 + (((__ptr->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar16->count = pUVar16->count + 1;
          if (((__ptr->hh).tbl)->ideal_chain_maxlen < pUVar16->count) {
            pUVar8 = (__ptr->hh).tbl;
            pUVar8->nonideal_items = pUVar8->nonideal_items + 1;
            uVar11 = __udivsi3(pUVar16->count,((__ptr->hh).tbl)->ideal_chain_maxlen);
            pUVar16->expand_mult = uVar11;
          }
          _he_thh->hh_prev = (UT_hash_handle *)0x0;
          _he_thh->hh_next = pUVar16->hh_head;
          if (pUVar16->hh_head != (UT_hash_handle *)0x0) {
            pUVar16->hh_head->hh_prev = _he_thh;
          }
          pUVar16->hh_head = _he_thh;
          _he_thh = pUVar15;
        }
      }
      free(((__ptr->hh).tbl)->buckets);
      ((__ptr->hh).tbl)->num_buckets = ((__ptr->hh).tbl)->num_buckets << 1;
      pUVar8 = (__ptr->hh).tbl;
      pUVar8->log2_num_buckets = pUVar8->log2_num_buckets + 1;
      ((__ptr->hh).tbl)->buckets = pUVar9;
      if (((__ptr->hh).tbl)->num_items >> 1 < ((__ptr->hh).tbl)->nonideal_items) {
        uVar11 = ((__ptr->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar11 = 0;
      }
      ((__ptr->hh).tbl)->ineff_expands = uVar11;
      if (1 < ((__ptr->hh).tbl)->ineff_expands) {
        ((__ptr->hh).tbl)->noexpand = 1;
      }
    }
    *(int *)((int)userdata + 0x2dc) = *(int *)((int)userdata + 0x2dc) + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1e13);
    _Var2 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x60));
    if ((_Var2) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Pool %d communication resumed, submitting work",*userdata);
      _applog(4,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Successfully_submitted__adding_t_0008d22c[0];
      tmp42[1] = s_Successfully_submitted__adding_t_0008d22c[1];
      tmp42[2] = s_Successfully_submitted__adding_t_0008d22c[2];
      tmp42[3] = s_Successfully_submitted__adding_t_0008d22c[3];
      tmp42[4] = s_Successfully_submitted__adding_t_0008d22c[4];
      tmp42[5] = s_Successfully_submitted__adding_t_0008d22c[5];
      tmp42[6] = s_Successfully_submitted__adding_t_0008d22c[6];
      tmp42[7] = s_Successfully_submitted__adding_t_0008d22c[7];
      tmp42[8] = s_Successfully_submitted__adding_t_0008d22c[8];
      tmp42[9] = s_Successfully_submitted__adding_t_0008d22c[9];
      tmp42[10] = s_Successfully_submitted__adding_t_0008d22c[10];
      tmp42[11] = s_Successfully_submitted__adding_t_0008d22c[11];
      tmp42[12] = s_Successfully_submitted__adding_t_0008d22c[12];
      tmp42[13] = s_Successfully_submitted__adding_t_0008d22c[13];
      tmp42[14] = s_Successfully_submitted__adding_t_0008d22c[14];
      tmp42[15] = s_Successfully_submitted__adding_t_0008d22c[15];
      tmp42[16] = s_Successfully_submitted__adding_t_0008d22c[16];
      tmp42[17] = s_Successfully_submitted__adding_t_0008d22c[17];
      tmp42[18] = s_Successfully_submitted__adding_t_0008d22c[18];
      tmp42[19] = s_Successfully_submitted__adding_t_0008d22c[19];
      tmp42[20] = s_Successfully_submitted__adding_t_0008d22c[20];
      tmp42[21] = s_Successfully_submitted__adding_t_0008d22c[21];
      tmp42[22] = s_Successfully_submitted__adding_t_0008d22c[22];
      tmp42[23] = s_Successfully_submitted__adding_t_0008d22c[23];
      tmp42[24] = s_Successfully_submitted__adding_t_0008d22c[24];
      tmp42[25] = s_Successfully_submitted__adding_t_0008d22c[25];
      tmp42[26] = s_Successfully_submitted__adding_t_0008d22c[26];
      tmp42[27] = s_Successfully_submitted__adding_t_0008d22c[27];
      tmp42[28] = s_Successfully_submitted__adding_t_0008d22c[28];
      tmp42[29] = s_Successfully_submitted__adding_t_0008d22c[29];
      tmp42[30] = s_Successfully_submitted__adding_t_0008d22c[30];
      tmp42[31] = s_Successfully_submitted__adding_t_0008d22c[31];
      tmp42[32] = s_Successfully_submitted__adding_t_0008d22c[32];
      tmp42[33] = s_Successfully_submitted__adding_t_0008d22c[33];
      tmp42[34] = s_Successfully_submitted__adding_t_0008d22c[34];
      tmp42[35] = s_Successfully_submitted__adding_t_0008d22c[35];
      tmp42[36] = s_Successfully_submitted__adding_t_0008d22c[36];
      tmp42[37] = s_Successfully_submitted__adding_t_0008d22c[37];
      tmp42[38] = s_Successfully_submitted__adding_t_0008d22c[38];
      tmp42[39] = s_Successfully_submitted__adding_t_0008d22c[39];
      tmp42[40] = s_Successfully_submitted__adding_t_0008d22c[40];
      tmp42[41] = s_Successfully_submitted__adding_t_0008d22c[41];
      tmp42[42] = s_Successfully_submitted__adding_t_0008d22c[42];
      tmp42[43] = s_Successfully_submitted__adding_t_0008d22c[43];
      tmp42[44] = s_Successfully_submitted__adding_t_0008d22c[44];
      tmp42[45] = s_Successfully_submitted__adding_t_0008d22c[45];
      tmp42[46] = s_Successfully_submitted__adding_t_0008d22c[46];
      tmp42[47] = s_Successfully_submitted__adding_t_0008d22c[47];
      tmp42[48] = s_Successfully_submitted__adding_t_0008d22c[48];
      tmp42[49] = s_Successfully_submitted__adding_t_0008d22c[49];
      tmp42[50] = s_Successfully_submitted__adding_t_0008d22c[50];
      tmp42[51] = s_Successfully_submitted__adding_t_0008d22c[51];
      _applog(7,tmp42,false);
    }
    bVar20 = true;
LAB_00055a2c:
    if (bVar20) {
      tVar4 = time((time_t *)0x0);
      __ptr->sshare_sent = tVar4;
      pcVar17 = (char *)(__ptr->sshare_sent - __ptr->sshare_time);
      if (((opt_debug != false) || (0 < (int)pcVar17)) &&
         ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Pool %d stratum share submission lag time %d seconds",*userdata);
        _applog(6,tmp42,false);
        in_stack_fffff320 = pcVar17;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_submit_stratum_share__d_0008d2f8[0];
        tmp42[1] = s_Failed_to_submit_stratum_share__d_0008d2f8[1];
        tmp42[2] = s_Failed_to_submit_stratum_share__d_0008d2f8[2];
        tmp42[3] = s_Failed_to_submit_stratum_share__d_0008d2f8[3];
        tmp42[4] = s_Failed_to_submit_stratum_share__d_0008d2f8[4];
        tmp42[5] = s_Failed_to_submit_stratum_share__d_0008d2f8[5];
        tmp42[6] = s_Failed_to_submit_stratum_share__d_0008d2f8[6];
        tmp42[7] = s_Failed_to_submit_stratum_share__d_0008d2f8[7];
        tmp42[8] = s_Failed_to_submit_stratum_share__d_0008d2f8[8];
        tmp42[9] = s_Failed_to_submit_stratum_share__d_0008d2f8[9];
        tmp42[10] = s_Failed_to_submit_stratum_share__d_0008d2f8[10];
        tmp42[11] = s_Failed_to_submit_stratum_share__d_0008d2f8[11];
        tmp42[12] = s_Failed_to_submit_stratum_share__d_0008d2f8[12];
        tmp42[13] = s_Failed_to_submit_stratum_share__d_0008d2f8[13];
        tmp42[14] = s_Failed_to_submit_stratum_share__d_0008d2f8[14];
        tmp42[15] = s_Failed_to_submit_stratum_share__d_0008d2f8[15];
        tmp42[16] = s_Failed_to_submit_stratum_share__d_0008d2f8[16];
        tmp42[17] = s_Failed_to_submit_stratum_share__d_0008d2f8[17];
        tmp42[18] = s_Failed_to_submit_stratum_share__d_0008d2f8[18];
        tmp42[19] = s_Failed_to_submit_stratum_share__d_0008d2f8[19];
        tmp42[20] = s_Failed_to_submit_stratum_share__d_0008d2f8[20];
        tmp42[21] = s_Failed_to_submit_stratum_share__d_0008d2f8[21];
        tmp42[22] = s_Failed_to_submit_stratum_share__d_0008d2f8[22];
        tmp42[23] = s_Failed_to_submit_stratum_share__d_0008d2f8[23];
        tmp42[24] = s_Failed_to_submit_stratum_share__d_0008d2f8[24];
        tmp42[25] = s_Failed_to_submit_stratum_share__d_0008d2f8[25];
        tmp42[26] = s_Failed_to_submit_stratum_share__d_0008d2f8[26];
        tmp42[27] = s_Failed_to_submit_stratum_share__d_0008d2f8[27];
        tmp42[28] = s_Failed_to_submit_stratum_share__d_0008d2f8[28];
        tmp42[29] = s_Failed_to_submit_stratum_share__d_0008d2f8[29];
        tmp42[30] = s_Failed_to_submit_stratum_share__d_0008d2f8[30];
        tmp42[31] = s_Failed_to_submit_stratum_share__d_0008d2f8[31];
        tmp42[32] = s_Failed_to_submit_stratum_share__d_0008d2f8[32];
        tmp42[33] = s_Failed_to_submit_stratum_share__d_0008d2f8[33];
        tmp42[34] = s_Failed_to_submit_stratum_share__d_0008d2f8[34];
        tmp42[35] = s_Failed_to_submit_stratum_share__d_0008d2f8[35];
        tmp42[36] = s_Failed_to_submit_stratum_share__d_0008d2f8[36];
        tmp42[37] = s_Failed_to_submit_stratum_share__d_0008d2f8[37];
        tmp42[38] = s_Failed_to_submit_stratum_share__d_0008d2f8[38];
        tmp42[39] = s_Failed_to_submit_stratum_share__d_0008d2f8[39];
        tmp42._40_3_ = (undefined3)ram0x0008d320;
        _applog(7,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1e3a);
      free(__ptr);
      *(int *)((int)userdata + 0x78) = *(int *)((int)userdata + 0x78) + 1;
      bVar20 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar20;
    }
  } while( true );
}

