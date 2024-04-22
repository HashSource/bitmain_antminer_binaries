
_Bool hash_push(work *work)

{
  bool bVar1;
  _Bool _Var2;
  UT_hash_table *pUVar3;
  UT_hash_bucket *pUVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  UT_hash_handle *pUVar9;
  UT_hash_bucket *pUVar10;
  void *pvVar11;
  work *work_local;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  UT_hash_handle *_hs_tail;
  UT_hash_handle *_hs_list;
  UT_hash_handle *_hs_e;
  UT_hash_handle *_hs_q;
  UT_hash_handle *_hs_p;
  uint _hs_qsize;
  uint _hs_psize;
  uint _hs_insize;
  uint _hs_nmerges;
  uint _hs_looping;
  uint _hs_i;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _ha_hashv;
  _Bool rc;
  
  rc = true;
  _mutex_lock(stgd_lock,"cgminer.c","hash_push",0x167a);
  _Var2 = work_rollable(work);
  if (_Var2) {
    staged_rollable = staged_rollable + 1;
  }
  if (getq->frozen == true) {
    rc = false;
  }
  else {
    _hj_key = (uchar *)&work->id;
    _ha_hashv = 0xfeedbeef;
    _hj_j = 0x9e3779b9;
    _hj_i = 0x9e3779b9;
    for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
      iVar5 = (uint)_hj_key[7] * 0x1000000 +
              (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 + _hj_j;
      uVar6 = (uint)_hj_key[0xb] * 0x1000000 +
              (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 + _ha_hashv;
      uVar7 = uVar6 >> 0xd ^
              (((uint)_hj_key[3] * 0x1000000 +
                (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 + _hj_i) -
              iVar5) - uVar6;
      uVar8 = uVar7 << 8 ^ (iVar5 - uVar6) - uVar7;
      uVar6 = uVar8 >> 0xd ^ (uVar6 - uVar7) - uVar8;
      uVar7 = uVar6 >> 0xc ^ (uVar7 - uVar8) - uVar6;
      uVar8 = uVar7 << 0x10 ^ (uVar8 - uVar6) - uVar7;
      uVar6 = uVar8 >> 5 ^ (uVar6 - uVar7) - uVar8;
      _hj_i = uVar6 >> 3 ^ (uVar7 - uVar8) - uVar6;
      _hj_j = _hj_i << 10 ^ (uVar8 - uVar6) - _hj_i;
      _ha_hashv = _hj_j >> 0xf ^ (uVar6 - _hj_i) - _hj_j;
      _hj_key = _hj_key + 0xc;
    }
    uVar6 = _ha_hashv + 4;
    switch(_hj_k) {
    case 8:
      _hj_j = (uint)_hj_key[5] * 0x100 +
              (uint)_hj_key[6] * 0x10000 + (uint)_hj_key[7] * 0x1000000 + _hj_j + (uint)_hj_key[4];
    case 4:
      _hj_i = (uint)_hj_key[1] * 0x100 +
              (uint)_hj_key[2] * 0x10000 + (uint)_hj_key[3] * 0x1000000 + _hj_i + (uint)*_hj_key;
    }
    uVar7 = uVar6 >> 0xd ^ (_hj_i - _hj_j) - uVar6;
    uVar8 = uVar7 << 8 ^ (_hj_j - uVar6) - uVar7;
    uVar6 = uVar8 >> 0xd ^ (uVar6 - uVar7) - uVar8;
    uVar7 = uVar6 >> 0xc ^ (uVar7 - uVar8) - uVar6;
    uVar8 = uVar7 << 0x10 ^ (uVar8 - uVar6) - uVar7;
    uVar6 = uVar8 >> 5 ^ (uVar6 - uVar7) - uVar8;
    uVar7 = uVar6 >> 3 ^ (uVar7 - uVar8) - uVar6;
    uVar8 = uVar7 << 10 ^ (uVar8 - uVar6) - uVar7;
    uVar6 = uVar8 >> 0xf ^ (uVar6 - uVar7) - uVar8;
    (work->hh).hashv = uVar6;
    (work->hh).key = &work->id;
    (work->hh).keylen = 4;
    if (staged_work == (work *)0x0) {
      (work->hh).next = (void *)0x0;
      (work->hh).prev = (void *)0x0;
      staged_work = work;
      pUVar3 = (UT_hash_table *)malloc(0x2c);
      (work->hh).tbl = pUVar3;
      if ((staged_work->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((staged_work->hh).tbl,0,0x2c);
      ((staged_work->hh).tbl)->tail = &staged_work->hh;
      ((staged_work->hh).tbl)->num_buckets = 0x20;
      ((staged_work->hh).tbl)->log2_num_buckets = 5;
      ((staged_work->hh).tbl)->hho = 0x158;
      pUVar3 = (staged_work->hh).tbl;
      pUVar4 = (UT_hash_bucket *)malloc(0x180);
      pUVar3->buckets = pUVar4;
      if (((staged_work->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(((staged_work->hh).tbl)->buckets,0,0x180);
      ((staged_work->hh).tbl)->signature = 0xa0111fe1;
    }
    else {
      (work->hh).tbl = (staged_work->hh).tbl;
      (work->hh).next = (void *)0x0;
      (work->hh).prev = (void *)((int)((staged_work->hh).tbl)->tail - ((staged_work->hh).tbl)->hho);
      ((staged_work->hh).tbl)->tail->next = work;
      ((staged_work->hh).tbl)->tail = &work->hh;
    }
    pUVar3 = (staged_work->hh).tbl;
    pUVar3->num_items = pUVar3->num_items + 1;
    uVar6 = ((staged_work->hh).tbl)->num_buckets - 1 & uVar6;
    pUVar4 = ((staged_work->hh).tbl)->buckets;
    pUVar4[uVar6].count = pUVar4[uVar6].count + 1;
    (work->hh).hh_next = ((staged_work->hh).tbl)->buckets[uVar6].hh_head;
    (work->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((staged_work->hh).tbl)->buckets[uVar6].hh_head != (UT_hash_handle *)0x0) {
      (((staged_work->hh).tbl)->buckets[uVar6].hh_head)->hh_prev = &work->hh;
    }
    ((staged_work->hh).tbl)->buckets[uVar6].hh_head = &work->hh;
    if (((((staged_work->hh).tbl)->buckets[uVar6].expand_mult + 1) * 10 <=
         ((staged_work->hh).tbl)->buckets[uVar6].count) && (((work->hh).tbl)->noexpand != 1)) {
      pUVar4 = (UT_hash_bucket *)malloc(((work->hh).tbl)->num_buckets * 0x18);
      if (pUVar4 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar4,0,((work->hh).tbl)->num_buckets * 0x18);
      ((work->hh).tbl)->ideal_chain_maxlen =
           (((work->hh).tbl)->num_items >> (((work->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((work->hh).tbl)->num_buckets * 2 - 1 & ((work->hh).tbl)->num_items) != 0);
      ((work->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((work->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((work->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar9 = _he_thh->hh_next;
          pUVar10 = pUVar4 + (((work->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar10->count = pUVar10->count + 1;
          if (((work->hh).tbl)->ideal_chain_maxlen < pUVar10->count) {
            pUVar3 = (work->hh).tbl;
            pUVar3->nonideal_items = pUVar3->nonideal_items + 1;
            uVar6 = __udivsi3(pUVar10->count,((work->hh).tbl)->ideal_chain_maxlen);
            pUVar10->expand_mult = uVar6;
          }
          _he_thh->hh_prev = (UT_hash_handle *)0x0;
          _he_thh->hh_next = pUVar10->hh_head;
          if (pUVar10->hh_head != (UT_hash_handle *)0x0) {
            pUVar10->hh_head->hh_prev = _he_thh;
          }
          pUVar10->hh_head = _he_thh;
          _he_thh = pUVar9;
        }
      }
      free(((work->hh).tbl)->buckets);
      ((work->hh).tbl)->num_buckets = ((work->hh).tbl)->num_buckets << 1;
      pUVar3 = (work->hh).tbl;
      pUVar3->log2_num_buckets = pUVar3->log2_num_buckets + 1;
      ((work->hh).tbl)->buckets = pUVar4;
      if (((work->hh).tbl)->num_items >> 1 < ((work->hh).tbl)->nonideal_items) {
        uVar6 = ((work->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar6 = 0;
      }
      ((work->hh).tbl)->ineff_expands = uVar6;
      if (1 < ((work->hh).tbl)->ineff_expands) {
        ((work->hh).tbl)->noexpand = 1;
      }
    }
    if (staged_work != (work *)0x0) {
      _hs_insize = 1;
      bVar1 = true;
      _hs_list = &staged_work->hh;
      while (bVar1) {
        _hs_p = _hs_list;
        _hs_list = (UT_hash_handle *)0x0;
        _hs_tail = (UT_hash_handle *)0x0;
        _hs_nmerges = 0;
        while (_hs_p != (UT_hash_handle *)0x0) {
          _hs_nmerges = _hs_nmerges + 1;
          _hs_q = _hs_p;
          _hs_psize = 0;
          for (_hs_i = 0; _hs_i < _hs_insize; _hs_i = _hs_i + 1) {
            _hs_psize = _hs_psize + 1;
            if (_hs_q->next == (void *)0x0) {
              _hs_q = (UT_hash_handle *)0x0;
            }
            else {
              _hs_q = (UT_hash_handle *)(((staged_work->hh).tbl)->hho + (int)_hs_q->next);
            }
            if (_hs_q == (UT_hash_handle *)0x0) break;
          }
          _hs_qsize = _hs_insize;
          while ((_hs_psize != 0 || ((_hs_qsize != 0 && (_hs_q != (UT_hash_handle *)0x0))))) {
            if (_hs_psize == 0) {
              _hs_e = _hs_q;
              if (_hs_q->next == (void *)0x0) {
                _hs_q = (UT_hash_handle *)0x0;
              }
              else {
                _hs_q = (UT_hash_handle *)(((staged_work->hh).tbl)->hho + (int)_hs_q->next);
              }
              _hs_qsize = _hs_qsize - 1;
            }
            else if ((_hs_qsize == 0) || (_hs_q == (UT_hash_handle *)0x0)) {
              _hs_e = _hs_p;
              if (_hs_p != (UT_hash_handle *)0x0) {
                if (_hs_p->next == (void *)0x0) {
                  _hs_p = (UT_hash_handle *)0x0;
                }
                else {
                  _hs_p = (UT_hash_handle *)(((staged_work->hh).tbl)->hho + (int)_hs_p->next);
                }
              }
              _hs_psize = _hs_psize - 1;
            }
            else {
              iVar5 = tv_sort((work *)((int)_hs_p - ((staged_work->hh).tbl)->hho),
                              (work *)((int)_hs_q - ((staged_work->hh).tbl)->hho));
              if (iVar5 < 1) {
                _hs_e = _hs_p;
                if (_hs_p != (UT_hash_handle *)0x0) {
                  if (_hs_p->next == (void *)0x0) {
                    _hs_p = (UT_hash_handle *)0x0;
                  }
                  else {
                    _hs_p = (UT_hash_handle *)(((staged_work->hh).tbl)->hho + (int)_hs_p->next);
                  }
                }
                _hs_psize = _hs_psize - 1;
              }
              else {
                _hs_e = _hs_q;
                if (_hs_q->next == (void *)0x0) {
                  _hs_q = (UT_hash_handle *)0x0;
                }
                else {
                  _hs_q = (UT_hash_handle *)(((staged_work->hh).tbl)->hho + (int)_hs_q->next);
                }
                _hs_qsize = _hs_qsize - 1;
              }
            }
            if (_hs_tail == (UT_hash_handle *)0x0) {
              _hs_list = _hs_e;
            }
            else {
              if (_hs_e == (UT_hash_handle *)0x0) {
                pvVar11 = (void *)0x0;
              }
              else {
                pvVar11 = (void *)((int)_hs_e - ((staged_work->hh).tbl)->hho);
              }
              _hs_tail->next = pvVar11;
            }
            if (_hs_e != (UT_hash_handle *)0x0) {
              if (_hs_tail == (UT_hash_handle *)0x0) {
                pvVar11 = (void *)0x0;
              }
              else {
                pvVar11 = (void *)((int)_hs_tail - ((staged_work->hh).tbl)->hho);
              }
              _hs_e->prev = pvVar11;
            }
            _hs_tail = _hs_e;
          }
          _hs_p = _hs_q;
        }
        if (_hs_tail != (UT_hash_handle *)0x0) {
          _hs_tail->next = (void *)0x0;
        }
        if (_hs_nmerges < 2) {
          bVar1 = false;
          ((staged_work->hh).tbl)->tail = _hs_tail;
          staged_work = (work *)((int)_hs_list - ((staged_work->hh).tbl)->hho);
        }
        _hs_insize = _hs_insize << 1;
      }
    }
  }
  pthread_cond_broadcast((pthread_cond_t *)&getq->cond);
  _mutex_unlock(stgd_lock,"cgminer.c","hash_push",0x168c);
  return rc;
}

