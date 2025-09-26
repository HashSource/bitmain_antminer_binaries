
_Bool check_pt2_success(eeprom_data_format_t *efd)

{
  int iVar1;
  undefined1 uVar2;
  bool bVar3;
  eeprom_data_format_t *efd_local;
  
  iVar1 = (*efd->pt2_result_get)(efd);
  bVar3 = iVar1 == 1;
  if (bVar3) {
    iVar1 = 1;
  }
  uVar2 = (undefined1)iVar1;
  if (!bVar3) {
    uVar2 = 0;
  }
  return (_Bool)uVar2;
}

