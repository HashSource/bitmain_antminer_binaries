
_Bool parse_stratum_response(pool *pool,char *s)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  json_t *json;
  json_t *json_00;
  json_t *err_val_00;
  json_t *json_01;
  json_t *pjVar5;
  char *pcVar6;
  UT_hash_bucket *pUVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  UT_hash_table *pUVar11;
  double *pdVar12;
  int iVar13;
  bool bVar14;
  json_int_t jVar15;
  char *s_local;
  pool *pool_local;
  char tmp42 [2048];
  int id;
  json_error_t err;
  double pool_diff;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  uint _hf_bkt;
  json_t *version_mask;
  json_t *id_val;
  json_t *err_val;
  json_t *res_val;
  json_t *val;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _hf_hashv;
  char *ss;
  _Bool ret;
  stratum_share *sshare;
  
  ret = false;
  json = json_loads(s,0,&err);
  if (json == (json_t *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
      _applog(6,tmp42,false);
    }
  }
  else {
    json_00 = json_object_get(json,"result");
    err_val_00 = json_object_get(json,"error");
    json_01 = json_object_get(json,"id");
    if (((json_01 == (json_t *)0x0) || (json_01->type != JSON_NULL)) && (json_01 != (json_t *)0x0))
    {
      pjVar5 = json_object_get(json_00,"version-rolling.mask");
      if (((pjVar5 == (json_t *)0x0) &&
          (pcVar6 = strstr(s,"mining.configure"), pcVar6 == (char *)0x0)) &&
         (pcVar6 = strstr(s,"mining.set_version_mask"), pcVar6 == (char *)0x0)) {
        jVar15 = json_integer_value(json_01);
        id = (int)jVar15;
        _mutex_lock(&sshare_lock,"cgminer.c","parse_stratum_response",0x1c60);
        _hj_key = (uchar *)&id;
        _hf_hashv = 0xfeedbeef;
        _hj_j = 0x9e3779b9;
        _hj_i = 0x9e3779b9;
        for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
          iVar13 = (uint)_hj_key[7] * 0x1000000 +
                   (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 + _hj_j;
          uVar8 = (uint)_hj_key[0xb] * 0x1000000 +
                  (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
                  _hf_hashv;
          uVar9 = uVar8 >> 0xd ^
                  (((uint)_hj_key[3] * 0x1000000 +
                    (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 + _hj_i)
                  - iVar13) - uVar8;
          uVar10 = uVar9 << 8 ^ (iVar13 - uVar8) - uVar9;
          uVar8 = uVar10 >> 0xd ^ (uVar8 - uVar9) - uVar10;
          uVar9 = uVar8 >> 0xc ^ (uVar9 - uVar10) - uVar8;
          uVar10 = uVar9 << 0x10 ^ (uVar10 - uVar8) - uVar9;
          uVar8 = uVar10 >> 5 ^ (uVar8 - uVar9) - uVar10;
          _hj_i = uVar8 >> 3 ^ (uVar9 - uVar10) - uVar8;
          _hj_j = _hj_i << 10 ^ (uVar10 - uVar8) - _hj_i;
          _hf_hashv = _hj_j >> 0xf ^ (uVar8 - _hj_i) - _hj_j;
          _hj_key = _hj_key + 0xc;
        }
        uVar8 = _hf_hashv + 4;
        switch(_hj_k) {
        case 8:
          _hj_j = (uint)_hj_key[5] * 0x100 +
                  (uint)_hj_key[6] * 0x10000 + (uint)_hj_key[7] * 0x1000000 + _hj_j +
                  (uint)_hj_key[4];
        case 4:
          _hj_i = (uint)_hj_key[1] * 0x100 +
                  (uint)_hj_key[2] * 0x10000 + (uint)_hj_key[3] * 0x1000000 + _hj_i + (uint)*_hj_key
          ;
        default:
          uVar9 = uVar8 >> 0xd ^ (_hj_i - _hj_j) - uVar8;
          uVar10 = uVar9 << 8 ^ (_hj_j - uVar8) - uVar9;
          uVar8 = uVar10 >> 0xd ^ (uVar8 - uVar9) - uVar10;
          uVar9 = uVar8 >> 0xc ^ (uVar9 - uVar10) - uVar8;
          uVar10 = uVar9 << 0x10 ^ (uVar10 - uVar8) - uVar9;
          uVar8 = uVar10 >> 5 ^ (uVar8 - uVar9) - uVar10;
          uVar9 = uVar8 >> 3 ^ (uVar9 - uVar10) - uVar8;
          uVar10 = uVar9 << 10 ^ (uVar10 - uVar8) - uVar9;
          uVar8 = uVar10 >> 0xf ^ (uVar8 - uVar9) - uVar10;
          sshare = (stratum_share *)0x0;
          if (stratum_shares != (stratum_share *)0x0) {
            uVar9 = ((stratum_shares->hh).tbl)->num_buckets - 1 & uVar8;
            if (((stratum_shares->hh).tbl)->buckets[uVar9].hh_head == (UT_hash_handle *)0x0) {
              sshare = (stratum_share *)0x0;
            }
            else {
              sshare = (stratum_share *)
                       ((int)((stratum_shares->hh).tbl)->buckets[uVar9].hh_head -
                       ((stratum_shares->hh).tbl)->hho);
            }
            while ((sshare != (stratum_share *)0x0 &&
                   (((uVar8 != (sshare->hh).hashv || ((sshare->hh).keylen != 4)) ||
                    (iVar13 = memcmp((sshare->hh).key,&id,4), iVar13 != 0))))) {
              if ((sshare->hh).hh_next == (UT_hash_handle *)0x0) {
                sshare = (stratum_share *)0x0;
              }
              else {
                sshare = (stratum_share *)
                         ((int)(sshare->hh).hh_next - ((stratum_shares->hh).tbl)->hho);
              }
            }
          }
          if (sshare != (stratum_share *)0x0) {
            if (((sshare->hh).prev == (void *)0x0) && ((sshare->hh).next == (void *)0x0)) {
              free(((stratum_shares->hh).tbl)->buckets);
              free((stratum_shares->hh).tbl);
              stratum_shares = (stratum_share *)0x0;
            }
            else {
              if (sshare == (stratum_share *)
                            ((int)((stratum_shares->hh).tbl)->tail - ((stratum_shares->hh).tbl)->hho
                            )) {
                ((stratum_shares->hh).tbl)->tail =
                     (UT_hash_handle *)((int)(sshare->hh).prev + ((stratum_shares->hh).tbl)->hho);
              }
              if ((sshare->hh).prev == (void *)0x0) {
                stratum_shares = (stratum_share *)(sshare->hh).next;
              }
              else {
                *(void **)((int)(sshare->hh).prev + ((stratum_shares->hh).tbl)->hho + 8) =
                     (sshare->hh).next;
              }
              if ((sshare->hh).next != (void *)0x0) {
                *(void **)((int)(sshare->hh).next + ((stratum_shares->hh).tbl)->hho + 4) =
                     (sshare->hh).prev;
              }
              uVar8 = ((stratum_shares->hh).tbl)->num_buckets - 1 & (sshare->hh).hashv;
              pUVar7 = ((stratum_shares->hh).tbl)->buckets;
              pUVar7[uVar8].count = pUVar7[uVar8].count - 1;
              if (sshare == (stratum_share *)((stratum_shares->hh).tbl)->buckets[uVar8].hh_head) {
                ((stratum_shares->hh).tbl)->buckets[uVar8].hh_head = (sshare->hh).hh_next;
              }
              if ((sshare->hh).hh_prev != (UT_hash_handle *)0x0) {
                ((sshare->hh).hh_prev)->hh_next = (sshare->hh).hh_next;
              }
              if ((sshare->hh).hh_next != (UT_hash_handle *)0x0) {
                ((sshare->hh).hh_next)->hh_prev = (sshare->hh).hh_prev;
              }
              pUVar11 = (stratum_shares->hh).tbl;
              pUVar11->num_items = pUVar11->num_items - 1;
            }
            pool->sshares = pool->sshares + -1;
          }
          _mutex_unlock(&sshare_lock,"cgminer.c","parse_stratum_response",0x1c68);
          if (sshare == (stratum_share *)0x0) {
            if (json_00 != (json_t *)0x0) {
              _cg_rlock(&pool->data_lock,"cgminer.c","parse_stratum_response",0x1c74);
              pdVar12 = &pool->sdiff;
              dVar4 = *pdVar12;
              dVar3 = *pdVar12;
              dVar2 = *pdVar12;
              dVar1 = *pdVar12;
              _cg_runlock(&pool->data_lock,"cgminer.c","parse_stratum_response",0x1c76);
              if ((json_00 == (json_t *)0x0) || (json_00->type != JSON_TRUE)) {
                if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"Rejected untracked stratum share from pool %d",pool->pool_no
                          );
                  _applog(5,tmp42,false);
                }
                _mutex_lock(&stats_lock,"cgminer.c","parse_stratum_response",0x1c89);
                bVar14 = 0xfffffffe < (uint)total_rejected;
                total_rejected._0_4_ = (uint)total_rejected + 1;
                total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar14;
                uVar8 = *(uint *)&pool->rejected;
                iVar13 = *(int *)((int)&pool->rejected + 4);
                *(uint *)&pool->rejected = uVar8 + 1;
                *(uint *)((int)&pool->rejected + 4) = iVar13 + (uint)(0xfffffffe < uVar8);
                total_diff_rejected = total_diff_rejected + dVar3;
                pool->diff_rejected = pool->diff_rejected + dVar4;
                _mutex_unlock(&stats_lock,"cgminer.c","parse_stratum_response",0x1c8e);
              }
              else {
                if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Accepted untracked stratum share from pool %d",pool->pool_no
                          );
                  _applog(5,tmp42,false);
                }
                _mutex_lock(&stats_lock,"cgminer.c","parse_stratum_response",0x1c7e);
                bVar14 = 0xfffffffe < (uint)total_accepted;
                total_accepted._0_4_ = (uint)total_accepted + 1;
                total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar14;
                uVar8 = *(uint *)&pool->accepted;
                iVar13 = *(int *)((int)&pool->accepted + 4);
                *(uint *)&pool->accepted = uVar8 + 1;
                *(uint *)((int)&pool->accepted + 4) = iVar13 + (uint)(0xfffffffe < uVar8);
                total_diff_accepted = total_diff_accepted + dVar1;
                pool->diff_accepted = pool->diff_accepted + dVar2;
                _mutex_unlock(&stats_lock,"cgminer.c","parse_stratum_response",0x1c83);
              }
            }
          }
          else {
            stratum_share_result(json,json_00,err_val_00,sshare);
            _free_work(&sshare->work,"cgminer.c","parse_stratum_response",0x1c95);
            free(sshare);
            ret = true;
          }
        }
      }
    }
    else {
      if (err_val_00 == (json_t *)0x0) {
        ss = strdup("(unknown reason)");
      }
      else {
        ss = json_dumps(err_val_00,3);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"JSON-RPC non method decode failed: %s",ss);
        _applog(6,tmp42,false);
      }
      free(ss);
    }
  }
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  return ret;
}

