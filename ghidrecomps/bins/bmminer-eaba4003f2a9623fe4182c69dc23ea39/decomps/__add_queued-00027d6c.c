
void __add_queued(cgpu_info *cgpu,work *work)

{
  UT_hash_table *pUVar1;
  UT_hash_bucket *pUVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  UT_hash_handle *pUVar7;
  UT_hash_bucket *pUVar8;
  work *pwVar9;
  work *work_local;
  cgpu_info *cgpu_local;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _ha_hashv;
  
  cgpu->queued_count = cgpu->queued_count + 1;
  _hj_key = (uchar *)&work->id;
  _ha_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar3 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                    (uint)_hj_key[7] * 0x1000000;
    uVar4 = _ha_hashv +
            (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
            (uint)_hj_key[0xb] * 0x1000000;
    uVar5 = uVar4 >> 0xd ^
            ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                      (uint)_hj_key[3] * 0x1000000) - iVar3) - uVar4;
    uVar6 = uVar5 << 8 ^ (iVar3 - uVar4) - uVar5;
    uVar4 = uVar6 >> 0xd ^ (uVar4 - uVar5) - uVar6;
    uVar5 = uVar4 >> 0xc ^ (uVar5 - uVar6) - uVar4;
    uVar6 = uVar5 << 0x10 ^ (uVar6 - uVar4) - uVar5;
    uVar4 = uVar6 >> 5 ^ (uVar4 - uVar5) - uVar6;
    _hj_i = uVar4 >> 3 ^ (uVar5 - uVar6) - uVar4;
    _hj_j = _hj_i << 10 ^ (uVar6 - uVar4) - _hj_i;
    _ha_hashv = _hj_j >> 0xf ^ (uVar4 - _hj_i) - _hj_j;
    _hj_key = _hj_key + 0xc;
  }
  uVar4 = _ha_hashv + 4;
  switch(_hj_k) {
  case 8:
    _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000 + (uint)_hj_key[6] * 0x10000 +
            (uint)_hj_key[5] * 0x100 + (uint)_hj_key[4];
  case 4:
    _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000 + (uint)_hj_key[2] * 0x10000 +
            (uint)_hj_key[1] * 0x100 + (uint)*_hj_key;
  }
  uVar5 = uVar4 >> 0xd ^ (_hj_i - _hj_j) - uVar4;
  uVar6 = uVar5 << 8 ^ (_hj_j - uVar4) - uVar5;
  uVar4 = uVar6 >> 0xd ^ (uVar4 - uVar5) - uVar6;
  uVar5 = uVar4 >> 0xc ^ (uVar5 - uVar6) - uVar4;
  uVar6 = uVar5 << 0x10 ^ (uVar6 - uVar4) - uVar5;
  uVar4 = uVar6 >> 5 ^ (uVar4 - uVar5) - uVar6;
  uVar5 = uVar4 >> 3 ^ (uVar5 - uVar6) - uVar4;
  uVar6 = uVar5 << 10 ^ (uVar6 - uVar4) - uVar5;
  uVar4 = uVar6 >> 0xf ^ (uVar4 - uVar5) - uVar6;
  (work->hh).hashv = uVar4;
  (work->hh).key = &work->id;
  (work->hh).keylen = 4;
  if (cgpu->queued_work == (work *)0x0) {
    (work->hh).next = (void *)0x0;
    (work->hh).prev = (void *)0x0;
    cgpu->queued_work = work;
    pwVar9 = cgpu->queued_work;
    pUVar1 = (UT_hash_table *)malloc(0x2c);
    (pwVar9->hh).tbl = pUVar1;
    if ((cgpu->queued_work->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset((cgpu->queued_work->hh).tbl,0,0x2c);
    ((cgpu->queued_work->hh).tbl)->tail = &cgpu->queued_work->hh;
    ((cgpu->queued_work->hh).tbl)->num_buckets = 0x20;
    ((cgpu->queued_work->hh).tbl)->log2_num_buckets = 5;
    ((cgpu->queued_work->hh).tbl)->hho = 0x158;
    pUVar1 = (cgpu->queued_work->hh).tbl;
    pUVar2 = (UT_hash_bucket *)malloc(0x180);
    pUVar1->buckets = pUVar2;
    if (((cgpu->queued_work->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(((cgpu->queued_work->hh).tbl)->buckets,0,0x180);
    ((cgpu->queued_work->hh).tbl)->signature = 0xa0111fe1;
  }
  else {
    (work->hh).tbl = (cgpu->queued_work->hh).tbl;
    (work->hh).next = (void *)0x0;
    (work->hh).prev =
         (void *)((int)((cgpu->queued_work->hh).tbl)->tail - ((cgpu->queued_work->hh).tbl)->hho);
    ((cgpu->queued_work->hh).tbl)->tail->next = work;
    ((cgpu->queued_work->hh).tbl)->tail = &work->hh;
  }
  pUVar1 = (cgpu->queued_work->hh).tbl;
  pUVar1->num_items = pUVar1->num_items + 1;
  uVar4 = uVar4 & ((cgpu->queued_work->hh).tbl)->num_buckets - 1;
  pUVar2 = ((cgpu->queued_work->hh).tbl)->buckets;
  pUVar2[uVar4].count = pUVar2[uVar4].count + 1;
  (work->hh).hh_next = ((cgpu->queued_work->hh).tbl)->buckets[uVar4].hh_head;
  (work->hh).hh_prev = (UT_hash_handle *)0x0;
  if (((cgpu->queued_work->hh).tbl)->buckets[uVar4].hh_head != (UT_hash_handle *)0x0) {
    (((cgpu->queued_work->hh).tbl)->buckets[uVar4].hh_head)->hh_prev = &work->hh;
  }
  ((cgpu->queued_work->hh).tbl)->buckets[uVar4].hh_head = &work->hh;
  if (((((cgpu->queued_work->hh).tbl)->buckets[uVar4].expand_mult + 1) * 10 <=
       ((cgpu->queued_work->hh).tbl)->buckets[uVar4].count) && (((work->hh).tbl)->noexpand != 1)) {
    pUVar2 = (UT_hash_bucket *)malloc(((work->hh).tbl)->num_buckets * 0x18);
    if (pUVar2 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar2,0,((work->hh).tbl)->num_buckets * 0x18);
    ((work->hh).tbl)->ideal_chain_maxlen =
         (((work->hh).tbl)->num_items >> (((work->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
         (uint)((((work->hh).tbl)->num_buckets * 2 - 1 & ((work->hh).tbl)->num_items) != 0);
    ((work->hh).tbl)->nonideal_items = 0;
    for (_he_bkt_i = 0; _he_bkt_i < ((work->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
      _he_thh = ((work->hh).tbl)->buckets[_he_bkt_i].hh_head;
      while (_he_thh != (UT_hash_handle *)0x0) {
        pUVar7 = _he_thh->hh_next;
        pUVar8 = pUVar2 + (((work->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
        pUVar8->count = pUVar8->count + 1;
        if (((work->hh).tbl)->ideal_chain_maxlen < pUVar8->count) {
          pUVar1 = (work->hh).tbl;
          pUVar1->nonideal_items = pUVar1->nonideal_items + 1;
          uVar4 = __aeabi_uidiv(pUVar8->count,((work->hh).tbl)->ideal_chain_maxlen);
          pUVar8->expand_mult = uVar4;
        }
        _he_thh->hh_prev = (UT_hash_handle *)0x0;
        _he_thh->hh_next = pUVar8->hh_head;
        if (pUVar8->hh_head != (UT_hash_handle *)0x0) {
          pUVar8->hh_head->hh_prev = _he_thh;
        }
        pUVar8->hh_head = _he_thh;
        _he_thh = pUVar7;
      }
    }
    free(((work->hh).tbl)->buckets);
    ((work->hh).tbl)->num_buckets = ((work->hh).tbl)->num_buckets << 1;
    pUVar1 = (work->hh).tbl;
    pUVar1->log2_num_buckets = pUVar1->log2_num_buckets + 1;
    ((work->hh).tbl)->buckets = pUVar2;
    if (((work->hh).tbl)->num_items >> 1 < ((work->hh).tbl)->nonideal_items) {
      uVar4 = ((work->hh).tbl)->ineff_expands + 1;
    }
    else {
      uVar4 = 0;
    }
    ((work->hh).tbl)->ineff_expands = uVar4;
    if (1 < ((work->hh).tbl)->ineff_expands) {
      ((work->hh).tbl)->noexpand = 1;
    }
  }
  return;
}

