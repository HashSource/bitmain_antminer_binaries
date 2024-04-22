
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool stratum_send(pool *pool,char *s,ssize_t len)

{
  undefined uVar1;
  bool bVar2;
  ssize_t len_local;
  char *s_local;
  pool *pool_local;
  char tmp42 [2048];
  send_ret ret;
  
  ret = SEND_INACTIVE;
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf(tmp42,0x800,"SEND: %s",s);
    _applog(7,tmp42,false);
  }
  _mutex_lock(&pool->stratum_lock,"util.c","stratum_send",0x698);
  if (pool->stratum_active != false) {
    ret = __stratum_send(pool,s,len);
  }
  _mutex_unlock(&pool->stratum_lock,"util.c","stratum_send",0x69e);
  if (ret == SEND_SENDFAIL) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Failed_to_send_in_stratum_send_0007b150[0];
      tmp42[1] = s_Failed_to_send_in_stratum_send_0007b150[1];
      tmp42[2] = s_Failed_to_send_in_stratum_send_0007b150[2];
      tmp42[3] = s_Failed_to_send_in_stratum_send_0007b150[3];
      tmp42[4] = s_Failed_to_send_in_stratum_send_0007b150[4];
      tmp42[5] = s_Failed_to_send_in_stratum_send_0007b150[5];
      tmp42[6] = s_Failed_to_send_in_stratum_send_0007b150[6];
      tmp42[7] = s_Failed_to_send_in_stratum_send_0007b150[7];
      tmp42[8] = s_Failed_to_send_in_stratum_send_0007b150[8];
      tmp42[9] = s_Failed_to_send_in_stratum_send_0007b150[9];
      tmp42[10] = s_Failed_to_send_in_stratum_send_0007b150[10];
      tmp42[11] = s_Failed_to_send_in_stratum_send_0007b150[11];
      tmp42[12] = s_Failed_to_send_in_stratum_send_0007b150[12];
      tmp42[13] = s_Failed_to_send_in_stratum_send_0007b150[13];
      tmp42[14] = s_Failed_to_send_in_stratum_send_0007b150[14];
      tmp42[15] = s_Failed_to_send_in_stratum_send_0007b150[15];
      tmp42[16] = s_Failed_to_send_in_stratum_send_0007b150[16];
      tmp42[17] = s_Failed_to_send_in_stratum_send_0007b150[17];
      tmp42[18] = s_Failed_to_send_in_stratum_send_0007b150[18];
      tmp42[19] = s_Failed_to_send_in_stratum_send_0007b150[19];
      tmp42[20] = s_Failed_to_send_in_stratum_send_0007b150[20];
      tmp42[21] = s_Failed_to_send_in_stratum_send_0007b150[21];
      tmp42[22] = s_Failed_to_send_in_stratum_send_0007b150[22];
      tmp42[23] = s_Failed_to_send_in_stratum_send_0007b150[23];
      tmp42[24] = s_Failed_to_send_in_stratum_send_0007b150[24];
      tmp42[25] = s_Failed_to_send_in_stratum_send_0007b150[25];
      tmp42[26] = s_Failed_to_send_in_stratum_send_0007b150[26];
      tmp42[27] = s_Failed_to_send_in_stratum_send_0007b150[27];
      tmp42._28_3_ = (undefined3)ram0x0007b16c;
      _applog(7,tmp42,false);
    }
    suspend_stratum(pool);
  }
  else if (ret == SEND_INACTIVE) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Stratum_send_failed_due_to_no_po_0007b170[0];
      tmp42[1] = s_Stratum_send_failed_due_to_no_po_0007b170[1];
      tmp42[2] = s_Stratum_send_failed_due_to_no_po_0007b170[2];
      tmp42[3] = s_Stratum_send_failed_due_to_no_po_0007b170[3];
      tmp42[4] = s_Stratum_send_failed_due_to_no_po_0007b170[4];
      tmp42[5] = s_Stratum_send_failed_due_to_no_po_0007b170[5];
      tmp42[6] = s_Stratum_send_failed_due_to_no_po_0007b170[6];
      tmp42[7] = s_Stratum_send_failed_due_to_no_po_0007b170[7];
      tmp42[8] = s_Stratum_send_failed_due_to_no_po_0007b170[8];
      tmp42[9] = s_Stratum_send_failed_due_to_no_po_0007b170[9];
      tmp42[10] = s_Stratum_send_failed_due_to_no_po_0007b170[10];
      tmp42[11] = s_Stratum_send_failed_due_to_no_po_0007b170[11];
      tmp42[12] = s_Stratum_send_failed_due_to_no_po_0007b170[12];
      tmp42[13] = s_Stratum_send_failed_due_to_no_po_0007b170[13];
      tmp42[14] = s_Stratum_send_failed_due_to_no_po_0007b170[14];
      tmp42[15] = s_Stratum_send_failed_due_to_no_po_0007b170[15];
      tmp42[16] = s_Stratum_send_failed_due_to_no_po_0007b170[16];
      tmp42[17] = s_Stratum_send_failed_due_to_no_po_0007b170[17];
      tmp42[18] = s_Stratum_send_failed_due_to_no_po_0007b170[18];
      tmp42[19] = s_Stratum_send_failed_due_to_no_po_0007b170[19];
      tmp42[20] = s_Stratum_send_failed_due_to_no_po_0007b170[20];
      tmp42[21] = s_Stratum_send_failed_due_to_no_po_0007b170[21];
      tmp42[22] = s_Stratum_send_failed_due_to_no_po_0007b170[22];
      tmp42[23] = s_Stratum_send_failed_due_to_no_po_0007b170[23];
      tmp42[24] = s_Stratum_send_failed_due_to_no_po_0007b170[24];
      tmp42[25] = s_Stratum_send_failed_due_to_no_po_0007b170[25];
      tmp42[26] = s_Stratum_send_failed_due_to_no_po_0007b170[26];
      tmp42[27] = s_Stratum_send_failed_due_to_no_po_0007b170[27];
      tmp42[28] = s_Stratum_send_failed_due_to_no_po_0007b170[28];
      tmp42[29] = s_Stratum_send_failed_due_to_no_po_0007b170[29];
      tmp42[30] = s_Stratum_send_failed_due_to_no_po_0007b170[30];
      tmp42[31] = s_Stratum_send_failed_due_to_no_po_0007b170[31];
      tmp42[32] = s_Stratum_send_failed_due_to_no_po_0007b170[32];
      tmp42[33] = s_Stratum_send_failed_due_to_no_po_0007b170[33];
      tmp42[34] = s_Stratum_send_failed_due_to_no_po_0007b170[34];
      tmp42[35] = s_Stratum_send_failed_due_to_no_po_0007b170[35];
      tmp42[36] = s_Stratum_send_failed_due_to_no_po_0007b170[36];
      tmp42[37] = s_Stratum_send_failed_due_to_no_po_0007b170[37];
      tmp42[38] = s_Stratum_send_failed_due_to_no_po_0007b170[38];
      tmp42[39] = s_Stratum_send_failed_due_to_no_po_0007b170[39];
      tmp42[40] = s_Stratum_send_failed_due_to_no_po_0007b170[40];
      tmp42[41] = s_Stratum_send_failed_due_to_no_po_0007b170[41];
      tmp42[42] = s_Stratum_send_failed_due_to_no_po_0007b170[42];
      tmp42[43] = s_Stratum_send_failed_due_to_no_po_0007b170[43];
      tmp42[44] = s_Stratum_send_failed_due_to_no_po_0007b170[44];
      tmp42[45] = s_Stratum_send_failed_due_to_no_po_0007b170[45];
      tmp42[46] = s_Stratum_send_failed_due_to_no_po_0007b170[46];
      tmp42[47] = s_Stratum_send_failed_due_to_no_po_0007b170[47];
      tmp42._48_2_ = (undefined2)ram0x0007b1a0;
      _applog(7,tmp42,false);
    }
  }
  else if (ret == SEND_SELECTFAIL) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Write select failed on pool %d sock",pool->pool_no);
      _applog(7,tmp42,false);
    }
    suspend_stratum(pool);
  }
  bVar2 = ret != SEND_OK;
  if (bVar2) {
    ret = SEND_OK;
  }
  uVar1 = (undefined)ret;
  if (!bVar2) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

