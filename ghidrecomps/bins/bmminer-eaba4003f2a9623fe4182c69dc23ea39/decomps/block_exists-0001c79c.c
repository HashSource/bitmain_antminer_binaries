
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool block_exists(char *hexstr,uchar *bedata,work *work)

{
  bool bVar1;
  block *__ptr;
  size_t sVar2;
  block *__dest;
  UT_hash_table *pUVar3;
  UT_hash_bucket *pUVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  void *pvVar8;
  int iVar9;
  UT_hash_handle *pUVar10;
  UT_hash_bucket *pUVar11;
  size_t sVar12;
  work *work_local;
  uchar *bedata_local;
  char *hexstr_local;
  char tmp42 [2048];
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  uint _hd_bkt;
  UT_hash_handle *_hd_hh_del;
  block *oldblock;
  uint _hf_bkt;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key_1;
  uint _hj_k_1;
  uint _hj_j_1;
  uint _hj_i_1;
  uint _ha_hashv;
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
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _hf_hashv;
  _Bool ret;
  block *s;
  int deleted_block;
  
  deleted_block = 0;
  ret = true;
  _wr_lock(&blk_lock,"cgminer.c","block_exists",0x1566);
  _hf_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  _hj_k = strlen(hexstr);
  _hj_key = (uchar *)hexstr;
  for (; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar9 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                    (uint)_hj_key[7] * 0x1000000;
    uVar5 = _hf_hashv +
            (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
            (uint)_hj_key[0xb] * 0x1000000;
    uVar6 = uVar5 >> 0xd ^
            ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                      (uint)_hj_key[3] * 0x1000000) - iVar9) - uVar5;
    uVar7 = uVar6 << 8 ^ (iVar9 - uVar5) - uVar6;
    uVar5 = uVar7 >> 0xd ^ (uVar5 - uVar6) - uVar7;
    uVar6 = uVar5 >> 0xc ^ (uVar6 - uVar7) - uVar5;
    uVar7 = uVar6 << 0x10 ^ (uVar7 - uVar5) - uVar6;
    uVar5 = uVar7 >> 5 ^ (uVar5 - uVar6) - uVar7;
    _hj_i = uVar5 >> 3 ^ (uVar6 - uVar7) - uVar5;
    _hj_j = _hj_i << 10 ^ (uVar7 - uVar5) - _hj_i;
    _hf_hashv = _hj_j >> 0xf ^ (uVar5 - _hj_i) - _hj_j;
    _hj_key = _hj_key + 0xc;
  }
  sVar2 = strlen(hexstr);
  _hf_hashv = _hf_hashv + sVar2;
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
  s = (block *)0x0;
  if (blocks != (block *)0x0) {
    uVar6 = uVar5 & ((blocks->hh).tbl)->num_buckets - 1;
    if (((blocks->hh).tbl)->buckets[uVar6].hh_head == (UT_hash_handle *)0x0) {
      s = (block *)0x0;
    }
    else {
      s = (block *)((int)((blocks->hh).tbl)->buckets[uVar6].hh_head - ((blocks->hh).tbl)->hho);
    }
    while (s != (block *)0x0) {
      if (((s->hh).hashv == uVar5) &&
         (sVar12 = (s->hh).keylen, sVar2 = strlen(hexstr), sVar12 == sVar2)) {
        pvVar8 = (s->hh).key;
        sVar2 = strlen(hexstr);
        iVar9 = memcmp(pvVar8,hexstr,sVar2);
        if (iVar9 == 0) break;
      }
      if ((s->hh).hh_next == (UT_hash_handle *)0x0) {
        s = (block *)0x0;
      }
      else {
        s = (block *)((int)(s->hh).hh_next - ((blocks->hh).tbl)->hho);
      }
    }
  }
  if (s == (block *)0x0) {
    __dest = (block *)_cgcalloc(0x68,1,"cgminer.c","block_exists",0x156a);
    if (__dest == (block *)0x0) {
      tmp42[0] = s_block_exists_OOM_00073174[0];
      tmp42[1] = s_block_exists_OOM_00073174[1];
      tmp42[2] = s_block_exists_OOM_00073174[2];
      tmp42[3] = s_block_exists_OOM_00073174[3];
      tmp42[4] = s_block_exists_OOM_00073174[4];
      tmp42[5] = s_block_exists_OOM_00073174[5];
      tmp42[6] = s_block_exists_OOM_00073174[6];
      tmp42[7] = s_block_exists_OOM_00073174[7];
      tmp42[8] = s_block_exists_OOM_00073174[8];
      tmp42[9] = s_block_exists_OOM_00073174[9];
      tmp42[10] = s_block_exists_OOM_00073174[10];
      tmp42[11] = s_block_exists_OOM_00073174[11];
      tmp42[12] = s_block_exists_OOM_00073174[12];
      tmp42[13] = s_block_exists_OOM_00073174[13];
      tmp42[14] = s_block_exists_OOM_00073174[14];
      tmp42[15] = s_block_exists_OOM_00073174[15];
      tmp42[16] = (char)ram0x00073184;
      _applog(3,tmp42,true);
      _quit(1);
    }
    strcpy((char *)__dest,hexstr);
    __dest->block_no = new_blocks;
    new_blocks = new_blocks + 1;
    ret = false;
    if ((blocks != (block *)0x0) && (3 < ((blocks->hh).tbl)->num_items)) {
      if (blocks != (block *)0x0) {
        _hs_insize = 1;
        bVar1 = true;
        _hs_list = &blocks->hh;
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
                _hs_q = (UT_hash_handle *)((int)_hs_q->next + ((blocks->hh).tbl)->hho);
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
                  _hs_q = (UT_hash_handle *)((int)_hs_q->next + ((blocks->hh).tbl)->hho);
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
                    _hs_p = (UT_hash_handle *)((int)_hs_p->next + ((blocks->hh).tbl)->hho);
                  }
                }
                _hs_psize = _hs_psize - 1;
              }
              else {
                iVar9 = block_sort((block *)((int)_hs_p - ((blocks->hh).tbl)->hho),
                                   (block *)((int)_hs_q - ((blocks->hh).tbl)->hho));
                if (iVar9 < 1) {
                  _hs_e = _hs_p;
                  if (_hs_p != (UT_hash_handle *)0x0) {
                    if (_hs_p->next == (void *)0x0) {
                      _hs_p = (UT_hash_handle *)0x0;
                    }
                    else {
                      _hs_p = (UT_hash_handle *)((int)_hs_p->next + ((blocks->hh).tbl)->hho);
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
                    _hs_q = (UT_hash_handle *)((int)_hs_q->next + ((blocks->hh).tbl)->hho);
                  }
                  _hs_qsize = _hs_qsize - 1;
                }
              }
              if (_hs_tail == (UT_hash_handle *)0x0) {
                _hs_list = _hs_e;
              }
              else {
                if (_hs_e == (UT_hash_handle *)0x0) {
                  pvVar8 = (void *)0x0;
                }
                else {
                  pvVar8 = (void *)((int)_hs_e - ((blocks->hh).tbl)->hho);
                }
                _hs_tail->next = pvVar8;
              }
              if (_hs_e != (UT_hash_handle *)0x0) {
                if (_hs_tail == (UT_hash_handle *)0x0) {
                  pvVar8 = (void *)0x0;
                }
                else {
                  pvVar8 = (void *)((int)_hs_tail - ((blocks->hh).tbl)->hho);
                }
                _hs_e->prev = pvVar8;
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
            ((blocks->hh).tbl)->tail = _hs_tail;
            blocks = (block *)((int)_hs_list - ((blocks->hh).tbl)->hho);
          }
          _hs_insize = _hs_insize << 1;
        }
      }
      __ptr = blocks;
      deleted_block = blocks->block_no;
      if (((blocks->hh).prev == (void *)0x0) && ((blocks->hh).next == (void *)0x0)) {
        free(((blocks->hh).tbl)->buckets);
        free((blocks->hh).tbl);
        blocks = (block *)0x0;
      }
      else {
        pUVar10 = &blocks->hh;
        if ((block *)((int)((blocks->hh).tbl)->tail - ((blocks->hh).tbl)->hho) == blocks) {
          ((blocks->hh).tbl)->tail =
               (UT_hash_handle *)((int)(blocks->hh).prev + ((blocks->hh).tbl)->hho);
        }
        if ((__ptr->hh).prev == (void *)0x0) {
          blocks = (block *)(__ptr->hh).next;
        }
        else {
          *(void **)((int)(__ptr->hh).prev + ((blocks->hh).tbl)->hho + 8) = (__ptr->hh).next;
        }
        if ((__ptr->hh).next != (void *)0x0) {
          *(void **)((int)(__ptr->hh).next + ((blocks->hh).tbl)->hho + 4) = (__ptr->hh).prev;
        }
        uVar5 = ((blocks->hh).tbl)->num_buckets - 1 & (__ptr->hh).hashv;
        pUVar4 = ((blocks->hh).tbl)->buckets;
        pUVar4[uVar5].count = pUVar4[uVar5].count - 1;
        if (((blocks->hh).tbl)->buckets[uVar5].hh_head == pUVar10) {
          ((blocks->hh).tbl)->buckets[uVar5].hh_head = (__ptr->hh).hh_next;
        }
        if ((__ptr->hh).hh_prev != (UT_hash_handle *)0x0) {
          ((__ptr->hh).hh_prev)->hh_next = (__ptr->hh).hh_next;
        }
        if ((__ptr->hh).hh_next != (UT_hash_handle *)0x0) {
          ((__ptr->hh).hh_next)->hh_prev = (__ptr->hh).hh_prev;
        }
        pUVar3 = (blocks->hh).tbl;
        pUVar3->num_items = pUVar3->num_items - 1;
      }
      free(__ptr);
    }
    _ha_hashv = 0xfeedbeef;
    _hj_j_1 = 0x9e3779b9;
    _hj_i_1 = 0x9e3779b9;
    _hj_k_1 = strlen((char *)__dest);
    _hj_key_1 = (uchar *)__dest;
    for (; 0xb < _hj_k_1; _hj_k_1 = _hj_k_1 - 0xc) {
      iVar9 = _hj_j_1 + (uint)_hj_key_1[4] + (uint)_hj_key_1[5] * 0x100 +
                        (uint)_hj_key_1[6] * 0x10000 + (uint)_hj_key_1[7] * 0x1000000;
      uVar5 = _ha_hashv +
              (uint)_hj_key_1[8] + (uint)_hj_key_1[9] * 0x100 + (uint)_hj_key_1[10] * 0x10000 +
              (uint)_hj_key_1[0xb] * 0x1000000;
      uVar6 = uVar5 >> 0xd ^
              ((_hj_i_1 +
               (uint)*_hj_key_1 + (uint)_hj_key_1[1] * 0x100 + (uint)_hj_key_1[2] * 0x10000 +
               (uint)_hj_key_1[3] * 0x1000000) - iVar9) - uVar5;
      uVar7 = uVar6 << 8 ^ (iVar9 - uVar5) - uVar6;
      uVar5 = uVar7 >> 0xd ^ (uVar5 - uVar6) - uVar7;
      uVar6 = uVar5 >> 0xc ^ (uVar6 - uVar7) - uVar5;
      uVar7 = uVar6 << 0x10 ^ (uVar7 - uVar5) - uVar6;
      uVar5 = uVar7 >> 5 ^ (uVar5 - uVar6) - uVar7;
      _hj_i_1 = uVar5 >> 3 ^ (uVar6 - uVar7) - uVar5;
      _hj_j_1 = _hj_i_1 << 10 ^ (uVar7 - uVar5) - _hj_i_1;
      _ha_hashv = _hj_j_1 >> 0xf ^ (uVar5 - _hj_i_1) - _hj_j_1;
      _hj_key_1 = _hj_key_1 + 0xc;
    }
    sVar2 = strlen((char *)__dest);
    _ha_hashv = _ha_hashv + sVar2;
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
    (__dest->hh).hashv = uVar5;
    (__dest->hh).key = __dest;
    sVar2 = strlen((char *)__dest);
    (__dest->hh).keylen = sVar2;
    if (blocks == (block *)0x0) {
      (__dest->hh).next = (void *)0x0;
      (__dest->hh).prev = (void *)0x0;
      blocks = __dest;
      pUVar3 = (UT_hash_table *)malloc(0x2c);
      (__dest->hh).tbl = pUVar3;
      if ((blocks->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((blocks->hh).tbl,0,0x2c);
      ((blocks->hh).tbl)->tail = &blocks->hh;
      ((blocks->hh).tbl)->num_buckets = 0x20;
      ((blocks->hh).tbl)->log2_num_buckets = 5;
      ((blocks->hh).tbl)->hho = 0x44;
      pUVar3 = (blocks->hh).tbl;
      pUVar4 = (UT_hash_bucket *)malloc(0x180);
      pUVar3->buckets = pUVar4;
      if (((blocks->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(((blocks->hh).tbl)->buckets,0,0x180);
      ((blocks->hh).tbl)->signature = 0xa0111fe1;
    }
    else {
      (__dest->hh).tbl = (blocks->hh).tbl;
      (__dest->hh).next = (void *)0x0;
      (__dest->hh).prev = (void *)((int)((blocks->hh).tbl)->tail - ((blocks->hh).tbl)->hho);
      ((blocks->hh).tbl)->tail->next = __dest;
      ((blocks->hh).tbl)->tail = &__dest->hh;
    }
    pUVar3 = (blocks->hh).tbl;
    pUVar3->num_items = pUVar3->num_items + 1;
    uVar5 = uVar5 & ((blocks->hh).tbl)->num_buckets - 1;
    pUVar4 = ((blocks->hh).tbl)->buckets;
    pUVar4[uVar5].count = pUVar4[uVar5].count + 1;
    (__dest->hh).hh_next = ((blocks->hh).tbl)->buckets[uVar5].hh_head;
    (__dest->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((blocks->hh).tbl)->buckets[uVar5].hh_head != (UT_hash_handle *)0x0) {
      (((blocks->hh).tbl)->buckets[uVar5].hh_head)->hh_prev = &__dest->hh;
    }
    ((blocks->hh).tbl)->buckets[uVar5].hh_head = &__dest->hh;
    if (((((blocks->hh).tbl)->buckets[uVar5].expand_mult + 1) * 10 <=
         ((blocks->hh).tbl)->buckets[uVar5].count) && (((__dest->hh).tbl)->noexpand != 1)) {
      pUVar4 = (UT_hash_bucket *)malloc(((__dest->hh).tbl)->num_buckets * 0x18);
      if (pUVar4 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar4,0,((__dest->hh).tbl)->num_buckets * 0x18);
      ((__dest->hh).tbl)->ideal_chain_maxlen =
           (((__dest->hh).tbl)->num_items >> (((__dest->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((__dest->hh).tbl)->num_buckets * 2 - 1 & ((__dest->hh).tbl)->num_items) != 0);
      ((__dest->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__dest->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__dest->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar10 = _he_thh->hh_next;
          pUVar11 = pUVar4 + (((__dest->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar11->count = pUVar11->count + 1;
          if (((__dest->hh).tbl)->ideal_chain_maxlen < pUVar11->count) {
            pUVar3 = (__dest->hh).tbl;
            pUVar3->nonideal_items = pUVar3->nonideal_items + 1;
            uVar5 = __aeabi_uidiv(pUVar11->count,((__dest->hh).tbl)->ideal_chain_maxlen);
            pUVar11->expand_mult = uVar5;
          }
          _he_thh->hh_prev = (UT_hash_handle *)0x0;
          _he_thh->hh_next = pUVar11->hh_head;
          if (pUVar11->hh_head != (UT_hash_handle *)0x0) {
            pUVar11->hh_head->hh_prev = _he_thh;
          }
          pUVar11->hh_head = _he_thh;
          _he_thh = pUVar10;
        }
      }
      free(((__dest->hh).tbl)->buckets);
      ((__dest->hh).tbl)->num_buckets = ((__dest->hh).tbl)->num_buckets << 1;
      pUVar3 = (__dest->hh).tbl;
      pUVar3->log2_num_buckets = pUVar3->log2_num_buckets + 1;
      ((__dest->hh).tbl)->buckets = pUVar4;
      if (((__dest->hh).tbl)->num_items >> 1 < ((__dest->hh).tbl)->nonideal_items) {
        uVar5 = ((__dest->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar5 = 0;
      }
      ((__dest->hh).tbl)->ineff_expands = uVar5;
      if (1 < ((__dest->hh).tbl)->ineff_expands) {
        ((__dest->hh).tbl)->noexpand = 1;
      }
    }
    set_blockdiff(work);
    if (((deleted_block != 0) && (opt_debug != false)) &&
       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
      snprintf(tmp42,0x800,"Deleted block %d from database",deleted_block);
      _applog(7,tmp42,false);
    }
  }
  _wr_unlock(&blk_lock,"cgminer.c","block_exists",0x158c);
  if (ret != true) {
    set_curblock(hexstr,bedata);
  }
  if (((deleted_block != 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Deleted block %d from database",deleted_block);
    _applog(7,tmp42,false);
  }
  return ret;
}

