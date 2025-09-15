
_Bool add_cgpu(cgpu_info *cgpu)

{
  size_t sVar1;
  _cgpu_devid_counter *__s;
  UT_hash_table *pUVar2;
  UT_hash_bucket *pUVar3;
  time_t tVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  UT_hash_handle *pUVar9;
  UT_hash_bucket *pUVar10;
  size_t sVar11;
  char *__s2;
  void *__s1;
  cgpu_info *cgpu_local;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  uint _hf_bkt;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key_1;
  uint _hj_k_1;
  uint _hj_j_1;
  uint _hj_i_1;
  uint _ha_hashv;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _hf_hashv;
  _cgpu_devid_counter *d;
  
  _hj_key = (uchar *)cgpu->drv->name;
  _hf_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  for (_hj_k = strlen(cgpu->drv->name); 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar8 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                    (uint)_hj_key[7] * 0x1000000;
    uVar5 = _hf_hashv +
            (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
            (uint)_hj_key[0xb] * 0x1000000;
    uVar6 = uVar5 >> 0xd ^
            ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                      (uint)_hj_key[3] * 0x1000000) - iVar8) - uVar5;
    uVar7 = uVar6 << 8 ^ (iVar8 - uVar5) - uVar6;
    uVar5 = uVar7 >> 0xd ^ (uVar5 - uVar6) - uVar7;
    uVar6 = uVar5 >> 0xc ^ (uVar6 - uVar7) - uVar5;
    uVar7 = uVar6 << 0x10 ^ (uVar7 - uVar5) - uVar6;
    uVar5 = uVar7 >> 5 ^ (uVar5 - uVar6) - uVar7;
    _hj_i = uVar5 >> 3 ^ (uVar6 - uVar7) - uVar5;
    _hj_j = _hj_i << 10 ^ (uVar7 - uVar5) - _hj_i;
    _hf_hashv = _hj_j >> 0xf ^ (uVar5 - _hj_i) - _hj_j;
    _hj_key = _hj_key + 0xc;
  }
  sVar1 = strlen(cgpu->drv->name);
  _hf_hashv = _hf_hashv + sVar1;
  switch(_hj_k) {
  case 0xb:
    _hf_hashv = _hf_hashv + (uint)_hj_key[10] * 0x1000000;
  case 10:
    _hf_hashv = _hf_hashv + (uint)_hj_key[9] * 0x10000;
  case 9:
    _hf_hashv = _hf_hashv + (uint)_hj_key[8] * 0x100;
  case 8:
    _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000;
  case 7:
    _hj_j = _hj_j + (uint)_hj_key[6] * 0x10000;
  case 6:
    _hj_j = _hj_j + (uint)_hj_key[5] * 0x100;
  case 5:
    _hj_j = _hj_j + _hj_key[4];
  case 4:
    _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000;
  case 3:
    _hj_i = _hj_i + (uint)_hj_key[2] * 0x10000;
  case 2:
    _hj_i = _hj_i + (uint)_hj_key[1] * 0x100;
  case 1:
    _hj_i = _hj_i + *_hj_key;
  }
  uVar5 = _hf_hashv >> 0xd ^ (_hj_i - _hj_j) - _hf_hashv;
  uVar6 = uVar5 << 8 ^ (_hj_j - _hf_hashv) - uVar5;
  uVar7 = uVar6 >> 0xd ^ (_hf_hashv - uVar5) - uVar6;
  uVar5 = uVar7 >> 0xc ^ (uVar5 - uVar6) - uVar7;
  uVar6 = uVar5 << 0x10 ^ (uVar6 - uVar7) - uVar5;
  uVar7 = uVar6 >> 5 ^ (uVar7 - uVar5) - uVar6;
  uVar5 = uVar7 >> 3 ^ (uVar5 - uVar6) - uVar7;
  uVar6 = uVar5 << 10 ^ (uVar6 - uVar7) - uVar5;
  uVar5 = uVar6 >> 0xf ^ (uVar7 - uVar5) - uVar6;
  d = (_cgpu_devid_counter *)0x0;
  if (add_cgpu::devids != (_cgpu_devid_counter *)0x0) {
    uVar6 = uVar5 & ((add_cgpu::devids->hh).tbl)->num_buckets - 1;
    if (((add_cgpu::devids->hh).tbl)->buckets[uVar6].hh_head == (UT_hash_handle *)0x0) {
      d = (_cgpu_devid_counter *)0x0;
    }
    else {
      d = (_cgpu_devid_counter *)
          ((int)((add_cgpu::devids->hh).tbl)->buckets[uVar6].hh_head -
          ((add_cgpu::devids->hh).tbl)->hho);
    }
    while (d != (_cgpu_devid_counter *)0x0) {
      if (((d->hh).hashv == uVar5) &&
         (sVar11 = (d->hh).keylen, sVar1 = strlen(cgpu->drv->name), sVar11 == sVar1)) {
        __s1 = (d->hh).key;
        __s2 = cgpu->drv->name;
        sVar1 = strlen(cgpu->drv->name);
        iVar8 = memcmp(__s1,__s2,sVar1);
        if (iVar8 == 0) break;
      }
      if ((d->hh).hh_next == (UT_hash_handle *)0x0) {
        d = (_cgpu_devid_counter *)0x0;
      }
      else {
        d = (_cgpu_devid_counter *)((int)(d->hh).hh_next - ((add_cgpu::devids->hh).tbl)->hho);
      }
    }
  }
  if (d == (_cgpu_devid_counter *)0x0) {
    __s = (_cgpu_devid_counter *)_cgmalloc(0x28,"cgminer.c","add_cgpu",0x2b87);
    _cg_memcpy(__s,cgpu->drv->name,4,"cgminer.c","add_cgpu",0x2b88);
    __s->lastid = 0;
    cgpu->device_id = __s->lastid;
    _ha_hashv = 0xfeedbeef;
    _hj_j_1 = 0x9e3779b9;
    _hj_i_1 = 0x9e3779b9;
    _hj_k_1 = strlen((char *)__s);
    _hj_key_1 = (uchar *)__s;
    for (; 0xb < _hj_k_1; _hj_k_1 = _hj_k_1 - 0xc) {
      iVar8 = _hj_j_1 + (uint)_hj_key_1[4] + (uint)_hj_key_1[5] * 0x100 +
                        (uint)_hj_key_1[6] * 0x10000 + (uint)_hj_key_1[7] * 0x1000000;
      uVar5 = _ha_hashv +
              (uint)_hj_key_1[8] + (uint)_hj_key_1[9] * 0x100 + (uint)_hj_key_1[10] * 0x10000 +
              (uint)_hj_key_1[0xb] * 0x1000000;
      uVar6 = uVar5 >> 0xd ^
              ((_hj_i_1 +
               (uint)*_hj_key_1 + (uint)_hj_key_1[1] * 0x100 + (uint)_hj_key_1[2] * 0x10000 +
               (uint)_hj_key_1[3] * 0x1000000) - iVar8) - uVar5;
      uVar7 = uVar6 << 8 ^ (iVar8 - uVar5) - uVar6;
      uVar5 = uVar7 >> 0xd ^ (uVar5 - uVar6) - uVar7;
      uVar6 = uVar5 >> 0xc ^ (uVar6 - uVar7) - uVar5;
      uVar7 = uVar6 << 0x10 ^ (uVar7 - uVar5) - uVar6;
      uVar5 = uVar7 >> 5 ^ (uVar5 - uVar6) - uVar7;
      _hj_i_1 = uVar5 >> 3 ^ (uVar6 - uVar7) - uVar5;
      _hj_j_1 = _hj_i_1 << 10 ^ (uVar7 - uVar5) - _hj_i_1;
      _ha_hashv = _hj_j_1 >> 0xf ^ (uVar5 - _hj_i_1) - _hj_j_1;
      _hj_key_1 = _hj_key_1 + 0xc;
    }
    sVar1 = strlen((char *)__s);
    _ha_hashv = _ha_hashv + sVar1;
    switch(_hj_k_1) {
    case 0xb:
      _ha_hashv = _ha_hashv + (uint)_hj_key_1[10] * 0x1000000;
    case 10:
      _ha_hashv = _ha_hashv + (uint)_hj_key_1[9] * 0x10000;
    case 9:
      _ha_hashv = _ha_hashv + (uint)_hj_key_1[8] * 0x100;
    case 8:
      _hj_j_1 = _hj_j_1 + (uint)_hj_key_1[7] * 0x1000000;
    case 7:
      _hj_j_1 = _hj_j_1 + (uint)_hj_key_1[6] * 0x10000;
    case 6:
      _hj_j_1 = _hj_j_1 + (uint)_hj_key_1[5] * 0x100;
    case 5:
      _hj_j_1 = _hj_j_1 + _hj_key_1[4];
    case 4:
      _hj_i_1 = _hj_i_1 + (uint)_hj_key_1[3] * 0x1000000;
    case 3:
      _hj_i_1 = _hj_i_1 + (uint)_hj_key_1[2] * 0x10000;
    case 2:
      _hj_i_1 = _hj_i_1 + (uint)_hj_key_1[1] * 0x100;
    case 1:
      _hj_i_1 = _hj_i_1 + *_hj_key_1;
    }
    uVar5 = _ha_hashv >> 0xd ^ (_hj_i_1 - _hj_j_1) - _ha_hashv;
    uVar6 = uVar5 << 8 ^ (_hj_j_1 - _ha_hashv) - uVar5;
    uVar7 = uVar6 >> 0xd ^ (_ha_hashv - uVar5) - uVar6;
    uVar5 = uVar7 >> 0xc ^ (uVar5 - uVar6) - uVar7;
    uVar6 = uVar5 << 0x10 ^ (uVar6 - uVar7) - uVar5;
    uVar7 = uVar6 >> 5 ^ (uVar7 - uVar5) - uVar6;
    uVar5 = uVar7 >> 3 ^ (uVar5 - uVar6) - uVar7;
    uVar6 = uVar5 << 10 ^ (uVar6 - uVar7) - uVar5;
    uVar5 = uVar6 >> 0xf ^ (uVar7 - uVar5) - uVar6;
    (__s->hh).hashv = uVar5;
    (__s->hh).key = __s;
    sVar1 = strlen((char *)__s);
    (__s->hh).keylen = sVar1;
    if (add_cgpu::devids == (_cgpu_devid_counter *)0x0) {
      (__s->hh).next = (void *)0x0;
      (__s->hh).prev = (void *)0x0;
      add_cgpu::devids = __s;
      pUVar2 = (UT_hash_table *)malloc(0x2c);
      (__s->hh).tbl = pUVar2;
      if ((add_cgpu::devids->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((add_cgpu::devids->hh).tbl,0,0x2c);
      ((add_cgpu::devids->hh).tbl)->tail = &add_cgpu::devids->hh;
      ((add_cgpu::devids->hh).tbl)->num_buckets = 0x20;
      ((add_cgpu::devids->hh).tbl)->log2_num_buckets = 5;
      ((add_cgpu::devids->hh).tbl)->hho = 8;
      pUVar2 = (add_cgpu::devids->hh).tbl;
      pUVar3 = (UT_hash_bucket *)malloc(0x180);
      pUVar2->buckets = pUVar3;
      if (((add_cgpu::devids->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(((add_cgpu::devids->hh).tbl)->buckets,0,0x180);
      ((add_cgpu::devids->hh).tbl)->signature = 0xa0111fe1;
    }
    else {
      (__s->hh).tbl = (add_cgpu::devids->hh).tbl;
      (__s->hh).next = (void *)0x0;
      (__s->hh).prev =
           (void *)((int)((add_cgpu::devids->hh).tbl)->tail - ((add_cgpu::devids->hh).tbl)->hho);
      ((add_cgpu::devids->hh).tbl)->tail->next = __s;
      ((add_cgpu::devids->hh).tbl)->tail = &__s->hh;
    }
    pUVar2 = (add_cgpu::devids->hh).tbl;
    pUVar2->num_items = pUVar2->num_items + 1;
    uVar5 = uVar5 & ((add_cgpu::devids->hh).tbl)->num_buckets - 1;
    pUVar3 = ((add_cgpu::devids->hh).tbl)->buckets;
    pUVar3[uVar5].count = pUVar3[uVar5].count + 1;
    (__s->hh).hh_next = ((add_cgpu::devids->hh).tbl)->buckets[uVar5].hh_head;
    (__s->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((add_cgpu::devids->hh).tbl)->buckets[uVar5].hh_head != (UT_hash_handle *)0x0) {
      (((add_cgpu::devids->hh).tbl)->buckets[uVar5].hh_head)->hh_prev = &__s->hh;
    }
    ((add_cgpu::devids->hh).tbl)->buckets[uVar5].hh_head = &__s->hh;
    if (((((add_cgpu::devids->hh).tbl)->buckets[uVar5].expand_mult + 1) * 10 <=
         ((add_cgpu::devids->hh).tbl)->buckets[uVar5].count) && (((__s->hh).tbl)->noexpand != 1)) {
      pUVar3 = (UT_hash_bucket *)malloc(((__s->hh).tbl)->num_buckets * 0x18);
      if (pUVar3 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar3,0,((__s->hh).tbl)->num_buckets * 0x18);
      ((__s->hh).tbl)->ideal_chain_maxlen =
           (((__s->hh).tbl)->num_items >> (((__s->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((__s->hh).tbl)->num_buckets * 2 - 1 & ((__s->hh).tbl)->num_items) != 0);
      ((__s->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__s->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__s->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar9 = _he_thh->hh_next;
          pUVar10 = pUVar3 + (((__s->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar10->count = pUVar10->count + 1;
          if (((__s->hh).tbl)->ideal_chain_maxlen < pUVar10->count) {
            pUVar2 = (__s->hh).tbl;
            pUVar2->nonideal_items = pUVar2->nonideal_items + 1;
            uVar5 = __aeabi_uidiv(pUVar10->count,((__s->hh).tbl)->ideal_chain_maxlen);
            pUVar10->expand_mult = uVar5;
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
      free(((__s->hh).tbl)->buckets);
      ((__s->hh).tbl)->num_buckets = ((__s->hh).tbl)->num_buckets << 1;
      pUVar2 = (__s->hh).tbl;
      pUVar2->log2_num_buckets = pUVar2->log2_num_buckets + 1;
      ((__s->hh).tbl)->buckets = pUVar3;
      if (((__s->hh).tbl)->num_items >> 1 < ((__s->hh).tbl)->nonideal_items) {
        uVar5 = ((__s->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar5 = 0;
      }
      ((__s->hh).tbl)->ineff_expands = uVar5;
      if (1 < ((__s->hh).tbl)->ineff_expands) {
        ((__s->hh).tbl)->noexpand = 1;
      }
    }
  }
  else {
    d->lastid = d->lastid + 1;
    cgpu->device_id = d->lastid;
  }
  _wr_lock(&devices_lock,"cgminer.c","add_cgpu",0x2b8d);
  devices = (cgpu_info **)
            _cgrealloc(devices,(total_devices + new_devices + 2) * 4,"cgminer.c","add_cgpu",0x2b8e);
  _wr_unlock(&devices_lock,"cgminer.c","add_cgpu",0x2b8f);
  _mutex_lock(&stats_lock,"cgminer.c","add_cgpu",0x2b91);
  tVar4 = time((time_t *)0x0);
  cgpu->last_device_valid_work = tVar4;
  _mutex_unlock(&stats_lock,"cgminer.c","add_cgpu",0x2b93);
  if (hotplug_mode == false) {
    devices[total_devices] = cgpu;
    total_devices = total_devices + 1;
  }
  else {
    devices[new_devices + total_devices] = cgpu;
    new_devices = new_devices + 1;
  }
  adjust_mostdevs();
  return true;
}

