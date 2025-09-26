
int cmd_NumTickets(int param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = strtol(param_2,(char **)0x0,10);
  if (lVar1 < 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 != 0) {
      iVar2 = SSL_CTX_set_num_tickets(iVar2,lVar1);
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar2 = SSL_set_num_tickets(*(int *)(param_1 + 0x10),lVar1);
      return iVar2;
    }
  }
  return iVar2;
}

