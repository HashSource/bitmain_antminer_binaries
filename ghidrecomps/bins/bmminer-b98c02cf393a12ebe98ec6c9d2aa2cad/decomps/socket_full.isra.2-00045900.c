
bool socket_full_isra_2(uint param_1,uint param_2)

{
  int iVar1;
  __suseconds_t *p_Var2;
  uint uVar3;
  uint uVar4;
  timeval local_a0;
  fd_set local_98;
  
  local_a0.tv_sec = param_2 & ~((int)param_2 >> 0x1f);
  p_Var2 = &local_a0.tv_usec;
  do {
    p_Var2 = p_Var2 + 1;
    *p_Var2 = 0;
  } while (p_Var2 != local_98.fds_bits + 0x1f);
  uVar4 = param_1 & 0x1f;
  uVar3 = param_1 + 0x1f & (int)param_1 >> 0x20;
  if (p_Var2 < local_98.fds_bits + 0x1f) {
    uVar3 = param_1;
  }
  if ((int)param_1 < 1) {
    uVar4 = -(-param_1 & 0x1f);
  }
  local_a0.tv_usec = 0;
  local_98.fds_bits[(int)uVar3 >> 5] = local_98.fds_bits[(int)uVar3 >> 5] | 1 << (uVar4 & 0xff);
  iVar1 = select(param_1 + 1,&local_98,(fd_set *)0x0,(fd_set *)0x0,&local_a0);
  return 0 < iVar1;
}

