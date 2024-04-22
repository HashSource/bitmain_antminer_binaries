
_Bool isdupnonce(cgpu_info *cgpu,work *work,uint nonce)

{
  K_ITEM *pKVar1;
  uint uVar2;
  bool bVar3;
  int *piVar4;
  void *pvVar5;
  double dVar6;
  double dVar7;
  uint nonce_local;
  work *work_local;
  cgpu_info *cgpu_local;
  char tmp42 [2048];
  timeval now;
  dupdata *dup;
  K_ITEM *item;
  _Bool unique;
  
  piVar4 = (int *)cgpu->dup_data;
  bVar3 = true;
  if (piVar4 == (int *)0x0) {
    bVar3 = false;
  }
  else {
    cgtime(&now);
    uVar2 = piVar4[4];
    piVar4[4] = uVar2 + 1;
    piVar4[5] = piVar4[5] + (uint)(0xfffffffe < uVar2);
    _cg_wlock(*(cglock_t **)(piVar4[1] + 8),"noncedup.c","isdupnonce",0x46);
    item = *(K_ITEM **)(piVar4[2] + 0x10);
    while ((bVar3 && (item != (K_ITEM *)0x0))) {
                    /* WARNING: Load size is inaccurate */
      if ((*item->data == work->id) && (*(uint *)((int)item->data + 4) == nonce)) {
        bVar3 = false;
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"%s%d: Duplicate nonce %08x",cgpu->drv->name,cgpu->device_id,nonce);
          _applog(4,tmp42,false);
        }
      }
      else {
        item = item->prev;
      }
    }
    if (bVar3) {
      pKVar1 = _k_unlink_head((K_LIST *)piVar4[1],"noncedup.c","isdupnonce",0x51);
      *(uint *)pKVar1->data = work->id;
      *(uint *)((int)pKVar1->data + 4) = nonce;
      pvVar5 = pKVar1->data;
      *(__time_t *)((int)pvVar5 + 8) = now.tv_sec;
      *(__suseconds_t *)((int)pvVar5 + 0xc) = now.tv_usec;
      _k_add_head((K_LIST *)piVar4[2],pKVar1,"noncedup.c","isdupnonce",0x55);
    }
    item = *(K_ITEM **)(piVar4[2] + 0x10);
    while (item != (K_ITEM *)0x0) {
      dVar6 = tdiff((timeval *)((int)item->data + 8),&now);
      dVar7 = (double)(longlong)*piVar4;
      if (dVar6 == dVar7 || dVar6 < dVar7 != (NAN(dVar6) || NAN(dVar7))) break;
      pKVar1 = _k_unlink_tail((K_LIST *)piVar4[2],"noncedup.c","isdupnonce",0x59);
      _k_add_head((K_LIST *)piVar4[1],pKVar1,"noncedup.c","isdupnonce",0x5a);
      item = *(K_ITEM **)(piVar4[2] + 0x10);
    }
    _cg_wunlock(*(cglock_t **)(piVar4[1] + 8),"noncedup.c","isdupnonce",0x5d);
    if (!bVar3) {
      uVar2 = piVar4[6];
      piVar4[6] = uVar2 + 1;
      piVar4[7] = piVar4[7] + (uint)(0xfffffffe < uVar2);
    }
    bVar3 = !bVar3;
  }
  return bVar3;
}

