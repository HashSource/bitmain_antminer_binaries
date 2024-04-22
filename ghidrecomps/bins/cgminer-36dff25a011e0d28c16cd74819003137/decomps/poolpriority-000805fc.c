
void poolpriority(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  pool *ppVar5;
  _Bool a_Stack_48 [3];
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char *ptr;
  int_0_ *new_prio;
  int local_2c;
  _Bool_0_ *pools_changed;
  int local_24;
  char *next;
  int i;
  int pr;
  int prio;
  
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
    for (i = 0; new_prio = a_Stack_48 + iVar2 + iVar1, local_2c = total_pools + -1,
        pools_changed = a_Stack_48 + iVar1, local_24 = total_pools + -1, next = param,
        i < total_pools; i = i + 1) {
      (a_Stack_48 + iVar1)[i] = false;
    }
    while ((next != (char *)0x0 && (*next != '\0'))) {
      ptr = next;
      pcVar3 = strchr(next,0x2c);
      next = pcVar3;
      if (pcVar3 != (char *)0x0) {
        next = pcVar3 + 1;
        *pcVar3 = '\0';
      }
      iVar4 = atoi(ptr);
      i = iVar4;
      if ((iVar4 < 0) || (total_pools <= iVar4)) {
        *(uint *)(&stack0xffffffb0 + iVar2 + iVar1) = (uint)isjson_local;
        message(io_data_local,0x1a,i,(char *)0x0,(_Bool)(&stack0xffffffb0)[iVar2 + iVar1]);
        return;
      }
      if (pools_changed[iVar4] != '\0') {
        *(uint *)(&stack0xffffffb0 + iVar2 + iVar1) = (uint)isjson_local;
        message(io_data_local,0x4a,i,(char *)0x0,(_Bool)(&stack0xffffffb0)[iVar2 + iVar1]);
        return;
      }
      pools_changed[iVar4] = 1;
      *(int *)(new_prio + iVar4 * 4) = prio;
      prio = prio + 1;
    }
    for (i = 0; i < total_pools; i = i + 1) {
      if (pools_changed[i] != '\0') {
        pools[i]->prio = *(int *)(new_prio + i * 4);
      }
    }
    for (pr = 0; pr < total_pools; pr = pr + 1) {
      for (i = 0; i < total_pools; i = i + 1) {
        if ((pools_changed[i] != '\x01') && (pr == pools[i]->prio)) {
          pools[i]->prio = prio;
          pools_changed[i] = 1;
          prio = prio + 1;
          break;
        }
      }
    }
    ppVar5 = current_pool();
    if (ppVar5->prio != 0) {
      switch_pools((pool *)0x0);
    }
    *(uint *)(&stack0xffffffb0 + iVar2 + iVar1) = (uint)isjson_local;
    message(io_data_local,0x49,0,(char *)0x0,(_Bool)(&stack0xffffffb0)[iVar2 + iVar1]);
  }
  return;
}

