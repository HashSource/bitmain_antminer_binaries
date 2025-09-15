
void poolpriority(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int iVar2;
  int iVar3;
  pool *ppVar4;
  int_0_ aiStack_68 [4];
  uint local_64;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char *ptr;
  int_0_ *new_prio;
  int local_44;
  _Bool_0_ *pools_changed;
  int local_3c;
  int prio;
  int pr;
  int i;
  char *next;
  
  prio = 0;
  isjson_local = isjson;
  param_local = param;
  c_local = c;
  io_data_local = io_data;
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
  }
  else {
    iVar1 = -(total_pools + 7U & 0xfffffff8);
    iVar2 = -(total_pools * 4 + 10U & 0xfffffff8);
    for (i = 0; local_64 = (uint)total_pools >> 0x1d, new_prio = aiStack_68 + iVar2 + iVar1,
        local_44 = total_pools + -1, pools_changed = aiStack_68 + iVar1, local_3c = total_pools + -1
        , next = param, i < total_pools; i = i + 1) {
      (aiStack_68 + iVar1)[i] = 0;
    }
    while ((next != (char *)0x0 && (*next != '\0'))) {
      ptr = next;
      next = strchr(next,0x2c);
      if (next != (char *)0x0) {
        *next = '\0';
        next = next + 1;
      }
      iVar3 = atoi(ptr);
      i = iVar3;
      if ((iVar3 < 0) || (total_pools <= iVar3)) {
        *(uint *)(&stack0xffffff90 + iVar2 + iVar1) = (uint)isjson_local;
        message(io_data_local,0x1a,i,(char *)0x0,(_Bool)(&stack0xffffff90)[iVar2 + iVar1]);
        return;
      }
      if (pools_changed[iVar3] != '\0') {
        *(uint *)(&stack0xffffff90 + iVar2 + iVar1) = (uint)isjson_local;
        message(io_data_local,0x4a,i,(char *)0x0,(_Bool)(&stack0xffffff90)[iVar2 + iVar1]);
        return;
      }
      pools_changed[iVar3] = 1;
      *(int *)(new_prio + iVar3 * 4) = prio;
      prio = prio + 1;
    }
    for (i = 0; i < total_pools; i = i + 1) {
      if (pools_changed[i] != '\0') {
        pools[i]->prio = *(int *)(new_prio + i * 4);
      }
    }
    for (pr = 0; pr < total_pools; pr = pr + 1) {
      for (i = 0; i < total_pools; i = i + 1) {
        if ((pools_changed[i] != '\x01') && (pools[i]->prio == pr)) {
          pools[i]->prio = prio;
          pools_changed[i] = 1;
          prio = prio + 1;
          break;
        }
      }
    }
    ppVar4 = current_pool();
    if (ppVar4->prio != 0) {
      switch_pools((pool *)0x0);
    }
    *(uint *)(&stack0xffffff90 + iVar2 + iVar1) = (uint)isjson_local;
    message(io_data_local,0x49,0,(char *)0x0,(_Bool)(&stack0xffffff90)[iVar2 + iVar1]);
  }
  return;
}

