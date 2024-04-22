
void ftp_state_type(int *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if ((*(char *)(iVar3 + 0x307) != '\0') && (param_1[0x102] != 0)) {
    cVar1 = *(char *)(iVar3 + 0x2fb);
    if (cVar1 == '\0') {
      cVar2 = 'I';
    }
    else {
      cVar2 = 'A';
    }
    if (*(char *)(param_1 + 0x106) != cVar2) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14c) + 0xc) = 1;
      ftp_nb_type(param_1,cVar1,0x13);
      return;
    }
  }
  ftp_state_size(param_1);
  return;
}

